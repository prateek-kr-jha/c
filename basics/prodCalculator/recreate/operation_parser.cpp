#include "calculator.hpp"
#include <stdexcept>

Operation parseOperation(char c) {
  switch(c) {
    case '+': return Operation::Add;
    case '-': return Operation::Subtract;
    case '*': return Operation::Multiply;
    case '/': return Operation::Divide;
    case '%': return Operation::Modulo;
    case '^': return Operation::Power;
    case '@': return Operation::AreaCircle;
    case '$': return Operation::AreaSquare;
    case '&': return Operation::AreaRectangle;
    default: 
      throw std::invalid_argument("unknown operator");
  }
}




