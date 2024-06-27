// A. Road To Zero

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two integers x and y. You can perform two types of operations:

// Pay a dollars and increase or decrease any of these integers by 1. For example, if x=0 and y=7 there are four possible outcomes after this operation:

// x=0, y=6;
// x=0, y=8;
// x=−1, y=7;
// x=1, y=7.

// Pay b dollars and increase or decrease both integers by 1. For example, if x=0 and y=7 there are two possible outcomes after this operation:
// x=−1, y=6;
// x=1, y=8.

// Your goal is to make both given integers equal zero simultaneously, i.e. x=y=0. There are no other requirements. In particular, it is possible to move from x=1, y=0 to x=y=0.

// Calculate the minimum amount of dollars you have to spend on it.

// Input
// The first line contains one integer t (1≤t≤100) — the number of testcases.

// The first line of each test case contains two integers x and y (0≤x,y≤109).

// The second line of each test case contains two integers a and b (1≤a,b≤109).

// Output
// For each test case print one integer — the minimum amount of dollars you have to spend.

// Example
// Input
// 2
// 1 3
// 391 555
// 0 0
// 9 4
// Output
// 1337
// 0

// Note
// In the first test case you can perform the following sequence of operations: first, second, first. This way you spend 391+555+391=1337 dollars.
// In the second test case both integers are equal to zero initially, so you dont' have to spend money.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //Initial values of x and y(to be made equal to 0)
    long long int x, y;
    cin >> x >> y;

    //Amount to be paid to make changes in x and y
    long long int a, b;
    cin >> a >> b;

    long long int minAmount = 0;

    if(x==0 && y==0)
    {
        cout << minAmount << endl;
        return;
    }
    if(x==0)
    {
        minAmount = a*abs(y);
        cout << minAmount << endl;
        return;
    }
    if(y==0)
    {
        minAmount = a*abs(x);
        cout << minAmount << endl;
        return;
    }
    if(x<0 && y>0 || x>0 && y<0)
    {
        long long int diff = abs(x-y);
        minAmount = a*diff;
        cout << minAmount << endl;
        return;
    }

    long long int difference = max(abs(x),abs(y)) - min(abs(x),abs(y));
    long long int minVar = min(abs(x),abs(y));

    minAmount = a*difference + b*minVar;
    cout << minAmount << endl;

    return;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Calling the function t times
        solve();
    }

    return 0;
}
