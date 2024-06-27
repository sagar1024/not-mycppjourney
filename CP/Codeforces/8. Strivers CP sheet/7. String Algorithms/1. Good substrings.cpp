// D. Good Substrings

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// You've got string s, consisting of small English letters. Some of the English letters are good, the rest are bad. A substring s[l...r] (1 ≤ l ≤ r ≤ |s|) of string s  =  s1s2...s|s| (where |s| is the length of string s) is string  slsl + 1...sr. The substring s[l...r] is good, if among the letters  sl, sl + 1, ..., sr there are at most k bad ones (look at the sample's explanation to understand it more clear). Your task is to find the number of distinct good substrings of the given string s. Two substrings s[x...l] and s[p...q] are considered distinct if their content is different, i.e. s[x...l] ≠ s[p...q].

// Input
// The first line of the input is the non-empty string s, consisting of small English letters, the string's length is at most 1500 characters. The second line of the input is the string of characters "0" and "1", the length is exactly 26 characters. If the i-th character of this string equals "1", then the i-th English letter is good, otherwise it's bad. That is, the first character of this string corresponds to letter "a", the second one corresponds to letter "b" and so on. The third line of the input consists a single integer k (0 ≤ k ≤ |s|) — the maximum acceptable number of bad characters in a good substring.

// Output
// Print a single integer — the number of distinct good substrings of string s.

// Examples
// inputCopy
// ababab
// 01000000000000000000000000
// 1
// outputCopy
// 5
// inputCopy
// acbacbacaa
// 00000000000000000000000000
// 2
// outputCopy
// 8

// Note
// In the first example there are following good substrings: "a", "ab", "b", "ba", "bab".
// In the second example there are following good substrings: "a", "aa", "ac", "b", "ba", "l", "ca", "cb".

//My original soln(tle on tc8) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long long int N = 1e9+7;

// void solve()
// {
//     string s;
//     cin >> s;

//     string goodOrBad;
//     cin >> goodOrBad;

//     vector<int> badLetters;
//     for(int i=0; i<goodOrBad.size(); i++)
//     {
//         if(goodOrBad[i]=='0')
//         {
//             badLetters.push_back(i+'a');
//         }
//     }

//     int k;
//     cin >> k;

//     //Checking the num of bad char in each substring
//     //AND counting the num of substrings who have less than or equal to k bad chars
//     //INSTEAD we will store the good substrings in a set as distinct substrings
//     set<string> goodSubstrings;
//     int count = 0;
//     for(int i=0; i<s.size(); i++)
//     {
//         string x;
//         for(int j=i; j<s.size(); j++)
//         {
//             int badCharCount = 0;
//             x += s[j];
//             for(int l=0; l<x.size(); l++)
//             {
//                 if(find(badLetters.begin(), badLetters.end(), x[l])!=badLetters.end())
//                 {
//                     badCharCount++;
//                 }
//             }
//             if(badCharCount<=k)
//             {
//                 goodSubstrings.insert(x);
//             }
//         }
//     }

//     int ans = goodSubstrings.size();

//     cout << ans << endl;
//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

//Alternate approach -

