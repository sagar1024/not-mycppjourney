//My first computer game created using C++
//This is a game of your luck. Here, the player will enter his DOB and try to match it with mine. If there's a match, then he is a WINNER else a LOSER(lol). 

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//Creating a function to match the player's DOB
int gameFunction(int user_dob)
{
    //Initializing my DOB
    int myDOB = 07;

    if(user_dob == myDOB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    //Game formalities
    cout << "Welcome to the Game of your luck!" << endl;
    cout << "Press ENTER to continue:" << endl;

    //Waits for the user to press ENTER key
    cin.get();
    
    int user_dob;

    cout << "Enter your date of birth!" << endl;
    cin >> user_dob;

    //Storing the result of the game
    string gameResult;

    //Calling the function
    if (gameFunction(user_dob))
    {
        gameResult = "Congratulations! You WON!";
    }
    else
    {
        gameResult = "You LOSE! Better luck next time!";
    }

    //Printing the game Result
    cout << gameResult << endl;
    
    return 0;
}