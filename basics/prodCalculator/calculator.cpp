#include "calculator.hpp"
#include <cmath>
#include <limits>

constexpr double PI = 3.141592653589793;

double calculate(double a, double b, Operation op) {
    switch (op) {
        case Operation::Add: return a + b;
        case Operation::Subtract: return a - b;
        case Operation::Multiply: return a * b;
        case Operation::Divide:
            if (b == 0) throw std::invalid_argument("division by zero");
            return a / b;
        case Operation::Modulo:
            if (b == 0) throw std::invalid_argument("division by zero");
            return std::fmod(a, b);
        case Operation::Power:
            return std::pow(a, b);
        case Operation::AreaCircle:
            if (a < 0) throw std::invalid_argument("negative radius");
            return PI * a * a;
        case Operation::AreaSquare:
            if (a < 0) throw std::invalid_argument("negative side");
            return a * a;
        case Operation::AreaRectangle:
            if (a < 0 || b < 0) throw std::invalid_argument("negative dimension");
            return a * b;
        default:
            return std::numeric_limits<double>::quiet_NaN();
    }
}
