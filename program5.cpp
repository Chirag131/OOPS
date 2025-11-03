#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    void inputTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    void displayTime() const {
        cout << "Time (via member function): ";
        cout << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
};

void showTime(Time t) {
    cout << "Time (via separate function): ";
    cout << t.getHours() << "h:" << t.getMinutes() << "m:" << t.getSeconds() << "s" << endl;
}

int main() {
    Time t1;
    t1.inputTime();
    t1.displayTime();
    showTime(t1);
    return 0;
}
