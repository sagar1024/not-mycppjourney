#include <iostream>
using namespace std;

// When we need answer in yes or no, we use bool datatype

bool prime(int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

// The main function is where the real execution starts

int main()
{
    int a;
    cout << "Enter the number: ";
    cin >> a;

    cout << prime(a);

    return 0;
}