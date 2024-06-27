// B. Progressive Square

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A progressive square of size n is an n×n matrix. Maxim chooses three integers a1,1, c, and d and constructs a progressive square according to the following rules:

// ai+1,j=ai,j+c
// ai,j+1=ai,j+d

// For example, if n=3, a1,1=1, c=2, and d=3, then the progressive square looks as follows:

// ⎛⎝⎜1354687911⎞⎠⎟

// Last month Maxim constructed a progressive square and remembered the values of n, c, and d. Recently, he found an array b of n2 integers in random order and wants to make sure that these elements are the elements of that specific square. It can be shown that for any values of n, a1,1, c, and d, there exists exactly one progressive square that satisfies all the rules.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains three integers n, c, and d (2≤n≤500, 1≤c,d≤106) — the size of the square and the values of c and d as described in the statement. The second line of each test case contains n⋅n integers b1,b2,…,bn⋅n (1≤bi≤109) — the elements found by Maxim. It is guaranteed that the sum of n2 over all test cases does not exceed 25⋅104.

// Output
// For each test case, output "YES" in a separate line if a progressive square for the given n, c, and d can be constructed from the array elements a, otherwise output "NO". You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

// Example
// inputCopy
// 5
// 3 2 3
// 3 9 6 5 7 1 10 4 8
// 3 2 3
// 3 9 6 5 7 1 11 4 8
// 2 100 100
// 400 300 400 500
// 3 2 3
// 3 9 6 6 5 1 11 4 8
// 4 4 4
// 15 27 7 19 23 23 11 15 7 3 19 23 11 15 11 15
// outputCopy
// NO
// YES
// YES
// NO
// NO

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;

    vector<long long int> matrix(n*n);
    for(int i=0; i<n*n; i++)
    {
        cin >> matrix[i];
    }

    sort(matrix.begin(), matrix.end());
    int smallestNum = matrix[0];
    int currentNum = smallestNum;

    //Generating the matrix
    vector<vector<long long int>> newMatrix(n, vector<long long int>(n));
    vector<long long int> newMatrix2;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            newMatrix[i][j] = currentNum;
            newMatrix2.push_back(currentNum);
            currentNum += d;
        }

        currentNum = smallestNum + c*(i+1);
    }

    sort(newMatrix2.begin(), newMatrix2.end());
    bool isEqual = true;
    for(int i=0; i<n*n; i++)
    {
        if(matrix[i]!=newMatrix2[i])
        {
            isEqual = false;
        }
    }

    if(isEqual)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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
