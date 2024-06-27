// A. Yet Another Two Integers Problem

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two integers a and b.

// In one move, you can choose some integer k from 1 to 10 and add it to a or subtract it from a. In other words, you choose an integer k∈[1;10] and perform a:=a+k or a:=a−k. You may use different values of k in different moves.

// Your task is to find the minimum number of moves required to obtain b from a.

// You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

// The only line of the test case contains two integers a and b (1≤a,b≤109).

// Output
// For each test case, print the answer: the minimum number of moves required to obtain b from a.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    //The two numbers
    int a, b;
    int moveCount = 0;

    //Iterating over the test cases
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

        //Taking the absolute value of the diff btw a and b
        int difference = abs(a - b);

        //If a and b are equal, no move is required
        if (difference==0)
        {
            cout << moveCount << endl;
            continue;
        }

        //If the diff is not equal to 
        //Iterating over 10 to 1
        int x = 10;

        while (x >= 1)
        {
            //Main logic
            if (difference >= x)
            {
                //Here the moveCount will store the quotient which is basically the minimum number of moves required to reduce the diff btw a and b
                //We keep adding the quotient number in each successive loop
                moveCount += difference / x;

                //Here the difference will store the remainder which is basically the left over undivisible number by the current number i 
                difference = difference % x;
            }
            //Updation
            //From 10, 9, 8,... till 1
            x--;
        }

        //Output for each test case
        cout << moveCount << endl;

        //Resetting the moveCount back to 0
        moveCount = 0;
    }

    return 0;
}
