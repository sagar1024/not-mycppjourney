// Game 5: Hangman game
// Guessing a hidden word by suggesting letter
// Displaying the progess of the word using undersocres
// Reveal the correctly guessed letter

#include <iostream>
#include <string>
#include <vector>

//To use the time function in our program
#include <ctime>
#include <cstdlib>

//To use find()
#include <algorithm>

using namespace std;

//Selecting a random word generator
string randomWord()
{
    // Creating a list of words
    vector<string> words = {"apple", "banana", "cherry", "donut", "grape", "orange", "pizza", "strawberry"};

    // Picking up a random word from the word bank
    int randomWordIndex = rand() % words.size();
    return words[randomWordIndex];
}

//To display the guessed letters
void displayWord(string secretWord, vector<char> guessedLetters)
{
    for (char letter : secretWord)
    {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
        {
            cout << letter << " ";
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
}

//Checking whether all the letters have been guessed
bool allLettersGuessed(const string &word, const vector<char> &guessed)
{
    for (char letter : word)
    {
        if (find(guessed.begin(), guessed.end(), letter) == guessed.end())
        {
            return false; // If any letter is not guessed, returns false
        }
    }
    return true; // All letters have been guessed, returns true
}

int main()
{
    // Seeding the random number generator
    srand(static_cast<unsigned>(time(0)));

    //Randwom word generated
    string secretWord = randomWord();

    int max_attempts = 5;
    int attempts = 0;

    //Storing the letters entered by the player
    vector<char> guessedLetters;

    // Game formalities
    cout << "Welcome to the Hangman game!" << endl;

    cout << "Press ENTER to continue: " << endl;
    cin.get();

    cout << "Let's begin the game!" << endl;

    //Game loop
    while (attempts < max_attempts)
    {
        cout << "Word to guess: " << endl;

        displayWord(secretWord, guessedLetters);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        guessedLetters.push_back(guess);

        //Game logic
        if (secretWord.find(guess) == string::npos)
        {
            cout << "Incorrect guess. You have " << max_attempts - attempts - 1 << " attempts left." << endl;
            attempts++;
        }
        else
        {
            cout << "Correct guess!" << endl;
        }

        if (secretWord.find(guess) == string::npos)
        {
            cout << "You've run out of attempts. The word was: " << secretWord << endl;
            break;
        }

        if (allLettersGuessed(secretWord, guessedLetters))
        {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    return 0;
}