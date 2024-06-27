//Game 4: Rock paper scissors
//The rules for this game are same as usual
//No comments for this code
//The executable file is NOT being generated for some reason
//The code is working perfectly fine in online compilers
//Now its running fine here as well
//The problem got fixed after I moved all source code to a new folder 

#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    //Seeding the random num generator
    srand(static_cast<unsigned>(time(0)));

    int player_hand, computer_hand;
    int p_score = 0, c_score = 0;

    int numer_of_rounds;

    cout << "Let's play Rock paper scissors!" << endl;

    cout << "Enter the number of rounds you want to play: " << endl;
    cin >> numer_of_rounds;

    for(int i=1; i<=numer_of_rounds; i++)
    {
        cout << "Round " << i << endl;

        cout << "Enter your choice: " << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissor" << endl;
        cout << "Enter the choice(1, 2 or 3): " << endl;

        cin >> player_hand;

        if(player_hand<1 || player_hand>3)
        {
            cout << "Invalid response! You lost your chance for this round!" << endl;
            continue;
        }

        //Generating a random choice
        computer_hand = rand()%3 + 1;

        const string choices[] = {"Rock", "Paper", "Scissor"};

        cout << "Player chose: " << choices[player_hand - 1] << endl;
        cout << "Computer chose: " << choices[computer_hand - 1] << endl;

        //Determining the winner
        if(player_hand==computer_hand)
        {
            cout << "Round " << i << " is a tie!" << endl;
        }

        else if((player_hand==1 && computer_hand==3) || (player_hand==2 && computer_hand==1) || (player_hand==3 && computer_hand==2))
        {
            cout << "Round " << i << " is won by the player!" << endl;
            p_score++;
        }

        else
        {
            cout << "Round " << i << " is won by the computer!" << endl;
            c_score++;
        }
    }

    cout << "Game over! Final score: " << endl;
    cout << "The Player scored: " << p_score << " points" << endl;
    cout << "The Computer scored: " << c_score << " points" << endl;

    if(p_score>c_score)
    {
        cout << "The player wins!" << endl;
    }
    else if(c_score>p_score)
    {
        cout << "The computer wins!" <<endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
