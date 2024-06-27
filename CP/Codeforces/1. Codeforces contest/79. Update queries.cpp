// C. Update Queries

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's consider the following simple problem. You are given a string s of length n, consisting of lowercase Latin letters, as well as an array of indices ind of length m (1≤indi≤n) and a string c of length m, consisting of lowercase Latin letters. Then, in order, you perform the update operations, namely, during the i-th operation, you set sindi=ci. Note that you perform all m operations from the first to the last. Of course, if you change the order of indices in the array ind and/or the order of letters in the string c, you can get different results. Find the lexicographically smallest string s that can be obtained after m update operations, if you can rearrange the indices in the array ind and the letters in the string c as you like. A string a is lexicographically less than a string b if and only if one of the following conditions is met:

// a is a prefix of b, but a≠b;
// in the first position where a and b differ, the symbol in string a is earlier in the alphabet than the corresponding symbol in string b.

// Input
// Each test consists of several sets of input data. The first line contains a single integer t (1≤t≤104) — the number of sets of input data. Then follows their description. The first line of each set of input data contains two integers n and m (1≤n,m≤105) — the length of the string s and the number of updates. The second line of each set of input data contains a string s of length n, consisting of lowercase Latin letters. The third line of each set of input data contains m integers ind1,ind2,…,indm (1≤indi≤n) — the array of indices ind. The fourth line of each set of input data contains a string c of length m, consisting of lowercase Latin letters. It is guaranteed that the sum of n over all sets of input data does not exceed 2⋅105. Similarly, the sum of m over all sets of input data does not exceed 2⋅105.

// Output
// For each set of input data, output the lexicographically smallest string s that can be obtained by rearranging the indices in the array ind and the letters in the string c as you like.

// Example
// inputCopy
// 4
// 1 2
// a
// 1 1
// cb
// 4 4
// meow
// 1 2 1 4
// zcwz
// 7 4
// abacaba
// 1 3 5 7
// damn
// 7 10
// traktor
// 7 6 5 4 3 2 1 6 4 2
// codeforces
// outputCopy
// b
// cwoz
// abdcmbn
// ccdeefo

// Note
// In the first set of input data, you can leave the array ind and the string c unchanged and simply perform all operations in that order.
// In the second set of input data, you can set the array ind=[1,1,4,2] and c= "zczw". Then the string s will change as follows: meow→zeow→ceow→ceoz→cwoz.
// In the third set of input data, you can leave the array ind unchanged and set c= "admn". Then the string s will change as follows: abacaba→abacaba→abdcaba→abdcmba→abdcmbn.

//Original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     //String length and num of ops
//     int n, m;
//     cin >> n >> m;

//     string s;
//     cin >> s;

//     vector<int> idx(m);
//     for (int i = 0; i < m; ++i)
//     {
//         cin >> idx[i];
//         idx[i]--; //0-based index
//     }

//     string c;
//     cin >> c;

//     string ans = s;
//     for(int i=0; i<m; i++)
//     {
//         int x = ans[idx[i]]-'a';
//         int y = c[i]-'a';
//         ans[idx[i]] = min(x,y) + 'a';
//     }

//     cout << ans << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln(wrong on last tc) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //String length and number of operations
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> idx(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> idx[i];
        idx[i]--; //Convert to 0-based index
    }

    string c;
    cin >> c;

    sort(c.begin(), c.end());

    //Create a map from index to vector of characters to place at that index
    unordered_map<int, vector<char>> char_map;
    for (int i = 0; i < m; ++i)
    {
        char_map[idx[i]].push_back(c[i]);
    }

    for (auto &entry : char_map)
    {
        sort(entry.second.begin(), entry.second.end());
    }

    string result = s;
    for (auto &entry : char_map)
    {
        int index = entry.first;
        result[index] = entry.second.front(); //Take the smallest character
    }

    cout << result << endl;

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
