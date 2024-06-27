// B. Sequential Nim

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n piles of stones, where the i-th pile has ai stones. Two people play a game, where they take alternating turns removing stones. In a move, a player may remove a positive number of stones from the first non-empty pile (the pile with the minimal index, that has at least one stone). The first player who cannot make a move (because all piles are empty) loses the game. If both players play optimally, determine the winner of the game.

// Input
// The first line contains a single integer t (1≤t≤1000)  — the number of test cases. Next 2t lines contain descriptions of test cases. The first line of each test case contains a single integer n (1≤n≤105)  — the number of piles. The second line of each test case contains n integers a1,…,an (1≤ai≤109)  — ai is equal to the number of stones in the i-th pile. It is guaranteed that the sum of n for all test cases does not exceed 105.

// Output
// For each test case, if the player who makes the first move will win, output "First". Otherwise, output "Second".

// Example
// inputCopy
// 7
// 3
// 2 5 4
// 8
// 1 1 1 1 1 1 1 1
// 6
// 1 2 3 4 5 6
// 6
// 1 1 2 1 2 2
// 1
// 1000000000
// 5
// 1 2 2 1 1
// 3
// 1 1 1

// outputCopy
// First
// Second
// Second
// First
// First
// Second
// First

// Note
// In the first test case, the first player will win the game. His winning strategy is:
// The first player should take the stones from the first pile. He will take 1 stone. The numbers of stones in piles will be [1,5,4].
// The second player should take the stones from the first pile. He will take 1 stone because he can't take any other number of stones. The numbers of stones in piles will be [0,5,4].
// The first player should take the stones from the second pile because the first pile is empty. He will take 4 stones. The numbers of stones in piles will be [0,1,4].
// The second player should take the stones from the second pile because the first pile is empty. He will take 1 stone because he can't take any other number of stones. The numbers of stones in piles will be [0,0,4].
// The first player should take the stones from the third pile because the first and second piles are empty. He will take 4 stones. The numbers of stones in piles will be [0,0,0].
// The second player will lose the game because all piles will be empty.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Num of piles
        int n;
        cin >> n;

        vector<long long int> stones(n);
        bool allOne = true;
        int firstIndexOfGreaterThanOne = 0;
        int lastIndexOfGreaterThanOne = 0;
        for(int i=0; i<n; i++)
        {
            cin >> stones[i];
            if(stones[i]!=1)
            {
                allOne = false;
            }
            if(!firstIndexOfGreaterThanOne && stones[i]>1)
            {
                firstIndexOfGreaterThanOne = i;
            }
            if(stones[i]>1)
            {
                lastIndexOfGreaterThanOne = i;
            }
        }

        //Special case
        if(allOne)
        {
            if(n%2!=0)
            {
                cout << "First" << endl;
            }
            else
            {
                cout << "Second" << endl;
            }
            continue;
        }

        //General case
        //Let
        //First = true
        //Second = false

        // bool first = false;

        // for(int i=0; i<n; i++)
        // {
        //     if(stones[i]==1)
        //     {
        //         first = !first;
        //     }
        //     else if(stones[i]>1)
        //     {
        //         if(i==lastIndexOfGreaterThanOne)
        //         {
        //             first = !first;
        //         }
        //     }
        // }

        // if(first) cout << "First" << endl;
        // else cout << "Second" << endl;

        if((firstIndexOfGreaterThanOne+1)%2!=0)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }

    return 0;
}
