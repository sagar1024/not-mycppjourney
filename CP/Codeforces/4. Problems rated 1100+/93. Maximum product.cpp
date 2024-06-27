// B. Maximum Product

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// You are given an array of integers a1,a2,…,an. Find the maximum possible value of aiajakalat among all five indices (i,j,k,l,t) (i<j<k<l<t).

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤2⋅104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (5≤n≤105) — the size of the array. The second line of each test case contains n integers a1,a2,…,an (−3×103≤ai≤3×103) — given array. It's guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print one integer — the answer to the problem.

// Example
// inputCopy
// 4
// 5
// -1 -2 -3 -4 -5
// 6
// -1 -2 -3 1 2 -1
// 6
// -1 0 0 0 -1 -1
// 6
// -9 -7 -5 -3 -2 1

// outputCopy
// -120
// 12
// 0
// 945

// Note
// In the first test case, choosing a1,a2,a3,a4,a5 is a best choice: (−1)⋅(−2)⋅(−3)⋅(−4)⋅(−5)=−120.
// In the second test case, choosing a1,a2,a3,a5,a6 is a best choice: (−1)⋅(−2)⋅(−3)⋅2⋅(−1)=12.
// In the third test case, choosing a1,a2,a3,a4,a5 is a best choice: (−1)⋅0⋅0⋅0⋅(−1)=0.
// In the fourth test case, choosing a1,a2,a3,a4,a6 is a best choice: (−9)⋅(−7)⋅(−5)⋅(−3)⋅1=945.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a1(n);
    vector<int> a2(n);
    vector<long long int> dp(200005);
    bool allNegative = true;
    bool allPositive = true;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        a1[i] = x;
        a2[i] = abs(x);
        if(x>=0)
        {
            allNegative = false;
        }
        if(x<0)
        {
            allPositive = false;
        }
    }

    sort(a1.begin(), a1.end());
    if(allNegative)
    {
        int answer = a1[0]*a1[1]*a1[2]*a1[3]*a1[4];
        cout << answer << endl;
        return;
    }

    // vector<int> reqIntegers;
    // int j = n-1;
    // for(int i=0; i<n; i++)
    // {
    //     if(a1[i]==a2[j])
    //     {
    //         reqIntegers.push_back(a1[i]);
    //         j--;
    //     }
    // }
    // long long int answer = 1;
    // for(int i=0; i<reqIntegers.size(); i++)
    // {
    //     answer *= reqIntegers[i];
    // }

    sort(a2.begin(), a2.end());
    int count = 0;
    int answer = 1;
    for(int i=n-1; i>=0; i--)
    {
        answer *= a2[i];
        count++;
        if(count>=5)
        {
            if(answer>=0)
            {
                cout << answer << endl;
                return;
            }
            else
            {
                answer = answer/a2[i];   
            }
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
