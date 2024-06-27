//Implementation of stack using array

#include <iostream>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int arr[MAX_SIZE]; // Array to store elements
    int top; // Index of the top element

public:
    // Constructor to initialize an empty stack
    Stack() : top(-1) {}

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull())
        {
            cerr << "Stack overflow! Cannot push element " << value << ".\n";
            return;
        }

        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty())
        {
            cerr << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }

        cout << "Popped " << arr[top--] << " from the stack.\n";
    }

    // Function to get the top element of the stack without popping
    int peek() const {
        if (isEmpty())
        {
            cerr << "Cannot peek from an empty stack.\n";
            return -1; // Or throw an exception
        }

        return arr[top];
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    //Initializing my stack
    Stack myStack;

    //Pushing elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    //Displaying
    myStack.display();

    //Displaying the top element
    cout << "Top element: " << myStack.peek() << "\n";

    //Popping
    myStack.pop();

    //And then displaying the altered stack
    myStack.display();

    return 0;
}
