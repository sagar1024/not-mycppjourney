// C. Building Permutation

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Permutation p is an ordered set of integers p1,  p2,  ...,  pn, consisting of n distinct positive integers, each of them doesn't exceed n. We'll denote the i-th element of permutation p as pi. We'll call number n the size or the length of permutation p1,  p2,  ...,  pn. You have a sequence of integers a1, a2, ..., an. In one move, you are allowed to decrease or increase any number by one. Count the minimum number of moves, needed to build a permutation from this sequence.

// Input
// The first line contains integer n (1 ≤ n ≤ 3·105) — the size of the sought permutation. The second line contains n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109).

// Output
// Print a single number — the minimum number of moves. Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Examples
// inputCopy
// 2
// 3 0
// outputCopy
// 2
// inputCopy
// 3
// -1 -1 2
// outputCopy
// 6

// Note
// In the first sample you should decrease the first number by one and then increase the second number by one. The resulting permutation is (2, 1).
// In the second sample you need 6 moves to build permutation (1, 3, 2).

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    //MAIN logic
    long long int moveCount = 0;

    sort(a.begin(), a.end());
    for(int i=0; i<n; i++)
    {
        moveCount += abs((i+1)-a[i]);
    }

    cout << moveCount << endl;

    return 0;
}
