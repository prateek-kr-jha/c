#include <iostream>
int read_input(int &num) {
    std::cin >> num;
    // std::cout << std::decltype(num) << "\n";
    // return typeid(num).name();
    std::cout << typeid(num).name() << " " << typeid(int());
    return (typeid(num) == typeid(int()));
}



int main() {
    int x = 10;
    std::cout << read_input(x) << "\n";
    // while(read_input(x)) {
    //     std::cout << "current X: " << x << "\n";
    // }
}