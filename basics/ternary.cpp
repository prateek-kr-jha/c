#include <iostream>

int main() {
    int x{};
    std::cin >> x;
    // int y = 10;
    int y = (x > 10) ? 10 : x;
    std::cout << y << "\n";
}