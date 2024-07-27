// C. Contrast Value

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// For an array of integers [a1,a2,…,an], let's call the value |a1−a2|+|a2−a3|+⋯+|an−1−an| the contrast of the array. Note that the contrast of an array of size 1 is equal to 0. You are given an array of integers a. Your task is to build an array of b in such a way that all the following conditions are met:

// b is not empty, i.e there is at least one element;
// b is a subsequence of a, i.e b can be produced by deleting some elements from a (maybe zero);
// the contrast of b is equal to the contrast of a.

// What is the minimum possible size of the array b?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤3⋅105) — the size of the array a. The second line contains n integers a1,a2,⋅,an (0≤ai≤109) — elements of the array itself. The sum of n over all test cases doesn't exceed 3⋅105.

// Output
// For each test case, print a single integer — the minimum possible size of the array b.

// Example
// inputCopy
// 4
// 5
// 1 3 3 3 7
// 2
// 4 2
// 4
// 1 1 1 1
// 7
// 5 4 2 1 0 0 4

// outputCopy
// 2
// 2
// 1
// 3

// My original soln(tle on tc5) -

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

//     //Preprocessing
//     //Removing the adjacent equal elements
//     for(int i=1; i<a.size(); i++)
//     {
//         if(a[i-1]==a[i])
//         {
//             a.erase(a.begin()+i);
//             i--;
//         }
//     }
//     //Removing the middle elements
//     //If a<b<c, then b is removed
//     for(int i=1; i<a.size()-1; i++)
//     {
//         if((a[i-1]<a[i] && a[i]<a[i+1]) || (a[i-1]>a[i] && a[i]>a[i+1]))
//         {
//             a.erase(a.begin()+i);
//             i--;
//         }
//     }

//     cout << a.size() << endl;
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
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            b.push_back(a[i]);
        }
    }

    n = b.size();
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    int min_size = 2; //Minimum size is at least 2 (start and end)
    for (int i = 1; i < n - 1; ++i)
    {
        if ((b[i-1] < b[i] && b[i] < b[i+1]) || (b[i-1] > b[i] && b[i] > b[i+1]))
        {
            continue; //This element is not contributing to the contrast
        }

        min_size++;
    }

    cout << min_size << endl;
    return;
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
