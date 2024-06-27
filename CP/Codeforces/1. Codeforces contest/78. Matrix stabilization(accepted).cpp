// B. Matrix Stabilization

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a matrix of size n×m, where the rows are numbered from 1 to n from top to bottom, and the columns are numbered from 1 to m from left to right. The element at the intersection of the i-th row and the j-th column is denoted by aij. Consider the algorithm for stabilizing matrix a: Find the cell (i,j) such that its value is strictly greater than the values of all its neighboring cells. If there is no such cell, terminate the algorithm. If there are multiple such cells, choose the cell with the smallest value of i, and if there are still multiple cells, choose the one with the smallest value of j. Set aij=aij−1. Go to step 1. In this problem, cells (a,b) and (c,d) are considered neighbors if they share a common side, i.e., |a−c|+|b−d|=1. Your task is to output the matrix a after the stabilization algorithm has been executed. It can be shown that this algorithm cannot run for an infinite number of iterations.

// Input
// Each test consists of multiple sets of input data. The first line contains a single integer t (1≤t≤104) — the number of sets of input data. This is followed by their description. The first line of each set of input data contains two integers n and m (1≤n,m≤100,n⋅m>1) — the number of rows and columns of matrix a. The next n lines describe the corresponding rows of the matrix. The i-th line contains m integers ai1,ai2,…,aim (1≤aij≤109). It is guaranteed that the sum of n⋅m over all sets of input data does not exceed 2⋅105.

// Output
// For each set of input data, output n lines with m numbers in each line — the values of the cells of matrix a after the stabilization algorithm.

// Example
// inputCopy
// 6
// 1 2
// 3 1
// 2 1
// 1
// 1
// 2 2
// 1 2
// 3 4
// 2 3
// 7 4 5
// 1 8 10
// 5 4
// 92 74 31 74
// 74 92 17 7
// 31 17 92 3
// 74 7 3 92
// 7 31 1 1
// 3 3
// 1000000000 1 1000000000
// 1 1000000000 1
// 1000000000 1 1000000000
// outputCopy
// 1 1 
// 1 
// 1 
// 1 2 
// 3 3 
// 4 4 5 
// 1 8 8 
// 74 74 31 31 
// 74 74 17 7 
// 31 17 17 3 
// 31 7 3 3 
// 7 7 1 1 
// 1 1 1 
// 1 1 1 
// 1 1 1

// Note
// In the first set of input data, the algorithm will select the cell (1,1) twice in a row and then terminate.
// In the second set of input data, there is no cell whose value is strictly greater than the values of all neighboring cells.
// In the third set of input data, the algorithm will select the cell (2,2) and then terminate.
// In the fourth set of input data, the algorithm will select the cell (1,1) three times and then the cell (2,3) twice.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long int>> matrix(n, vector<long long int>(m));
    priority_queue<tuple<int, int, int>> pq;

    // Original matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            pq.emplace(matrix[i][j], i, j);
        }
    }

    // MAIN logic
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!pq.empty())
    {
        auto [value, i, j] = pq.top();
        pq.pop();

        bool is_max = true;
        long long int secondLargest = 1;
        for (auto &dir : directions)
        {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m)
            {
                if (matrix[ni][nj] >= matrix[i][j])
                {
                    is_max = false;
                    break;
                }
                secondLargest = max(secondLargest, matrix[ni][nj]);
            }
        }

        if (is_max)
        {
            // while(secondLargest<matrix[i][j])
            // {
            //     matrix[i][j]--;
            // }
            // matrix[i][j]--;
            // if (matrix[i][j] > secondLargest)
            // {
            //     pq.emplace(matrix[i][j], i, j);
            // }
            matrix[i][j] = secondLargest;
        }
    }

    // Stabilized matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

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
