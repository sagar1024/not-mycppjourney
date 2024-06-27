// C. Watto and Mechanism

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Watto, the owner of a spare parts store, has recently got an order for the mechanism that can process strings in a certain way. Initially the memory of the mechanism is filled with n strings. Then the mechanism should be able to process queries of the following type: "Given string s, determine if the memory of the mechanism contains string t that consists of the same number of characters as s and differs from s in exactly one position". Watto has already compiled the mechanism, all that's left is to write a program for it and check it on the data consisting of n initial lines and m queries. He decided to entrust this job to you.

// Input
// The first line contains two non-negative numbers n and m (0 ≤ n ≤ 3·105, 0 ≤ m ≤ 3·105) — the number of the initial strings and the number of queries, respectively. Next follow n non-empty strings that are uploaded to the memory of the mechanism. Next follow m non-empty strings that are the queries to the mechanism. The total length of lines in the input doesn't exceed 6·105. Each line consists only of letters 'a', 'b', 'c'.

// Output
// For each query print on a single line "YES" (without the quotes), if the memory of the mechanism contains the required string, otherwise print "NO" (without the quotes).

// Examples
// inputCopy
// 2 3
// aaaaa
// acacaca
// aabaa
// ccacacc
// caaac
// outputCopy
// YES
// NO
// NO

// My original soln(tle on tc9) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long long int N = 1e9+7;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<string> memory(n);
//     for(int i=0; i<n; i++) cin >> memory[i];

//     //Queries
//     while(m--)
//     {
//         string query;
//         cin >> query;

//         //Counting the num of different letters
//         //If count is 1, then output yes else no
//         int count = 0;
//         for(int i=0; i<n; i++)
//         {
//             count = 0;
//             if(query.size()==memory[i].size())
//             {
//                 for(int j=0; j<query.size(); j++)
//                 {
//                     if(query[j]!=memory[i][j])
//                     {
//                         count++;
//                     }
//                 }
//             }
//             if(count==1)
//             {
//                 cout << "YES" << endl;
//                 break;
//             }
//         }
//         if(count==1)
//         {
//             continue;
//         }
//         cout << "NO" << endl;
//     }

//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate approach(mle on tc18) -

// To solve the problem efficiently, we need to preprocess the memory strings in a way that allows quick lookups for the queries. The idea is to leverage a hash map to store variations of each memory string, where each variation has one character replaced by a wildcard. This will allow us to efficiently check if any of these variations match a query string with exactly one differing character. Here's the step-by-step approach:

// Preprocess Memory Strings: For each string in memory, generate all possible variations by replacing each character one at a time with a wildcard (e.g., *). Store these variations in a hash map where the key is the variation and the value is a list of original strings that can generate this variation.

// Query Processing: For each query string, generate all possible variations by replacing each character one at a time with a wildcard. Check if any of these variations exist in the hash map. If found, it means there exists a memory string that differs by exactly one character.

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long long int N = 1e9+7;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<string> memory(n);
//     unordered_map<string, vector<string>> memory_map;

//     //Reading memory strings
//     //AND mapping variations of each string to itself
//     for(int i=0; i<n; i++)
//     {
//         cin >> memory[i];

//         int len = memory[i].size();
//         for(int j=0; j<len; j++)
//         {
//             string variation = memory[i];
//             variation[j] = '*'; //Wildcard character
//             memory_map[variation].push_back(memory[i]);
//         }
//     }

//     //Processing queries
//     while(m--)
//     {
//         string query;
//         cin >> query;

//         int len = query.size();
//         bool found = false;
//         for(int i=0; i<len; i++)
//         {
//             string variation = query;
//             variation[i] = '*';

//             if(memory_map.find(variation)!=memory_map.end())
//             {
//                 for(const string &memo: memory_map[variation])
//                 {
//                     int count = 0;
//                     for(int j=0; j<len; j++)
//                     {
//                         if(memo[j]!=query[j])
//                         {
//                             count++;
//                         }
//                     }
//                     if(count==1)
//                     {
//                         found = true;
//                         break;
//                     }
//                 }
//             }

//             if(found) break;
//         }

//         if(found) cout << "YES" << endl;
//         else cout << "NO" << endl;
//     }

//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate soln(using polynomial hashing) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

const long long int N = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    return;
}

int32_t main()
{
    solve();
    return 0;
}
