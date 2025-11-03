#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int index;
    cout << "Enter index (0-4): ";
    cin >> index;
    try {
        if (index >= 5)
            throw index;
        cout << "Element at index " << index << " is " << arr[index] << endl;
    } catch (int i) {
        cout << "Exception: Index " << i << " is out of range" << endl;
    }
    return 0;
}
