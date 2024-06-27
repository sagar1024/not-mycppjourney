// D. Anti-Sudoku

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a correct solution of the sudoku puzzle. If you don't know what is the sudoku, you can read about it here. The picture showing the correct sudoku solution: Blocks are bordered with bold black color. Your task is to change at most 9 elements of this field (i.e. choose some 1≤i,j≤9 and change the number at the position (i,j) to any other number in range [1;9]) to make it anti-sudoku. The anti-sudoku is the 9×9 field, in which:

// Any number in this field is in range [1;9];
// each row contains at least two equal elements;
// each column contains at least two equal elements;
// each 3×3 block (you can read what is the block in the link above) contains at least two equal elements.

// It is guaranteed that the answer exists. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t(1≤t≤104) — the number of test cases. Then t test cases follow. Each test case consists of 9 lines, each line consists of 9 characters from 1 to 9 without any whitespaces — the correct solution of the sudoku puzzle.

// Output
// For each test case, print the answer — the initial field with at most 9 changed elements so that the obtained field is anti-sudoku. If there are several solutions, you can print any. It is guaranteed that the answer exists.

// Example
// inputCopy
// 1
// 154873296
// 386592714
// 729641835
// 863725149
// 975314628
// 412968357
// 631457982
// 598236471
// 247189563

// outputCopy
// 154873396
// 336592714
// 729645835
// 863725145
// 979314628
// 412958357
// 631457992
// 998236471
// 247789563

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         vector<vector<int>> sudokuBoard(9, vector<int>(9));
//         for(int i=0; i<9; i++)
//         {
//             for(int j=0; j<9; j++)
//             {
//                 cin >> sudokuBoard[i][j];
//             }
//         }

//         //MAIN logic
//         if(sudokuBoard[0][0] == 1)
//         {
//             sudokuBoard[0][0] = 2;
//         }
//         else
//         {
//             sudokuBoard[0][0] = 1;
//         }
//         if(sudokuBoard[1][3] == 2)
//         {
//             sudokuBoard[1][3] = 3;
//         }
//         else
//         {
//             sudokuBoard[1][3] = 2;
//         }
//         if(sudokuBoard[2][6] == 3)
//         {
//             sudokuBoard[2][6] = 4;
//         }
//         else
//         {
//             sudokuBoard[2][6] = 3;
//         }
//         if(sudokuBoard[3][1] == 4)
//         {
//             sudokuBoard[3][1] = 5;
//         }
//         else
//         {
//             sudokuBoard[3][1] = 4;
//         }
//         if(sudokuBoard[4][4] == 5)
//         {
//             sudokuBoard[4][4] = 6;
//         }
//         else
//         {
//             sudokuBoard[4][4] = 5;
//         }
//         if(sudokuBoard[5][7] == 6)
//         {
//             sudokuBoard[5][7] = 7;
//         }
//         else
//         {
//             sudokuBoard[5][7] = 6;
//         }
//         if(sudokuBoard[6][2] == 7)
//         {
//             sudokuBoard[6][2] = 8;
//         }
//         else
//         {
//             sudokuBoard[6][2] = 7;
//         }
//         if(sudokuBoard[7][5] == 8)
//         {
//             sudokuBoard[7][5] = 9;
//         }
//         else
//         {
//             sudokuBoard[7][5] = 8;
//         }
//         if(sudokuBoard[8][8] == 9)
//         {
//             sudokuBoard[8][8] = 1;
//         }
//         else
//         {
//             sudokuBoard[8][8] = 9;
//         }

//         //Output
//         for(int i=0; i<9; i++)
//         {
//             for(int j=0; j<9; j++)
//             {
//                 cout << sudokuBoard[i][j];
//             }
//             cout << endl;
//         }
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Inputs
        //vector<vector<int>> sudokuBoard(9, vector<int>(9));
        int sudokuBoard[9][9];
        for(int i=0; i<9; i++)
        {
            string s;
            cin >> s;
            for(int j=0; j<s.size(); j++)
            {
                //Important line
                //It is necessary to subtract it by '0' because numbers are of char type
                //Else it creates/stores garbage values
                sudokuBoard[i][j] = s[j]-'0';
            }
        }

        //MAIN logic
        //Replacing 1s with 2s will automatically duplicate the num "2" is each row, col and grid
        //The resulting sudoku will be an anti-sudoku
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(sudokuBoard[i][j]==1)
                {
                    sudokuBoard[i][j] = 2;
                }
            }
        }

        //Output
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout << sudokuBoard[i][j];
            }

            cout << endl;
        }
    }

    return 0;
}
