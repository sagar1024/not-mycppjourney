// A. Game with Integers

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vanya and Vova are playing a game. Players are given an integer n. On their turn, the player can add 1 to the current integer or subtract 1. The players take turns; Vanya starts. If after Vanya's move the integer is divisible by 3, then he wins. If 10 moves have passed and Vanya has not won, then Vova wins. Write a program that, based on the integer n, determines who will win if both players play optimally.

// Input
// The first line contains the integer t (1≤t≤100) — the number of test cases. The single line of each test case contains the integer n (1≤n≤1000).

// Output
// For each test case, print "First" without quotes if Vanya wins, and "Second" without quotes if Vova wins.

// Example
// inputCopy
// 6
// 1
// 3
// 5
// 100
// 999
// 1000

// outputCopy
// First
// Second
// First
// First
// Second
// First

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    if(n%3==1 || n%3==2)
    {
        cout << "First" << endl;
    }
    else if(n%3==0)
    {
        cout << "Second" << endl;
    }
    
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
