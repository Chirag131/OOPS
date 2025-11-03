#include <iostream>
using namespace std;

class List {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
};

class Stack : public List {
    int arr[10], top;
public:
    Stack() { top = -1; }
    void store(int value) {
        if (top < 9) arr[++top] = value;
    }
    int retrieve() {
        if (top >= 0) return arr[top--];
        return -1;
    }
};

class Queue : public List {
    int arr[10], front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void store(int value) {
        if (rear < 9) arr[++rear] = value;
    }
    int retrieve() {
        if (front <= rear) return arr[front++];
        return -1;
    }
};

int main() {
    List *list;
    Stack s;
    Queue q;

    list = &s;
    list->store(10);
    list->store(20);
    cout << "Stack Retrieve: " << list->retrieve() << endl;

    list = &q;
    list->store(30);
    list->store(40);
    cout << "Queue Retrieve: " << list->retrieve() << endl;

    return 0;
}
