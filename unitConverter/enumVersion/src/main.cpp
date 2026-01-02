#include <iostream>
#include <string>
#include "converter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: ./unit_converter <value> <conversion_type>\n";
    return 1;
  }

  try {
    size_t pos {};
    double value = std::stod(argv[1], &pos);

    if(std::string(argv[1]).length() != pos) {
      std::cerr << "Something wrong with conversion value, please check\n";
      return 1;
    }

    std::string conversionStr = argv[2];
    Conversion conversion = parseConversion(conversionStr);
    
    double result = convert(value, conversion);
    std::cout << "Result: "<< result << std::endl;

    return 0;
  } catch(const std::exception& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return 1;
  }
}
