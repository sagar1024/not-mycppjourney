// C. Print from N to 1

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print all numbers from N to 1 separated by a single space. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1 ≤ N ≤ 103).

// Output
// Print from N to 1 separated by a single space.

// Example
// inputCopy
// 4
// outputCopy
// 4 3 2 1

// Note
// Make sure don't print any leading or trailing spaces.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void myfunc(int n)
{
    if(n==0) return;
    else if(n==1)
    {
        cout << n;
        return;
    }
    cout << n << " ";
    return myfunc(n-1);
}

int32_t main()
{
    int n;
    cin >> n;

    myfunc(n);

    return 0;
}
