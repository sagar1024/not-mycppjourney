//Game 2: Guess the number
//The computer generates a random number and the player has to guess it
//Number of attempts is unlimited

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

//Game initialization
//Generating the secret number
int game_initialization()
{
    //Seeding the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    //Generating a random number btw 1 and 100
    return rand()%100 + 1;
}

//Game function
void playGame(int secret_num)
{
    int user_guess;
    int attempts_count = 0;

    //Game logic
    while (true)
    {
        cout << "Guess a number btw 1 and 100" << endl;
        cin >> user_guess;

        attempts_count++;

        //Matching the user's guess to the secret number
        if(user_guess < secret_num)
        {
            cout << "That's too low, aim for a higher number!" << endl;
            
        }
        else if(user_guess > secret_num)
        {
            cout << "That's too high, aim for a lower number!" << endl;
        }
        else
        {
            cout << "Congratulations! You have guessed the correct number!" << endl;
            cout << "YOU WON!" << endl;
            cout << "Number of attempts made: " << attempts_count << endl;
            break;
        }
    }
}

int main()
{
    //Game formalities
    cout << "Welcome to the Game of guessing the numbers!" << endl;
    cout << "Press ENTER to continue: " << endl;

    //Waits for the player to press ENTER
    cin.get();

    //Variable to store the randomly generated secret number
    int secret_number = game_initialization();

    //Game function/loop
    playGame(secret_number);

    return 0; 
}
