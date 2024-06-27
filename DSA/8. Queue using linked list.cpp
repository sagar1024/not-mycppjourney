//Queue implementation using linked list

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        //Constructor
        Node(int value): data(value), next(nullptr) {} 
};

class Queue {
    private:
        Node* front; //Pointer to the front element
        Node* rear; //Pointer to the rear element

    public:
        //Constructor
        Queue(): front(nullptr), rear(nullptr) {}

        //Functions
        //Checking if the queue is empty
        bool isEmpty() const {
            return front==nullptr;
        }

        //Enqueue an element
        void enqueue(int value) {
            Node* newNode = new Node(value);

            if(isEmpty()) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Enqueued " << value << " into the queue.\n";
        }

        //Dequeue an element
        //Automatically removed element from the front
        void dequeue() {
            if (isEmpty()) {
                cerr << "Queue underflow! Cannot dequeue from an empty queue.\n";
                return;
            }

            Node* temp = front;
            front = front->next;

            cout << "Dequeued " << temp->data << " from the queue.\n";
            delete temp;

            //If the queue becomes empty after dequeueing the last element
            if (front == nullptr) {
                rear = nullptr;
            }
        }

        //Indicating that these functions do not modify the state of the object
        //Getting the front element of the queue without dequeuing
        int peek() const {
            if (isEmpty()) {
                cerr << "Cannot peek from an empty queue.\n";
                return -1; //Or throw an exception
            }
            return front->data;
        }

        //Displaying the elements of the queue
        void display() const {
            if (isEmpty()) {
                cout << "Queue is empty.\n";
                return;
            }

            cout << "Queue elements: ";

            Node* current = front;

            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "\n";
        }

         // Destructor to delete all nodes when the object is destroyed
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }
};

int main() {
    //Init
    Queue myQueue;

    //Enq
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    //Display
    myQueue.display();

    //Peek
    cout << "Front element: " << myQueue.peek() << "\n";

    //Deq and display
    myQueue.dequeue();

    myQueue.display();

    return 0;
}
