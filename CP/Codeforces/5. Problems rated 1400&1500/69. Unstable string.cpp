// C. Unstable String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s consisting of the characters 0, 1, and ?. Let's call a string unstable if it consists of the characters 0 and 1 and any two adjacent characters are different (i. e. it has the form 010101... or 101010...). Let's call a string beautiful if it consists of the characters 0, 1, and ?, and you can replace the characters ? to 0 or 1 (for each character, the choice is independent), so that the string becomes unstable. For example, the strings 0??10, 0, and ??? are beautiful, and the strings 00 and ?1??1 are not. Calculate the number of beautiful contiguous substrings of the string s.

// Input
// The first line contains a single integer t (1≤t≤104) — number of test cases. The first and only line of each test case contains the string s (1≤|s|≤2⋅105) consisting of characters 0, 1, and ?. It is guaranteed that the sum of the string lengths over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the number of beautiful substrings of the string s.

// Example
// inputCopy
// 3
// 0?10
// ???
// ?10??1100

// outputCopy
// 8
// 6
// 25

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

bool unstableString(string s)
{
    bool unstable = true;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i-1]==s[i])
        {
            unstable = false;
        }
    }

    return unstable;
}

void solve()
{
    string s1;
    cin >> s1;

    string s2 = s1;

    int n = s1.size();
    int count = 0;

    //Assigning the string s1's "?" to 0
    for(int i=0; i<n; i++)
    {
        if(s1[i]=='?')
        {
            s1[i] = '0';
        }
    }

    //Now counting the num of unstable strings
    for(int i=0; i<n; i++)
    {
        string currString;
        for(int j=i; j<n; j++)
        {
            currString += s1[j];
            if(unstableString(currString))
            {
                count++;
            }
        }
    }

    //Assigning string s2's "?" to 1
    for(int i=0; i<n; i++)
    {
        if(s2[i]=='?')
        {
            s2[i] = '1';
        }
    }

    //Now counting the num of unstable strings
    for(int i=0; i<n; i++)
    {
        string currString;
        for(int j=i; j<n; j++)
        {
            currString += s2[j];
            if(unstableString(currString))
            {
                count++;
            }
        }
    }

    cout << count << endl;
    
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
