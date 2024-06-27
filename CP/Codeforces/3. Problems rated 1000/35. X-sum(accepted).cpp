// D. X-Sum

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Timur's grandfather gifted him a chessboard to practice his chess skills. This chessboard is a grid a with n rows and m columns with each cell having a non-negative integer written on it. Timur's challenge is to place a bishop on the board such that the sum of all cells attacked by the bishop is maximal. The bishop attacks in all directions diagonally, and there is no limit to the distance which the bishop can attack. Note that the cell on which the bishop is placed is also considered attacked. Help him find the maximal sum he can get.

// Input
// The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. The description of test cases follows. The first line of each test case contains the integers n and m (1≤n≤200, 1≤m≤200). The following n lines contain m integers each, the j-th element of the i-th line aij is the number written in the j-th cell of the i-th row (0≤aij≤106). It is guaranteed that the sum of n⋅m over all test cases does not exceed 4⋅104.

// Output
// For each test case output a single integer, the maximum sum over all possible placements of the bishop.

// Example
// inputCopy
// 4
// 4 4
// 1 2 2 1
// 2 4 2 4
// 2 2 3 1
// 2 4 2 4
// 2 1
// 1
// 0
// 3 3
// 1 1 1
// 1 1 1
// 1 1 1
// 3 3
// 0 1 1
// 1 0 1
// 1 1 0
// outputCopy
// 20
// 1
// 5
// 3

// Note
// For the first test case here the best sum is achieved by the bishop being in this position: (an Image of a chessboard for explanation)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> boardSquares(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> boardSquares[i][j];
        }
    }

    //MAIN LOGIC
    int maxSum = 0;

    int x, y;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //Resetting the sum to 0 for every loop
            int sum = 0;
            x = i;
            y = j;
            sum += boardSquares[i][j];

            //Diagonal Up-Left
            for (int x=i, y=j; x>=0 && y>=0; x--, y--)
            {
                sum += boardSquares[x][y];
            }

            //Diagonal Up-Right
            for (int x=i, y=j; x>=0 && y<m; x--, y++)
            {
                sum += boardSquares[x][y];
            }

            //Diagonal Down-Left
            for (int x=i, y=j; x<n && y>=0; x++, y--)
            {
                sum += boardSquares[x][y];
            }

            //Diagonal Down-Right
            for (int x=i, y=j; x<n && y<m; x++, y++)
            {
                sum += boardSquares[x][y];
            }

            //Subtracting the current cell four times
            //Since it is added four times additionally
            sum -= 4*boardSquares[i][j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
