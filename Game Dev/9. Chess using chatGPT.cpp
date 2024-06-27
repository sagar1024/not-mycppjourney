// Game 9: Chess++
// Game of CHESS using chatgpt

// Importing the required libraries
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Functions prototype
void displayBoard();
bool isPawnMoveValid(int fromRow, int fromCol, int toRow, int toCol, char player);
bool isKingMoveValid(int fromRow, int fromCol, int toRow, int toCol);
bool isQueenMoveValid(int fromRow, int fromCol, int toRow, int toCol);
bool isBishopMoveValid(int fromRow, int fromCol, int toRow, int toCol);
bool isKnightMoveValid(int fromRow, int fromCol, int toRow, int toCol);
bool isRookMoveValid(int fromRow, int fromCol, int toRow, int toCol);
bool isMoveValid(int fromRow, int fromCol, int toRow, int toCol, char player);
bool isKingInCheck(char player);
bool isCheckmate(char player);

// Constants to represent chess pieces
const char KING = 'K';
const char QUEEN = 'Q';
const char BISHOP = 'B';
const char KNIGHT = 'N';
const char ROOK = 'R';
const char PAWN = 'P';
const char EMPTY = ' ';

// Define the chessboard as a 2D array
// Lowercase chars - BLACK
// Uppercase chars - WHITE
char board[8][8] =
    {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

// MAIN function
int main()
{
    char currentPlayer = 'W'; // 'W' for white, 'B' for black
    bool gameOver = false;

    // Main game loop
    while (!gameOver)
    {
        // Display the chessboard
        displayBoard();

        cout << "Player " << currentPlayer << "'s turn. Enter your move (e.g., fromRow fromCol toRow toCol): ";
        int fromRow, fromCol, toRow, toCol;
        cin >> fromRow >> fromCol >> toRow >> toCol;

        // Validate the move
        if (isMoveValid(fromRow, fromCol, toRow, toCol, currentPlayer))
        {
            // Make the move (update the board)
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = EMPTY;

            // Check if the move puts the opponent's king in check
            if (isKingInCheck(currentPlayer))
            {
                cout << "Check!" << endl;
            }

            // Check if the move results in checkmate
            if (isCheckmate(currentPlayer))
            {
                cout << "Checkmate! Player " << currentPlayer << " wins." << endl;
                gameOver = true;
            }

            // Switch to the other player's turn
            currentPlayer = (currentPlayer == 'W') ? 'B' : 'W';
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

// Implementation of the functions
//  Function to display the chessboard
void displayBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to validate a move for a pawn
bool isPawnMoveValid(int fromRow, int fromCol, int toRow, int toCol, char player)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Move forward one square
    if (player == 'P' && fromCol == toCol && fromRow + 1 == toRow && board[toRow][toCol] == EMPTY)
        return true;
    if (player == 'p' && fromCol == toCol && fromRow - 1 == toRow && board[toRow][toCol] == EMPTY)
        return true;

    // Capture diagonally
    if (abs(toCol - fromCol) == 1 && toRow == fromRow + 1 && player == 'P' && islower(board[toRow][toCol]))
        return true;
    if (abs(toCol - fromCol) == 1 && toRow == fromRow - 1 && player == 'p' && isupper(board[toRow][toCol]))
        return true;

    // Handle the initial two-square move for a pawn
    if (player == 'P' && fromCol == toCol && fromRow == 1 && toRow == 3 && board[2][toCol] == EMPTY && board[3][toCol] == EMPTY)
        return true;
    if (player == 'p' && fromCol == toCol && fromRow == 6 && toRow == 4 && board[5][toCol] == EMPTY && board[4][toCol] == EMPTY)
        return true;

    return false;
}

// Function to validate a move for a king
bool isKingMoveValid(int fromRow, int fromCol, int toRow, int toCol)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Kings can move one square in any direction (horizontally, vertically, or diagonally)
    int rowDiff = abs(toRow - fromRow);
    int colDiff = abs(toCol - fromCol);
    return (rowDiff <= 1) && (colDiff <= 1);
}

// Function to validate a move for a queen
bool isQueenMoveValid(int fromRow, int fromCol, int toRow, int toCol)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Queens can move horizontally, vertically, and diagonally
    int rowDiff = abs(toRow - fromRow);
    int colDiff = abs(toCol - fromCol);
    return (fromRow == toRow || fromCol == toCol) || (rowDiff == colDiff);
}

// Function to validate a move for a bishop
bool isBishopMoveValid(int fromRow, int fromCol, int toRow, int toCol)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Bishops can move diagonally
    int rowDiff = abs(toRow - fromRow);
    int colDiff = abs(toCol - fromCol);
    return rowDiff == colDiff;
}

