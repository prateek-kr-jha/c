/*
 * Improved Number Guessing Game Implementation
 * 
 * This file contains an improved version with:
 * - Bug fixes (attempt counting, validation)
 * - Better error handling
 * - Const correctness
 * - Clearer error messages
 * - Edge case handling
 * - Following cursorContext.md principles
 */

#include "number_guessing_game.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

// Named constant for invalid input return value
constexpr int INVALID_GUESS = -1;

// Helper function to read and validate a guess from user input
// Returns the guess value, or INVALID_GUESS if input is invalid
int readValidGuess(const std::string& input) {
    try {
        size_t pos = 0;
        int guessValue = std::stoi(input, &pos);
        
        // Check if entire string was consumed (no trailing characters)
        if (pos != input.length()) {
            return INVALID_GUESS;
        }
        
        return guessValue;
    } catch (const std::invalid_argument&) {
        // Input was not a valid integer
        return INVALID_GUESS;
    } catch (const std::out_of_range&) {
        // Input was out of int range
        return INVALID_GUESS;
    }
}

// Generates a random number in the range [min, max] (inclusive)
// Precondition: min <= max (validation should be done by caller)
int generateRandomNumber(int min, int max) {
    if (min > max) {
        throw std::invalid_argument("min must be <= max");
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    
    return dist(gen);
}

// Main game loop
// max: the maximum number that can be generated (must be >= 1)
void startGame(int max) {
    // Validate max is positive
    if (max < 1) {
        std::cerr << "Error: Maximum number must be at least 1.\n";
        return;
    }
    
    const int min = 1;// not best way to define
    int randomValue = generateRandomNumber(min, max);
    int attempts = 0;
    
    std::cout << "Game starts: Guess a number between " << min << " and " << max << "\n";
    
    while (true) {
        std::string input;
        
        // Read input line by line to handle spaces and edge cases better
        if (!(std::cin >> input)) {
            // Handle EOF or stream errors
            if (std::cin.eof()) {
                std::cout << "\nGame ended (EOF detected).\n";
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input error. Please try again.\n";
            continue;
        }
        
        // Validate the input
        int guessValue = readValidGuess(input);
        
        if (guessValue == INVALID_GUESS) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            continue; // Don't increment attempts for invalid input
        }
        
        // Increment attempts only for valid guesses
        attempts++;
        
        // Compare guess with secret number
        if (guessValue < randomValue) {
            std::cout << "Too low\n";
        } else if (guessValue > randomValue) {
            std::cout << "Too high\n";
        } else {
            // Correct guess!
            std::cout << "Correct! Attempts: " << attempts << "\n";
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    // Validate command-line arguments
    if (argc != 2) {
        std::cerr << "Usage: ./number_guessing_game <integer>\n";
        std::cerr << "  <integer>: Maximum number that can be generated (must be >= 1)\n";
        return 1;
    }
    
    try {
        // Parse and validate the maximum value
        size_t pos = 0;
        int game_ceiling = std::stoi(argv[1], &pos);
        
        // Check if entire argument was consumed
        if (pos != std::string(argv[1]).length()) {
            std::cerr << "Error: Invalid input value. Must be an integer.\n";
            return 1;
        }
        
        // Additional validation: check for positive value
        if (game_ceiling < 1) {
            std::cerr << "Error: Maximum number must be at least 1.\n";
            return 1;
        }
        
        // Start the game
        startGame(game_ceiling);
        return 0;
        
    } catch (const std::out_of_range&) {
        std::cerr << "Error: Input value is too large for an integer.\n";
        return 1;
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Invalid input. Must be an integer.\n";
        return 1;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
}
