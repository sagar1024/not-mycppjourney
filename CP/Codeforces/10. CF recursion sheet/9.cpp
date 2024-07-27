// I. Count Vowels

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a string S. Print number of vowels in the string. Note: Vowel letters: ['a', 'e', 'i', 'o', 'u']. Vowel letters could be capital or small. Solve this problem using recursion.

// Input
// Only one line containing a string S (1 ≤ |S| ≤ 200) where |S| is the length of the string and it consists only of capital, small letters and spaces.

// Output
// Print number of vowels in string S.

// Example
// inputCopy
// Data Structure Lab
// outputCopy
// 6

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        return true;
    }
    return false;
}

void calcVowels(string s, int idx, int &ans)
{
    if(idx==0)
    {
        return;
    }

    calcVowels(s,idx-1,ans);
    if(isVowel(s[idx-1])) ans++;
    return;
}

int32_t main()
{
    string s;
    //cin >> s;
    getline(cin, s);

    int n = s.size();
    int ans = 0;
    calcVowels(s,n,ans);
    cout << ans << endl;

    return 0;
}
