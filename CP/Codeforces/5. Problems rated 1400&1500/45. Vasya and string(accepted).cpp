// C. Vasya and String

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters. Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

// Input
// The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and the maximum number of characters to change. The second line contains the string, consisting of letters 'a' and 'b' only.

// Output
// Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.

// Examples
// inputCopy
// 4 2
// abba
// outputCopy
// 4
// inputCopy
// 8 1
// aabaabaa
// outputCopy
// 5

// Note
// In the first sample, Vasya can obtain both strings "aaaa" and "bbbb".
// In the second sample, the optimal answer is obtained with the string "aaaaabaa" or with the string "aabaaaaa".

// My original soln(honest work) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     //Two pointers
//     int l=0, r=s.size()-1;

//     int countA = 0;
//     int countB = 0;

//     int length = 0;
//     while(l<=r)
//     {
//         countA = 0;
//         countB = 0;

//         for(int i=l; i<=r; i++)
//         {
//             if(s[i]=='a')
//             {
//                 countA++;
//             }
//             else
//             {
//                 countB++;
//             }
//         }

//         if(countA>countB)
//         {
//             if(countB<=k)
//             {
//                 length = max(r-l+1, length);
//             }
//         }
//         else
//         {
//             if(countA<=k)
//             {
//                 length = max(r-l+1, length);
//             }
//         }

//         l++; //Move left pointer towards right
//     }

//     cout << length << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m;
string s;

//Function to find the maximum length of a substring with at most m characters of type x
ll maxLength(char x)
{
    ll i, j = 0, cnt = 0, ans = 0;
    for (i = 0; i < n; i++)
    {
        if(s[i]==x) cnt++;
        if(cnt > m)
        {
            //Shrink the window until the count becomes less than or equal to m
            while (cnt > m)
            {
                if(s[j++] == x) cnt--;
            }
        }

        //Update the maximum length
        ans = max(ans, i - j + 1);
    }

    return ans;
}

int main()
{
    while (cin >> n >> m)
    {
        cin >> s;
        cout << max(maxLength('a'), maxLength('b')) << endl;
    }

    return 0;
}
