// B. Make It Ugly

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's call an array a beautiful if you can make all its elements the same by using the following operation an arbitrary number of times (possibly, zero): choose an index i (2≤i≤|a|−1) such that ai−1=ai+1, and replace ai with ai−1. You are given a beautiful array a1,a2,…,an. What is the minimum number of elements you have to remove from it in order for it to stop being beautiful? Swapping elements is prohibited. If it is impossible to do so, then output -1.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤3⋅105). The second line contains n integers a1,a2,…,an (1≤ai≤n). Additional constraints on the input: in every test case, the given array a is beautiful; the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, output a single integer — the minimum number of elements you have to remove from the array a in order for it to stop being beautiful. If it is impossible, then output -1.

// Example
// inputCopy
// 4
// 3
// 2 2 2
// 5
// 1 2 1 2 1
// 1
// 1
// 7
// 3 3 3 5 3 3 3
// outputCopy
// -1
// 1
// -1
// 3

// Note
// In the first testcase, it is impossible to modify the array in such a way that it stops being beautiful. An array consisting of identical numbers will remain beautiful no matter how many numbers we remove from it.
// In the second testcase, you can remove the number at the index 5, for example. The resulting array will be [1,2,1,2]. Let's check if it is beautiful. Two operations are available: Choose i=2: the array becomes [1,1,1,2]. No more operations can be applied to it, and the numbers are not all the same. Choose i=3 instead: the array becomes [1,2,2,2]. No more operations can be applied to it either, and the numbers are still not all the same. Thus, the array [1,2,1,2] is not beautiful.

// In the fourth testcase, you can remove the first three elements, for example. The resulting array [5,3,3,3] is not beautiful.

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
//     cin >> n;

//     vector<int> a(n);
//     bool allSame = true;
//     int firstElement = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         if(firstElement==0)
//         {
//             firstElement = a[i];
//         }
//         else if(firstElement!=a[i])
//         {
//             allSame = false;
//         }
//     }

//     if(allSame)
//     {
//         cout << "-1" << endl;
//         return;
//     }

//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(a[i]==firstElement)
//         {
//             count++;
//         }
//         else
//         {
//             break;
//         }
//     }

//     cout << count << endl;

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
    cin >> n;

    vector<int> a(n);
    bool allSame = true;
    int firstElement = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(firstElement==0)
        {
            firstElement = a[i];
        }
        else if(firstElement!=a[i])
        {
            allSame = false;
        }
    }

    if(allSame)
    {
        cout << "-1" << endl;
        return;
    }

    int first = a[0];
    int last = a[n - 1];
    int minRemoval1 = 0;

    // Check for how many elements need to be removed from the beginning of the array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == first)
        {
            minRemoval1++;
        }
        else
        {
            break;
        }
    }

    int minRemoval2 = 0;
    // Check for how many elements need to be removed from the end of the array
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == last)
        {
            minRemoval2++;
        }
        else
        {
            break;
        }
    }

    cout << min(minRemoval1, minRemoval2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
