// C. Assembly via Remainders

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array x2,x3,…,xn. Your task is to find any array a1,…,an, where:

// 1≤ai≤109 for all 1≤i≤n.
// xi=aimodai−1 for all 2≤i≤n.

// Here cmodd denotes the remainder of the division of the integer c by the integer d. For example 5mod2=1, 72mod3=0, 143mod14=3. Note that if there is more than one a which satisfies the statement, you are allowed to find any.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (2≤n≤500) — the number of elements in a. The second line of each test case contains n−1 integers x2,…,xn (1≤xi≤500) — the elements of x. It is guaranteed that the sum of values n over all test cases does not exceed 2⋅105.

// Output
// For each test case output any a1,…,an (1≤ai≤109) which satisfies the statement.

// Example
// inputCopy
// 5
// 4
// 2 4 1
// 3
// 1 1
// 6
// 4 2 5 1 2
// 2
// 500
// 3
// 1 5
// outputCopy
// 3 5 4 9
// 2 5 11
// 5 14 16 5 11 24
// 501 500
// 2 7 5

// Note
// In the first test case a=[3,5,4,9] satisfies the conditions, because:
// a2moda1=5mod3=2=x2;
// a3moda2=4mod5=4=x3;
// a4moda3=9mod4=1=x4;

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n-1);
    for(int i=0; i<n-1; i++)
    {
        cin >> x[i];
    }

    vector<int> answer(n);
    answer[0] = x[0] + 1;
    for(int i=1; i<=n-1; i++)
    {
        answer[i] = answer[i-1] + x[i-1];

        if(answer[i] < x[i] && i<n-1)
        {
            while(answer[i]<=x[i])
            {
                answer[i] += answer[i-1];
            }
        }
        // else if(answer[i] > x[i] && i<n-1)
        // {
        //     answer[i] = x[i-1];
        // }
    }

    //Output
    for(int i=0; i<n; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
