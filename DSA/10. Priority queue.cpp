//Implementation of priority queue using linked list
//Each element in the linked list has an associated priority
//AND
//Elements with higher priority are dequeued before elements with lower priority

// #include <iostream>

// using namespace std;

// //Node represents an element in the priority queue
// class Node {
// public:
//     int data;       //Data of the node
//     int priority;   //Priority of the node
//     Node* next;     //Pointer to the next node

//     //Constructor to initialize a node
//     Node(int value, int p) : data(value), priority(p), next(nullptr) {}
// };

// //PriorityQueue represents the priority queue implemented using a linked list
// class PriorityQueue {
// private:
//     Node* front;  //Pointer to the front of the priority queue

// public:
//     //Constructor to initialize an empty priority queue
//     PriorityQueue() : front(nullptr) {}

//     //Function to check if the priority queue is empty
//     bool isEmpty() const {
//         return front == nullptr;
//     }

//     //Function to enqueue an element into the priority queue based on priority
//     void enqueue(int value, int priority) {
//         Node* newNode = new Node(value, priority);

//         //If the priority queue is empty or the new node has higher priority
//         if (isEmpty() || priority > front->priority) {
//             newNode->next = front;
//             front = newNode;
//         } else {
//             //Find the position to insert the new node based on priority
//             Node* current = front;
//             while (current->next != nullptr && priority <= current->next->priority) {
//                 current = current->next;
//             }
//             newNode->next = current->next;
//             current->next = newNode;
//         }

//         cout << "Enqueued " << value << " with priority " << priority << " into the priority queue.\n";
//     }

//     //Function to dequeue the element with the highest priority from the priority queue
//     void dequeue() {
//         if (isEmpty()) {
//             cerr << "Priority Queue underflow! Cannot dequeue from an empty queue.\n";
//             return;
//         }

//         Node* temp = front;
//         front = front->next;

//         cout << "Dequeued " << temp->data << " with priority " << temp->priority << " from the priority queue.\n";

//         delete temp;
//     }

//     //Function to display the elements of the priority queue
//     void display() const {
//         if (isEmpty()) {
//             cout << "Priority Queue is empty.\n";
//             return;
//         }

//         cout << "Priority Queue elements: ";
//         Node* current = front;
//         while (current != nullptr) {
//             cout << "(" << current->data << ", " << current->priority << ") ";
//             current = current->next;
//         }
//         cout << "\n";
//     }

//     //Destructor to delete all nodes when the object is destroyed
//     ~PriorityQueue() {
//         while (!isEmpty()) {
//             dequeue();
//         }
//     }
// };

// int main() {
//     PriorityQueue myPriorityQueue;

//     myPriorityQueue.enqueue(10, 3);
//     myPriorityQueue.enqueue(20, 1);
//     myPriorityQueue.enqueue(30, 2);

//     myPriorityQueue.display();

//     myPriorityQueue.dequeue();
//     myPriorityQueue.display();

//     return 0;
// }

//Re-writing the code again for practice -

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        int priority;
        Node* next;

        //Constructor
        Node(int value, int p): data(value), priority(p), next(nullptr) {}
};

class PriorityQueue {
    private:
        Node* front;

    public:
        //Constructor to initialize empty priority queue
        PriorityQueue(): front(nullptr) {}

        //Functions
        //Checking if it is empty
        bool isEmpty() const {
            return front==nullptr;
        }

        //Enqueue an element based on priority
        void enqueue(int value, int priority) {
            Node* newNode = new Node(value, priority);

            //If the priority queue is empty
            //OR
            //The new node has higher priority
            if(isEmpty() || priority > front->priority) {
                newNode->next = front;
                front = newNode;
            }
            else {
                //Find a position to insert the newnode based on the priority
                Node* current = front;
                while(current->next!=nullptr && priority <= current->next->priority) {
                    current = current->next;
                }

                newNode->next = current->next;
                current->next = newNode;
            }

            cout << "Enqueued " << value << " with priority " << priority << " into the priority queue.\n";
        }

        //Function to dequeue the element
        //With the highest priority from the priority queue
        void dequeue() {
            if(isEmpty()) {
                cerr << "Priority queue underflow!" << endl;
                return;
            }

            Node* temp = front;
            front = front->next;

            cout << "Dequeued " << temp->data << " with priority " << temp->priority << " from the priority queue.\n";
            
            delete temp;
        }

        //Function to display the elements of the priority queue
        void display() const {
            if (isEmpty()) {
                cout << "Priority Queue is empty.\n";
                return;
            }

            cout << "Priority Queue elements: ";

            Node* current = front;

            while (current != nullptr) {
                cout << "(" << current->data << ", " << current->priority << ") ";
                current = current->next;
            }
            cout << "\n";
        }

        // Destructor to delete all nodes when the object is destroyed
        ~PriorityQueue() {
            while (!isEmpty()) {
                dequeue();
            }
        }
};

int main() {
    //Init
    PriorityQueue myPriorityQueue;

    //Enqueue
    myPriorityQueue.enqueue(10, 3);
    myPriorityQueue.enqueue(20, 1);
    myPriorityQueue.enqueue(30, 2);

    //Display
    myPriorityQueue.display();

    //Dequeue and display
    myPriorityQueue.dequeue();
    myPriorityQueue.display();

    return 0;
}
