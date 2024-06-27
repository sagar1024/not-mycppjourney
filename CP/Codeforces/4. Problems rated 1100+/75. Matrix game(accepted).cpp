// A. Matrix Game

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ashish and Vivek play a game on a matrix consisting of n rows and m columns, where they take turns claiming cells. Unclaimed cells are represented by 0, while claimed cells are represented by 1. The initial state of the matrix is given. There can be some claimed cells in the initial state. In each turn, a player must claim a cell. A cell may be claimed if it is unclaimed and does not share a row or column with any other already claimed cells. When a player is unable to make a move, he loses and the game ends. If Ashish and Vivek take turns to move and Ashish goes first, determine the winner of the game if both of them are playing optimally. Optimal play between two players means that both players choose the best possible strategy to achieve the best possible outcome for themselves.

// Input
// The first line consists of a single integer t (1≤t≤50) — the number of test cases. The description of the test cases follows. The first line of each test case consists of two space-separated integers n, m (1≤n,m≤50) — the number of rows and columns in the matrix. The following n lines consist of m integers each, the j-th integer on the i-th line denoting ai,j (ai,j∈{0,1}).

// Output
// For each test case if Ashish wins the game print "Ashish" otherwise print "Vivek" (without quotes).

// Example
// inputCopy
// 4
// 2 2
// 0 0
// 0 0
// 2 2
// 0 0
// 0 1
// 2 3
// 1 0 1
// 1 1 0
// 3 3
// 1 0 0
// 0 0 0
// 1 0 0
// outputCopy
// Vivek
// Ashish
// Vivek
// Ashish

// Note
// For the first case: One possible scenario could be: Ashish claims cell (1,1), Vivek then claims cell (2,2). Ashish can neither claim cell (1,2), nor cell (2,1) as cells (1,1) and (2,2) are already claimed. Thus Ashish loses. It can be shown that no matter what Ashish plays in this case, Vivek will win.
// For the second case: Ashish claims cell (1,1), the only cell that can be claimed in the first move. After that Vivek has no moves left.
// For the third case: Ashish cannot make a move, so Vivek wins.
// For the fourth case: If Ashish claims cell (2,3), Vivek will have no moves left.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         int n, m;
//         cin >> n >> m;

//         vector<vector<int>> matrix(n, vector<int>(m));
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 cin >> matrix[i][j];
//             }
//         }

//         //MAIN logic
//         int countRows1 = 0;
//         int maxCountRows1 = 0;
//         int countCols1 = 0;
//         bool onePresent = false;
//         //int maxCountCols1 = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(matrix[i][j]==1)
//                 {
//                     countRows1++;
//                     onePresent = true;
//                 }
//             }
//             maxCountRows1 = max(countRows1, maxCountRows1);
//             if(onePresent)
//             {
//                 countCols1++;
//             }
//         }

//         //Unclaimed cells with distinct rows and cols
//         int totUnclaimedCells = min(maxCountRows1, (m - countCols1));

//         if(totUnclaimedCells%2!=0)
//         {
//             cout << "Ashish" << endl;
//         }
//         else
//         {
//             cout << "Vivek" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        vector<int> rowClaimed(n), colClaimed(m);

        //Input the matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1)
                {
                    rowClaimed[i] = 1;
                    colClaimed[j] = 1;
                }
            }
        }

        //Counting the number of unclaimed rows and columns
        int unclaimedRows = 0, unclaimedCols = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!rowClaimed[i])
                unclaimedRows++;
        }
        for (int j = 0; j < m; ++j)
        {
            if (!colClaimed[j])
                unclaimedCols++;
        }

        //Output
        //Determining the winner based on the number of unclaimed rows and columns
        if (min(unclaimedRows, unclaimedCols) % 2 == 1)
        {
            cout << "Ashish" << endl;
        }
        else
        {
            cout << "Vivek" << endl;
        }
    }

    return 0;
}
