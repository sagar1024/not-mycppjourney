// B. Segment Occurrences

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two strings s and t, both consisting only of lowercase Latin letters. The substring s[l..r] is the string which is obtained by taking characters sl,sl+1,…,sr without changing the order. Each of the occurrences of string a in a string b is a position i (1≤i≤|b|−|a|+1) such that b[i..i+|a|−1]=a (|a| is the length of string a). You are asked q queries: for the i-th query you are required to calculate the number of occurrences of string t in a substring s[li..ri].

// Input
// The first line contains three integer numbers n, m and q (1≤n,m≤103, 1≤q≤105) — the length of string s, the length of string t and the number of queries, respectively. The second line is a string s (|s|=n), consisting only of lowercase Latin letters. The third line is a string t (|t|=m), consisting only of lowercase Latin letters. Each of the next q lines contains two integer numbers li and ri (1≤li≤ri≤n) — the arguments for the i-th query.

// Output
// Print q lines — the i-th line should contain the answer to the i-th query, that is the number of occurrences of string t in a substring s[li..ri].

// Examples
// inputCopy
// 10 3 4
// codeforces
// for
// 1 3
// 3 10
// 5 6
// 5 7
// outputCopy
// 0
// 1
// 0
// 1
// inputCopy
// 15 2 3
// abacabadabacaba
// ba
// 1 15
// 3 4
// 2 14
// outputCopy
// 4
// 0
// 3
// inputCopy
// 3 5 2
// aaa
// baaab
// 1 3
// 1 1
// outputCopy
// 0
// 0

// Note
// In the first example the queries are substrings: "cod", "deforces", "fo" and "for", respectively.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// int32_t main()
// {
//     ll n, m, q;
//     cin >> n >> m >> q;

//     string s, t;
//     cin >> s >> t;

//     //vector<pair<int,int>> que(q);
//     for(int i=0; i<q; i++)
//     {
//         //Left and right indexes
//         //cin >> que[i].first >> que[i].second;
//         ll left, right;
//         cin >> left >> right;

//         int count = 0;
//         int idx = 0;
//         int ans = 0;
//         for(int j=left-1; j<right-1; j++)
//         {
//             if(s[j]==t[idx])
//             {
//                 count++;
//                 if(count==m)
//                 {
//                     ans++;
//                     count = 0;
//                     idx = 0;
//                 }
//                 idx++;
//             }
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int32_t main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    //Preprocessing - We'll preprocess the string s to count the number of occurrences of t in each prefix of s.
    //We'll store these counts in an array prefix_count where prefix_count[i] gives the number of times t appears in the substring s[0..i].
    //Answering Queries: For each query, we'll use the prefix_count array
    //To quickly compute the number of times t appears in the substring s[l..r]
    vector<int> prefixCount(n,0);
    for(int i=0; i<n-m; i++)
    {
        if(s.substr(i,m)==t)
        {
            prefixCount[i] = 1;
        }
    }

    //Cumulative sum
    for(int i=1; i<n; i++)
    {
        prefixCount[i] += prefixCount[i-1];
    }

    //Q queries
    while(q--)
    {
        ll li, ri;
        cin >> li >> ri;

        li--;
        ri--;

        ll res = 0;
        if((ri-li+1)>=m)
        {
            if(li==0)
            {
                res = prefixCount[ri-m+1];
            }
            else
            {
                res = prefixCount[ri-m+1] - prefixCount[li-1];
            }
        }

        //Output for each query
        cout << res << endl;
    }

    return 0;
}
