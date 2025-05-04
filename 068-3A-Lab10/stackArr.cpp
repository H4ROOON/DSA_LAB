#include <iostream>
using namespace std;

class Stack {
public:
    int arr[10];
    int top;

    Stack() {
        top = -1;
    }

    void push(int d) {
        if (top == 9) {
            cout << "Stack is full\n";
            return;
        }
        ++top;
        arr[top] = d;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is already empty\n";
            return;
        }
        --top;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    cout << "After deleting!\n";
    s.display();
    return 0;
}
