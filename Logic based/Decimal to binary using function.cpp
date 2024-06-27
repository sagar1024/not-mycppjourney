#include <iostream>
using namespace std;

int decimalToBinary(int decimal)
{
    // Creating some containers
    int binary = 0;
    int base = 1;

    while(decimal>0)
    {
        // Logic part
        int remainder = decimal%2; 
        binary = binary + remainder*base;

        // Update statement
        decimal = decimal/2;
        base = base*10;

    }
    return binary;
}

int main()
{
    int a;
    cout << "Enter the decimal: ";
    cin >> a;

    // Calling the function
    cout << decimalToBinary(a) << endl;

    return 0;
}
