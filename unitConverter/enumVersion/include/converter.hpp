#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

enum class Conversion {
    MilesToKm,
    KmToMiles,
    KgToPounds,
    PoundsToKg,
    CelsiusToFahrenheit,
    FahrenheitToCelsius
};

Conversion parseConversion(const std::string& conversionStr);

double convert(double value, Conversion conversion);


#endif