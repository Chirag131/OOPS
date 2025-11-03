#include <iostream>
using namespace std;

template <class T>
class Compare {
    T a, b;
public:
    Compare(T x, T y) {
        a = x;
        b = y;
        cout << "Constructor called" << endl;
    }
    void displayBigger() {
        if (a > b)
            cout << a << " is bigger" << endl;
        else if (b > a)
            cout << b << " is bigger" << endl;
        else
            cout << "Both are equal" << endl;
    }
    ~Compare() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Compare<int> c1(10, 20);
    c1.displayBigger();

    Compare<double> c2(5.5, 2.3);
    c2.displayBigger();

    return 0;
}
