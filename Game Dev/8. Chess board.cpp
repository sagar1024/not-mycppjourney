//Game 8: The game of CHESS
//Console based game
//The rules are same as usual

//Importing the header files

#include <iostream>
#include <string>

using namespace std;

//Functions
//To define the Chess board

void defineBoard()
{
    char chessBoard[8][8];

    //Labelling the board with its pieces in their original places
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 1 || i == 6)
            {
                chessBoard[i][j] = 'P';
            }
            if ((i == 0 && j == 4) || (i == 7 && j == 4))
            {
                chessBoard[i][j] = 'K';
            }
            if ((i == 0 && j == 3) || (i == 7 && j == 3))
            {
                chessBoard[i][j] = 'Q';
            }
            if ((i == 0 && j == 2) || (i == 0 && j == 5) || (i == 7 && j == 2) || (i == 7 && j == 5))
            {
                chessBoard[i][j] = 'B';
            }
            if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 1) || (i == 7 && j == 6))
            {
                chessBoard[i][j] = 'N';
            }
            if ((i == 0 && j == 0) || (i == 0 && j == 7) || (i == 7 && j == 0) || (i == 7 && j == 7))
            {
                chessBoard[i][j] = 'R';
            }
            //For the initially empty squares
            if (i == 2 || i == 3 || i == 4 || i == 5)
            {
                chessBoard[i][j] = 'x';
            }
        }
    }

    //Printing the chess board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s = "Welcome to the Game of CHESS!";
    cout << s << endl;

    cout << "Press ENTER to continue: " << endl;
    cin.get();

    //Calling the define function
    defineBoard();

    return 0;
}
