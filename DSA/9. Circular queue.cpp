#include <iostream>

using namespace std;

//Node represents an element in the circular queue
class Node
{
public:
    int data;   //Data of the node
    Node *next; //Pointer to the next node

    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

//CircularQueue represents the circular queue implemented using a linked list
class CircularQueue
{
private:
    Node *rear; //Pointer to the rear of the circular queue

public:
    //Constructor to initialize an empty circular queue
    CircularQueue() : rear(nullptr) {}

    //Function to check if the circular queue is empty
    bool isEmpty() const
    {
        return rear == nullptr;
    }

    //Function to enqueue an element into the circular queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            newNode->next = newNode; //Point to itself for the first element
            rear = newNode;
        }
        else
        {
            newNode->next = rear->next; //Link the new node to the front
            rear->next = newNode; //Update rear to the new node
            rear = newNode; //Update rear to the new node
        }

        cout << "Enqueued " << value << " into the circular queue.\n";
    }

    //Function to dequeue an element from the circular queue
    void dequeue()
    {
        if (isEmpty())
        {
            cerr << "Circular Queue underflow! Cannot dequeue from an empty queue.\n";
            return;
        }

        Node *front = rear->next; //Front is the next node after rear

        cout << "Dequeued " << front->data << " from the circular queue.\n";

        if (front == rear)
        {
            delete front;
            rear = nullptr; //Queue becomes empty after dequeueing the last element
        }
        else
        {
            rear->next = front->next; //Update rear to the next node after front
            delete front;
        }
    }

    //Function to get the front element of the circular queue without dequeuing
    int peek() const
    {
        if (isEmpty())
        {
            cerr << "Cannot peek from an empty circular queue.\n";
            return -1; //Or throw an exception
        }

        return rear->next->data; //Front is the next node after rear
    }

    //Function to display the elements of the circular queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty.\n";
            return;
        }

        cout << "Circular Queue elements: ";
        Node *current = rear->next; //Front is the next node after rear
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next); //Loop until we reach the front again
        cout << "\n";
    }

    //Destructor to delete all nodes when the object is destroyed
    ~CircularQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    CircularQueue myCircularQueue;

    myCircularQueue.enqueue(10);
    myCircularQueue.enqueue(20);
    myCircularQueue.enqueue(30);

    myCircularQueue.display();

    cout << "Front element: " << myCircularQueue.peek() << "\n";

    myCircularQueue.dequeue();
    myCircularQueue.display();

    return 0;
}
