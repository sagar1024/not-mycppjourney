// D. Print Digits using Recursion

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print the digits of N separated by a space. Note: Solve this problem using recursion.

// Input
// First line contains a number T (1 ≤ T ≤ 10) number of test cases. Next T lines will contain a number N (0 ≤ N ≤ 109).

// Output
// For each test case print a single line contains the digits of the number separated by space.

// Example
// inputCopy
// 3
// 121
// 39
// 123456
// outputCopy
// 1 2 1 
// 3 9 
// 1 2 3 4 5 6 

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void myfunc(string &s, int n, int n2)
{
    //Base case
    if(n==0)
    {
        cout << s[0] << " ";
        return;
    }
    
    //Recursive function
    myfunc(s,n-1,n2);
    if(n==n2)
    {
        cout << s[n];
        return;
    }

    cout << s[n] << " ";
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int n2 = n; //Dummy size
    n--;
    n2--;

    myfunc(s,n,n2);
    cout << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
