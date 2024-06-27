// A. Odd One Out

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given three digits a, b, c. Two of them are equal, but the third one is different from the other two. Find the value that occurs exactly once.

// Input
// The first line contains a single integer t (1≤t≤270) — the number of test cases. The only line of each test case contains three digits a, b, c (0≤a, b, c≤9). Two of the digits are equal, but the third one is different from the other two.

// Output
// For each test case, output the value that occurs exactly once.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==b)
        {
            cout << c << endl;
        }
        else if(b==c)
        {
            cout << a << endl;
        }
        else if(c==a)
        {
            cout << b << endl;
        }
    }

    return 0;
}
