#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

// Function to print all prime num btw a and b

bool isPrime(int x)
{
    for(int i = 2; i<x; i++)
    {
        if(x%i==0)
        {
            return false;
        }
        
    }
    return 0;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    // This loop will traverse through every number and call the function to check its primality
    for(int z = a; z<=b; z++)
    {
        if(isPrime(z))
        {
            cout << z << " ";
        }
    }
    return 0;
}