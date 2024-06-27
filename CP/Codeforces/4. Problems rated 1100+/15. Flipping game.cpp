// A. Flipping Game

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Iahub got bored, so he invented a game to be played on paper. He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x. The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.

// Input
// The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.

// Output
// Print an integer — the maximal number of 1s that can be obtained after exactly one move.

// Examples
// inputCopy
// 5
// 1 0 0 1 0
// outputCopy
// 4
// inputCopy
// 4
// 1 0 0 1
// outputCopy
// 4

// Note
// In the first case, flip the segment from 2 to 5 (i = 2, j = 5). That flip changes the sequence, it becomes: [1 1 1 0 1]. So, it contains four ones. There is no way to make the whole sequence equal to [1 1 1 1 1].
// In the second case, flipping only the second and the third element (i = 2, j = 3) will turn all numbers into 1.

//My original soln-
//The goal of the game is that after exactly one move(must make a move) to obtain the maximum number of ones

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    vector<long long int> integers(n);

    //Finding the max continuous occurence of 0
    long long int count = 0;
    long long int maxOccurrence = INT_MIN;

    //Counting max num of 1s
    long long int count1 = 0;

    for(long long int i=0; i<n; i++)
    {
        cin >> integers[i];

        if(integers[i]==0)
        {
            count++;
            maxOccurrence = max(count, maxOccurrence);
        }
        else
        {
            count = 0;
        }

        if(integers[i]==1)
        {
            count1++;
        }
    }

    //Special case
    if(n==1 && integers[0]==1)
    {
        cout << 0 << endl;
        return 0;
    }

    //MAIN logic

    //Finding the first and last occurences of 0
    long long int firstOcc = 0;
    long long int lastOcc = 0;

    for(int i=0; i<n; i++)
    {
        if(integers[i]==0)
        {
            if(!firstOcc)
            {
                firstOcc = i;
            }
            lastOcc = i;
        }
    }

    long long int count_0s_Btw_0s = 0;
    long long int count_1s_Btw_0s = 0;

    for(long long int i=firstOcc; i<=lastOcc; i++)
    {
        if(integers[i]==0)
        {
            count_0s_Btw_0s++;
        }
        if(integers[i]==1)
        {
            count_1s_Btw_0s++;
        }
    }

    // if(count_0s_Btw_0s>count_1s_Btw_0s)
    // {
    //     cout << count1-abs(firstOcc-lastOcc)+count_0s_Btw_0s << endl;
    // }
    // else if(count_0s_Btw_0s<count_1s_Btw_0s)
    // {
    //     cout << count1 + maxOccurrence << endl;
    // }
    // else
    // {
    //     cout << count1 + maxOccurrence << endl;
    // }

    int x = count1-count_1s_Btw_0s+abs(firstOcc-lastOcc);
    int y = count1 + maxOccurrence;

    int maxNum = max(x,y);

    cout << maxNum << endl;

    return 0;
}

