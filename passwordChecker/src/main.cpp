#include <iostream>
#include <cctype>
#include <stdexcept>
#include "password_checker.hpp"

Strength checkPasswordStrength(const std::string& password) {
    const size_t MINIMUM_LENGTH = 8;

    if(password.length() < MINIMUM_LENGTH) {
        return Strength::Weak;
    }

    bool hasSpecial = false;
    bool hasDigit = false;
    bool hasUpper = false;

    for(char ch : password) {
        unsigned char c = static_cast<unsigned char>(ch);

        if(std::ispunct(c)) {
            hasSpecial = true;
        } else if(std::isdigit(c)) {
            hasDigit = true;
        } else if(std::isupper(c)) {
            hasUpper = true;
        }
    }

    int score = hasDigit + hasSpecial + hasUpper;

    if(score == 3) {
        return Strength::Strong;
    }

    if(score == 2) {
        return Strength::Medium;
    }

    return Strength::Weak;
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: ./password_checker <password>";
        return 1;
    }

    const std::string password = argv[1];
    Strength passwordStrength = checkPasswordStrength(password);

    switch (passwordStrength) {
    case Strength::Weak:
        std::cout << "Weak Password\n";
        break;
    case Strength::Medium:
        std::cout << "Medium Password\n";
        break;
    case Strength::Strong:
        std::cout << "Strong Password\n";
        break;
    }

    return 0;
}