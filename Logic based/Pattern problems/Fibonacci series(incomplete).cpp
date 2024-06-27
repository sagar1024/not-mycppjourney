#include <iostream>
using namespace std;

void fibo(int n)
{
    // Initialising the required variables
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    // The loop for the fibonacci series

    for(int i = 1; i<=n; i++)
    {
        cout << t1;
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return;
}

int main()
{
    int x;
    cin >> x;

    cout << fibo(x);
    return 0;
}

