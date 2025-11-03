#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double base, result = 1.0;
    int exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    if (exponent > 0) {
        for (int i = 1; i <= exponent; ++i)
            result *= base;
    } else if (exponent < 0) {
        for (int i = 1; i <= -exponent; ++i)
            result *= base;
        result = 1.0 / result;
    } else {
        result = 1.0;
    }

    cout << base << " raised to " << exponent << " = " << result << endl;
    return 0;
}
