#include <iostream>

int main() {
    int num{};
    std::cout << "Enter a number: ";
    std::cin >> num;
    int n = 2;
    bool is_prime = true;
    while(n < num) {
        if(num % n == 0) {
            is_prime = false;
            break;
        }
        n++;
    }

    std::cout << "is prime: " << is_prime <<"\n";
}