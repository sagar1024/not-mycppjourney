// A. Maximum Increase

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array. A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

// Input
// The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of integers. The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

// Output
// Print the maximum length of an increasing subarray of the given array.

// Examples
// inputCopy
// 5
// 1 7 2 11 15
// outputCopy
// 3
// inputCopy
// 6
// 100 100 100 100 100 100
// outputCopy
// 1
// inputCopy
// 3
// 1 2 3
// outputCopy
// 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int32_t main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxLen = 1;
    int currentLen = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i-1])
        {
            currentLen++;
        }
        else
        {
            currentLen = 1;
        }

        maxLen = max(maxLen, currentLen);
    }

    cout << maxLen << endl;
    return 0;
}
