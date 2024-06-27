//Queue implementation using arrays

#include <iostream>

using namespace std;

class Queue
{
private:
    static const int MAX_SIZE = 100; //Maximum size of the queue
    int arr[MAX_SIZE]; //Array to store elements
    int front; //Index of the front element
    int rear; //Index of the rear element

public:
    //Constructor to initialize an empty queue
    Queue() : front(-1), rear(-1) {}

    //Function to check if the queue is empty
    bool isEmpty() const
    {
        return front == -1 && rear == -1;
    }

    //Function to check if the queue is full
    bool isFull() const
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    //Function to enqueue an element into the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cerr << "Queue overflow! Cannot enqueue element " << value << ".\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        cout << "Enqueued " << value << " into the queue.\n";
    }

    //Function to dequeue an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cerr << "Queue underflow! Cannot dequeue from an empty queue.\n";
            return;
        }

        cout << "Dequeued " << arr[front] << " from the queue.\n";

        if (front == rear)
        {
            front = rear = -1; //Queue becomes empty after dequeueing the last element
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    //Function to get the front element of the queue without dequeuing
    int peek() const
    {
        if (isEmpty())
        {
            cerr << "Cannot peek from an empty queue.\n";
            return -1; //Or throw an exception
        }

        return arr[front];
    }

    //Function to display the elements of the queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << "\n";
    }
};

int main()
{
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    cout << "Front element: " << myQueue.peek() << "\n";

    myQueue.dequeue();
    myQueue.display();

    return 0;
}
