// B. Phoenix and Beauty

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Phoenix loves beautiful arrays. An array is beautiful if all its subarrays of length k have the same sum. A subarray of an array is any sequence of consecutive elements. Phoenix currently has an array a of length n. He wants to insert some number of integers, possibly zero, into his array such that it becomes beautiful. The inserted integers must be between 1 and n inclusive. Integers may be inserted anywhere (even before the first or after the last element), and he is not trying to minimize the number of inserted integers.

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤50) — the number of test cases. The first line of each test case contains two integers n and k (1≤k≤n≤100). The second line of each test case contains n space-separated integers (1≤ai≤n) — the array that Phoenix currently has. This array may or may not be already beautiful.

// Output
// For each test case, if it is impossible to create a beautiful array, print -1. Otherwise, print two lines. The first line should contain the length of the beautiful array m (n≤m≤104). You don't need to minimize m. The second line should contain m space-separated integers (1≤bi≤n) — a beautiful array that Phoenix can obtain after inserting some, possibly zero, integers into his array a. You may print integers that weren't originally in array a. If there are multiple solutions, print any. It's guaranteed that if we can make array a beautiful, we can always make it with resulting length no more than 104.

// Example
// inputCopy
// 4
// 4 2
// 1 2 2 1
// 4 3
// 1 2 2 1
// 3 2
// 1 2 3
// 4 4
// 4 3 4 2
// outputCopy
// 5
// 1 2 1 2 1
// 4
// 1 2 2 1
// -1
// 7
// 4 3 2 1 4 3 2

// Note
// In the first test case, we can make array a beautiful by inserting the integer 1 at index 3 (in between the two existing 2s). Now, all subarrays of length k=2 have the same sum 3. There exists many other possible solutions, for example:
// 2,1,2,1,2,1
// 1,2,1,2,1,2

// In the second test case, the array is already beautiful: all subarrays of length k=3 have the same sum 5.
// In the third test case, it can be shown that we cannot insert numbers to make array a beautiful.
// In the fourth test case, the array b shown is beautiful and all subarrays of length k=4 have the same sum 10. There exist other solutions also.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i, n) for (int i = 0; i < n; i++)

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     int sum = 0;
//     for(int i=0; i<n-k; i++)
//     {
//         for(int j=i; j<=k; j++)
//         {
//             sum += givenArray[j];
//         }

//         if(sum>=k)
//         {
//             cout << "-1" << endl;
//             return;
//         }
//     }

//     //How do I insert elements between array elements?
//     //So that the sliding window sum at each step is equal to k?

//     return;
// }

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> givenArray(n);
    for (int i = 0; i < n; i++)
    {
        cin >> givenArray[i];
    }

    // Calculate the frequency of each element in the given array
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[givenArray[i]]++;
    }

    // Check if there is at least one element that appears k times
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == k)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        // If there is an element that appears k times, the array is already beautiful
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << givenArray[i] << " ";
        }
        cout << endl;
    }
    else
    {
        // Otherwise, we need to insert elements to make the array beautiful
        // Let's insert an element at each position
        cout << n * (k - 1) << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k - 1; j++)
            {
                cout << "1 ";
            }
            cout << givenArray[i] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
