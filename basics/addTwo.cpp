#include <iostream>

int add(int a, int b) {
  return a + b;
}

int main(){
  int a {};
  int b {};
  std::cout << "enter first number\n";
  std::cin >> a;
  std::cout << "enter second number\n";
  std::cin >> b;
  std::cout << add(a, b) << std::endl;
  return 0;
}

