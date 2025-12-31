#include "calculator.hpp"
#include <cmath>
#include <limits>

constexpr double PI = 3.141;

double calculator(double a, double b, Operation op) {
  switch(op) {
    case Operation::Add: return a + b;
    case Operation::Subtract: return a - b;
    case Operation::Multiply: return a * b;
    case Operation::Modulo:
      if(b == 0) throw std::invalid_argument("division by zero");
      return std::fmod(a, b);
    case Operation::Power:
      if(b == 0) throw std::invalid_argument("division by zero");
      return std::pow(a, b);
    case Operation::Divide:

    case Operation::AreaCircle:
    case Operation::AreaRectangle:
    case Operation::AreaSquare:
    default: 
      return std::numeric_limits<double>::quiet_NaN();
  }
}
