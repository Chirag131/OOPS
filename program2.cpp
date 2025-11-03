#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string address;
    int age;
    float salary;

public:
    inline void getData() {
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
    }

    inline void displayData() const {
        cout << "\n---- Employee Details ----\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp;
    cout << "Enter Employee Details:\n";
    emp.getData();
    emp.displayData();
    return 0;
}
