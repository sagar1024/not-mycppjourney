// A. Too Min Too Max

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given an array a of n elements, find the maximum value of the expression:

// |ai−aj|+|aj−ak|+|ak−al|+|al−ai| where i, j, k, and l are four distinct indices of the array a, with 1≤i,j,k,l≤n.

// Here |x| denotes the absolute value of x.

// Input
// The first line contains one integer t (1≤t≤500) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (4≤n≤100) — the length of the given array. The second line of each test case contains n integers a1,a2,…,an (−106≤ai≤106).

// Output
// For each test case, print a single integer — the maximum value.

// Example
// inputCopy
// 5
// 4
// 1 1 1 1
// 5
// 1 1 2 2 3
// 8
// 5 1 3 2 -3 -1 10 3
// 4
// 3 3 1 1
// 4
// 1 2 2 -1
// outputCopy
// 0
// 6
// 38
// 8
// 8

// Note
// In the first test case, for any selection of i, j, k, l, the answer will be 0. For example, |a1−a2|+|a2−a3|+|a3−a4|+|a4−a1|=|1−1|+|1−1|+|1−1|+|1−1|=0+0+0+0=0.
// In the second test case, for i=1, j=3, k=2, and l=5, the answer will be 6. |a1−a3|+|a3−a2|+|a2−a5|+|a5−a1|=|1−2|+|2−1|+|1−3|+|3−1|=1+1+2+2=6.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long int> a(n);
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        //MAIN logic
        sort(a.begin(), a.end());

        long long int x1 = abs(a[0] - a[n-1]);
        long long int x2 = abs(a[1] - a[n-2]);
        long long int sum = x1 + x2;

        long long int result = sum*2;

        cout << result << endl;
    }

    return 0;
}
