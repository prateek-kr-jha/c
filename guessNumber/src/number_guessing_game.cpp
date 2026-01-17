#include <stdexcept>
#include <iostream>
#include <string>
#include <random>
#include <limits>

constexpr int INVALID_GUESS = -1;

int generateRandomNumber(int min, int max) {
    if(min > max) {
        throw std::invalid_argument("min must be <= max");
    }
    
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
            return INVALID_GUESS;
        }
        return guessValue;
    } catch(const std::invalid_argument& e) {
        return INVALID_GUESS;
    } catch(const std::out_of_range& e) {
        return INVALID_GUESS;
    }
}


void startGame(int max) {
    if(max < 1) {
        std::cerr << "Error: Maximum number should be atleast greater than 1.\n";
        return;
    }

    const int min{1};
    int randomValue { generateRandomNumber(min, max) };
    int attempts = 0;

    std::cout << "Game starts: Guess a number between " << min << " and " << max << "\n";

    while (true){
        std::string guess{ };

        if(!(std::cin >> guess)) {
            if(std::cin.eof()) {
                std::cout << "\nGame ended: EOF detected.\n";
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input error. Please try again.\n";
            continue;
        }
        
        int guessValue  { convertInteger(guess) };
        if(guessValue == INVALID_GUESS) {
            std::cout << "Value guessed is invalid, Please input a valid integer.\n";
            continue;
        }

        attempts++;
        if(guessValue > randomValue) {
            std::cout << "Value guessed is more than actual, Please guess again.\n";
        } else if(guessValue < randomValue) {
            std::cout << "Value guessed is less than actual, Please guess again.\n";
        } else {
            std::cout << "Correct!\n";
            std::cout << "Total attempts = " << attempts << "\n";
            break;
        }
    }
}
