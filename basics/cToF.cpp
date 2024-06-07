#include <simplecpp>

main_program {
    int celsius;
    cout << "Enter temp. in celsius: ";
    cin >> celsius;
    int fahrenheit = 32.0 + (celsius * 9.0)/5.0;
    cout << fahrenheit << ".\n";
}