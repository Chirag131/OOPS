#include <iostream>
using namespace std;

class Factorial {
    int num;
    long long fact;
public:
    Factorial(int n) {
        num = n;
        fact = 1;
        for (int i = 1; i <= num; i++)
            fact *= i;
        cout << "Factorial of " << num << " is " << fact << endl;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Factorial f(n);
    return 0;
}
