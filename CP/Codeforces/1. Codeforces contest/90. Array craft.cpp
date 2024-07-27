// B. Array Craft

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// For an array b of size m, we define:

// the maximum prefix position of b is the smallest index i that satisfies b1+…+bi=maxmj=1(b1+…+bj);
// the maximum suffix position of b is the largest index i that satisfies bi+…+bm=maxmj=1(bj+…+bm).

// You are given three integers n, x, and y (x>y). Construct an array a of size n satisfying:
// ai is either 1 or −1 for all 1≤i≤n;
// the maximum prefix position of a is x;
// the maximum suffix position of a is y.

// If there are multiple arrays that meet the conditions, print any. It can be proven that such an array always exists under the given conditions.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. For each test case: The only line contains three integers n, x, and y (2≤n≤105,1≤y<x≤n). It is guaranteed that the sum of n over all test cases will not exceed 105.

// Output
// For each test case, output n space-separated integers a1,a2,…,an in a new line.

// Example
// inputCopy
// 3
// 2 2 1
// 4 4 3
// 6 5 1

// outputCopy
// 1 1
// 1 -1 1 1
// 1 1 -1 1 1 -1

// Note
// In the second test case,
// i=x=4 is the smallest index that satisfies a1+…+ai=maxnj=1(a1+…+aj)=2;
// i=y=3 is the greatest index that satisfies ai+…+an=maxnj=1(aj+…+an)=2.
// Thus, the array a=[1,−1,1,1] is considered correct.

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n, -1);
    if (x < y)
    {
        if (y - x >= n / 2)
        {
            for (int i = 0; i < x; i++)
            {
                a[i] = 1;
            }
            for (int i = y; i < n; i++)
            {
                a[i] = 1;
            }
        }
        else
        {
            x = x - n/4;
            y = y + n/4;
            for (int i = 0; i < x; i++)
            {
                a[i] = 1;
            }
            for (int i = y; i < n; i++)
            {
                a[i] = 1;
            }
        }
    }
    else if (x > y)
    {
        for (int i = y - 1; i < x; i++)
        {
            a[i] = 1;
        }
    }

    // Output
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
