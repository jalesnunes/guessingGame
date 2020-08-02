#include <iostream>
#include <vector>
#include <time.h> 
#include <string>

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
* Function: setLevel()
* This function will set the game difficulty
*****************************************************************/
void setLevel(string& levelChoice, int& tryChances)
{
    if (levelChoice == "E")
    {
        tryChances = 15;
    }
    else if (levelChoice == "M")
    {
        tryChances = 10;
    }
    else if (levelChoice == "H")
    {
        tryChances = 5;
    }

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
    int attempts = 0;
    float score = 1000.0;
    string levelChoice;
    int tryChances;

    srand(time(NULL)); //initialize random seed 
    secretNumber = rand() % 100;

    cout << "#######################################" << endl
         << "# Try to guess the secret number      #" << endl
         << "# The Number is between 1 to 100      #" << endl
         << "# Your starting score is 1000         #" << endl
         << "# Let's get it start!                 #" << endl
         << "#######################################\n" << endl;

    cout << "Game levels:" << endl
         << "\tType E for Easy" << endl
         << "\tType M for Medium" << endl
         << "\tType H for Hard" << endl;
    cout << "Choose the game level: ";
   cin >> levelChoice;

   if (levelChoice != "E" && levelChoice != "M" && levelChoice != "H")
   {
       cout << "ERROR: This is not a valid option." << endl;
   }

   setLevel(levelChoice, tryChances);

   for(attempts; attempts < tryChances; attempts++)
    {
       cout << "\nAttempt: " << attempts + 1 << endl;

       getGuess(guess);

        float lostPoints = abs(guess - secretNumber) / 2.0; // abs always will return an absolute number
        score -= lostPoints;

        if (guess < secretNumber)
        {
            cout << "Try again, Your guess is smaller than the secret number"
                << endl;
            guessCollection.push_back(guess);

        }
        else if (guess > secretNumber)
        {
            cout << "Try again, Your guess is bigger than the secret number"
                << endl;
            guessCollection.push_back(guess);
        }
        else
        {
            break; //if the user hits the secret number we break the loop
        }

        cout << "\nWrong guesses: ";

        for (int i = 0; i < guessCollection.size(); i++)
        {
            cout << guessCollection[i] << " ";
        }

        cout << endl;
    }


   if (guess != secretNumber)
   {
       cout << "Sorry you just lost the game." << endl
            << "Please try again!" << endl;
   }
   else
   {
       cout.precision(2);
       cout << fixed;
       cout << "\nCongratulations you got it in "
           << attempts
           << " attempts!"
           << endl
           << "This is your score: "
           << score
           << endl;
   }


    return 0;
}