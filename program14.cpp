#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    char ch;
    while (in.get(ch)) {
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\v' && ch != '\f' && ch != '\r')
            out << ch;
    }
    in.close();
    out.close();
    cout << "Whitespace removed and saved to output.txt" << endl;
    return 0;
}
