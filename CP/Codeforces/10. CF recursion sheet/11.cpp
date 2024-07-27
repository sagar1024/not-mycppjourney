// K. Max Number

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Given a number N and an array A of N numbers. Print the maximum value in this array. Note: Solve this problem using recursion.

// Input
// First line contains a number N (1 ≤ N ≤ 103) number of elements. Second line contains N numbers ( - 109 ≤ Ai ≤ 109).

// Output
// Print the maximum value in this array.

// Example
// inputCopy
// 5
// 1 -3 5 4 -6

// outputCopy
// 5

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void calcMaxNum(vector<long long int> &a, int sz, long long int &ans)
{
    if(sz<0)
    {
        return;
    }
    calcMaxNum(a,sz-1,ans);
    ans = max(ans,a[sz]);
    return;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    long long int ans = LLONG_MIN;
    calcMaxNum(a,n-1,ans);

    cout << ans << endl;

    return 0;
}
