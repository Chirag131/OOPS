#include <iostream>
#include <fstream>
using namespace std;

class Student {
    char name[30];
    int age;
    char sex;
    float height, weight;
public:
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sex (M/F): ";
        cin >> sex;
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter weight: ";
        cin >> weight;
    }
    void display() {
        cout << "Name: " << name << "\nAge: " << age << "\nSex: " << sex
             << "\nHeight: " << height << "\nWeight: " << weight << "\n";
    }
};

int main() {
    Student s;
    fstream file;
    file.open("student.dat", ios::out | ios::binary);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();

    file.open("student.dat", ios::in | ios::binary);
    cout << "\nData read from file:\n";
    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }
    file.close();
    return 0;
}
