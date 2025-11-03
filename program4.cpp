#include <iostream>
#include <cmath>
using namespace std;

class AreaCalculator {
public:
    double area(double radius) {
        return 3.14159 * radius * radius;
    }

    double area(double length, double breadth) {
        return length * breadth;
    }

    double area(float base, float height) {
        return 0.5 * base * height;
    }
};

int main() {
    AreaCalculator calc;
    double r, l, b;
    float t_base, t_height;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of Circle = " << calc.area(r) << endl;

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle = " << calc.area(l, b) << endl;

    cout << "\nEnter base and height of triangle: ";
    cin >> t_base >> t_height;
    cout << "Area of Triangle = " << calc.area(t_base, t_height) << endl;

    return 0;
}
