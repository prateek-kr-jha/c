#include <iostream>
int five() {
    return 5;
}
int main() {
    // int[] x= new int[4];
    int y {five()};
    // std::cout << "enter number: ";
    // std::cin >> x;
    std::cout << "enter number2: " << sizeof(int);
    // std::cin >> y;

    std::cout << "hi there! " << " & " << y << "\n";
    return 0;
}
