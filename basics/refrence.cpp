#include <iostream>
int main() {
    int i = 10;
    int &p = i;
    std::cout<< "i: " << i <<"\n";
    std::cout<< "&p: " << p <<"\n";
    p = 20;
    std::cout<< "i: " << &i <<"\n";
    std::cout<< "p: " << p <<"\n";
    int* x = &i;
    std::cout<< "x: " << x <<"\n";
    std::cout<< "*x: " << *x <<"\n";


}