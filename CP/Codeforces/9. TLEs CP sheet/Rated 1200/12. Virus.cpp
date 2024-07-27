// C. Virus

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n houses numbered from 1 to n on a circle. For each 1≤i≤n−1, house i and house i+1 are neighbours; additionally, house n and house 1 are also neighbours. Initially, m of these n houses are infected by a deadly virus. Each morning, Cirno can choose a house which is uninfected and protect the house from being infected permanently. Every day, the following things happen in order: Cirno chooses an uninfected house, and protect it permanently. All uninfected, unprotected houses which have at least one infected neighbor become infected. Cirno wants to stop the virus from spreading. Find the minimum number of houses that will be infected in the end, if she optimally choose the houses to protect. Note that every day Cirno always chooses a house to protect before the virus spreads. Also, a protected house will not be infected forever.

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of test cases follows. The first line of each test case consists of two positive integers n,m (5≤n≤109, 1≤m≤min(n,105)) — the number of houses on the circle, and the number of houses that are initially infected. The second line of each test case consists of m distinct positive integers a1,a2,⋯,am (1≤ai≤n) — the indices of the houses infected initially. It is guaranteed that the sum of m over all test cases does not exceed 105.

// Output
// For each test case, output an integer on a separate line, which is the minimum number of infected houses in the end.

// Example
// inputCopy
// 8
// 10 3
// 3 6 8
// 6 2
// 2 5
// 20 3
// 3 7 12
// 41 5
// 1 11 21 31 41
// 10 5
// 2 4 6 8 10
// 5 5
// 3 2 5 4 1
// 1000000000 1
// 1
// 1000000000 4
// 1 1000000000 10 16
// outputCopy
// 7
// 5
// 11
// 28
// 9
// 5
// 2
// 15

// Note
// In the first test case:
// At the start of the first day, house 3, 6, 8 are infected. Choose house 2 to protect.
// At the start of the second day, house 3, 4, 5, 6, 7, 8, 9 are infected. Choose house 10 to protect.
// At the start of the third day, no more houses are infected.
// In the second test case:
// At the start of the first day, house 2, 5 are infected. Choose house 1 to protect.
// At the start of the second day, house 2, 3, 4, 5, 6 are infected. No more available houses can be protected.

//My original soln -

//Our final strategy can be decribed as following: Sort the uninfected segments of houses according to their length, then the longer the segment is, the earlier we will deal with the houses lying on the side of the segment

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> infected(m);
    for(int i=0; i<m; i++)
    {
        cin >> infected[i];
    }

    vector<int> uninfected;
    for(int i=0; i<m-1; i++)
    {
        int x = infected[i+1] - infected[i] - 1;
        uninfected.push_back(x);
    }

    int y = infected[0] - infected[m-1] - 1 + n;
    uninfected.push_back(y);

    sort(uninfected.begin(), uninfected.end(), greater<int>());
    long long int ans = 0;
    long long int count = 0;
    for(int i=0; i<m; i++)
    {
        if(uninfected[i]-count*2>0)
        {
            ans += max(1ll, uninfected[i] - count*2 - 1);
        }
        count += 2;
    }

    cout << n-ans << endl;
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
