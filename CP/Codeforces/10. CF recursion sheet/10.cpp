// J. Factorial

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print factorial of N. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1 ≤ N ≤ 20).

// Output
// Print the factorial of the number N.

// Example
// inputCopy
// 5
// outputCopy
// 120

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void calcFact(int n, long long &ans)
{
    if(n==1)
    {
        return;
    }

    calcFact(n-1,ans);
    ans *= n;
    return;
}

int32_t main()
{
    int n;
    cin >> n;
    
    long long int ans = 1;
    calcFact(n,ans);

    cout << ans << endl;
    return 0;
}
