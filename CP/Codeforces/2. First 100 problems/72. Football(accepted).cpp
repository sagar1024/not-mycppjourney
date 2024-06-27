// A. Football

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

// Input
// The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

// Output
// Print "YES" if the situation is dangerous. Otherwise, print "NO".

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;

    bool dangerous = false;

    if (n.size() >= 7)
    {
        // Iterating till length+7
        // To make the small strings iteratable
        for (int i = 0; i < n.length(); i++)
        {
            // Main logic
            if (n[i] == n[i + 1] && n[i + 1] == n[i + 2] && n[i + 2] == n[i + 3] && n[i + 3] == n[i + 4] && n[i + 4] == n[i + 5] && n[i + 5] == n[i + 6] && n[i+6]==n[i])
            {
                dangerous = true;
                break;
            }
        }
    }

    if (dangerous)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
