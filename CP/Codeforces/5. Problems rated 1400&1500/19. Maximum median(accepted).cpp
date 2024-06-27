// C. Maximum Median

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a of n integers, where n is odd. You can make the following operation with it: Choose one of the elements of the array (for example ai) and increase it by 1 (that is, replace it with ai+1). You want to make the median of the array the largest possible using at most k operations. The median of the odd-sized array is the middle element after the array is sorted in non-decreasing order. For example, the median of the array [1,5,2,3,5] is 3.

// Input
// The first line contains two integers n and k (1≤n≤2⋅105, n is odd, 1≤k≤109) — the number of elements in the array and the largest number of operations you can make. The second line contains n integers a1,a2,…,an (1≤ai≤109).

// Output
// Print a single integer — the maximum possible median after the operations.

// Examples
// inputCopy
// 3 2
// 1 3 5
// outputCopy
// 5

// inputCopy
// 5 5
// 1 2 1 1 1
// outputCopy
// 3

// inputCopy
// 7 7
// 4 1 2 4 3 4 4
// outputCopy
// 5

// Note
// In the first example, you can increase the second element twice. Than array will be [1,5,5] and it's median is 5.
// In the second example, it is optimal to increase the second number and than increase third and fifth. This way the answer is 3.
// In the third example, you can make four operations: increase first, fourth, sixth, seventh element. This way the array will be [5,1,2,5,3,5,5] and the median will be 5.

// My original soln -

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

//     sort(givenArray.begin(), givenArray.end());
//     int medianIdx = ((n+1)/2)-1;

//     vll cumulativeSum;
//     long long int currSum = 0;
//     for(int i=medianIdx+1; i<n; i++)
//     {
//         currSum += abs(givenArray[medianIdx] - givenArray[i]);
//         cumulativeSum.push_back(currSum);
//     }

//     int maxMedian = givenArray[medianIdx];
//     int x = 0;
//     while(k>0 && x<cumulativeSum.size())
//     {
//         //maxMedian += givenArray[medianIdx] + cumulativeSum[x];
//         maxMedian += cumulativeSum[x];
//         k -= cumulativeSum[x];
//         x++;
//     }

//     cout << maxMedian << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

// Alternate soln -

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

//     sort(givenArray.begin(), givenArray.end());
//     int medianIndex = ((n+1)/2)-1;
//     int median = givenArray[medianIndex];
//     int i = 1;
//     while(k>0 && i<n-medianIndex)
//     {
//         median += givenArray[medianIndex+i] - median;
//         k -= (givenArray[medianIndex+i] - median)*i;
//         i++;
//     }

//     cout << median << endl;
//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k;
vector<ll> a;
bool check(ll x)
{
    ll moves = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (x - a[i] > 0)
            moves += x - a[i];
        if (moves > k)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        a.push_back(x);
    }

    sort(a.begin(), a.end());
    ll small = 1;
    ll big = 2e9;
    while (small != big)
    {
        ll mid = (small + big + 1) / 2;
        if (check(mid))
        {
            small = mid;
        }
        else
        {
            big = mid - 1;
        }
    }

    cout << small << endl;

    return 0;
}
