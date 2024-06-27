// B. Ilya and Queries

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ilya the Lion wants to help all his friends with passing exams. They need to solve the following problem to pass the IT exam. You've got string s = s1s2... sn (n is the length of the string), consisting only of characters "." and "#" and m queries. Each query is described by a pair of integers li, ri (1 ≤ li < ri ≤ n). The answer to the query li, ri is the number of such integers i (li ≤ i < ri), that si = si + 1. Ilya the Lion wants to help his friends but is there anyone to help him? Help Ilya, solve the problem.

// Input
// The first line contains string s of length n (2 ≤ n ≤ 105). It is guaranteed that the given string only consists of characters "." and "#". The next line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains the description of the corresponding query. The i-th line contains integers li, ri (1 ≤ li < ri ≤ n).

// Output
// Print m integers — the answers to the queries in the order in which they are given in the input.

// Examples
// inputCopy
// ......
// 4
// 3 4
// 2 3
// 1 6
// 2 6
// outputCopy
// 1
// 1
// 5
// 4
// inputCopy
// #..###
// 5
// 1 3
// 5 6
// 1 5
// 3 6
// 3 4
// outputCopy
// 1
// 1
// 2
// 2
// 0

//My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     int m;
//     cin >> m;

//     vector<pair<int, int>> queries(m, {0,0});
//     for(int i=0; i<m; i++)
//     {
//         cin >> queries[i].first >> queries[i].second;
//     }

//     //MAIN logic

//     int reqInteger = 0;
//     int count = 0;
//     int maxCount = INT_MIN;
//     int n = s.size();
//     int totalSum = 0;

//     // for(int i=0; i<s.size(); i++)
//     // {
//     //     for(int j=queries[i].first-1; j<queries[i].second-1; j++)
//     //     {
//     //         if(s[j]==s[j+1])
//     //         {
//     //             count++;
//     //             maxCount = max(count, maxCount);
//     //         }
//     //         else
//     //         {
//     //             count = 0;
//     //         }
//     //     }

//     //     cout << maxCount << endl;
//     // }

//     //Precalculating array A
//     vector<int> A(n, 0);
//     for (int i = 1; i < n; i++)
//     {
//         if (s[i - 1] == s[i])
//         {
//             A[i] = 1;
//         }
//     }

//     for(int i=0; i<m; i++)
//     {
//         for(int j=queries[i].first; j<queries[i].second; j++)
//         {
//             // if(s[j]==s[j+1])
//             // {
//             //     count++;
//             //     maxCount = max(count, maxCount);
//             // }
//             // else
//             // {
//             //     count = 0;
//             // }

//             totalSum += A[j];
//         }

//         cout << totalSum << endl;

//         //Resetting total sum
//         totalSum = 0;
//     }

//     return 0;
// }

//Alternate soln(optimized) -

//Using a prefix sum array
//To calculate the cumulative sum of the array A
//This will avoid the need for nested loops

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int m;
    cin >> m;

    int n = s.size();

    // Precalculate array A
    vector<int> A(n, 0);
    for (int i=1; i<n; i++)
    {
        if (s[i-1] == s[i])
        {
            A[i] = 1;
        }
    }

    // Precalculate prefix sum array
    vector<int> prefixSum(n, 0);
    prefixSum[0] = A[0];
    for (int i=1; i<n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    // Process queries
    for (int i=0; i<m; i++)
    {
        int l, r;
        cin >> l >> r;

        // Calculate sum of the interval (l, r)
        int result = prefixSum[r-1] - (l>1 ? prefixSum[l-1] : 0);

        cout << result << endl;
    }

    return 0;
}
