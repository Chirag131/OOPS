#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float val) {
        real = val;
        imag = val;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1;
    Complex c2(5);
    Complex c3(3, 7);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Third Complex Number: ";
    c3.display();

    Complex sum = c2.add(c3);
    cout << "\nSum of Second and Third Complex Numbers: ";
    sum.display();

    return 0;
}
