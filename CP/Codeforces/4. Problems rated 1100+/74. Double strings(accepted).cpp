// D. Double Strings

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given n strings s1,s2,…,sn of length at most 8. For each string si, determine if there exist two strings sj and sk such that si=sj+sk. That is, si is the concatenation of sj and sk. Note that j can be equal to k. Recall that the concatenation of strings s and t is s+t=s1s2…spt1t2…tq, where p and q are the lengths of strings s and t respectively. For example, concatenation of "code" and "forces" is "codeforces".

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤105) — the number of strings. Then n lines follow, the i-th of which contains non-empty string si of length at most 8, consisting of lowercase English letters. Among the given n strings, there may be equal (duplicates). The sum of n over all test cases doesn't exceed 105.

// Output
// For each test case, output a binary string of length n. The i-th bit should be 1 if there exist two strings sj and sk where si=sj+sk, and 0 otherwise. Note that j can be equal to k.

// Example
// inputCopy
// 3
// 5
// abab
// ab
// abc
// abacb
// c
// 3
// x
// xx
// xxx
// 8
// codeforc
// es
// codes
// cod
// forc
// forces
// e
// code
// outputCopy
// 10100
// 011
// 10100101

// Note
// In the first test case, we have the following:

// s1=s2+s2, since abab=ab+ab. Remember that j can be equal to k.
// s2 is not the concatenation of any two strings in the list.
// s3=s2+s5, since abc=ab+c.
// s4 is not the concatenation of any two strings in the list.
// s5 is not the concatenation of any two strings in the list.

// Since only s1 and s3 satisfy the conditions, only the first and third bits in the answer should be 1, so the answer is 10100.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define forn(i,n) for(int i=0; i<n; i++){}

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<string> s(n);
//     int i=0;
//     forn(i,n)
//     {
//         cin >> s[i];
//     }

//     string answer;

//     int j=0, k=0;
//     bool concatPairFound = false;
//     forn(i,n)
//     {
//         forn(j,n)
//         {
//             forn(k,n)
//             {
//                 if(i!=j && i!=k)
//                 {
//                     if(s[i]==s[j]+s[k])
//                     {
//                         concatPairFound = true;
//                     }
//                 }
//             }
//         }

//         if(concatPairFound)
//         {
//             answer += "1";
//             concatPairFound = false;
//         }
//         else
//         {
//             answer += "0";
//         }
//     }

//     cout << answer << endl;
//     return;
// }

// int_fast32_t main()
// {
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

int_fast32_t main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        int n;
        cin >> n;

        vector<string> strings(n);
        unordered_set<string> stringSet;
        for (int i = 0; i < n; i++)
        {
            cin >> strings[i];
            stringSet.insert(strings[i]);
        }

        //MAIN logic
        string answer;
        for (int i = 0; i < n; i++)
        {
            bool concatPairFound = false;
            for (int j = 1; j < strings[i].size(); j++)
            {
                string prefix = strings[i].substr(0, j);
                string suffix = strings[i].substr(j);

                //Checking if both the prefix and suffix exist in the stringSet
                //If there is an instance when such pair exists, add "1" to the answer string 
                if (stringSet.count(prefix) && stringSet.count(suffix))
                {
                    concatPairFound = true;
                    break;
                }
            }
            
            //Output string
            answer += concatPairFound ? '1' : '0';
        }

        //Output
        cout << answer << endl;
    }

    return 0;
}
