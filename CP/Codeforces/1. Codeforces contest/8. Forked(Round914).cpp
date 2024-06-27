// A. Forked!

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Lunchbox is done with playing chess! His queen and king just got forked again! In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and the queen. Lunchbox knows that knights can be tricky, and in the version of chess that he is playing, knights are even trickier: instead of moving 1 tile in one direction and 2 tiles in the other, knights in Lunchbox's modified game move a tiles in one direction and b tiles in the other. Lunchbox is playing chess on an infinite chessboard which contains all cells (x,y) where x and y are (possibly negative) integers. Lunchbox's king and queen are placed on cells (xK,yK) and (xQ,yQ) respectively. Find the number of positions such that if a knight was placed on that cell, it would attack both the king and queen.

// Input
// Each test contains multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers a and b (1≤a,b≤108) — describing the possible moves of the knight. The second line of each test case contains two integers xK and yK (0≤xK,yK≤108) — the position of Lunchbox's king. The third line in a test case contains xQ and yQ (0≤xQ,yQ≤108) — the position of Lunchbox's queen. It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, (xK,yK)≠(xQ,yQ).

// Output
// For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen.

//My original soln + chatgpts help

//Importing the header files
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
        //Knight's maneuvers
        int a, b;
        cin >> a >> b;

        //Kings position
        int xk, yk;
        cin >> xk >> yk;

        //Queens position
        int xq, yq;
        cin >> xq >> yq;

        //Possible knight moves - 8
        //Possible positions from where the king can be attacked - 8
        array<pair<int, int>, 8> pairArray;

        //If the knight is placed at origin
        //It can move to all 4 quadrants
        //For each quadrant, there are 2 possibilities
        //All possible knight moves - 8
        pairArray = {{{xk+a, yk+b}, {xk+b, yk+a},
        {xk-a, yk-b}, {xk-b, yk-a},
        {xk-a, yk+b}, {xk-b, yk+a},
        {xk+a, yk-b}, {xk+b, yk-a}}};

        // Creating a set of unique pairs of knights positions
        set<pair<int, int>> uniquePairs;
        for (const auto &p : pairArray)
        {
            uniquePairs.insert(p);
        }

        //Possible knight moves - 8
        //Possible positions from where the queen can be attacked - 8
        array<pair<int, int>, 8> pairArray2;

        //For each quadrant, there are 2 possibilities
        pairArray2 = {{{xq+a, yq+b}, {xq+b, yq+a},
        {xq-a, yq-b}, {xq-b, yq-a},
        {xq-a, yq+b}, {xq-b, yq+a},
        {xq+a, yq-b}, {xq+b, yq-a}}};

        // Creating a set of unique pairs of knights positions
        set<pair<int, int>> uniquePairs2;
        for (const auto &p : pairArray2)
        {
            uniquePairs2.insert(p);
        }

        //Counting the number of possible positions of knight
        int count = 0;
        
        //Comparing the two sets to count the common positions
        for (const auto &p : uniquePairs)
        {
            //Looking for common knight positions
            if (uniquePairs2.find(p) != uniquePairs2.end())
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
