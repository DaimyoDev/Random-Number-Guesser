#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>
using namespace std;

void playGame();
bool wantToPlayAgain();
bool isGameOver(int secretNumber, int numberOfTries, int currentPlayerGuess);
int getGuess(int numberOfTries);
void displayResult(int secretNumber, int numberOfTries);
const int IGNORE_CHARS = 256;

int main()
{
    srand((unsigned int) time(NULL));

    do
    {
        playGame();
    } while(wantToPlayAgain());

    return 0;
}

void playGame()
{
    const int UPPER_BOUND = 100;
    int secretNumber = rand() % UPPER_BOUND;
    int numberOfTries = ceil(log2(UPPER_BOUND));
    int guess = 0;


    do
    {
        
        guess = getGuess(numberOfTries);
        if(guess != secretNumber)
        {
            numberOfTries--;
            if (guess > secretNumber) {
                
                cout << "Your guess was too high" << endl;
            }
            else
            {
                cout << "Your guess was too low" << endl;
            }
        }
    } while (!isGameOver(secretNumber, numberOfTries, guess));
    displayResult(secretNumber, numberOfTries);
}

bool wantToPlayAgain()
{
    char input;
    bool failure;

    do
    {
        failure = false;

        cout << "Would you like to play again? (y/n)" << endl;
        cin >> input;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "Input error please try again" << endl;
            failure = true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');

            input = tolower(input)
        }

    } while (failure);
    
    return input == 'y';
}

bool isGameOver(int secretNumber, int numberOfTries, int currentPlayerGuess) 
{
    return secretNumber == currentPlayerGuess || numberOfTries <= 0;
}

int getGuess(int numberOfTries)
{
    
    int guess;
    bool failure;

    do
    {
        failure = false;
        cout << "The range of the number is between 1 and 100" << endl;
        cout << "Please enter your guess (number of guesses left: " << numberOfTries << "): " << endl;
        cin >> guess;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "Input error! Please try again ^^" << endl;
            failure = true;
        }
    } while (failure);
    return guess;
}

void displayResult(int secretNumber, int numberOfTries)
{
    if(numberOfTries > 0) {
        cout << "You got it, it was: " << secretNumber << endl;
    }
    else
    {
        cout << "You didn't get it, it was: " << secretNumber << endl;
    }
}