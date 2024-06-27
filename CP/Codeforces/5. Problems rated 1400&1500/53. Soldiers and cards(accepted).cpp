// C. Soldier and Cards

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Two bored soldiers are playing card war. Their card deck consists of exactly n cards, numbered from 1 to n, all values are different. They divide cards between them in some manner, it's possible that they have different number of cards. Then they play a "war"-like card game. The rules are following. On each turn a fight happens. Each of them picks card from the top of his stack and puts on the table. The one whose card value is bigger wins this fight and takes both cards from the table to the bottom of his stack. More precisely, he first takes his opponent's card and puts to the bottom of his stack, and then he puts his card to the bottom of his stack. If after some turn one of the player's stack becomes empty, he loses and the other one wins. You have to calculate how many fights will happen and who will win the game, or state that game won't end.

// Input
// First line contains a single integer n (2 ≤ n ≤ 10), the number of cards. Second line contains integer k1 (1 ≤ k1 ≤ n - 1), the number of the first soldier's cards. Then follow k1 integers that are the values on the first soldier's cards, from top to bottom of his stack. Third line contains integer k2 (k1 + k2 = n), the number of the second soldier's cards. Then follow k2 integers that are the values on the second soldier's cards, from top to bottom of his stack. All card values are different.

// Output
// If somebody wins in this game, print 2 integers where the first one stands for the number of fights before end of game and the second one is 1 or 2 showing which player has won. If the game won't end and will continue forever output  - 1.

// Examples
// inputCopy
// 4
// 2 1 3
// 2 4 2
// outputCopy
// 6 2
// inputCopy
// 3
// 1 2
// 2 1 3
// outputCopy
// -1

// Note
// First sample:(figure)
// Second sample:(figure)

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     int k1;
//     cin >> k1;
//     vector<int> player1(k1);
//     for(int i=0; i<k1; i++)
//     {
//         cin >> player1[i];
//     }

//     reverse(player1.begin(), player1.end());
//     //stack<int, vector<int>> stack1(player1);
//     stack<int> stack1;
//     for(int card : player1)
//     {
//         stack1.push(card);
//     }

//     int k2;
//     cin >> k2;
//     vector<int> player2(k2);
//     for(int i=0; i<k2; i++)
//     {
//         cin >> player2[i];
//     }

//     reverse(player2.begin(), player2.end());
//     //stack<int, vector<int>> stack2(player2);
//     stack<int> stack2;
//     for(int card : player2)
//     {
//         stack2.push(card);
//     }

//     int fightCount = 0;
//     while(!stack1.empty() && !stack2.empty())
//     {
//         int x1 = stack1.top();
//         int x2 = stack2.top();

//         if(x1>x2)
//         {
//             stack1.push(x2);
//             stack1.push(x1);

//             stack1.pop();
//             stack2.pop();
//         }
//         else
//         {
//             stack2.push(x1);
//             stack2.push(x2);

//             stack1.pop();
//             stack2.pop();
//         }

//         fightCount++;
//     }

//     if(stack1.empty())
//     {
//         cout << fightCount << " " << "2" << endl;
//     }
//     else if(stack2.empty())
//     {
//         cout << fightCount << " " << "1" << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    int k1;
    cin >> k1;
    vector<int> player1(k1);
    for(int i=0; i<k1; i++)
    {
        cin >> player1[i];
    }

    deque<int> dq1;
    for(int card : player1)
    {
        dq1.push_back(card);
    }

    int k2;
    cin >> k2;
    vector<int> player2(k2);
    for(int i=0; i<k2; i++)
    {
        cin >> player2[i];
    }

    deque<int> dq2;
    for(int card : player2)
    {
        dq2.push_back(card);
    }

    int fightCount = 0;
    while(!dq1.empty() && !dq2.empty())
    {
        int x1 = dq1.front();
        int x2 = dq2.front();

        dq1.pop_front();
        dq2.pop_front();

        if(x1>x2)
        {
            dq1.push_back(x2);
            dq1.push_back(x1);
        }
        else
        {
            dq2.push_back(x1);
            dq2.push_back(x2);
        }

        fightCount++;

        //The game wont end
        if(fightCount>=1000)
        {
            fightCount = -1;
            break;
        }
    }

    if(fightCount==-1)
    {
        cout << "-1" << endl;
    }
    else if(dq1.empty())
    {
        cout << fightCount << " " << "2" << endl;
    }
    else if(dq2.empty())
    {
        cout << fightCount << " " << "1" << endl;
    }

    return 0;
}
