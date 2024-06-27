// F. Interesting Function

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two integers l and r, where l<r. We will add 1 to l until the result is equal to r. Thus, there will be exactly r−l additions performed. For each such addition, let's look at the number of digits that will be changed after it.

// For example:

// if l=909, then adding one will result in 910 and 2 digits will be changed;
// if you add one to l=9, the result will be 10 and 2 digits will also be changed;
// if you add one to l=489999, the result will be 490000 and 5 digits will be changed.

// Changed digits always form a suffix of the result written in the decimal system. Output the total number of changed digits, if you want to get r from l, adding 1 each time.

// Input
// The first line contains an integer t (1≤t≤104). Then t test cases follow. Each test case is characterized by two integers l and r (1≤l<r≤109).

// Output
// For each test case, calculate the total number of changed digits if you want to get r from l, adding one each time.

// Example
// inputCopy
// 4
// 1 9
// 9 10
// 10 20
// 1 1000000000
// outputCopy
// 8
// 2
// 11
// 1111111110

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    long long int l, r;
    cin >> l >> r;

    // string l2 = to_string(l);
    // int sizeL2 = l2.size();

    // string r2 = to_string(r);
    // int sizeR2 = r2.size();

    // string r3 = string("1", sizeR2);
    // long long int r4 = stoll(r3);
    
    long long int digitChangeCount = r-l;
    while(r>0 || l>0)
    {
        l /= 10;
        r /= 10;

        digitChangeCount += r-l;
    }

    cout << digitChangeCount << endl;

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
