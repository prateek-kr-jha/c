#ifndef PASSWORD_CHECKER_HPP
#define PASSWORD_CHECKER_HPP

#include <string>

enum class Strength {
    Weak,
    Medium,
    Strong
};

Strength checkPasswordStrength(const std::string& password);

#endif