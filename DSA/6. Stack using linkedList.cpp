//Stack implementation using linked list

#include <iostream>

using namespace std;

//Node representing an element in the stack
class Node {
    public:
        int data;
        Node* next;

        //Constructor
        Node(int value): data(value), next(nullptr) {}
};

class Stack {
    private:
        Node* top; //Pointer to top element

    public:
        Stack(): top(nullptr) {}

        //Functions
        //Checking if the stack is empty
        bool isEmpty() const {
            return top==nullptr;
        }

        //Pushing an element to the stack
        //NOT checking for stack overflow because its dynamic
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            cout << "Pushed " << value << " onto the stack.\n";
        }

        //Popping an element
        void pop() {
            if(isEmpty()) {
                cerr << "Stack underflow! Cannot pop from an empty stack.\n";
                return;
            }

            Node* temp = top;
            top = top->next;
            cout << "Popped " << temp->data << " from the stack.\n";
            delete temp;
        }

        //To get the top element
        int peek() const {
            if (isEmpty()) {
                cerr << "Cannot peek from an empty stack.\n";
                return -1; // Or throw an exception
            }

            return top->data;
        }

        //Displaying the elements
        void display() const {
            if(isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }

            cout << "Stack elements: ";

            Node* current = top;

            while(current!=nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        //Destructor
        //To delete all nodes when obj is destroyed
        ~Stack() {
            while(isEmpty()) {
                pop();
            }
        }
};

int main() {
    //Initializing
    Stack myStack;

    //Pushing
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    //Displaying
    myStack.display();

    //Peeking
    cout << "Top element: " << myStack.peek() << "\n";

    //Popping and displaying
    myStack.pop();
    myStack.display();

    return 0;
}
