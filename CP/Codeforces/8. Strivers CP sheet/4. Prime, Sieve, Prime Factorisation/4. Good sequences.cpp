// B. Good Sequences

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Squirrel Liss is interested in sequences. She also has preferences of integers. She thinks n integers a1, a2, ..., an are good. Now she is interested in good sequences. A sequence x1, x2, ..., xk is called good if it satisfies the following three conditions:

// The sequence is strictly increasing, i.e. xi < xi + 1 for each i (1 ≤ i ≤ k - 1).
// No two adjacent elements are coprime, i.e. gcd(xi, xi + 1) > 1 for each i (1 ≤ i ≤ k - 1) (where gcd(p, q) denotes the greatest common divisor of the integers p and q).
// All elements of the sequence are good integers.

// Find the length of the longest good sequence.

// Input
// The input consists of two lines. The first line contains a single integer n (1 ≤ n ≤ 105) — the number of good integers. The second line contains a single-space separated list of good integers a1, a2, ..., an in strictly increasing order (1 ≤ ai ≤ 105; ai < ai + 1).

// Output
// Print a single integer — the length of the longest good sequence.

// Examples
// inputCopy
// 5
// 2 3 4 6 9
// outputCopy
// 4
// inputCopy
// 9
// 1 2 3 5 6 7 8 9 10
// outputCopy
// 4

// Note
// In the first example, the following sequences are examples of good sequences: [2; 4; 6; 9], [2; 4; 6], [3; 9], [6]. The length of the longest good sequence is 4.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int gcd(int a, int b)
// {
//     while (b != 0)
//     {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;   
// }

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for(int i=0; i<n; i++) cin >> a[i];

//     int maxLength = 0;
//     for(int i=0; i<n; i++)
//     {
//         int currNum = a[i];
//         int length = 0;
//         for(int j=i+1; j<n; j++)
//         {
//             if(currNum<a[j] && gcd(currNum,a[j])>1)
//             {
//                 length++;
//                 currNum = a[j];
//             }
//         }
//         maxLength = max(length, maxLength);
//     }

//     cout << maxLength+1 << endl;
//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;   
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    //Let's define dp[x] as the maximal value of the length of the good sequence whose last element is x
    vector<int> dp(n+1, 1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            //The numbers are increasing by default(given)
            if(gcd(a[i],a[j])>1)
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int maxLen = *max_element(dp.begin(), dp.end());
    cout << maxLen << endl;

    return 0;
}
