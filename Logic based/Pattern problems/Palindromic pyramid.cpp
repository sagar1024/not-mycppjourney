#include <iostream>
using namespace std;

// This is the palindromic pyramid

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for(int i = 1; i<=n; i++)
    {
        for(int a = i; a<=n-i; a++)
        {
            cout << " ";
        }
        cout << "\n";
    }

    for(int j = 1; j<=n; j++)
    {
        for(int k = j; k>=1; k--)
        {
            cout << k;
        }
        cout << "\n";
    }

    for(int x = 2; x<=n; x++)
    {
        for(int y = 2; y<=x; y++)
        {
            cout << y;
        }
        cout << "\n";
    }
    return 0;
}