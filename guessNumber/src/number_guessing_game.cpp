#include <stdexcept>
#include <iostream>
#include <string>
#include <random>

int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

int convertInteger(std::string& guess) {
    try {
        size_t pos;
        int guessValue = stoi(guess, &pos);
    
        if(pos != guess.length()) {
            throw std::invalid_argument("Invalid value");
        }
        return guessValue;
    } catch(const std::invalid_argument& e) {
        std::cout << e.what();
        return -1;
    }
}


void startGame(int max=100) {
    const int min{1};
    int randomValue = generateRandomNumber(min, max);
    int attempts = 0;
    std::cout << "Game starts: Guess a number between " << min << " and " << max << "\n";
    while (true){
        attempts++;
        std::string guess{ };
        std::cin >> guess;
        int guessValue  { convertInteger(guess) };
        if(guessValue == -1) {
            std::cout << "Value guessed is invalid, Please guess again.\n";
        } else if(guessValue > randomValue) {
            std::cout << "Value guessed is more than actual, Please guess again.\n";
        } else if(guessValue < randomValue) {
            std::cout << "Value guessed is less than actual, Please guess again.\n";
        } else {
            std::cout << "Correct\n";
            std::cout << "Total attempts = " << attempts << "\n";
            break;
        }
    }
    
}
