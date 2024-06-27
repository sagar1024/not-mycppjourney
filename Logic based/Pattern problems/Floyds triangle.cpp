#include <iostream>
using namespace std;

// This is the floyds triangle

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int num = 1;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout << num;
            num++;
        }
        cout << "\n";
    }
    return 0;
}