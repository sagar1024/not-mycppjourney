// A. Maximize?

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an integer x. Your task is to find any integer y (1≤y<x) such that gcd(x,y)+y is maximum possible. Note that if there is more than one y which satisfies the statement, you are allowed to find any. gcd(a,b) is the Greatest Common Divisor of a and b. For example, gcd(6,4)=2.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. Each of the following t lines contains a single integer x (2≤x≤1000).

// Output
// For each test case, output any y (1≤y<x), which satisfies the statement.

// Example
// inputCopy
// 7
// 10
// 7
// 21
// 100
// 2
// 1000
// 6
// outputCopy
// 5
// 6
// 18
// 98
// 1
// 750
// 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int x;
    cin >> x;

    if(x%2==0)
    {
        cout << x/2 << endl;
    }
    else
    {
        cout << x-1 << endl;
    }

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
