// A. Three Pairwise Maximums

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given three positive (i.e. strictly greater than zero) integers x, y and z. Your task is to find positive integers a, b and c such that x=max(a,b), y=max(a,c) and z=max(b,c), or determine that it is impossible to find such a, b and c. You have to answer t independent test cases. Print required a, b and c in any (arbitrary) order.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The only line of the test case contains three integers x, y, and z (1≤x,y,z≤109).

// Output
// For each test case, print the answer: "NO" in the only line of the output if a solution doesn't exist.
// OR "YES" in the first line and any valid triple of positive integers a, b and c (1≤a,b,c≤109) in the second line. You can print a, b and c in any order.

// Example
// inputCopy
// 5
// 3 2 3
// 100 100 100
// 50 49 49
// 10 30 20
// 1 1000000000 1000000000
// outputCopy
// YES
// 3 2 1
// YES
// 100 100 100
// NO
// NO
// YES
// 1 1 1000000000

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long int x, y, z;
    cin >> x >> y >> z;

    long long int numbers[3] = {x, y, z};
    sort(numbers, numbers+3);
    if(numbers[1]==numbers[2])
    {
        cout << "YES" << endl;
        cout << numbers[0] << " " << numbers[0] << " " << numbers[2] << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

signed main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
