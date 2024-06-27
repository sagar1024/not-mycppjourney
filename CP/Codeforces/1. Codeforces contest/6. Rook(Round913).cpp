// A. Rook

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// As you probably know, chess is a game that is played on a board with 64 squares arranged in an 8×8 grid. Columns of this board are labeled with letters from a to h, and rows are labeled with digits from 1 to 8. Each square is described by the row and column it belongs to. The rook is a piece in the game of chess. During its turn, it may move any non-zero number of squares horizontally or vertically. Your task is to find all possible moves for a rook on an empty chessboard.

// Input
// The first line of input contains single integer t (1≤t≤64) — the number of test cases. The descriptions of test cases follow. Each test case contains one string of two characters, description of the square where rook is positioned. The first character is a letter from a to h, the label of column, and the second character is a digit from 1 to 8, the label of row. The same position may occur in more than one test case.

// Output
// For each test case, output descriptions of all squares where the rook can move, in the same format as in the input. You can output squares in any order per test case.

// Example

// Input
// 1
// d5
// Output
// d1
// d2
// b5
// g5
// h5
// d3
// e5
// f5
// d8
// a5
// d6
// d7
// c5
// d4

//Importing the header files
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
        //Current position of the rook
        string s;
        cin >> s;

        //Storing the file and rank of the rooks position
        char file = s[0];
        char rank = s[1];

        //Creating an array of files and ranks for traversals
        char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        char ranks[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

        //Traversing the files - A to H
        for(int i=0; i<8; i++)
        {
            //Keep skipping until we reach out current file
            if(file != files[i])
            {
                continue;
            }
            //Traversing the ranks - 1 to 8
            for(int j=0; j<8; j++)
            {
                //Skipping the rank of the current position
                if(rank==ranks[j])
                {
                    continue;
                }

                //All possible moves in the file of the current position
                cout << files[i] << ranks[j] << endl;
            }
            //Breaking the loop once done printing the output
            break;
        }

        //Traversing the ranks
        for(int i=0; i<8; i++)
        {
            //Skipping till we reach out current rank
            if(rank != ranks[i])
            {
                continue;
            }
            //Traversing the files
            for(int j=0; j<8; j++)
            {
                //Skipping the file of the current position
                if(file == files[j])
                {
                    continue;
                }
                //All possible moves in the rank of the current position
                cout << files[j] << ranks[i] << endl;
            }
            //Breaking the loop once done printing the output
            break;
        }
    }

    return 0;
}
