#include <iostream>
#include <ctime>
#include <cstdlib>

int generateRandomNumber() {
    return rand() % 100 + 1;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int randomNumber = generateRandomNumber();
    int guess, attempts = 0;

    std::cout << "Guess the number between 1 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
            std::cout << "Number of attempts: " << attempts << "\n";
        }

    } while (guess != randomNumber);

    return 0;
}
