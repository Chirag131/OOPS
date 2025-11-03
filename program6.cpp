#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks[5];
    float average;
    string stream;

public:
    void input() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    void calculateAverage() {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        average = sum / 5;
    }

    void assignStream() {
        if (average >= 75)
            stream = "Science";
        else if (average >= 60)
            stream = "Commerce";
        else
            stream = "Arts";
    }

    void display() {
        cout << "\n---- Student Details ----\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << "\nAverage: " << average << endl;
        cout << "Assigned Stream: " << stream << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.calculateAverage();
    s.assignStream();
    s.display();
    return 0;
}
