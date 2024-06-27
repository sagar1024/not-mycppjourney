// A. Keyboard

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Our good friend Mole is trying to code a big message. He is typing on an unusual keyboard with characters arranged in following way:

// qwertyuiop
// asdfghjkl;
// zxcvbnm,./

// Unfortunately Mole is blind, so sometimes it is problem for him to put his hands accurately. He accidentally moved both his hands with one position to the left or to the right. That means that now he presses not a button he wants, but one neighboring button (left or right, as specified in input). We have a sequence of characters he has typed and we want to find the original message.

// Input
// First line of the input contains one letter describing direction of shifting ('L' or 'R' respectively for left or right). Second line contains a sequence of characters written by Mole. The size of this sequence will be no more than 100. Sequence contains only symbols that appear on Mole's keyboard. It doesn't contain spaces as there is no space on Mole's keyboard. It is guaranteed that even though Mole hands are moved, he is still pressing buttons on keyboard and not hitting outside it.

// Output
// Print a line that contains the original message.

// Examples
// Input
// R
// s;;upimrrfod;pbr
// Output
// allyouneedislove

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     char shiftDirection;
//     cin >> shiftDirection;

//     string molesMessage;
//     cin >> molesMessage;

//     //Keyboard keys
//     string keys = "qwertyuiopasdfghjkl;zxcvbnm,./";

//     //Storing the keys in an array
//     char keyss[30];
//     for(int i=0; i<30; i++)
//     {
//         keyss[i] = keys[i];
//     }
//     //String after shifting
//     string keysL;
//     string keysR;

//     if(shiftDirection == 'L')
//     {
//         for(int i=0; i<30; i++)
//         {
//             keysL[i] = keys[i+1];
//         }
//     }
//     if(shiftDirection == 'R')
//     {
//         for(int i=0; i<30; i++)
//         {
//             keysR[i] = keys[i-1];
//         }
//     }

//     return 0;
// }

// Chatgpts soln

#include <iostream>
using namespace std;

int main()
{
    char shiftDirection;
    cin >> shiftDirection;

    string molesMessage;
    cin >> molesMessage;

    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string shiftedKeyboard;

    // Shift the keyboard according to the given direction
    if (shiftDirection == 'L')
    {
        shiftedKeyboard = keyboard[29] + keyboard.substr(0, 29);
    }
    else if (shiftDirection == 'R')
    {
        shiftedKeyboard = keyboard.substr(1, 29) + keyboard[0];
    }

    string originalMessage;

    // Match the characters in Mole's sequence to the shifted keyboard to find the original message
    for (int i = 0; i < molesMessage.length(); i++)
    {
        size_t pos = shiftedKeyboard.find(molesMessage[i]);
        originalMessage += keyboard[pos];
    }

    cout << originalMessage << endl;

    return 0;
}
