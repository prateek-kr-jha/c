# Unit Converter:

```
|- include/
|   |- converter.hpp
|- src/
|   |- converter.cpp 
|   |- main.cpp
````

KM <-> Miles: 1 mile => 1.609344 km_to_miles
Celsius <-> Fahrenheit => 1 f = (celsius * 1.8) + 32
KG <-> Pounds => 1 kg = 2.204623 Pounds

### Logic:
inputs: <value> <conversion string>
conversion string: 
- miles_to_km <-> km_to_miles
- c_to_f <-> f_to_c
- kg_to_pounds <-> pounds_to_kg


