// C. Good String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's call left cyclic shift of some string t1t2t3…tn−1tn as string t2t3…tn−1tnt1. Analogically, let's call right cyclic shift of string t as string tnt1t2t3…tn−1. Let's say string t is good if its left cyclic shift is equal to its right cyclic shift. You are given string s which consists of digits 0–9. What is the minimum number of characters you need to erase from s to make it good?

// Input
// The first line contains single integer t (1≤t≤1000) — the number of test cases. Next t lines contains test cases — one per line. The first and only line of each test case contains string s (2≤|s|≤2⋅105). Each character si is digit 0–9. It's guaranteed that the total length of strings doesn't exceed 2⋅105.

// Output
// For each test case, print the minimum number of characters you need to erase from s to make it good.

// Example
// inputCopy
// 3
// 95831
// 100120013
// 252525252525
// outputCopy
// 3
// 5
// 0

// Note
// In the first test case, you can erase any 3 characters, for example, the 1-st, the 3-rd, and the 4-th. You'll get string 51 and it is good.
// In the second test case, we can erase all characters except 0: the remaining string is 0000 and it's good.
// In the third test case, the given string s is already good.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     string s;
//     cin >> s;

//     vector<long long int> freq(10);
//     for(int i=0; i<s.size(); i++)
//     {
//         freq[s[i]-'0']++;
//     }

//     //Sorting the freq in descending order
//     sort(freq.begin(), freq.end(), greater<int>());

//     if(freq[0]==1)
//     {
//         cout << s.size()-2 << endl;
//         return;
//     }
//     else if(freq[0]==freq[1])
//     {
//         cout << 0 << endl;
//         return;
//     }
//     else
//     {
//         cout << s.size()-freq[0] << endl;
//         return;
//     }
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

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

//Function to find the maximum length of a good substring starting with characters x and y
int findGoodSubstring(const string &s, int x, int y)
{
    int maxLength = 0;
    for (auto c : s)
    {
        //If the current character matches x
        if (c - '0' == x)
        {
            //Incrementing the length of the substring
            ++maxLength;
            //Swapping x and y for the next iteration
            swap(x, y);
        }
    }

    //If x and y are different and the length of the substring is odd, decrement the length
    if (x != y && maxLength % 2 == 1)
    {
        maxLength--;
    }

    return maxLength;
}

//Function to solve each test case
void solve()
{
    string s;
    cin >> s;

    int maxLength = 0;

    //Iterating over all possible pairs of starting characters
    forn(x, 10)
    {
        forn(y, 10)
        {
            //Finding the maximum length of a good substring starting with characters x and y
            maxLength = max(maxLength, findGoodSubstring(s, x, y));
        }
    }

    //Output the minimum number of characters to erase
    cout << sz(s) - maxLength << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
