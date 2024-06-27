// B. Polo the Penguin and Matrix

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Little penguin Polo has an n × m matrix, consisting of integers. Let's index the matrix rows from 1 to n from top to bottom and let's index the columns from 1 to m from left to right. Let's represent the matrix element on the intersection of row i and column j as aij. In one move the penguin can add or subtract number d from some matrix element. Find the minimum number of moves needed to make all matrix elements equal. If the described plan is impossible to carry out, say so.

// Input
// The first line contains three integers n, m and d (1 ≤ n, m ≤ 100, 1 ≤ d ≤ 104) — the matrix sizes and the d parameter. Next n lines contain the matrix: the j-th integer in the i-th row is the matrix element aij (1 ≤ aij ≤ 104).

// Output
// In a single line print a single integer — the minimum number of moves the penguin needs to make all matrix elements equal. If that is impossible, print "-1" (without the quotes).

// Examples
// inputCopy
// 2 2 2
// 2 4
// 6 8
// outputCopy
// 4
// inputCopy
// 1 2 7
// 6 7
// outputCopy
// -1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n, m, d;
//     cin >> n >> m >> d;

//     vector<long long int> matrix(n*m);
//     for(int i=0; i<n*m; i++)
//     {
//         cin >> matrix[i];
//     }

//     sort(matrix.begin(), matrix.end());

//     int median1 = matrix[n/2 + 1];
//     int moveCount1 = 0;
//     for(int i=0; i<n*m; i++)
//     {
//         int diff = abs(matrix[i] - median1);
//         if(diff%d!=0)
//         {
//             cout << "-1" << endl;
//             return;
//         }

//         moveCount1 += diff/d;
//     }

//     int median2 = matrix[n/2];
//     int moveCount2 = 0;
//     for(int i=0; i<n*m; i++)
//     {
//         int diff = abs(matrix[i] - median2);
//         if(diff%d!=0)
//         {
//             cout << "-1" << endl;
//             return;
//         }

//         moveCount2 += diff/d;
//     }

//     cout << min(moveCount1, moveCount2) << endl;
//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

// More correct soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> matrix(n * m);
    for (int i = 0; i < n * m; i++)
    {
        cin >> matrix[i];
    }

    sort(matrix.begin(), matrix.end());

    int median = matrix[(n * m) / 2];

    int moves = 0;
    for (int i = 0; i < n * m; i++)
    {
        if ((abs(matrix[i] - median)) % d != 0)
        {
            cout << "-1" << endl;
            return;
        }

        moves += (abs(matrix[i] - median)) / d;
    }

    cout << moves << endl;
}

int main()
{
    solve();
    return 0;
}
