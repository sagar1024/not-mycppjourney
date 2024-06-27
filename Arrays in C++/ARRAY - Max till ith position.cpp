// Program to print the max element of an array till ith position

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }

    int maximum = -19999999;

    for(int i = 0; i<n; i++)
    {
        maximum = max(maximum, a[i]);
        cout << maximum << " "; 
    }

    return 0;
}