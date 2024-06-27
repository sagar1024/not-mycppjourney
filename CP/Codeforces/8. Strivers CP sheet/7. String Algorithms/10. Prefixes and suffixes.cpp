// D. Prefixes and Suffixes

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have a string s = s1s2...s|s|, where |s| is the length of string s, and si its i-th character. Let's introduce several definitions: A substring s[i..j] (1 ≤ i ≤ j ≤ |s|) of string s is string sisi + 1...sj. The prefix of string s of length l (1 ≤ l ≤ |s|) is string s[1..l]. The suffix of string s of length l (1 ≤ l ≤ |s|) is string s[|s| - l + 1..|s|]. Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

// Input
// The single line contains a sequence of characters s1s2...s|s| (1 ≤ |s| ≤ 105) — string s. The string only consists of uppercase English letters.

// Output
// In the first line, print integer k (0 ≤ k ≤ |s|) — the number of prefixes that match a suffix of string s. Next print k lines, in each line print two integers li ci. Numbers li ci mean that the prefix of the length li matches the suffix of length li and occurs in string s as a substring ci times. Print pairs li ci in the order of increasing li.

// Examples
// inputCopy
// ABACABA
// outputCopy
// 3
// 1 4
// 3 2
// 7 1
// inputCopy
// AAA
// outputCopy
// 3
// 1 3
// 2 2
// 3 1

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> calcPrefixFunc(const string &s)
{
    int n = s.size();
    vector<int> pi(n,0);

    //Implementation

    return pi;
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pi = calcPrefixFunc(s);

    int numOfMatch = 0;
    vector<pair<int,int>> ans;
    for(int i=0; i<n; i++)
    {
        numOfMatch = max(numOfMatch, pi[i]);
    }

    //Further implementation

    return 0;
}
