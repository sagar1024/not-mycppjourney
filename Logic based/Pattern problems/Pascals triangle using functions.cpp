#include <iostream>
using namespace std;

int fact(int n)
{
    int factorial = 1;
    for(int i = 2; i<=n; i++)
    {
        factorial = factorial*i;
    }
    return factorial;
}

int main()
{
    int a;
    cin >> a;

    for(int i = 0; i<a; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout << fact(i)/(fact(j)*fact(i-j)); 
        }
        cout << endl;
    }
    return 0;
}
