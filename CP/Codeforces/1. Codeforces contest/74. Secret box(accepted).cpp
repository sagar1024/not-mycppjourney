// E. Secret Box

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ntarsis has a box B with side lengths x, y, and z. It lies in the 3D coordinate plane, extending from (0,0,0) to (x,y,z). Ntarsis has a secret box S. He wants to choose its dimensions such that all side lengths are positive integers, and the volume of S is k. He can place S somewhere within B such that: S is parallel to all axes. Every corner of S lies on an integer coordinate. S is magical, so when placed at an integer location inside B, it will not fall to the ground. Among all possible ways to choose the dimensions of S, determine the maximum number of distinct locations he can choose to place his secret box S inside B. Ntarsis does not rotate S once its side lengths are selected.

// Input
// The first line consists of an integer t, the number of test cases (1≤t≤2000). The description of the test cases follows. The first and only line of each test case contains four integers x,y,z and k (1≤x,y,z≤2000, 1≤k≤x⋅y⋅z). It is guaranteed the sum of all x, sum of all y, and sum of all z do not exceed 2000 over all test cases. Note that k may not fit in a standard 32-bit integer data type.

// Output
// For each test case, output the answer as an integer on a new line. If there is no way to select the dimensions of S so it fits in B, output 0.

// Example
// inputCopy
// 7
// 3 3 3 8
// 3 3 3 18
// 5 1 1 1
// 2 2 2 7
// 3 4 2 12
// 4 3 1 6
// 1800 1800 1800 4913000000
// outputCopy
// 8
// 2
// 5
// 0
// 4
// 4
// 1030301

// Note
// For the first test case, it is optimal to choose S with side lengths 2, 2, and 2, which has a volume of 2⋅2⋅2=8. It can be shown there are 8 ways to put S inside B.
// The coordinate with the least x, y, and z values for each possible arrangement of S are:
// (0,0,0)
// (1,0,0)
// (0,1,0)
// (0,0,1)
// (1,0,1)
// (1,1,0)
// (0,1,1)
// (1,1,1)
// The arrangement of S with a coordinate of (0,0,0) is depicted below: (figure)

// For the second test case, S with side lengths 2, 3, and 3 are optimal.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

//FINDING all factor triples (a, b, c) such that a * b * c = k
vector<tuple<long long, long long, long long>> findFactors(long long k)
{
    vector<tuple<long long, long long, long long>> factors;
    for (long long a = 1; a * a * a <= k; ++a)
    {
        if (k % a == 0)
        {
            long long remainder = k / a;
            for (long long b = 1; b * b <= remainder; ++b)
            {
                if (remainder % b == 0)
                {
                    long long c = remainder / b;
                    factors.push_back(make_tuple(a, b, c));
                    factors.push_back(make_tuple(a, c, b));
                    factors.push_back(make_tuple(b, a, c));
                    factors.push_back(make_tuple(b, c, a));
                    factors.push_back(make_tuple(c, a, b));
                    factors.push_back(make_tuple(c, b, a));
                }
            }
        }
    }

    return factors;
}

//Counting the number of valid positions for the box with dimensions (a, b, c) inside the box (x, y, z)
long long countValidPositions(long long x, long long y, long long z, long long a, long long b, long long c)
{
    return (x - a + 1) * (y - b + 1) * (z - c + 1);
}

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x, y, z;
        long long k;
        cin >> x >> y >> z >> k;

        vector<tuple<long long, long long, long long>> factors = findFactors(k);
        long long maxPositions = 0;
        for (auto [a, b, c] : factors)
        {
            if (a <= x && b <= y && c <= z)
            {
                maxPositions = max(maxPositions, countValidPositions(x, y, z, a, b, c));
            }
        }

        cout << maxPositions << endl;
    }
}

int main()
{
    solve();
    return 0;
}
