// startGame
// generateRandomNumber
// readValidGuess
#ifndef NUMBER_GUESSING_GAME_HPP
#define NUMBER_GUESSING_GAME_HPP

#include <string>

int generateRandomNumber(int min, int max);
int convertInteger(std::string& guess); 
void startGame(int max);

#endif

