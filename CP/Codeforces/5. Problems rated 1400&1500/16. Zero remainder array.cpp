// D. Zero Remainder Array

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a consisting of n positive integers. Initially, you have an integer x=0. During one move, you can do one of the following two operations:

// Choose exactly one i from 1 to n and increase ai by x (ai:=ai+x), then increase x by 1 (x:=x+1).
// Just increase x by 1 (x:=x+1).

// The first operation can be applied no more than once to each i from 1 to n. Your task is to find the minimum number of moves required to obtain such an array that each its element is divisible by k (the value k is given). You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The first line of the test case contains two integers n and k (1≤n≤2⋅105;1≤k≤109) — the length of a and the required divisior. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the i-th element of a. It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer — the minimum number of moves required to obtain such an array that each its element is divisible by k.

// Example
// inputCopy
// 5
// 4 3
// 1 2 1 3
// 10 6
// 8 7 1 8 3 7 5 10 8 9
// 5 10
// 20 100 50 20 100500
// 10 25
// 24 24 24 24 24 24 24 24 24 24
// 8 8
// 1 2 3 4 5 6 7 8
// outputCopy
// 6
// 18
// 0
// 227
// 8

// Note
// Consider the first test case of the example:

// x=0, a=[1,2,1,3]. Just increase x;
// x=1, a=[1,2,1,3]. Add x to the second element and increase x;
// x=2, a=[1,3,1,3]. Add x to the third element and increase x;
// x=3, a=[1,3,3,3]. Add x to the fourth element and increase x;
// x=4, a=[1,3,3,6]. Just increase x;
// x=5, a=[1,3,3,6]. Add x to the first element and increase x;
// x=6, a=[6,3,3,6]. We obtained the required array.

// Note that you can't add x to the same element more than once.

// My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     long long int k;
//     cin >> n >> k;

//     vll givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     int moves = 0;
//     int x = 0;
//     sort(givenArray.begin(), givenArray.end());
//     for(int i=0; i<n; i++)
//     {
//         if(givenArray[i]%k!=0)
//         {
//             while(givenArray[i]%k!=0)
//             {
//                 while(x!=givenArray[i]%k)
//                 {
//                     x++;
//                     moves++;
//                 }

//                 givenArray[i] = x;
//                 x++;
//             }
//         }
//     }

//     cout << moves << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

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
    long long k;
    cin >> n >> k;

    map<long long, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        long long ai;
        cin >> ai;

        ++cnt[ai % k];
    }

    long long ans = 0;
    for (auto &[key, val] : cnt)
    {
        if (key == 0) continue; //Elements already divisible by k, skip
        ans = max(ans, k * (val - 1) + key + 1);
    }

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
