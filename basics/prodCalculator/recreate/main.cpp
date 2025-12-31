#include <iostream>
#include <string>
#include "calculator.hpp"

int main(int argc, char* argv[]) {
  if(argc != 4) {
    std::cerr << "usage: ./calculator <a> <op> <b>\n";
    return 1;
  }

  try {
    size_t pos{};
    double a = std::stod(argv[1], &pos);
    if(pos != std::string(argv[1]).length())
      throw std::invalid_argument("invalid first operand");
    
    char opChar = argv[2][0];
    Operation op = parseOperation(opChar);

    double b = std::stod(argv[3], &pos);
    if(pos != std::string(argv[3]).length())
      throw std::invalid_argument("invalid second operand");

    std::cout << calculate(a, b, op) << '\n';

  } catch(const std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    return 1;
  }
}
