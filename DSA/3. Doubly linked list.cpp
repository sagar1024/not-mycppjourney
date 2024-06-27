//Implementation of doubly linked list

#include <iostream>

using namespace std;

//Node represents an element in the doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
    
    //Constructor
    Node(int value): data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    private:
        Node* head; //Pointer to the head of the list
        Node* tail; //Pointer to the tail of the list

    public:
        //Constructor
        //To initialize an empty doubly linked list
        DoublyLinkedList(): head(nullptr), tail(nullptr) {}

        //Functions
        //Inserting a node at the beginning
        void insertAtBeginning(int value) {
            //Memory allocation
            Node* newNode = new Node(value);

            //If the list is empty
            //Set the new node as both head and tail
            if(head==nullptr) {
                head = tail = newNode;
            }
            //Otherwise
            //Update the pointers and set the new node as the head
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        //Inserting a node at the end
        void insertAtEnd(int value) {
            //Memory allocation
            Node* newNode = new Node(value);

            //If the list is empty
            if(head==nullptr) {
                head = tail = newNode;
            }
            //Oterwise
            //Update the pointers
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        //Deleting a node with a specific value
        void deleteNode(int value) {
            //Initializing a temp variable for traversal purposes
            Node* current = head;

            while(current!=nullptr && current->data!=value) {
                current = current->next;
            }

            //If the node is found
            //Update the pointers and delete it
            if(current!=nullptr) {
                //Updating the pointers
                //Prev
                if(current->prev!=nullptr) {
                    //Joining the prev and next nodes
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                //Next
                if(current->next!=nullptr) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                //And only then, deleting it
                delete current;
            }
        }

        //Displaying the doubly linked list
        void display() {
            Node* current = head;

            //Traversing
            while(current!=nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        //Destructor to delete all nodes when the object is destroyed
        ~DoublyLinkedList() {
            Node* current = head;
            Node* nextNode;

            //Traversing
            while (current != nullptr) {
                //The order is imp!
                //Updating the pointers
                nextNode = current->next;
                //Then deleting it
                delete current;
                //Updating the current Node
                current = nextNode;
            }
        }
};

int main() {
    DoublyLinkedList myList;

    //Inserting at beginning
    myList.insertAtBeginning(30);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(10);

    //Inserting at end
    myList.insertAtEnd(40);
    myList.insertAtEnd(50);
    myList.insertAtEnd(70);

    //Displaying the initial doubly linked list
    cout << "Initial Doubly Linked List: ";
    myList.display();

    //Deleting a node
    myList.deleteNode(30);

    //Displaying the modified doubly linked list
    cout << "Doubly Linked List after deleting 30: ";
    myList.display();

    return 0;
}
