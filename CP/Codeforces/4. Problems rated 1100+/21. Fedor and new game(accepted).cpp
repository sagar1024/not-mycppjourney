// B. Fedor and New Game

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// After you had helped George and Alex to move in the dorm, they went to help their friend Fedor play a new computer game «Call of Soldiers 3». The game has (m + 1) players and n types of soldiers in total. Players «Call of Soldiers 3» are numbered form 1 to (m + 1). Types of soldiers are numbered from 0 to n - 1. Each player has an army. Army of the i-th player can be described by non-negative integer xi. Consider binary representation of xi: if the j-th bit of number xi equal to one, then the army of the i-th player has soldiers of the j-th type. Fedor is the (m + 1)-th player of the game. He assume that two players can become friends if their armies differ in at most k types of soldiers (in other words, binary representations of the corresponding numbers differ in at most k bits). Help Fedor and count how many players can become his friends.

// Input
// The first line contains three integers n, m, k (1 ≤ k ≤ n ≤ 20; 1 ≤ m ≤ 1000). The i-th of the next (m + 1) lines contains a single integer xi (1 ≤ xi ≤ 2n - 1), that describes the i-th player's army. We remind you that Fedor is the (m + 1)-th player.

// Output
// Print a single integer — the number of Fedor's potential friends.

// Examples
// inputCopy
// 7 3 1
// 8
// 5
// 111
// 17
// outputCopy
// 0
// inputCopy
// 3 3 3
// 1
// 2
// 3
// 4
// outputCopy
// 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to count set bits(1s)
int countSetBits(int n)
{
    int count = 0;
    while(n)
    {
        //Clearing the right most set bit
        //n = n & (n-1);
        //OR
        n &= (n-1);

        count++;
    }

    return count;
}

int main()
{
    //Num of players
    //Types of players
    //Max diff in soldiers
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> armyStrength(m+1);
    for(int i=0; i<m+1; i++)
    {
        cin >> armyStrength[i];
    }
    
    int fedorsArmy = armyStrength[m];
    int count = 0;

    // for(int i=0; i<m; i++)
    // {
    //     if(abs(armyStrength[i]-fedorsArmy)<=k)
    //     {
    //         count++;
    //     }
    // }

    // if(n<=m)
    // {
    //     cout << m << endl;
    // }
    // else
    // {
    //     cout << count << endl;
    // }

    int potentialFriends = 0;
    for(int i=0; i<m; i++)
    {
        //The number of different bits would be equal to the number of ones in the number X  xor  Y
        //Calculating the bitwise XOR between Fedor's army and the player's army
        int diff = fedorsArmy^armyStrength[i];

        //Counting the num of set bits in the difference(xor result)
        int bitCount = countSetBits(diff);

        if(bitCount<=k)
        {
            potentialFriends++;
        }
    }

    cout << potentialFriends << endl;

    return 0;
}
