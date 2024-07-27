// E. Binary Deque

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Slavic has an array of length n consisting only of zeroes and ones. In one operation, he removes either the first or the last element of the array. What is the minimum number of operations Slavic has to perform such that the total sum of the array is equal to s after performing all the operations? In case the sum s can't be obtained after any amount of operations, you should output -1.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two integers n and s (1≤n,s≤2⋅105) — the length of the array and the needed sum of elements. The second line of each test case contains n integers ai (0≤ai≤1) — the elements of the array. It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// For each test case, output a single integer — the minimum amount of operations required to have the total sum of the array equal to s, or -1 if obtaining an array with sum s isn't possible.

// Example
// inputCopy
// 7
// 3 1
// 1 0 0
// 3 1
// 1 1 0
// 9 3
// 0 1 0 1 1 1 0 0 1
// 6 4
// 1 1 1 1 1 1
// 5 1
// 0 0 1 1 0
// 16 2
// 1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
// 6 3
// 1 0 1 0 0 0
// outputCopy
// 0
// 1
// 3
// 2
// 2
// 7
// -1

// Note
// In the first test case, the sum of the whole array is 1 from the beginning, so we don't have to make any operations.
// In the second test case, the sum of the array is 2 and we want it to be equal to 1, so we should remove the first element. The array turns into [1,0], which has a sum equal to 1.
// In the third test case, the sum of the array is 5 and we need it to be 3. We can obtain such a sum by removing the first two elements and the last element, doing a total of three operations. The array turns into [0,1,1,1,0,0], which has a sum equal to 3.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n, sum;
//     cin >> n >> sum;

//     vector<int> a(n);
//     int currSum = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         currSum += a[i];
//     }

//     int minOps = 0; //If current sum = required sum, then minOps = 0
//     int left = 0, right = n-1;
//     if(currSum>sum)
//     {
//         while(left<right && currSum>sum)
//         {
//             if(a[left]==1)
//             {
//                 currSum--;
//                 left++;
//                 minOps++;
//             }
//             else if(a[right]==1)
//             {
//                 currSum--;
//                 right--;
//                 minOps++;
//             }
//             else if(a[left]==0)
//             {
//                 if(a[right]==1)
//                 {
//                     currSum--;
//                     right--;
//                     minOps++;
//                     continue;
//                 }
//                 left++;
//                 minOps++;
//             }
//             else if(a[right]==0)
//             {
//                 if(a[left]==1)
//                 {
//                     currSum--;
//                     left++;
//                     minOps++;
//                     continue;
//                 }
//                 right--;
//                 minOps++;
//             }
//         }
//     }
//     else if(currSum<sum)
//     {
//         minOps = -1;
//     }

//     cout << minOps << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln(tle on tc4) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int getSubarraySum(int left, int right, vector<ll int> prefix)
// {
//     return prefix[right] - (left? prefix[left-1]:0);
// }

// void solve()
// {
//     int n, s;
//     cin >> n >> s;

//     vector<ll int> a(n), prefixSum(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         prefixSum[i] = a[i];
//         if(i>0)
//         {
//             prefixSum[i] += prefixSum[i-1];
//         }
//     }

//     int minOps = INT_MAX;

//     //Iterating thru the array to find the min length subarray with the req sum
//     for(int start=0; start<n; start++)
//     {
//         int left=start, right=n-1, bestEnd=-1;
//         while(left<=right)
//         {
//             int mid = (left+right)/2;
//             if(getSubarraySum(start,mid,prefixSum)<=s)
//             {
//                 bestEnd = mid;
//                 left = mid+1;
//             }
//             else
//             {
//                 right = mid-1;
//             }
//         }

//         if(bestEnd!=-1 && getSubarraySum(start,bestEnd,prefixSum)==s)
//         {
//             minOps = min(minOps, n-(bestEnd-start+1));
//         }
//     }

//     cout << (minOps==INT_MAX? -1 : minOps) << endl;

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
#define ll long long

void solve()
{
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int minOps = INT_MAX;
    int left=0, currSum=0;
    for(int right=0; right<n; right++)
    {
        currSum += a[right];
        while(currSum>s && left<=right)
        {
            currSum -= a[left];
            left++;
        }
        if(currSum==s)
        {
            minOps = min(minOps,n-(right-left+1));
        }
    }

    cout << (minOps==INT_MAX? -1 : minOps) << endl;
    return;
}

signed main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
