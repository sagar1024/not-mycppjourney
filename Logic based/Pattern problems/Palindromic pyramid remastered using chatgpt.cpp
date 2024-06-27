#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    // This loop will traverse through each row
    for(int i = 1; i<=n; i++)
    {
        // For spaces
        for(int x = 1; x<=n-i; x++)
        {
            cout << " ";
        }

        // For ascending numbers
        for(int y = 1; y<=i; y++)
        {
            cout << y;
        }

        // For descending numbers
        for(int z = i-1; z>=1; z--)
        {
            cout << z;
        }
        cout << endl;
    }
    return 0;
}