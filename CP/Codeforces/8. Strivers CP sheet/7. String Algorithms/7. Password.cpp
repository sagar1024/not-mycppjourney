// B. Password

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them. A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s. Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s; and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end. Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened. You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.

// Input
// You are given the string s whose length can vary from 1 to 106 (inclusive), consisting of small Latin letters.

// Output
// Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.

// Examples
// inputCopy
// fixprefixsuffix
// outputCopy
// fix

// inputCopy
// abcdabc
// outputCopy
// Just a legend

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long long int N = 1e9+7;

// void solve()
// {
//     string s;
//     cin >> s;

//     string res;
//     bool prefix = false;
//     bool suffix = false;
//     bool obleix = false;
//     string s2;
//     s2 = s;
//     reverse(s2.begin(), s2.end());
//     for(int i=0; i<s.size(); i++)
//     {
//         //The largest substring which is same in prefix, suffix and in the middle
//     }

//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate soln - using KMP algorithm's prefix function

// Compute the Prefix Function: The prefix function for a string s is an array π where π[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring.The prefix function helps us in determining the repeated patterns within the string.

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//Function to compute the prefix function(KMP)
vector<int> computePrefixFunction(const string &s)
{
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) ++j;

        pi[i] = j;
    }

    return pi;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    vector<int> pi = computePrefixFunction(s);

    //Length of the longest proper prefix which is also a suffix
    int length = pi[n - 1];

    //Checking if this prefix appears somewhere else in the middle of the string
    for (int i = 1; i < n - 1; ++i)
    {
        if (pi[i] == length)
        {
            cout << s.substr(0, length) << endl;
            return;
        }
    }

    //If the exact length does not appear in the middle, check for shorter lengths
    while (length > 0)
    {
        length = pi[length - 1];
        for (int i = 1; i < n - 1; ++i)
        {
            if (pi[i] == length)
            {
                cout << s.substr(0, length) << endl;
                return;
            }
        }
    }

    cout << "Just a legend" << endl;   
    return;
}

int main()
{
    solve();
    return 0;
}

