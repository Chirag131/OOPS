#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char str[100];

public:
    String() {
        str[0] = '\0';
    }

    String(const char s[]) {
        strcpy(str, s);
    }

    String operator+(String s) {
        String temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    String operator=(String s) {
        strcpy(str, s.str);
        return *this;
    }

    bool operator<=(String s) {
        return strcmp(str, s.str) <= 0;
    }

    void length() {
        cout << "Length of string: " << strlen(str) << endl;
    }

    void toLower() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }
    }

    void toUpper() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3;

    cout << "String 1: ";
    s1.display();
    cout << "String 2: ";
    s2.display();

    s3 = s1 + s2;
    cout << "\nConcatenation (s1 + s2): ";
    s3.display();

    String s4;
    s4 = s1;
    cout << "\nAfter Copy (s4 = s1): ";
    s4.display();

    if (s1 <= s2)
        cout << "\nString 1 is less than or equal to String 2\n";
    else
        cout << "\nString 1 is greater than String 2\n";

    cout << "\n";
    s3.length();

    cout << "\nConverting to Lowercase: ";
    s3.toLower();
    s3.display();

    cout << "Converting to Uppercase: ";
    s3.toUpper();
    s3.display();

    return 0;
}
