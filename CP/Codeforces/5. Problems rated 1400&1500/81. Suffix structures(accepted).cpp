// B. Suffix Structures

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Bizon the Champion isn't just a bison. He also is a favorite of the "Bizons" team. At a competition the "Bizons" got the following problem: "You are given two distinct words (strings of English letters), s and t. You need to transform word s into word t". The task looked simple to the guys because they know the suffix data structures well. Bizon Senior loves suffix automaton. By applying it once to a string, he can remove from this string any single character. Bizon Middle knows suffix array well. By applying it once to a string, he can swap any two characters of this string. The guys do not know anything about the suffix tree, but it can help them do much more. Bizon the Champion wonders whether the "Bizons" can solve the problem. Perhaps, the solution do not require both data structures. Find out whether the guys can solve the problem and if they can, how do they do it? Can they solve it either only with use of suffix automaton or only with use of suffix array or they need both structures? Note that any structure may be used an unlimited number of times, the structures may be used in any order.

// Input
// The first line contains a non-empty word s. The second line contains a non-empty word t. Words s and t are different. Each word consists only of lowercase English letters. Each word contains at most 100 letters.

// Output
// In the single line print the answer to the problem. Print "need tree" (without the quotes) if word s cannot be transformed into word t even with use of both suffix array and suffix automaton. Print "automaton" (without the quotes) if you need only the suffix automaton to solve the problem. Print "array" (without the quotes) if you need only the suffix array to solve the problem. Print "both" (without the quotes), if you need both data structures to solve the problem. It's guaranteed that if you can solve the problem only with use of suffix array, then it is impossible to solve it only with use of suffix automaton. This is also true for suffix automaton.

// Examples
// inputCopy
// automaton
// tomat
// outputCopy
// automaton

// inputCopy
// array
// arary
// outputCopy
// array

// inputCopy
// both
// hot
// outputCopy
// both

// inputCopy
// need
// tree
// outputCopy
// need tree

// Note
// In the third sample you can act like that: first transform "both" into "oth" by removing the first character using the suffix automaton and then make two swaps of the string using the suffix array and get "hot".

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    bool sau = false;
    bool sar = true;
    bool both = true;

    //For the 1st problem
    //Using two pointers approach
    for(int i=0, j=0; i<n; i++)
    {
        if(s[i]==t[j] && j<m)
        {
            j++;
        }
        if(j==m)
        {
            sau = true;
        }
    }

    //For 2nd and 3rd problem
    //Freq array for the string's letters
    vector<int> freq(30,0);
    for(int i=0; i<n; i++)
    {
        freq[s[i]-'a']++;
    }
    for(int i=0; i<m; i++)
    {
        //Great logic
        //Solves both 2nd and 3rd type of problem
        //Nulls the freq of string s letters
        //If all elements becomes 0, then we only need rearranging
        //If some elements are not zero, then we need both
        //That is, elimination as well as rearranging
        freq[t[i]-'a']--;
    }

    for(int i=0; i<26; i++)
    {
        sar = sar & (freq[i]==0);
        both = both & (freq[i]>=0);
    }

    if(sau) cout << "automaton" << endl;
    else if(sar) cout << "array" << endl;
    else if(both) cout << "both" << endl;
    else cout << "need tree" << endl;

    return 0;
}

