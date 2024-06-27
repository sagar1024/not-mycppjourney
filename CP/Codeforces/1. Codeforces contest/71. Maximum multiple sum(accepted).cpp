// B. Maximum Multiple Sum

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given an integer n, find an integer x such that: 2≤x≤n. The sum of multiples of x that are less than or equal to n is maximized. Formally, x+2x+3x+⋯+kx where kx≤n is maximized over all possible values of x.

// Input
// The first line contains t (1≤t≤100) — the number of test cases. Each test case contains a single integer n (2≤n≤100).

// Output
// For each test case, output an integer, the optimal value of x. It can be shown there is only one unique answer.

// Example
// inputCopy
// 2
// 3
// 15
// outputCopy
// 3
// 2

// Note
// For n=3, the possible values of x are 2 and 3. The sum of all multiples of 2 less than or equal to n is just 2, and the sum of all multiples of 3 less than or equal to n is 3. Therefore, 3 is the optimal value of x.
// For n=15, the optimal value of x is 2. The sum of all multiples of 2 less than or equal to n is 2+4+6+8+10+12+14=56, which can be proven to be the maximal over all other possible values of x.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin >> n;

    int optimal_x = 2;
    int max_sum = 0;

    for (int x = 2; x <= n; x++)
    {
        int k = n / x;
        int sum = x * k * (k + 1) / 2;

        if (sum > max_sum)
        {
            max_sum = sum;
            optimal_x = x;
        }
    }

    cout << optimal_x << endl;
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
