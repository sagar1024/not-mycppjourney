// B. Binary Path

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a 2×n grid filled with zeros and ones. Let the number at the intersection of the i-th row and the j-th column be aij. There is a grasshopper at the top-left cell (1,1) that can only jump one cell right or downwards. It wants to reach the bottom-right cell (2,n). Consider the binary string of length n+1 consisting of numbers written in cells of the path without changing their order. Your goal is to:

// Find the lexicographically smallest† string you can attain by choosing any available path;
// Find the number of paths that yield this lexicographically smallest string.

// If two strings s and t have the same length, then s is lexicographically smaller than t if and only if in the first position where s and t differ, the string s has a smaller element than the corresponding element in t.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤2⋅105). The second line of each test case contains a binary string a11a12…a1n (a1i is either 0 or 1). The third line of each test case contains a binary string a21a22…a2n (a2i is either 0 or 1). It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output

// For each test case, output two lines:
// The lexicographically smallest string you can attain by choosing any available path;
// The number of paths that yield this string.

// Example
// inputCopy
// 3
// 2
// 00
// 00
// 4
// 1101
// 1100
// 8
// 00100111
// 11101101

// outputCopy
// 000
// 2
// 11000
// 1
// 001001101
// 4

// Note

// In the first test case, the lexicographically smallest string is 000. There are two paths that yield this string:
// In the second test case, the lexicographically smallest string is 11000. There is only one path that yields this string:

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         //Input grid
//         vector<vector<int>> grid(2, vector<int>(n));
//         for (int i=0; i<2; i++)
//         {
//             for (int j=0; j<n; j++)
//             {
//                 cin >> grid[i][j];
//             }
//         }

//         //Initialize DP arrays
//         vector<vector<string>> dp(2, vector<string>(n + 1, ""));
//         vector<vector<int>> count(2, vector<int>(n + 1, 0));

//         //Initialize DP arrays for the first row and column
//         dp[0][0] = dp[1][0] = "0";
//         count[0][0] = count[1][0] = 1;

//         //Calculate DP arrays
//         for (int i = 0; i < 2; ++i)
//         {
//             for (int j = 1; j <= n; ++j)
//             {
//                 if (i == 0 && j == 1)
//                     continue; // Skip the top-left cell
//                 int prev_i = (i == 0) ? 1 : 0;
//                 dp[i][j] = min(dp[prev_i][j], dp[i][j - 1]) + to_string(grid[i][j - 1]);
//                 if (dp[prev_i][j] <= dp[i][j - 1])
//                     count[i][j] += count[prev_i][j];
//                 if (dp[prev_i][j] >= dp[i][j - 1])
//                     count[i][j] += count[i][j - 1];
//             }
//         }

//         // Output result
//         cout << dp[1][n] << endl;
//         cout << count[1][n] << endl;
//     }

//     return 0;
// }

// Alternate code -

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        //Input grid
        vector<vector<int>> grid(2, vector<int>(n));
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> grid[i][j];
            }
        }

        //Initialize variables
        string path;
        long long int count = 1; // Initialize count as long long to avoid overflow
        int row = 0, col = 0;

        //Traverse the grid
        while (row < 2 && col < n)
        {
            //Append current element to the path
            path += to_string(grid[row][col]);

            //Count the number of paths
            if (row > 0 && col > 0)
            {
                int prev_row = row - 1;
                int prev_col = col - 1;
                if (grid[prev_row][col] <= grid[row][prev_col])
                {
                    count += count;
                    count %= 1000000007; // Apply modulo to avoid overflow
                }
            }

            //Move right if possible
            if (col < n - 1 && grid[row][col] >= grid[row][col + 1])
            {
                ++col;
            }
            //Move down
            else
            {
                ++row;
            }
        }

        //Outputs
        cout << path << endl;
        cout << count << endl;
    }

    return 0;
}
