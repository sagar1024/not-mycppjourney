// F. Xor-Paths

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There is a rectangular grid of size n×m. Each cell has a number written on it; the number on the cell (i,j) is ai,j. Your task is to calculate the number of paths from the upper-left cell (1,1) to the bottom-right cell (n,m) meeting the following constraints: You can move to the right or to the bottom only. Formally, from the cell (i,j) you may move to the cell (i,j+1) or to the cell (i+1,j). The target cell can't be outside of the grid.The xor of all the numbers on the path from the cell (1,1) to the cell (n,m) must be equal to k (xor operation is the bitwise exclusive OR, it is represented as '^' in Java or C++ and "xor" in Pascal). Find the number of such paths in the given grid.

// Input
// The first line of the input contains three integers n, m and k (1≤n,m≤20, 0≤k≤1018) — the height and the width of the grid, and the number k. The next n lines contain m integers each, the j-th element in the i-th line is ai,j (0≤ai,j≤1018).

// Output
// Print one integer — the number of paths from (1,1) to (n,m) with xor sum equal to k.

// Examples
// inputCopy
// 3 3 11
// 2 1 5
// 7 10 0
// 12 6 4
// outputCopy
// 3
// inputCopy
// 3 4 2
// 1 3 3 3
// 0 3 3 2
// 3 0 1 1
// outputCopy
// 5
// inputCopy
// 3 4 1000000000000000000
// 1 3 3 3
// 0 3 3 2
// 3 0 1 1
// outputCopy
// 0

// Note

// All the paths from the first example:
// (1,1)→(2,1)→(3,1)→(3,2)→(3,3);
// (1,1)→(2,1)→(2,2)→(2,3)→(3,3);
// (1,1)→(1,2)→(2,2)→(3,2)→(3,3).
// All the paths from the second example:
// (1,1)→(2,1)→(3,1)→(3,2)→(3,3)→(3,4);
// (1,1)→(2,1)→(2,2)→(3,2)→(3,3)→(3,4);
// (1,1)→(2,1)→(2,2)→(2,3)→(2,4)→(3,4);
// (1,1)→(1,2)→(2,2)→(2,3)→(3,3)→(3,4);
// (1,1)→(1,2)→(1,3)→(2,3)→(3,3)→(3,4).

// My original soln(mle on tc4) - using BFS

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Structure of data to be stored in queue
// struct State
// {
//     int x, y;
//     long long int xorValue;
// };

// int countPaths(vector<vector<long long int>> &a, long long int &k)
// {
//     int n = a.size();
//     int m = a[0].size();

//     int topLeft = a[0][0];
//     int bottomRight = a[n-1][m-1];

//     //For right and down respectively
//     int directions[2][2] = {{0,1}, {1,0}};

//     queue<State> q;
//     q.push({0,0,a[0][0]});

//     int paths = 0;
//     while(!q.empty())
//     {
//         State curr = q.front();
//         q.pop();

//         int x = curr.x;
//         int y = curr.y;
//         long long xorValue = curr.xorValue;

//         //If we reach bottom right cell
//         if(x==n-1 && y==m-1)
//         {
//             if(xorValue==k)
//             {
//                 paths++;
//             }

//             continue;
//         }

//         //Explore the further cells(right and down)
//         for(int i=0; i<2; i++)
//         {
//             //Here when i==0 then x2 remains same
//             //AND when i==1 then y2 remains same
//             int x2 = x + directions[i][0];
//             int y2 = y + directions[i][1];

//             //Make sure its not going beyond bottom right cell
//             if(x2<n && y2<m)
//             {
//                 q.push({x2,y2,xorValue^a[x2][y2]});
//             }
//         }
//     }

//     return paths;
// }

// int32_t main()
// {
//     int n, m;
//     cin >> n >> m;

//     long long int k;
//     cin >> k;

//     vector<vector<long long int>> a(n,vector<long long int>(m,0));
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }

//     long long int paths = countPaths(a,k);
//     cout << paths << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 20;
map<long long, int> v[N][N]; //3D map to store XOR values and their counts

int n, m;
int half; //Half of the total moves (n + m - 2) / 2
long long k;
long long a[N][N];
long long ans; //Result variable to store the number of valid paths

//Function to calculate left half of paths
void calclf(int x, int y, long long val, int cnt)
{
    val ^= a[x][y]; //XOR the current cell value
    //If reached half of the moves
    if (cnt == half)
    {
        ++v[x][y][val]; //Record the XOR value in the map for this cell
        return;
    }

    //Move right if within bounds
    if (x + 1 < n) calclf(x + 1, y, val, cnt + 1);

    //Move down if within bounds
    if (y + 1 < m) calclf(x, y + 1, val, cnt + 1);
}

//Function to calculate right half of paths and count valid paths
void calcrg(int x, int y, long long val, int cnt)
{
    //If reached the end of all moves
    if (cnt == n + m - 2 - half)
    {
        //Check if there exists a path from (0, 0) to (x, y) with XOR equal to k ^ val
        if (v[x][y].count(k ^ val)) ans += v[x][y][k ^ val]; //Add the count of such paths to the answer
        
        return;
    }
    //Move left if within bounds
    if (x > 0) calcrg(x - 1, y, val ^ a[x][y], cnt + 1);

    //Move up if within bounds
    if (y > 0) calcrg(x, y - 1, val ^ a[x][y], cnt + 1);
}

int main()
{
    cin >> n >> m >> k;
    half = (n + m - 2) / 2; //Calculate half of the total moves

    //Read grid values
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    //Calculate paths for the left half starting from (0, 0)
    calclf(0, 0, 0, 0);

    //Calculate paths for the right half ending at (n-1, m-1)
    calcrg(n - 1, m - 1, 0, 0);

    cout << ans << endl;

    return 0;
}
