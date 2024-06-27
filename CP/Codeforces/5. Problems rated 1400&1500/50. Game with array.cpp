// D. Game With Array

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Petya and Vasya are competing with each other in a new interesting game as they always do. At the beginning of the game Petya has to come up with an array of N positive integers. Sum of all elements in his array should be equal to S. Then Petya has to select an integer K such that 0≤K≤S. In order to win, Vasya has to find a non-empty subarray in Petya's array such that the sum of all selected elements equals to either K or S−K. Otherwise Vasya loses. You are given integers N and S. You should determine if Petya can win, considering Vasya plays optimally. If Petya can win, help him to do that.

// Input
// The first line contains two integers N and S (1≤N≤S≤106) — the required length of the array and the required sum of its elements.

// Output
// If Petya can win, print "YES" (without quotes) in the first line. Then print Petya's array in the second line. The array should contain N positive integers with sum equal to S. In the third line print K. If there are many correct answers, you can print any of them. If Petya can't win, print "NO" (without quotes). You can print each letter in any register (lowercase or uppercase).

// Examples
// inputCopy
// 1 4
// outputCopy
// YES
// 4
// 2
// inputCopy
// 3 4
// outputCopy
// NO
// inputCopy
// 3 8
// outputCopy
// YES
// 2 1 5
// 4

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

    vector<long long int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

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
