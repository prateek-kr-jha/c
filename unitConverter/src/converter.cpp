#include "converter.hpp"
#include <string>
#include <stdexcept>

constexpr double mile_kms = 1.609344;
constexpr double kg_pounds = 2.204623;

double convert(double value, const std::string& conversion) { 
  if(conversion == "miles_to_km") return value * mile_kms;
  if(conversion == "km_to_miles") return value / mile_kms;
  if(conversion == "kg_to_pounds") return value * kg_pounds;
  if(conversion == "pounds_to_kg") return value / kg_pounds;
  if(conversion == "f_to_c") return (value - 32) / 1.8;
  if(conversion == "c_to_f") return (value * 1.8) + 32;

  throw std::invalid_argument("Invalid conversion type");
}

