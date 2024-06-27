// A. Problem Generator

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vlad is planning to hold m rounds next month. Each round should contain one problem of difficulty levels 'A', 'B', 'C', 'D', 'E', 'F', and 'G'. Vlad already has a bank of n problems, where the i-th problem has a difficulty level of ai. There may not be enough of these problems, so he may have to come up with a few more problems. Vlad wants to come up with as few problems as possible, so he asks you to find the minimum number of problems he needs to come up with in order to hold m rounds. For example, if m=1, n=10, a= 'BGECDCBDED', then he needs to come up with two problems: one of difficulty level 'A' and one of difficulty level 'F'.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains two integers n and m (1≤n≤50, 1≤m≤5) — the number of problems in the bank and the number of upcoming rounds, respectively. The second line of each test case contains a string a of n characters from 'A' to 'G' — the difficulties of the problems in the bank.

// Output
// For each test case, output a single integer — the minimum number of problems that need to come up with to hold m rounds.

// Example
// inputCopy
// 3
// 10 1
// BGECDCBDED
// 10 2
// BGECDCBDED
// 9 1
// BBCDEFFGG
// outputCopy
// 2
// 5
// 1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     //Problems and rounds
//     int n, m;
//     cin >> n >> m;

//     string s;
//     cin >> s;

//     int lenS = s.size();

//     vector<int> freq(n);
//     for(int i=0; i<lenS; i++)
//     {
//         freq[s[i]-'A']++;
//     }

//     int ans = 0;
//     for(int i=0; i<7; i++)
//     {
//         if(freq[i]<m)
//         {
//             ans += m-freq[i];
//         }
//     }

//     cout << ans << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int freq[7] = {0};
    for (char c : s)
    {
        freq[c - 'A']++;
    }

    int additional_problems_needed = 0;
    for (int i = 0; i < 7; i++)
    {
        if (freq[i] < m)
        {
            additional_problems_needed += (m - freq[i]);
        }
    }

    cout << additional_problems_needed << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
