//Game 3: Tic-tac-toe
//The rules for this game are same as usual
//The code runs perfectly fine in online compilers

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

//Function to display the board
void displayBoard(char board[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            //Prints the characters that currently exists in the matrix
            cout << board[i][j];

            if(j<2)
            {
                //Column separation
                cout << " |";
            }
        }

        //New line for the row separation
        cout << endl;

        if(i<2)
        {
            //Row separation
            cout << "--------";
        }

        //New line, new row
        cout << endl;
    }
}

//Function to check the win status of the players
bool winStatus(char board[3][3], char player)
{
    for(int i=0; i<3; i++)
    {
        //Row triplets
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
            return true;
        }
        //Column triplets
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
        {
            return true;
        }
    }

    //Diagonal "\" triplet
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
    {
        return true;
    }

    //Diagonal "/" triplet
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
    {
        return true;
    }

    return false;
}

int main()
{
    //Game formalities
    cout << "Welcome to the Tic-tac-toe game!" << endl;
    cout << "Press ENTER to continue: " << endl;
    cin.get();
    cout << "Let's start!" << endl;

    //Initializing the game variables
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int move_count = 0;

    //Current player
    char current_player = 'x';

    //Game func/loop
    while(true)
    {
        //Displaying an empty board
        displayBoard(board);

        //Players play their moves
        int row, col;
        cout << "Player " << current_player << " play your move: " << endl;

        cout << "Enter the row: " << endl;
        cin >> row;
        cout << "Enter the col: " << endl;
        cin >> col;

        //Game logic
        //Error handling
        if(row<0 || col<0 || row>2 || col>2 || board[row][col]!=' ')
        {
            cout << "Invalid response!" << endl;
            continue;
        }

        //Updating the board
        board[row][col] = current_player;

        move_count++;

        //Calling the function
        //Declaring the game result
        if(winStatus(board, current_player))
        {
            displayBoard(board);
            cout << "Player " << current_player << " wins!" << endl;
            break;
        }
        else if(move_count==9)
        {
            cout << "It's a draw!" << endl;
            break;
        }
        
        //Switching the game control btw the 2 players
        current_player = (current_player == 'x')? 'o' : 'x';
    }

    return 0;
}