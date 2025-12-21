#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>
#include <stdexcept>

#define PI 3.14

double add(double num1, double num2) {
    return num1 + num2;
}

double substract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if(num2 == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return num1 / num2;
}

int remainder(int num1, int num2) {
    if(num2 == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return num1 % num2;
}

double power(double num1, double num2) {
    return std::pow(num1, num2);
}

double areaOfSquare(double num1) {
    return multiply(num1, num1);
}

double areaOfRectangle(double num1, double num2) {
    return multiply(num1, num2);
}

double areaOfCircle(double num1) {
    return PI * multiply(num1, num1);
}

double calculator(double num1, double num2, char operation) {
    
    switch (operation) {
        case '+':
            return add(num1, num2);
        case '-':
            return substract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1, num2);
        case '%':
            return static_cast<double>(remainder(
                static_cast<int>(num1), 
                static_cast<int>(num2)
            ));
        case '^':
            return power(num1, num2);
        case '@':
            return areaOfCircle(num1);
        case '$':
            return areaOfSquare(num1);
        case '&':
            return areaOfRectangle(num1, num2);
        default:
            return std::numeric_limits<double>::quiet_NaN();
    }

}


int main(int argc, char* argv[]) {
    if(argc != 4) {
        std::cout << "usage: ./program <operand1> <operator> <operand2>\n";
        return 1;
    }

    std::string operand1 = argv[1];
    std::string operationStr = argv[2];
    std::string operand2 = argv[3];

    double num1 {};
    double num2 {};
    char operation {};

    try {
        size_t pos {};
        num1 = stod(operand1, &pos);

        if(pos != operand1.length()) {
            std::cout << "Invalid input number" << std::endl;
            return 1;
        }

        if(operationStr.length() != 1) {
            std::cout << "invalid operand\n";
            return 1;
        }
        operation = operationStr[0];
        std::string validOperations = "@$%*+-&^/";

        if(validOperations.find(operation) == std::string::npos) {
            std::cout << "invalid operation\n";
            return 1;
        }

        num2 = stod(operand2, &pos);
        if(pos != operand2.length()) {
            std::cout << "Invalid input number" << std::endl;
            return 1;
        }

    } catch(...) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    double result {};
    try {
        result = calculator(num1, num2, operation);
    } catch(...) {
        std::cout << "Something went wrong with calculator\n";
        return 1;
    }
    std::cout << result << "\n";
    return 0;
}
