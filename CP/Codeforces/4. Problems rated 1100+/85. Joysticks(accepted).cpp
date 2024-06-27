// A. Joysticks

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Friends are going to play console. They have two joysticks and only one charger for them. Initially first joystick is charged at a1 percent and second one is charged at a2 percent. You can connect charger to a joystick only at the beginning of each minute. In one minute joystick either discharges by 2 percent (if not connected to a charger) or charges by 1 percent (if connected to a charger). Game continues while both joysticks have a positive charge. Hence, if at the beginning of minute some joystick is charged by 1 percent, it has to be connected to a charger, otherwise the game stops. If some joystick completely discharges (its charge turns to 0), the game also stops. Determine the maximum number of minutes that game can last. It is prohibited to pause the game, i. e. at each moment both joysticks should be enabled. It is allowed for joystick to be charged by more than 100 percent.

// Input
// The first line of the input contains two positive integers a1 and a2 (1 ≤ a1, a2 ≤ 100), the initial charge level of first and second joystick respectively.

// Output
// Output the only integer, the maximum number of minutes that the game can last. Game continues until some joystick is discharged.

// Examples
// inputCopy
// 3 5
// outputCopy
// 6

// inputCopy
// 4 4
// outputCopy
// 5

// Note

// In the first sample game lasts for 6 minute by using the following algorithm:

// at the beginning of the first minute connect first joystick to the charger, by the end of this minute first joystick is at 4%, second is at 3%;
// continue the game without changing charger, by the end of the second minute the first joystick is at 5%, second is at 1%;
// at the beginning of the third minute connect second joystick to the charger, after this minute the first joystick is at 3%, the second one is at 2%;
// continue the game without changing charger, by the end of the fourth minute first joystick is at 1%, second one is at 3%;
// at the beginning of the fifth minute connect first joystick to the charger, after this minute the first joystick is at 2%, the second one is at 1%;
// at the beginning of the sixth minute connect second joystick to the charger, after this minute the first joystick is at 0%, the second one is at 2%.

// After that the first joystick is completely discharged and the game is stopped.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Inputs
//     int a1, a2;
//     cin >> a1 >> a2;

//     //MAIN logic
//     int gameDuration = 0;

//     //Both odd
//     if(a1%2>0 && a2%2>0)
//     {
//         gameDuration = a1+a2-2;
//     }

//     //Both even
//     else if(a1%2==0 && a2%2==0)
//     {
//         int maxCharge = max(a1, a2);
//         int minCharge = min(a1, a2);

//         gameDuration = maxCharge/2 + minCharge+(maxCharge/2)/2;
//     }

//     //One even and one odd
//     else
//     {
//         if(a1%2==0)
//         {
//             gameDuration = a1/2 + a2+(a1/2)/2;
//         }
//         else if(a2%2==0)
//         {
//             gameDuration = a2/2 + a1+(a2/2)/2;
//         }
//     }

//     //Outputs
//     cout << gameDuration << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Inputs
    int a1, a2;
    cin >> a1 >> a2;

    // Main logic
    // Calculate the maximum number of minutes the game can last.
    // Each minute, one joystick is charged by 1% if it's connected to the charger,
    // and both joysticks discharge by 2% if not connected.
    // We need to find the maximum number of minutes until one of the joysticks is fully discharged.
    // At each minute, we connect the charger to the joystick with a lower charge.
    // If both joysticks have the same charge, we connect the charger to the first joystick.
    if((a1==0 && a2==0) || (a1==1 && a2==1))
    {
        cout << "0" << endl;
        return 0;
    }

    int minutes = 0;
    while (a1 > 0 && a2 > 0)
    {
        if (a1 < a2)
        {
            a1++; // Charge the first joystick by 1%
            a2 -= 2; // Discharge the second joystick by 2%
        }
        else
        {
            a2++; // Charge the second joystick by 1%
            a1 -= 2; // Discharge the first joystick by 2%
        }

        minutes++; // Increment the minute counter
    }

    //Outputs
    cout << minutes << endl;

    return 0;
}
