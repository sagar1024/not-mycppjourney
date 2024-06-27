// B. Find The Array

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array [a1,a2,…,an] such that 1≤ai≤109. Let S be the sum of all elements of the array a. Let's call an array b of n integers beautiful if:

// 1≤bi≤109 for each i from 1 to n;
// for every pair of adjacent integers from the array (bi,bi+1), either bi divides bi+1, or bi+1 divides bi (or both);
// 2∑i=1n|ai−bi|≤S.

// Your task is to find any beautiful array. It can be shown that at least one beautiful array always exists.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. Each test case consists of two lines. The first line contains one integer n (2≤n≤50). The second line contains n integers a1,a2,…,an (1≤ai≤109).

// Output
// For each test case, print the beautiful array b1,b2,…,bn (1≤bi≤109) on a separate line. It can be shown that at least one beautiful array exists under these circumstances. If there are multiple answers, print any of them.

// Example
// inputCopy
// 4
// 5
// 1 2 3 4 5
// 2
// 4 6
// 2
// 1 1000000000
// 6
// 3 4 8 1 2 3

// outputCopy
// 3 3 3 3 3
// 3 6
// 1 1000000000
// 4 4 8 1 3 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n;
    cin >> n;

    vector<long long int> givenArray(n);
    long long int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
        sum += givenArray[i];
    }

    //These lines initialize a vector cur with two elements, and then iterate over the elements of the array givenArray. Within the loop, it updates the counts of elements in cur based on their parity(even/odd)
    vector<long long int> cur(2, 0);
    for (int i = 0; i < n; i++)
    {
        //For each element at index i, it decrements the corresponding count in cur based on whether i is even or odd
        cur[i % 2] += givenArray[i] - 1;
    }

    //This loop checks if the conditions for constructing a beautiful array are satisfied. It iterates over cur to check the counts of elements at even and odd indices
    //If the total count at any index is not too high (i.e 2 * cur[j] is not greater than the sum of all elements), it modifies givenArray to form a beautiful array
    //If the conditions are met for either even or odd indices, it sets all elements at that index to 1
    for (int j = 0; j < 2; j++)
    {
        //Out of j=0 and j=1, we will choose the one which has 2*cur[j] less than or equal to sum
        if (2*cur[j] > sum)
        {
            continue;
        }

        //For every pair of adjacent integers from the array (bi,bi+1), either bi divides bi+1, or bi+1 divides bi(or both)
        //Putting 1 in the array in alternative indexes to satisfy this condition
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == j)
            {
                givenArray[i] = 1;
            }
        }

        break;
    }

    for (int i = 0; i < n; i++)
    {
        cout << givenArray[i] << " ";
    }

    cout << endl;

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
