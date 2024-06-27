// A. Greg and Array

// time limit per test1.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Greg has an array a = a1, a2, ..., an and m operations. Each operation looks as: li, ri, di, (1 ≤ li ≤ ri ≤ n). To apply operation i to the array means to increase all array elements with numbers li, li + 1, ..., ri by value di. Greg wrote down k queries on a piece of paper. Each query has the following form: xi, yi, (1 ≤ xi ≤ yi ≤ m). That means that one should apply operations with numbers xi, xi + 1, ..., yi to the array. Now Greg is wondering, what the array a will be after all the queries are executed. Help Greg.

// Input
// The first line contains integers n, m, k (1 ≤ n, m, k ≤ 105). The second line contains n integers: a1, a2, ..., an (0 ≤ ai ≤ 105) — the initial array. Next m lines contain operations, the operation number i is written as three integers: li, ri, di, (1 ≤ li ≤ ri ≤ n), (0 ≤ di ≤ 105). Next k lines contain the queries, the query number i is written as two integers: xi, yi, (1 ≤ xi ≤ yi ≤ m). The numbers in the lines are separated by single spaces.

// Output
// On a single line print n integers a1, a2, ..., an — the array after executing all the queries. Separate the printed numbers by spaces. Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

// Examples
// inputCopy
// 3 3 3
// 1 2 3
// 1 2 1
// 1 3 2
// 2 3 4
// 1 2
// 1 3
// 2 3
// outputCopy
// 9 18 17
// inputCopy
// 1 1 1
// 1
// 1 1 1
// 1 1
// outputCopy
// 2
// inputCopy
// 4 3 6
// 1 2 3 4
// 1 2 1
// 2 3 2
// 3 4 4
// 1 2
// 1 3
// 2 3
// 1 2
// 1 3
// 2 3
// outputCopy
// 5 18 31 20

//My original soln(help taken) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    // //Operations
    // vector<vector<int>> ops;
    // for(int i=0; i<m; i++)
    // {
    //     int x, y, z;
    //     cin >> x >> y >> z;

    //     ops.push_back({x,y,z});
    // }

    // //Queries
    // vector<pair<int,int>> queries;
    // for(int i=0; i<k; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;

    //     queries.push_back({x,y});
    // }

    vector<pair<int, int>> operations(m);
    for (int i = 0; i < m; ++i)
    {
        int l, r, d;
        cin >> l >> r >> d;
        operations[i] = {l, r};
    }

    vector<pair<int, int>> queries(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<long long> deltas(m + 1);
    for (int i = 0; i < k; ++i)
    {
        int l = queries[i].first, r = queries[i].second;
        ++deltas[l - 1];
        --deltas[r];
    }

    for (int i = 1; i <= m; ++i)
    {
        deltas[i] += deltas[i - 1];
    }

    for (int i = 0; i < m; ++i)
    {
        givenArray[operations[i].first - 1] += deltas[i];
        givenArray[operations[i].second] -= deltas[i];
    }

    for (int i = 1; i < n; ++i)
    {
        givenArray[i] += givenArray[i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << givenArray[i] << " ";
    }

    cout << endl;
    return;
}

int32_t main()
{
    fastio;
    solve();

    return 0;
}
