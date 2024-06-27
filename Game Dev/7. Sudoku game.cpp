// Game 7: Sudoku
// The rules are as usual
// Each row and each column must contain a number between 1 to 9
// No repetition in any row or column or grid

// Approach:
// 1. Display the board
// 2. Generate random digits in some positions
// 3. Write the sudoku logic
// 4. Check the win status of the player

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int n = 9;

// // Displaying the board, all num initialized with 0
// void displayBoard(vector<vector<int>> board)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << board[i][j] << "0";
//         }
//         cout << endl;
//     }
// }

// // Checking if the number is valid in a particular position
// bool validNum(vector<vector<int>> board, int row, int col, int num)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (board[row][i] == num || board[i][col] == num)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// // To check if the number is valid in the 3x3 grid
// bool validNumInGrid(vector<vector<int>> board, int row, int col, int num)
// {
//     return true;
// }

// // Backtracking algorithm
// bool solveSudoku(vector<vector<int>> board)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             if (board[row][col] == 0)
//             {
//                 for (int num = 1; num <= n; num++)
//                 {
//                     if (validNum(board, row, col, num))
//                     {
//                         board[row][col] = num;
//                         if (solveSudoku(board))
//                         {
//                             return true;
//                         }
//                         board[row][col] = 0; // Backtracking
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     // Game formalities
//     cout << "Welcome to the Game of Sudoku!" << endl;

//     cout << "Press ENTER to continue: " << endl;
//     cin.get();

//     // Seeding the random num generator
//     srand(static_cast<unsigned>(time(0)));

//     // Initializing the Sudoku grid
//     vector<vector<int>> sudokuGrid(n, vector<int>(n, 0));

//     if (solveSudoku(sudokuGrid))
//     {
//         cout << "Sudoku solved!" << endl;
//         displayBoard(sudokuGrid);
//     }
//     else
//     {
//         cout << "Solution not correct!" << endl;
//     }

//     return 0;
// }

// // Recreating the game of SUDOKU after going through multiple source code

#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 9;
int board[N][N];
// Function prototypes
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

// Checking if the number is correct in a particular square
bool safeSquare(int board[N][N], int row, int col, int num)
{
    // Checking if the number already exists in the row
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == num)
            return false;
    }
    // Checking if the number already exists in the col
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    return true;

    // Code for checking the safe square inside the 3x3 grid will be added later
}

bool solveSudoku(int board[N][N], int row, int col)
{
    // Game ends when all the squares are filled correctly
    if (row == N - 1 && col == N)
    {
        return true;
    }

    // Next row iteration
    if (col == N)
    {
        row++;
        col = 0;
    }

    // Code to ignore the pre-written values
    if (board[row][col] != 0)
    {
        solveSudoku(board, row, col + 1);
    }

    // Filling the squares with the numbers
    for (int i = 1; i <= 9; i++)
    {
        if (safeSquare(board, row, col, i))
        {
            board[row][col] = i;

            // Checking the solve status for the next item
            // Yet to confirm
            if (solveSudoku(board, row, col + 1))
            {
                return true;
            }
            else
            {
                return false;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

bool solvedGame(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}

void playTheGame(int board[N][N])
{
    int row, col, num;
    while (true)
    {
        printBoard(board);
        cout << "\n" << endl;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        cout << "Enter the num: ";
        cin >> num;

        if (row == -1 || col == -1 || num == -1)
        {
            // Yet to confirm
            solveSudoku(board, 0, 0);
            printBoard(board);
            cout << endl << "Better luck next time!" << endl;
            return;
        }

        // Breaking away from the loop if all elements have been filled correctly
        if (solvedGame(board))
        {
            break;
        }

        // Row/Col in thier index form
        row--;
        col--;

        // For invalid number
        if (!safeSquare(board, row, col, num))
        {
            cout << "Invalid move!" << endl;
            continue;
        }
        board[row][col] = num;
    }

    // Checking whether the game was solved correctly
    bool solved = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                solved = false;
            break;
        }
    }

    if (solved)
    {
        cout << "Congratulations! You WON!" << endl;
        printBoard(board);
    }
    else
    {
        cout << "You LOST. Try again!" << endl;
    }
}

int main()
{
    cout << "\t\t\t\tWelcome to the SUDOKU Game!" << endl;

    int gameBoard[N][N] ={{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0}, {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3}, {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6}, {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5}, {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    playTheGame(gameBoard);
    exit(0);

    return 0;
}
