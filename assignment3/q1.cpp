#include <iostream>
using namespace std;

#define MAX 5  

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << " Cannot push " << value << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed " << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << " Cannot pop." << endl;
    } else {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty." << endl;
    else
        cout << "Stack is not Empty." << endl;
}

void isFull() {
    if (top == MAX - 1)
        cout << "Stack is Full." << endl;
    else
        cout << "Stack is not Full." << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\nMenu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
