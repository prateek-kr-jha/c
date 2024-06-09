#include <iostream>

void swap(int &bigger, int &smaller) {
    int temp = bigger;
    bigger = smaller;
    smaller = temp;
}

int gcd(int bigger, int smaller) {
    if(bigger % smaller == 0) {
        return smaller;
    }

    return gcd(smaller, bigger % smaller);
}

int main() {
    int bigger{}, smaller{};
    std::cout << "Enter first number: ";
    std::cin >> bigger;
    std::cout << "Enter second number: ";
    std::cin >> smaller;

    if(bigger < smaller) {
        swap(bigger, smaller);
    }

    std::cout << "bigger: " << bigger << " smaller: " << smaller <<"\n";

    std::cout << "GCD: " << gcd(bigger, smaller) <<"\n";

}