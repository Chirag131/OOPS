#include <iostream>
using namespace std;

class A;
class B;

class A {
    int num1;
public:
    void input() {
        cout << "Enter first number: ";
        cin >> num1;
    }
    friend void compare(A, B);
};

class B {
    int num2;
public:
    void input() {
        cout << "Enter second number: ";
        cin >> num2;
    }
    friend void compare(A, B);
};

void compare(A a, B b) {
    if (a.num1 > b.num2)
        cout << a.num1 << " is greater";
    else if (b.num2 > a.num1)
        cout << b.num2 << " is greater";
    else
        cout << "Both are equal";
}

int main() {
    A a;
    B b;
    a.input();
    b.input();
    compare(a, b);
    return 0;
}
