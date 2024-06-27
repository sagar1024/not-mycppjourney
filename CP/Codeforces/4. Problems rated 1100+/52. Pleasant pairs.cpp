// B. Pleasant Pairs

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a1,a2,…,an consisting of n distinct integers. Count the number of pairs of indices (i,j) such that i<j and ai⋅aj=i+j.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t cases follow. The first line of each test case contains one integer n (2≤n≤105) — the length of array a. The second line of each test case contains n space separated integers a1,a2,…,an(1≤ai≤2⋅n) — the array a. It is guaranteed that all elements are distinct. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the number of pairs of indices (i,j) such that i<j and ai⋅aj=i+j.

// Example
// inputCopy
// 3
// 2
// 3 1
// 3
// 6 1 5
// 5
// 3 1 5 9 2
// outputCopy
// 1
// 1
// 3

// Note
// For the first test case, the only pair that satisfies the constraints is (1,2), as a1⋅a2=1+2=3
// For the second test case, the only pair that satisfies the constraints is (2,3).
// For the third test case, the pairs that satisfy the constraints are (1,2), (1,5), and (2,3).

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(a[i]*a[j] == (i+1)+(j+1))
//             {
//                 count++;
//             }
//         }
//     }

//     cout << count << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        freq[a[i]] = i + 1;
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j * j <= 2 * n; ++j)
        {
            if ((i + 1) % j == 0)
            {
                int x = (i + 1) / j;
                if (freq.count(j) && freq[j] * freq[a[i]] == i + 1 + freq[j] * a[i])
                {
                    count++;
                }
                if (x != j && freq.count(x) && freq[x] * freq[a[i]] == i + 1 + freq[x] * a[i])
                {
                    count++;
                }
            }
        }
    }

    cout << count / 2 << endl;
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
