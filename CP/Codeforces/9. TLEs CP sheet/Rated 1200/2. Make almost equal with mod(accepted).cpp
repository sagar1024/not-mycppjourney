// B. Make Almost Equal With Mod

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a1,a2,…,an of distinct positive integers. You have to do the following operation exactly once:

// choose a positive integer k;
// for each i from 1 to n, replace ai with ai mod k†.

// Find a value of k such that 1≤k≤1018 and the array a1,a2,…,an contains exactly 2 distinct values at the end of the operation. It can be shown that, under the constraints of the problem, at least one such k always exists. If there are multiple solutions, you can print any of them. Here a mod b denotes the remainder after dividing a by b. For example:

// 7 mod 3=1 since 7=3⋅2+1
// 15 mod 4=3 since 15=4⋅3+3
// 21 mod 1=0 since 21=21⋅1+0

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1017) — the initial state of the array. It is guaranteed that all the ai are distinct. Note that there are no constraints on the sum of n over all test cases.

// Output
// For each test case, output a single integer: a value of k (1≤k≤1018) such that the array a1,a2,…,an contains exactly 2 distinct values at the end of the operation.

// Example
// inputCopy
// 5
// 4
// 8 15 22 30
// 5
// 60 90 98 120 308
// 6
// 328 769 541 986 215 734
// 5
// 1000 2000 7000 11000 16000
// 2
// 2 1
// outputCopy
// 7
// 30
// 3
// 5000
// 1000000000000000000

// Note
// In the first test case, you can choose k=7. The array becomes [8 mod 7,15 mod 7,22 mod 7,30 mod 7]=[1,1,1,2], which contains exactly 2 distinct values ({1,2}).
// In the second test case, you can choose k=30. The array becomes [0,0,8,0,8], which contains exactly 2 distinct values ({0,8}). Note that choosing k=10 would also be a valid solution.
// In the last test case, you can choose k=1018. The array becomes [2,1], which contains exactly 2 distinct values ({1,2}). Note that choosing k=1018+1 would not be valid, because 1≤k≤1018 must be true.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     unordered_set<long long int> remainders;
//     long long int ans = 0;
//     for(long long int k=1; k<1000000000000000000; k++)
//     {
//         for(int i=0; i<n; i++)
//         {
//             int currRemainder = a[i]%k;
//             remainders.insert(currRemainder);
//         }

//         if(remainders.size()==2)
//         {
//             ans = k;
//             break;
//         }
//     }

//     cout << ans << endl;
//     return;
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int f(vector<long long int> &a, long long int k)
{
    unordered_set<long long int> distinctRems;
    for(int i=0; i<a.size(); i++)
    {
        distinctRems.insert(a[i]%k);
    }

    return distinctRems.size();
}

void solve()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i<=57; i++)
    {
        //Left shifting 1, i times
        //Basically k = 2^i
        long long int k = 1ll << i;
        if(f(a,k)==2)
        {
            cout << k << endl;
            return;
        }
    }

    return;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
