#include "square.h"
#include <iostream>

int main() {
    std::cout << "a square has " << getSquareSide() << "\n";
    std::cout << "a square of length 5 has perimeter length " <<
    getSquarePerimeter(5) << "\n";

    return 0;
}
