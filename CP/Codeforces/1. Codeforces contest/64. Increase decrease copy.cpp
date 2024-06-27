// B. Increase/Decrease/Copy

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two integer arrays: array a of length n and array b of length n+1. You can perform the following operations any number of times in any order:

// choose any element of the array a and increase it by 1;
// choose any element of the array a and decrease it by 1;
// choose any element of the array a, copy it and append the copy to the end of the array a.

// Your task is to calculate the minimum number of aforementioned operations (possibly zero) required to transform the array a into the array b. It can be shown that under the constraints of the problem, it is always possible.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. Each test case consists of three lines:

// the first line contains a single integer n (1≤n≤2⋅105);
// the second line contains n integers a1,a2,…,an (1≤ai≤109);
// the third line contains n+1 integers b1,b2,…,bn+1 (1≤bi≤109).

// Additional constraint on the input: the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// For each test case, print a single integer — the minimum number of operations (possibly zero) required to transform the array a into the array b.

// Example
// inputCopy
// 3
// 1
// 2
// 1 3
// 2
// 3 3
// 3 3 3
// 4
// 4 2 1 2
// 2 1 5 2 3
// outputCopy
// 3
// 1
// 8

// Note
// In the first example, you can transform a into b as follows: [2]→[2,2]→[1,2]→[1,3].

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n), b(n+1);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }
//     for(int i=0; i<n+1; i++)
//     {
//         cin >> b[i];
//     }

//     int ops = 0;
//     for(int i=0; i<n; i++)
//     {
//         ops += abs(a[i]-b[i]);
//         a[i] = b[i];
//     }

//     int lastNum = b[n];
//     int closestNum = INT_MAX;
//     bool found = false;
//     for(int i=0; i<n; i++)
//     {
//         if(a[i]==lastNum)
//         {
//             found = true;
//             break;
//         }
//         closestNum = min();
//     }

//     if(found) cout << ops << endl;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> a(n), b(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n+1; i++)
    {
        cin >> b[i];
    }

    long long int ops = 0;
    vector<long long int> transformations;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i])
        {
            //transformations.push_back(a[i]);
            while(a[i]!=b[i])
            {
                a[i]--;
                ops++;
                transformations.push_back(a[i]);
            }
        }
        else if(a[i]<b[i])
        {
            //transformations.push_back(a[i]);
            while(a[i]!=b[i])
            {
                a[i]++;
                ops++;
                transformations.push_back(a[i]);
            }
        }
        else
        {
            continue;
        }
    }

    bool found = false;
    long long int closestNum = INT_MAX;
    int lastNum = b[n];
    for(int i=0; i<transformations.size(); i++)
    {
        if(transformations[i]==lastNum)
        {
            found = true;
            break;
        }

        closestNum = min(abs(transformations[i]-b[n]), closestNum);
    }

    //One more traversal check
    //Checking the presence of lastnum in array a
    for(int i=0; i<n; i++)
    {
        if(a[i]==lastNum)
        {
            found = true;
            break;
        }
    }

    if(found) cout << transformations.size()+1 << endl;
    else if(transformations.size()==0) cout << "1" << endl;
    else cout << transformations.size()+closestNum << endl;

    return;
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
