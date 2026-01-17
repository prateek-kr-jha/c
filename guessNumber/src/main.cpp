/*
start game
exit
*/
//#include "number_guessing_game.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "number_guessing_game.hpp"

int main(int argc, char* argv[]){
  if(argc != 2) {
    std::cerr << "Usage: ./number_guessing_game <integer>";
    return 1;
  }

  try {
    size_t pos {};
    int game_ceiling = std::stoi(argv[1], &pos);

    if(pos !=std::string(argv[1]).length()) {
      std::cerr << "Something is wrong with input value\n";
      return 1;
    }

    startGame(game_ceiling);
    return 0;
  } catch(const std::& e) {
    std::cerr << "Error: invalid input. Must be an integer";
    return 1
  } catch(const std::invalid_argument& e) {
    std::cerr << "Error: invalid input. Must be an integer";
    return 1
  } catch(const std::exception& ex){
    std::cerro << "Error: " << ex.what() << std::endl;
    return 1;
  }
}

