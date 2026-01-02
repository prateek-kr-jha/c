#include "converter.hpp"
#include <stdexcept>
#include <string>

constexpr double mile_kms = 1.609344;
constexpr double kg_pounds = 2.204623;


Conversion parseConversion(const std::string& conversionStr) {
    if(conversionStr == "mlies_to_km") return Conversion::MilesToKm;
    if(conversionStr == "km_to_miles") return Conversion::KmToMiles;
    if(conversionStr == "kg_to_pounds")  return Conversion::KgToPounds;
    if(conversionStr == "pounds_to_kg")  return Conversion::PoundsToKg;
    if(conversionStr == "c_to_f")  return Conversion::CelsiusToFahrenheit;
    if(conversionStr == "f_to_c")  return Conversion::FahrenheitToCelsius;

    throw std::invalid_argument("Invalid conversion type");
}

double convert(double value, Conversion conversion) {
    switch(conversion) {
        case Conversion::MilesToKm:
            return value * mile_kms;
        
        case Conversion::KmToMiles:
            return value / mile_kms;
        
        case Conversion::KgToPounds:
            return value * kg_pounds;
        
        case Conversion::PoundsToKg:
            return value / kg_pounds;
        
        case Conversion::CelsiusToFahrenheit:
            return (value * 1.8) + 32;
        
        case Conversion::FahrenheitToCelsius:
            return (value - 32) / 1.8;
        
        default:
            throw std::invalid_argument("Unhandled Conversion");
    }

}