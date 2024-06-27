// E2. Erase and Extend (Hard Version)

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// This is the hard version of the problem. The only difference is the constraints on n and k. You can make hacks only if all versions of the problem are solved. You have a string s, and you can do two types of operations on it: Delete the last character of the string. Duplicate the string: s:=s+s, where + denotes concatenation. You can use each operation any number of times (possibly none). Your task is to find the lexicographically smallest string of length exactly k that can be obtained by doing these operations on string s. A string a is lexicographically smaller than a string b if and only if one of the following holds:

// a is a prefix of b, but a≠b;
// In the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

// Input
// The first line contains two integers n, k (1≤n,k≤5⋅105) — the length of the original string s and the length of the desired string. The second line contains the string s, consisting of n lowercase English letters.

// Output
// Print the lexicographically smallest string of length k that can be obtained by doing the operations on string s.

// Examples
// inputCopy
// 8 16
// dbcadabc
// outputCopy
// dbcadabcdbcadabc

// inputCopy
// 4 5
// abcd
// outputCopy
// aaaaa

// Note
// In the first test, it is optimal to make one duplication: "dbcadabc" → "dbcadabcdbcadabc".
// In the second test it is optimal to delete the last 3 characters, then duplicate the string 3 times, then delete the last 3 characters to make the string have length k.
// "abcd" → "abc" → "ab" → "a" → "aa" → "aaaa" → "aaaaaaaa" → "aaaaaaa" → "aaaaaa" → "aaaaa".

// My original soln(wrong on tc2) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long int N = 1e5+5;
// const long long int mod = 1e9+7;

// string operations(string &s, int k)
// {
//     while(s.size()<k)
//     {
//         s += s;
//     }
//     while(s.size()>k)
//     {
//         s.pop_back();
//     }

//     return s;
// }

// void solve()
// {
//     ll n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     string ans;
//     if((s[0]-'a')>s[1]-'a')
//     {
//         ans = operations(s,k);
//     }
//     else
//     {
//         string prefix = "";
//         prefix = s[0];
//         for(int i=0; i<n; i++)
//         {
//             ans += prefix;
//         }
//     }

//     cout << ans << endl;

//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// string smallestString(const string &s, int k)
// {
//     int n = s.size();
//     string smallest = s;

//     //Checking all possible prefixes
//     for (int i = 1; i <= n; ++i)
//     {
//         string prefix = s.substr(0, i);
//         string candidate;

//         //Repeating the prefix enough times to exceed length k
//         while (candidate.size() < k)
//         {
//             candidate += prefix;
//         }

//         //Truncating to length k
//         candidate = candidate.substr(0, k);

//         //Checking if the candidate is the smallest lexicographically
//         if (candidate < smallest)
//         {
//             smallest = candidate;
//         }
//     }

//     return smallest;
// }

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     cout << smallestString(s, k) << endl;
// }

// int main()
// {
//     solve();
//     return 0;
// }

// Alternate soln -

//Explanation
//Z-function Calculation: The z_func function calculates the Z-array for the string s. The Z-array stores the length of the longest common prefix between the substring starting at each position and the entire string.
//Finish Function: The finish function constructs and prints the final string of length k by repeating the smallest prefix found. It repeats the prefix of length m until the required length k is reached.
//Main Logic:The main function reads input values and calculates the Z-array. It then iterates through the string to find the smallest prefix that can be repeated to form the lexicographically smallest string of length k.
//During the iteration, it checks if the current character is greater or less than the corresponding character in the prefix. If it is greater, it prints the result using finish. If it is less, it updates the current prefix length. It also uses the Z-array to optimize the checks and handle overlaps efficiently.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
int n, k;

//Z-function to calculate the Z-array of a string
vector<int> z_func(const string &s)
{
    int n = s.size();
    vector<int> z(n, 0);

    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= R)
        {
            z[i] = min(z[i - L], R - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > R)
        {
            L = i;
            R = i + z[i] - 1;
        }
    }

    return z;
}

//Function to print the smallest lexicographical string
void finish(int m)
{
    for (int i = 0; i < k; i++)
    {
        cout << s[i % m];
    }

    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> s;
    auto z = z_func(s);

    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        //If s[i] is greater than the corresponding character in the current prefix
        if (s[i] > s[i % cur])
        {
            finish(cur);
        }

        //If s[i] is less than the corresponding character in the current prefix
        if (s[i] < s[i % cur])
        {
            cur = i + 1;
            continue;
        }

        int off = i - cur + 1;
        if (off == cur)
        {
            cur = i + 1;
            continue;
        }

        //Checking if we need to adjust the current length using the Z-function
        if (z[off] < cur - off)
        {
            if (cur + off + z[off] >= k)
            {
                cur = i + 1;
                continue;
            }
            if (s[off + z[off]] > s[z[off]])
            {
                cur = i + 1;
            }

            continue;
        }

        if (z[cur - off] < off)
        {
            if (2 * cur + z[cur - off] >= k)
            {
                cur = i + 1;
                continue;
            }
            if (s[cur - off + z[cur - off]] < s[z[cur - off]])
            {
                cur = i + 1;
            }

            continue;
        }

        cur = i + 1;
    }

    finish(cur);

    return 0;
}
