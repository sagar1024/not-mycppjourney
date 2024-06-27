// B. Caisa and Pylons

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Caisa solved the problem with the sugar and now he is on the way back to home. Caisa is playing a mobile game during his path. There are (n + 1) pylons numbered from 0 to n in this game. The pylon with number 0 has zero height, the pylon with number i (i > 0) has height hi. The goal of the game is to reach n-th pylon, and the only move the player can do is to jump from the current pylon (let's denote its number as k) to the next one (its number will be k + 1). When the player have made such a move, its energy increases by hk - hk + 1 (if this value is negative the player loses energy). The player must have non-negative amount of energy at any moment of the time. Initially Caisa stand at 0 pylon and has 0 energy. The game provides a special opportunity: one can pay a single dollar and increase the height of anyone pylon by one. Caisa may use that opportunity several times, but he doesn't want to spend too much money. What is the minimal amount of money he must paid to reach the goal of the game?

// Input
// The first line contains integer n (1 ≤ n ≤ 105). The next line contains n integers h1, h2, ..., hn (1  ≤  hi  ≤  105) representing the heights of the pylons.

// Output
// Print a single number representing the minimum number of dollars paid by Caisa.

// Examples
// inputCopy
// 5
// 3 4 3 2 4
// outputCopy
// 4

// inputCopy
// 3
// 4 4 4
// outputCopy
// 4

// Note
// In the first sample he can pay 4 dollars and increase the height of pylon with number 0 by 4 units. Then he can safely pass to the last pylon.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i=0; i<n; i++)
    {
        cin >> heights[i];
    }

    int energy = 0;
    int minDollars = heights[0];

    // for(int i=1; i<n; i++)
    // {
    //     if((heights[i]-heights[i-1])<0)
    //     {
    //         energy += heights[i]-heights[i-1];
    //     }
    //     else
    //     {
    //         if(energy>(heights[i]-heights[i-1]))
    //         {
    //             energy = energy-(heights[i]-heights[i-1]);
    //         }
    //         else
    //         {
    //             int x = (heights[i]-heights[i-1]) - energy;
    //             energy = 0;
    //             minDollars += x;
    //         }
    //     }
    // }

    for (int i=1; i<n; i++)
    {
        int diff = heights[i] - heights[i-1];
        if (diff < 0)
        {
            //The diff is negative, player will loses the energy
            energy -= diff;
        }
        else
        {
            if (energy >= diff)
            {
                energy -= diff; //Player has enough energy, no money spent
            }
            else
            {
                minDollars += diff - energy; //Player needs to spend money
                energy = 0;
            }
        }
    }

    int result = max(0, minDollars);
    cout << result << endl;

    return 0;
}
