// C. Nene's Magical Matrix

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The magical girl Nene has an n×n matrix a filled with zeroes. The j-th element of the i-th row of matrix a is denoted as ai,j. She can perform operations of the following two types with this matrix: Type 1 operation: choose an integer i between 1 and n and a permutation p1,p2,…,pn of integers from 1 to n. Assign ai,j:=pj for all 1≤j≤n simultaneously. Type 2 operation: choose an integer i between 1 and n and a permutation p1,p2,…,pn of integers from 1 to n. Assign aj,i:=pj for all 1≤j≤n simultaneously. Nene wants to maximize the sum of all the numbers in the matrix ∑i=1n∑j=1nai,j. She asks you to find the way to perform the operations so that this sum is maximized. As she doesn't want to make too many operations, you should provide a solution with no more than 2n operations. A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of test cases follows. The only line of each test case contains a single integer n (1≤n≤500) — the size of the matrix a. It is guaranteed that the sum of n2 over all test cases does not exceed 5⋅105.

// Output
// For each test case, in the first line output two integers s and m (0≤m≤2n) — the maximum sum of the numbers in the matrix and the number of operations in your solution. In the k-th of the next m lines output the description of the k-th operation:

// an integer c (c∈{1,2}) — the type of the k-th operation;
// an integer i (1≤i≤n) — the row or the column the k-th operation is applied to;
// a permutation p1,p2,…,pn of integers from 1 to n — the permutation used in the k-th operation.

// Note that you don't need to minimize the number of operations used, you only should use no more than 2n operations. It can be shown that the maximum possible sum can always be obtained in no more than 2n operations.

// Example
// inputCopy
// 2
// 1
// 2
// outputCopy
// 1 1
// 1 1 1
// 7 3
// 1 1 1 2
// 1 2 1 2
// 2 1 1 2

// Note
// In the first test case, the maximum sum s=1 can be obtained in 1 operation by setting a1,1:=1.
// In the second test case, the maximum sum s=7 can be obtained in 3 operations as follows:
// It can be shown that it is impossible to make the sum of the numbers in the matrix larger than 7.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i, n) for (int i = 0; i < n; i++)

void solve()
{
    int n;
    cin >> n;

    //Num of operations used
    int operations = 0;

    //Permutation sum
    int sumOfPermutation = 0;
    for(int i=0; i<n; i++)
    {
        sumOfPermutation += i+1;
    }

    //For output
    vector<pair<int,int>> type_and_rowcolnum;

    vector<vector<int>> magicalMatrix(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            magicalMatrix[i][j] = j+1;
        }

        operations++;
        type_and_rowcolnum[i].first = 1;
        type_and_rowcolnum[i].second = i+1;
    }

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            sum += magicalMatrix[j][i];
        }

        if(sum < sumOfPermutation)
        {
            for(int k=0; k<n; k++)
            {
                magicalMatrix[k][i] = k+1;
            }

            operations++;
            type_and_rowcolnum[i].first = 2;
            type_and_rowcolnum[i].second = i+1;
        }
    }

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            sum += magicalMatrix[i][j];
        }

        if(sum < sumOfPermutation)
        {
            for(int k=0; k<n; k++)
            {
                magicalMatrix[i][k] = k+1;
            }

            operations++;
            type_and_rowcolnum[i].first = 3;
            type_and_rowcolnum[i].second = i+1;
        }
    }

    int totalSum = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            totalSum += magicalMatrix[i][j];
        }
    }

    cout << totalSum << " " << operations << endl;
    for(int i=0; i<type_and_rowcolnum.size(); i++)
    {
        cout << type_and_rowcolnum[i].first << " " << type_and_rowcolnum[i].second << " ";
        for(int i=0; i<n; i++)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }

    return;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
