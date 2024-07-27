// B. Substring and Subsequence

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two strings a and b, both consisting of lowercase Latin letters. A subsequence of a string is a string which can be obtained by removing several (possibly zero) characters from the original string. A substring of a string is a contiguous subsequence of that string. For example, consider the string abac:
// a, b, c, ab, aa, ac, ba, bc, aba, abc, aac, bac and abac are its subsequences;
// a, b, c, ab, ba, ac, aba, bac and abac are its substrings.

// Your task is to calculate the minimum possible length of the string that contains a as a substring and b as a subsequence.

// Input
// The first line contains a single integer t (1≤t≤103) — the number of test cases. The first line of each test case contains a string a (1≤|a|≤100), consisting of lowercase Latin letters. The second line of each test case contains a string b (1≤|b|≤100), consisting of lowercase Latin letters.

// Output
// For each test case, print a single integer — the minimum possible length of the string that contains a as a substring and b as a subsequence.

// Example
// inputCopy
// 5
// aba
// cb
// er
// cf
// mmm
// mmm
// contest
// test
// cde
// abcefg
// outputCopy
// 4
// 4
// 3
// 7
// 7

// Note
// In the examples below, the characters that correspond to the subsequence equal to b are bolded.
// In the first example, one of the possible answers is caba.
// In the second example, one of the possible answers is ercf.
// In the third example, one of the possible answers is mmm.
// In the fourth example, one of the possible answers is contest.
// In the fifth example, one of the possible answers is abcdefg.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //Substring a, subsequence b
    string a, b;
    cin >> a >> b;

    vector<int> freq(30);
    for(int i=0; i<a.size(); i++)
    {
        freq[a[i]-'a']++;
    }
    for(int i=0; i<b.size(); i++)
    {
        freq[b[i]-'a']--;
    }

    int uncommonChars = 0;
    for(int i=0; i<30; i++)
    {
        uncommonChars += abs(freq[i]);
    }

    //Common ele
    int commonChars = (a.size() + b.size() - uncommonChars)/2;

    int ans = uncommonChars + commonChars;
    cout << ans << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
