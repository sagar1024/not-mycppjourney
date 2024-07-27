// E. Mirror Grid

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a square grid with n rows and n columns. Each cell contains either 0 or 1. In an operation, you can select a cell of the grid and flip it (from 0→1 or 1→0). Find the minimum number of operations you need to obtain a square that remains the same when rotated 0∘, 90∘, 180∘ and 270∘. The picture below shows an example of all rotations of a grid.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤100) — the size of the grid. Then n lines follow, each with n characters ai,j (0≤ai,j≤1) — the number written in each cell.

// Output
// For each test case output a single integer  — the minimum number of operations needed to make the square look the same rotated 0∘, 90∘, 180∘ and 270∘.

// Example
// inputCopy
// 5
// 3
// 010
// 110
// 010
// 1
// 0
// 5
// 11100
// 11011
// 01011
// 10011
// 11000
// 5
// 01000
// 10101
// 01010
// 00010
// 01001
// 5
// 11001
// 00000
// 11111
// 10110
// 01111

// outputCopy
// 1
// 0
// 9
// 7
// 6

// Note
// In the first test case, we can perform one operations to make the grid 010111010. Now, all rotations of the square are the same.
// In the second test case, all rotations of the square are already the same, so we don't need any flips.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<vector<char>> grid(n, vector<char>(n));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     int min_operations = 0;

//     //Iterating over the first quadrant of the grid
//     for (int i = 0; i < (n + 1) / 2; i++)
//     {
//         for (int j = 0; j < (n + 1) / 2; j++)
//         {
//             //Coordinates of the four symmetric cells
//             char a = grid[i][j];
//             char b = grid[j][n - 1 - i];
//             char c = grid[n - 1 - i][n - 1 - j];
//             char d = grid[n - 1 - j][i];

//             //Counting the number of 1's among these four cells
//             int ones = (a == '1') + (b == '1') + (c == '1') + (d == '1');

//             //The minimum flips needed to make all four cells the same
//             min_operations += min(ones, 4 - ones);
//         }
//     }

//     cout << min_operations << endl;
//     return;
// }

// int main()
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

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c-'0';
        }
    }

    int min_operations = 0;
    for(int i=0; i<(n+1)/2; i++)
    {
        for(int j=0; j<n/2; j++)
        {
            int currI = i, currJ = j;
            int oldJ = currJ;
            int sum = grid[currI][currJ];

            currJ = n - currI - 1;
            currI = oldJ;
            oldJ = currJ;
            sum += grid[currI][currJ];

            currJ = n - currI - 1;
            currI = oldJ;
            oldJ = currJ;
            sum += grid[currI][currJ];

            currJ = n - currI - 1;
            currI = oldJ;
            oldJ = currJ;
            sum += grid[currI][currJ];

            min_operations += min(sum, 4-sum);
        }
    }

    cout << min_operations << endl;
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

