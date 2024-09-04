#include <iostream>
int add(int num1, int num2);
int main() {
    int num1{};
    int num2{};
    std::cout << "enter first number: ";
    std::cin >> num1;
    std::cout << "enter second number: ";
    std::cin >> num2;
    std::cout << "sum is " << add(num1, num2) << "\n";
}