// Function to validate a move for a knight
bool isKnightMoveValid(int fromRow, int fromCol, int toRow, int toCol)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Knights can move in an L-shape (2 squares in one direction, then 1 square in a perpendicular direction)
    int rowDiff = abs(toRow - fromRow);
    int colDiff = abs(toCol - fromCol);
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

// Function to validate a move for a rook
bool isRookMoveValid(int fromRow, int fromCol, int toRow, int toCol)
{
    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Rooks can move horizontally or vertically
    if ((fromRow == toRow && fromCol != toCol) || (fromRow != toRow && fromCol == toCol))
        return true;

    return false;
}

// Function to validate a move (simplified for now)
bool isMoveValid(int fromRow, int fromCol, int toRow, int toCol, char player)
{
    char piece = board[fromRow][fromCol];
    // char targetPiece = board[toRow][toCol];

    // Check if the destination is within the board
    if (toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7)
        return false;

    // Handle move validation for different pieces
    switch (toupper(piece))
    {
    case 'P':
        return isPawnMoveValid(fromRow, fromCol, toRow, toCol, player);
    case 'K':
        return isKingMoveValid(fromRow, fromCol, toRow, toCol);
    case 'Q':
        return isQueenMoveValid(fromRow, fromCol, toRow, toCol);
    case 'B':
        return isBishopMoveValid(fromRow, fromCol, toRow, toCol);
    case 'N':
        return isKnightMoveValid(fromRow, fromCol, toRow, toCol);
    case 'R':
        return isRookMoveValid(fromRow, fromCol, toRow, toCol);

        // Add more piece-specific move validation here (e.g., bishop, queen, king).
    }

    return false;
}

// Function to check if the king is in check
// Implement logic to check if the king of the specified player is in check.
// This requires checking all opponent's pieces and their possible moves.
// We will add this logic later.

// Function to check if the king is in check
bool isKingInCheck(char player)
{
    int kingRow, kingCol;
    char kingPiece = (player == 'W') ? 'K' : 'k';

    // Find the position of the king
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col] == kingPiece)
            {
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }

    // Check if any of the opponent's pieces can capture the king
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            char piece = board[row][col];
            if (isupper(piece) && player == 'W')
            {
                if (isMoveValid(row, col, kingRow, kingCol, 'B'))
                {
                    return true;
                }
            }
            else if (islower(piece) && player == 'B')
            {
                if (isMoveValid(row, col, kingRow, kingCol, 'W'))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

// Function to check if it's a checkmate
// Implement logic to check if the specified player is in checkmate.
// This requires checking all possible moves for the player and see if any move can
// get the king out of check. We will add this logic later.

// Function to check if it's checkmate
bool isCheckmate(char player)
{
    // Check if the king is in check
    if (!isKingInCheck(player))
    {
        return false; // The king is not in check; it can't be checkmate.
    }

    // Find the king's position
    int kingRow, kingCol;
    char kingPiece = (player == 'W') ? 'K' : 'k';

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col] == kingPiece)
            {
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }

    // Iterate through all possible moves for the king
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0)
            {
                continue; // Skip the king's current position.
            }

            int newRow = kingRow + dr;
            int newCol = kingCol + dc;

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
            {
                // Simulate the king's move
                char originalPiece = board[newRow][newCol];
                board[newRow][newCol] = kingPiece;
                board[kingRow][kingCol] = EMPTY;

                // Check if the king is still in check after the move
                bool kingInCheckAfterMove = isKingInCheck(player);

                // Restore the board to its original state
                board[kingRow][kingCol] = kingPiece;
                board[newRow][newCol] = originalPiece;

                // If the king is not in check after the move, it's not checkmate
                if (!kingInCheckAfterMove)
                {
                    return false;
                }
            }
        }
    }

    // If there are no legal moves to get the king out of check, it's checkmate.
    return true;
}
