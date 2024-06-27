// B. Zero Array

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a1,a2,…,an. In one operation you can choose two elements ai and aj (i≠j) and decrease each of them by one. You need to check whether it is possible to make all the elements equal to zero or not.

// Input
// The first line contains a single integer n (2≤n≤105) — the size of the array. The second line contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array.

// Output
// Print "YES" if it is possible to make all elements zero, otherwise print "NO".

// Examples
// inputCopy
// 4
// 1 1 2 2
// outputCopy
// YES
// inputCopy
// 6
// 1 2 3 4 5 6
// outputCopy
// NO

// Note

// In the first example, you can make all elements equal to zero in 3 operations:
// Decrease a1 and a2,
// Decrease a3 and a4,
// Decrease a3 and a4

// In the second example, one can show that it is impossible to make all elements equal to zero.

//My original soln(tutorial help) -

//There are 2 things needed to be possible to make all elements zero: 1: The sum of the elements must be even. 2: The biggest element have to be less or equal than the sum of all the other elements. If both are true, the answer is "YES", otherwise "NO".

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];
    }

    if(sum%2==0 && sum-a[n-1]>=a[n-1])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
