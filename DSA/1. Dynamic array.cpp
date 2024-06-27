//Implementing a dynamic array
//The C++ Standard Library provides dynamic array container called vector

#include <iostream>
using namespace std;

class DynamicArray {
    private:
        int *arr; //Pointer to the dynamic array
        int size; //Current num of elements in the array
        int capacity; //Curr capacity of thr array

    public:
        //Constructor to initialize the dynamic array
        DynamicArray() {
            size = 0; //Initially 0 elements
            capacity = 2; //Initial capacity set to 2
            arr = new int[capacity]; //Allocating memory for the dynamic array
        }

        //Destructor to free the allocated memory
        ~DynamicArray() {
            delete[] arr; //Deallocates the memory when the object is destroyed
        }

        //Func to add an element to the array
        void push(int element) {
            //Checking if the array if full
            //And if so, double its capacity
            if(size==capacity) {
                //Creating a new array with double capacity
                int *temp = new int[2*capacity];

                //Copying elements from the old array to the new array
                for (int i = 0; i < size; ++i) {
                    temp[i] = arr[i];
                }

                //Deallocate the memory of the old array
                delete[] arr;

                //Update the pointer to point the new array
                arr = temp;

                //Update the capacity
                capacity *= 2;
            }

            //Adding the new element to the new array
            arr[size++] = element;
        }

        //Func to get the element at a specific index
        int get(int index) {
            if(index<0 || index >= size) {
                cerr << "Index out of bounds\n";
                return -1;
            }
            return arr[index];
        }

        //Func to get size
        int getSize() {
            return size;
        }

        //Func to get capacity
        int getCapacity() {
            return capacity;
        }
};

int main() {
    //Creating a dynamic array and adding elements
    DynamicArray myArray;
    myArray.push(10);
    myArray.push(20);
    myArray.push(30);

    for(int i=0; i<myArray.getSize(); i++)
    {
        cout << myArray.get(i) << " " << endl;
    }
    cout << "\nSize: " << myArray.getSize() << "\nCapacity: " << myArray.getCapacity() << endl;

    return 0;
}
