#pragma once
#include <stdexcept>

enum class Operation {
  Add, Subtract, Multiply, Divide,
  Modulo, Power, 
  AreaRectangle, AreaSquare, AreaRectangle
};

double calculate(double a, double b, Operation op);
Operation parseOperation(char symbol);
