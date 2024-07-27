// B. K-Sort

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array of integers a of length n. You can apply the following operation any number of times (maybe, zero): First, choose an integer k such that 1≤k≤n and pay k+1 coins. Then, choose exactly k indices such that 1≤i1<i2<…<ik≤n. Then, for each x from 1 to k, increase aix by 1. Find the minimum number of coins needed to make a non-decreasing. That is, a1≤a2≤…≤an.

// Input
// Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤105) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output a single integer — the minimum number of coins needed to make a non-decreasing.

// Example
// inputCopy
// 5
// 3
// 1 7 9
// 5
// 2 1 4 7 6
// 4
// 1 3 2 4
// 1
// 179
// 9
// 344 12 37 60 311 613 365 328 675
// outputCopy
// 0
// 3
// 2
// 0
// 1821

// Note
// In the first test case, a is already sorted, so you don't have to spend any coins.
// In the second test case, the optimal sequence of operations is:
// Choose k=2 and the indices 2 and 5: [2,1,4,7,6]→[2,2,4,7,7]. This costs 3 coins.
// It can be proven that it is not possible to make a non-decreasing by spending less than 3 coins.

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long int> a(n);

        //Vector to store the diff of elements of the array where a[i-1] > a[i]
        vector<long long int> a2;
        long long int currMax = 0;

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            if(currMax<a[i])
            {
                currMax = a[i];
            }
            else
            {
                a2.push_back(currMax-a[i]);
            }
        }

        //MAIN logic
        long long int coins = 0;

        sort(a2.begin(), a2.end());
        int len = a2.size();
        long long int currSum = 0;
        for(int i=0; i<len; i++)
        {
            a2[i] = a2[i] - currSum;
            coins += max(0ll,a2[i])*(len-i+1);
            currSum += a2[i];
        }

        cout << coins << endl;
    }

    return 0;
}

