// Given an array a[] of size n, output the sum of each subarray of the given array
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

    int sum = 0;

    for(int i = 0; i<n; i++)
    {
        sum = 0;
        for(int j = i; j<n; j++)
        {
            sum += a[j];
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}