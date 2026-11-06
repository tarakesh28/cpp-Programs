#include <iostream>
#include <stdexcept>
using namespace std;

class Overflow : public runtime_error {
public:
    Overflow() : runtime_error("Stack Overflow!") {}
};

class Underflow : public runtime_error {
public:
    Underflow() : runtime_error("Stack Underflow!") {}
};

class Stack {
    int arr[5];
    int top;

public:
    Stack() {top = -1;}
    void push(int value) {
        if (top == 4) throw Overflow();
        arr[++top] = value;
        cout << value << " pushed." << endl;
    }

    void pop() {
        if (top == -1) throw Underflow();
        cout << arr[top--] << " popped." << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (Overflow& e) {
        cout << e.what() << endl;
    }
    catch (Underflow& e) {
        cout << e.what() << endl;
    }
    return 0;
}