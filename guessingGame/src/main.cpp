#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

void verifyGuess(float& guess)
{
    while (cin.fail())
    {
        cout << "ERROR: This is not a valid option." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "What is your guess, choose a number: ";
        cin >> guess;
    }
}

float getGuess(float& guess)
{
    cout << "What is your guess, choose a number: ";
    cin >> guess;

    verifyGuess(guess);

    return guess;
}

int main()
{

    cout << "***************************************" << endl
         << "* Welcome to guessing game!           *" << endl
         << "***************************************" << endl;

    int secretNumber = 0;
    float guess = 0.0;
    vector<float> guessCollection;
    int count = 1;
    float score = 0;

    srand(time(NULL)); //initialize random seed 
    secretNumber = rand() % 100;

    cout << "Try to guess the secret number, let's get it start!" << endl;

    getGuess(guess);

    do
    {

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

    } while (guess != secretNumber);

    cout << "Congratulations you got it in "
        << count
        << " tries!"
        << endl
        << "This is your score: "
        << score
        << endl;


    return 0;
}