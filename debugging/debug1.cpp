#include <iostream>

int getValue() {
std::cerr << "getValue()\n";
    return 4;
}
int main() {
std::cerr << "main()\n";
    std::cout << getValue() << "\n";
}
