#include <iostream>
using namespace std;

template <typename T>
T square(T num) {
    return num * num;
}

int main() {
    int a = 5;
    double b = 4.2;
    float c = 3.5f;

    cout << "Square of int: " << square(a) << endl;
    cout << "Square of double: " << square(b) << endl;
    cout << "Square of float: " << square(c) << endl;

    return 0;
}
