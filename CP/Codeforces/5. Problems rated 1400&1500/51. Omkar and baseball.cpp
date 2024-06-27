// C. Omkar and Baseball

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Patrick likes to play baseball, but sometimes he will spend so many hours hitting home runs that his mind starts to get foggy! Patrick is sure that his scores across n sessions follow the identity permutation (ie. in the first game he scores 1 point, in the second game he scores 2 points and so on). However, when he checks back to his record, he sees that all the numbers are mixed up! Define a special exchange as the following: choose any subarray of the scores and permute elements such that no element of subarray gets to the same position as it was before the exchange. For example, performing a special exchange on [1,2,3] can yield [3,1,2] but it cannot yield [3,2,1] since the 2 is in the same position. Given a permutation of n integers, please help Patrick find the minimum number of special exchanges needed to make the permutation sorted! It can be proved that under given constraints this number doesn't exceed 1018. An array a is a subarray of an array b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows. The first line of each test case contains integer n (1≤n≤2⋅105)  — the length of the given permutation. The second line of each test case contains n integers a1,a2,...,an (1≤ai≤n)  — the initial permutation. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer: the minimum number of special exchanges needed to sort the permutation.

// Example
// inputCopy
// 2
// 5
// 1 2 3 4 5
// 7
// 3 2 4 5 1 6 7
// outputCopy
// 0
// 2

// Note
// In the first permutation, it is already sorted so no exchanges are needed.

// It can be shown that you need at least 2 exchanges to sort the second permutation.
// [3,2,4,5,1,6,7]
// Perform special exchange on range (1,5)
// [4,1,2,3,5,6,7]
// Perform special exchange on range (1,4)
// [1,2,3,4,5,6,7]

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

//     vector<int> x;
//     x = a;

//     int count = 0;

//     int left = 0, right = n-1;
//     int firstIdx = 0;
//     int lastIdx = 0;
//     while(left<right)
//     {
//         firstIdx = 0;
//         lastIdx = 0;

//         sort(x.begin()+left, x.begin()+right);
//         for(int i=left; i<=right; i++)
//         {
//             if(a[i]!=x[i])
//             {
//                 if(!firstIdx)
//                 {
//                     firstIdx = i;
//                 }
//                 lastIdx = i;
//             }
//         }

//         count++;

//         left = firstIdx;
//         right = lastIdx;
//     }

//     cout << count << endl;
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

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> sortedArray = a;
    sort(sortedArray.begin(), sortedArray.end());

    int firstIdx = -1, lastIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != sortedArray[i])
        {
            if (firstIdx == -1)
            {
                firstIdx = i;
            }
            lastIdx = i;
        }
    }

    if (firstIdx == -1)
    {
        cout << "0" << endl;
        return;
    }

    bool possible = true;
    for (int i = firstIdx; i < lastIdx; i++)
    {
        if (a[i] < a[i + 1])
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << "1" << endl;
        return;
    }

    //Checking if the remaining elements can be sorted with one special exchange
    bool canSortWithOneExchange = true;
    for (int i = lastIdx + 1; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            canSortWithOneExchange = false;
            break;
        }
    }

    if (canSortWithOneExchange)
    {
        cout << "2" << endl;
        return;
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
