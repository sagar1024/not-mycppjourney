#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i<=n; i++)
    {
        for(int j = n-1; j>=i; j--)
        {
            cout << " ";
        }
        for(int k = 1; k<=2*i-1; k++)
        {
            cout << "1";
        }
        cout << "\n";
    }
    return 0;
}