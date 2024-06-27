// B. Not Quite Latin Square

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A Latin square is a 3×3 grid made up of the letters A, B, and C such that:

// in each row, the letters A, B, and C each appear once, and
// in each column, the letters A, B, and C each appear once.

// For example, one possible Latin square is shown below.
// ⎡⎣⎢ACBBACCBA⎤⎦⎥

// You are given a Latin square, but one of the letters was replaced with a question mark ?. Find the letter that was replaced.

// Input
// The first line of the input contains a single integer t (1≤t≤108) — the number of testcases. Each test case contains three lines, each consisting of three characters, representing the Latin square. Each character is one of A, B, C, or ?. Each test case is a Latin square with exactly one of the letters replaced with a question mark ?.

// Output
// For each test case, output the letter that was replaced.

// My original soln

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Latin square
//         char latinSquare[3][3];

//         int row, col;

//         for(int i=0; i<3; i++)
//         {
//             for(int j=0; j<3; j++)
//             {
//                 cin >> latinSquare[i][j];

//                 //Storing the position of the question mark
//                 if(latinSquare[i][j]=='?')
//                 {
//                     row = i;
//                     col = j;
//                 }
//             }
//         }

//         //Main logic
//         if((latinSquare[row][0]=='A' && latinSquare[row][1]=='B') || (latinSquare[row][1]=='A' && latinSquare[row][2]=='B') || (latinSquare[row][2]=='A' && latinSquare[row][0]=='B'))
//         {
//             cout << 'C' << endl;
//         }
//         if((latinSquare[row][0]=='B' && latinSquare[row][1]=='C') || (latinSquare[row][1]=='B' && latinSquare[row][2]=='C') || (latinSquare[row][2]=='B' && latinSquare[row][0]=='C'))
//         {
//             cout << 'A' << endl;
//         }
//         if((latinSquare[row][0]=='C' && latinSquare[row][1]=='A') || (latinSquare[row][1]=='C' && latinSquare[row][2]=='A') || (latinSquare[row][2]=='C' && latinSquare[row][0]=='A'))
//         {
//             cout << 'B' << endl;
//         }
//     }

//     return 0;
// }

// Chatgpts logic

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // Latin square
        char latinSquare[3][3];

        // Frequency counts for each letter
        int countA = 0, countB = 0, countC = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> latinSquare[i][j];

                // Counting occurrences of each letter
                if (latinSquare[i][j] == 'A')
                    countA++;
                else if (latinSquare[i][j] == 'B')
                    countB++;
                else if (latinSquare[i][j] == 'C')
                    countC++;
            }
        }

        if(countA!=3)
        {
            cout << "A" << endl;
        }
        else if(countB!=3)
        {
            cout << "B" << endl;
        }
        else if(countC!=3)
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "?" << endl;
        }
    }

    return 0;
}
