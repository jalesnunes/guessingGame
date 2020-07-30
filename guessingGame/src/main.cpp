#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

/*****************************************************************
* Function: verifyGuess()
* This function will verify if guess is a number, if the user
* enter a char the program will not accept
*****************************************************************/
void verifyGuess(float& guess)
{
    //Loop until user enters a number
    while (cin.fail())
    {
        cout << "ERROR: This is not a valid option." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "What is your guess, choose a number: ";
        cin >> guess;
    }
}

/*****************************************************************
* Function: verifyRange()
* This function will verify if guess is in range beetween 1 to 100
* if the user enters a number smaller and bigger than those the 
* program will not accept
*****************************************************************/
void verifyRange(float& guess)
{
    bool wrongNumber = guess >= 1 && guess <= 100;

    //loop until user enters a valid number between the range
    while (!wrongNumber)
    {
        cout << "Number out of range, choose a number  between 1 to 100:  ";
        cin >> guess;
        verifyGuess(guess);
        wrongNumber = guess >= 1 && guess <= 100;
    }
}

/*****************************************************************
* Function: getGuess()
* This function is just to get the user guess and verify it
*****************************************************************/
float getGuess(float& guess)
{
    cout << "What is your guess, choose a number: ";
    cin >> guess;

    verifyGuess(guess);

    verifyRange(guess);

    return guess;
}

/*****************************************************************
* Function: main()
* the main function to drive the program
*****************************************************************/
int main()
{

    cout << "***************************************" << endl
         << "* Welcome to guessing game!           *" << endl
         << "***************************************\n" << endl;

    int secretNumber = 42;
    float guess = 0.0;
    vector<float> guessCollection;
    int count = 1;
    float score = 1000.0;

    srand(time(NULL)); //initialize random seed 
    secretNumber = rand() % 100;

    cout << "#######################################" << endl
         << "# Try to guess the secret number      #" << endl
         << "# The Number is between 1 to 100      #" << endl
         << "# Your starting score is 1000         #" << endl
         << "# Let's get it start!                 #" << endl
         << "#######################################\n" << endl;
          

   getGuess(guess);

   while (guess != secretNumber)
    {
        float lostPoints = abs(guess - secretNumber) / 2.0; // abs always will return an absolute number
        score -= lostPoints;

        if (guess < secretNumber)
        {
            cout << "Try again, Your guess is less than the secret number"
                << endl;
            guessCollection.push_back(guess);

        }
        else if (guess > secretNumber)
        {
            cout << "Try again, Your guess is bigger than the secret number"
                << endl;
            guessCollection.push_back(guess);
        }

        cout << "\nWrong guesses: ";

        for (int i = 0; i < guessCollection.size(); i++)
        {
            cout << guessCollection[i] << " ";
        }

        cout << endl;

        getGuess(guess);
        count++;
    }

    cout << "Congratulations you got it in "
        << count
        << " tries!"
        << endl
        << "This is your score: "
        << score
        << endl;


    return 0;
}