//Implementation of circular linked list

#include <iostream>

using namespace std;

// Node represents an element in the circular linked list
class Node
{
public:
    int data;   // Data of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

// CircularLinkedList represents the circular linked list
class CircularLinkedList
{
private:
    Node *head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty circular linked list
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        // If the list is empty, set the new node as the head and make it circular
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            // Otherwise, update pointers and set the new node as the head
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        // If the list is empty, set the new node as the head and make it circular
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            // Otherwise, update pointers and set the new node as the last node
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Function to delete a node with a specific value
    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            return; // List is empty
        }

        Node *current = head->next;
        Node *prev = head;

        // Traverse the circular list to find the node with the specified value
        do
        {
            if (current->data == value)
            {
                // If the node is found, update pointers and delete it
                prev->next = current->next;
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != head->next); // Continue until we complete a full loop

        // If the node is not found, print an error message
        cerr << "Node with value " << value << " not found in the circular linked list.\n";
    }

    // Function to display the circular linked list
    void display()
    {
        if (head == nullptr)
        {
            cout << "Circular Linked List is empty.\n";
            return;
        }

        Node *current = head->next;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head->next);

        cout << "\n";
    }

    // Destructor to delete all nodes when the object is destroyed
    ~CircularLinkedList()
    {
        if (head == nullptr)
        {
            return; // List is empty
        }

        Node *current = head->next;
        Node *nextNode;

        while (current != head)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head; // Delete the head node
    }
};

int main()
{
    CircularLinkedList myList;

    // Insert at the beginning
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    // Insert at the end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    // Display the initial circular linked list
    cout << "Initial Circular Linked List: ";
    myList.display();

    // Delete a node
    myList.deleteNode(3);

    // Display the modified circular linked list
    cout << "Circular Linked List after deleting 3: ";
    myList.display();

    return 0;
}
