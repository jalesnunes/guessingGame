#include <iostream>
#include <vector>

using namespace std;

int main()
{

    cout << "***************************************" << endl
         << "* Welcome to guessing game!           *" << endl
         << "***************************************" << endl;

    const int secretNumber = 42;
    float guess = 0.0;
    vector<float> guessCollection;

    cout << "Try to guess the secret number, let's get it start!" << endl;

    cout << "What is your guess, choose a number: ";
    cin >> guess;

    while (cin.fail())
    {
        cout << "ERROR: This is not a valid option." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "What is your guess, choose a number: ";
        cin >> guess;
    }

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
            cout << "Try again, Your guess is bigger than the secret number" ""
                << endl;
            guessCollection.push_back(guess);
        }
        else
        {
            cout << "ERROR: This is not a valid option." << endl;
        }

        cout << "\nWrong guesses: ";

        for (int i = 0; i < guessCollection.size(); i++)
        {
            cout << guessCollection[i] << " ";
        }

        cout << "\n\nWhat is your guess, choose a number: ";
        cin >> guess;

    } while (guess != secretNumber);

    cout << "Congratulations you got it!"
        << endl;


    return 0;
}