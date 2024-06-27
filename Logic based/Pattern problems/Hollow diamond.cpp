#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    for(int i = 1; i<=n; i++)
    {
        for(int x = 1; x<=n-i; x++)
        {
            cout << " ";
        }

        for(int y = 1; y<=2*i-1; y++)
        {
            if(y==1 || y==2*i-1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for(int i = n; i>=1; i--)
    {
        for(int x = 1; x<=n-i; x++)
        {
            cout << " ";
        }

        for(int y = 1; y<=2*i-1; y++)
        {
            if(y==1 || y==2*i-1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}