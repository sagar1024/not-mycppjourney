// C. Binary String Reconstruction

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Consider the following process. You have a binary string (a string where each character is either 0 or 1) w of length n and an integer x. You build a new binary string s consisting of n characters. The i-th character of s is chosen as follows:

// if the character wi−x exists and is equal to 1, then si is 1 (formally, if i>x and wi−x= 1, then si= 1);
// if the character wi+x exists and is equal to 1, then si is 1 (formally, if i+x≤n and wi+x= 1, then si=1);
// if both of the aforementioned conditions are false, then si is 0.

// You are given the integer x and the resulting string s. Reconstruct the original string w.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. Each test case consists of two lines. The first line contains the resulting string s (2≤|s|≤105, each character of s is either 0 or 1). The second line contains one integer x (1≤x≤|s|−1). The total length of all strings s in the input does not exceed 105.

// Output
// For each test case, print the answer on a separate line as follows: if no string w can produce the string s at the end of the process, print −1; otherwise, print the binary string w consisting of |s| characters. If there are multiple answers, print any of them.

// Example
// inputCopy
// 3
// 101110
// 2
// 01
// 1
// 110
// 1

// outputCopy
// 111011
// 10
// -1

// My original sol -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;

//     int x;
//     cin >> x;

//     //MAIN logic
//     //If the s[i] is 1
//     //AND
//     //w[i-x] or w[i+x] exists
//     //Then w[i-x] or w[i+x] is 1
//     //And the remaining are 0

//     int n = s.size();
//     string w(n, '0');
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='0')
//         {
//             if(w[i-x]=='0')
//             {
//                 w[i-x] = '1';
//             }
//             else if(w[i+x]=='0')
//             {
//                 w[i+x] = '1';
//             }
//         }
//     }

//     cout << w << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln - Note that si=1 means "either wi−x=1 or wi+x=1," whereas si=0 means "both wi−x=0 and wi+x=0." We can greedily solve this by starting out our string w with all 1's, then marking i−x and i+x as 0 whenever we are forced to because si=0. Then we can simply check whether all of the si=1 conditions are valid to confirm

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int x;

    cin >> s >> x;

    //MAIN logic
    //Here si=1 means "either wi−x=1 or wi+x=1"
    //AND si=0 means "both wi−x=0 and wi+x=0"
    int n = int(s.size());
    string w(n, '1');

    for (int i=0; i<n; i++)
    {
        if (s[i] == '0')
        {
            if (i-x >= 0)
            {
                w[i-x] = '0';
            }
            if (i+x < n)
            {
                w[i+x] = '0';
            }
        }
    }

    //Checking whether all of the si=1 conditions are valid to confirm
    for (int i = 0; i < n; i++)
    {
        bool one = false;

        one = one || (i - x >= 0 && w[i - x] == '1');
        one = one || (i + x < n && w[i + x] == '1');

        if (s[i] != one + '0')
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << w << endl;
    return;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
