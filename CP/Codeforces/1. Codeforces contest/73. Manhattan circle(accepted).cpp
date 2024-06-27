// D. Manhattan Circle

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a n by m grid consisting of '.' and '#' characters, there exists a whole manhattan circle on the grid. The top left corner of the grid has coordinates (1,1), and the bottom right corner has coordinates (n,m). Point (a,b) belongs to the manhattan circle centered at (h,k) if |h−a|+|k−b|<r, where r is a positive constant. On the grid, the set of points that are part of the manhattan circle is marked as '#'. Find the coordinates of the center of the circle.

// Input
// The first line contains t (1≤t≤1000)  — the number of test cases. The first line of each test case contains n and m (1≤n⋅m≤2⋅105) — the height and width of the grid, respectively. The next n lines contains m characters '.' or '#'. If the character is '#', then the point is part of the manhattan circle. It is guaranteed the sum of n⋅m over all test cases does not exceed 2⋅105, and there is a whole manhattan circle on the grid.

// Output
// For each test case, output the two integers, the coordinates of the center of the circle.

// Example
// inputCopy
// 6
// 5 5
// .....
// .....
// ..#..
// .....
// .....
// 5 5
// ..#..
// .###.
// #####
// .###.
// ..#..
// 5 6
// ......
// ......
// .#....
// ###...
// .#....
// 1 1
// #
// 5 6
// ...#..
// ..###.
// .#####
// ..###.
// ...#..
// 2 10
// ..........
// ...#......

// outputCopy
// 3 3
// 3 3
// 4 2
// 1 1
// 3 4
// 2 4

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    //Variables to find the bounding box of the '#' characters
    int minX = n, maxX = 0, minY = m, maxY = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '#')
            {
                if (i < minX)
                    minX = i;
                if (i > maxX)
                    maxX = i;
                if (j < minY)
                    minY = j;
                if (j > maxY)
                    maxY = j;
            }
        }
    }

    //The center should be the midpoint of the bounding box
    int centerX = (minX + maxX) / 2 + 1; //Here +1 to convert from 0-based to 1-based indexing
    int centerY = (minY + maxY) / 2 + 1; //Here +1 to convert from 0-based to 1-based indexing

    cout << centerX << " " << centerY << endl;

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
