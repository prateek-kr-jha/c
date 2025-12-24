#pragma once
#include <stdexcept>

enum class Operation {
    Add, Subtract, Multiply, Divide,
    Modulo, Power,
    AreaCircle, AreaSquare, AreaRectangle
};

double calculate(double a, double b, Operation op);
Operation parseOperation(char symbol);

// g++ -std=c++17 main.cpp calculator.cpp operation_parser.cpp -o calculator
