// B. Print from 1 to N

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print numbers from 1 to N in separate lines. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1 ≤ N ≤ 103).

// Output
// Print N lines according to the required above.

// Example
// inputCopy
// 5
// outputCopy
// 1
// 2
// 3
// 4
// 5

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cout << i << endl;
    }

    return 0;
}
