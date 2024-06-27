// A. Soldier and Bananas

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// A soldier wants to buy w bananas in the shop. He has to pay k dollars for the first banana, 2k dollars for the second one and so on (in other words, he has to pay i·k dollars for the i-th banana).

// He has n dollars. How many dollars does he have to borrow from his friend soldier to buy w bananas?

// Input
// The first line contains three positive integers k, n, w (1  ≤  k, w  ≤  1000, 0 ≤ n ≤ 109), the cost of the first banana, initial number of dollars the soldier has and number of bananas he wants.

// Output
// Output one integer — the amount of dollars that the soldier must borrow from his friend. If he doesn't have to borrow money, output 0.

#include <iostream>

using namespace std;

int main()
{
    //Cost of 1st banana
    int cost;
    //Initial savings
    int dollars;
    //No. of bananas
    int bananas;

    cin >> cost >> dollars >> bananas;

    //Total cost required to buy bananas
    int totalCost = 0;
    //Money to be borrowed from friend
    int borrow = 0;

    //Iterating over the number of bananas
    for(int i=1; i<=bananas; i++)
    {
        int temp = cost;

        //Calculating the cost for the ith banana
        cost = cost*i;

        //Adding them up
        totalCost += cost;

        //To keep track of the cost of the first banana
        cost = temp;
    }

    //Amount that need to be borrowed
    if(totalCost > dollars)
    {
        borrow = totalCost - dollars;
    }

    cout << borrow << endl;

    return 0;
}

