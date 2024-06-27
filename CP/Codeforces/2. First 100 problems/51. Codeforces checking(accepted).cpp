// A. Codeforces Checking

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a lowercase Latin character (letter), check if it appears in the string codeforces.

// Input
// The first line of the input contains an integer t (1≤t≤26) — the number of test cases. The only line of each test case contains a character c — a single lowercase Latin character (letter).

// Output
// For each test case, output "YES" (without quotes) if c satisfies the condition, and "NO" (without quotes) otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPresent(char x)
{
    string s = "codeforces";

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        char x;
        cin >> x;

        if(isPresent(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
