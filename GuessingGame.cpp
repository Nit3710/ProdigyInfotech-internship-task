#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    int randomNumber = rand() % 100 + 1;       // Generate a random number between 1 and 100
    int userGuess = 0;
    int attempts = 0;

    cout << "Welcome to the number guessing game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number." << endl;
            cout << "It took you " << attempts << " attempts to guess the correct number." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
