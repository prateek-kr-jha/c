#include <iostream>
#define TEXT "enter first number: "
 #define ADD

int add(int num1, int num2);
int main() {
    int num1{};
    int num2{};
    std::cout << TEXT;
    #ifdef ADD
    std::cin >> num1;
    std::cout << "enter second number: ";
    std::cin >> num2;
    std::cout << "sum is " << add(num1, num2) << "\n";
    #endif
    #ifndef ADD
    std::cout << "\n";
    #endif
}
