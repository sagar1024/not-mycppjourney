// B. Coin Games

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n coins on the table forming a circle, and each coin is either facing up or facing down. Alice and Bob take turns to play the following game, and Alice goes first. In each operation, the player chooses a facing-up coin, removes the coin, and flips the two coins that are adjacent to it. If (before the operation) there are only two coins left, then one will be removed and the other won't be flipped (as it would be flipped twice). If (before the operation) there is only one coin left, no coins will be flipped. If (before the operation) there are no facing-up coins, the player loses. Decide who will win the game if they both play optimally. It can be proved that the game will end in a finite number of operations, and one of them will win.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains only one positive integer n (1≤n≤100), representing the number of the coins. A string s of length n follows on the second line of each test case, containing only "U" and "D", representing that each coin is facing up or facing down.

// Output
// For each test case, print "YES" if Alice will win the game, and "NO" otherwise. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// inputCopy
// 3
// 5
// UUDUD
// 5
// UDDUD
// 2
// UU
// outputCopy
// YES
// NO
// NO

// Note
// In the first test case, the game may go as follows.

// Alice chooses the first coin and s becomes "DDUU".
// Bob chooses the last coin and s becomes "UDD".
// Alice chooses the first coin and s becomes "UU".
// Bob chooses the first coin and s becomes "U".
// Alice chooses the only coin and s becomes empty.
// Bob can't choose any coin now, and he loses the game.

// It can be proved that Bob will always lose if they both play optimally.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    for(char c: s)
    {
        if(c=='U')
        {
            count++;
        }
    }

    if(count%2!=0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
