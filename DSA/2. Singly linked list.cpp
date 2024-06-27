//Implementig singly linked list

#include <iostream>

using namespace std;

//Node represents an element in a linked list
class Node {
    public:
        int data; //Data of the node
        Node* next; //Pointer to the next node

        //Constructor to initialize a node
        Node(int value) : data(value), next(nullptr) {}
};

//Linked list representing the singly linked list
class LinkedList {
    private:
        Node* head; //Pointer to the head of the list

    public:
        //Constructor to initialize an empty linked list
        LinkedList() : head(nullptr) {}

        //Func to insert a new node at the beginning of the list
        void insertAtBeginning(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        //Func to insert a new node at the end of the list
        void insertAtEnd(int value) {
            Node* newNode = new Node(value);

            //If the list is empty, set the node as the head
            if(head==nullptr) {
                head = newNode;
                return;
            }

            //Traverse the node to find the last node
            Node* current = head;
            while(current->next!=nullptr) {
                current = current->next;
            }

            //Attach the new node to the last node
            current->next = newNode;
        }

        //Func to delete a node with a specific value
        void deleteNode(int value) {
            Node* current = head;
            Node* prev = nullptr;

            //Traverse the list to find the node with the specified value
            while(current!=nullptr && current->data!=value) {
                prev = current;
                current = current->next;
            }

            //If the node is found, deleting it
            if(current!=nullptr) {
                //If the node is the head, update the head
                if(prev==nullptr) {
                    head = current->next;
                }
                else {
                    //Else skip the current node
                    prev->next = current->next;
                }
                delete current;
            }
        }

        //Func to display the list
        void display() {
            Node* current = head;

            while(current!=nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        //Destructor to delete all the nodes
        //When the object is destroyed
        ~LinkedList() {
            Node* current = head;
            Node* nextNode;

            while(current!=nullptr) {
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
};

int main() {
    LinkedList myList;

    //Insert at beginning
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    //Insert at end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    //Display the initial linked list
    cout << "Initial linked list: " << endl;
    myList.display();

    //Delete a node
    myList.deleteNode(3);

    //Display the modified linked list
    cout << "Linked list after deleting 3: " << endl;
    myList.display();

    return 0;
}
