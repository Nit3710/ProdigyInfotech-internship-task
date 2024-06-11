#include <iostream>
#include <iomanip>

using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

void convertTemperature(double value, char unit, double& celsius, double& fahrenheit, double& kelvin) {
    switch (unit) {
        case 'C':
        case 'c':
            celsius = value;
            fahrenheit = celsiusToFahrenheit(celsius);
            kelvin = celsiusToKelvin(celsius);
            break;
        case 'F':
        case 'f':
            fahrenheit = value;
            celsius = fahrenheitToCelsius(fahrenheit);
            kelvin = fahrenheitToKelvin(fahrenheit);
            break;
        case 'K':
        case 'k':
            kelvin = value;
            celsius = kelvinToCelsius(kelvin);
            fahrenheit = kelvinToFahrenheit(kelvin);
            break;
        default:
            throw invalid_argument("Invalid unit of measurement. Please use 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin.");
    }
}

int main() {
    try {
        double value;
        char unit;

        cout << "Enter the temperature value: ";
        cin >> value;
        cout << "Enter the unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ";
        cin >> unit;

        double celsius, fahrenheit, kelvin;
        convertTemperature(value, unit, celsius, fahrenheit, kelvin);

        cout << fixed << setprecision(2);
        cout << "\nConverted temperatures:" << endl;
        cout << value << " " << unit << " is equivalent to:" << endl;
        cout << celsius << " °C" << endl;
        cout << fahrenheit << " °F" << endl;
        cout << kelvin << " K" << endl;

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
