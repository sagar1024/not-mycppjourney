// B. Card Constructions

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A card pyramid of height 1 is constructed by resting two cards against each other. For h>1, a card pyramid of height h is constructed by placing a card pyramid of height h−1 onto a base. A base consists of h pyramids of height 1, and h−1 cards on top. For example, card pyramids of heights 1, 2, and 3 look as follows: You start with n cards and build the tallest pyramid that you can. If there are some cards remaining, you build the tallest pyramid possible with the remaining cards. You repeat this process until it is impossible to build another pyramid. In the end, how many pyramids will you have constructed?

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contain descriptions of test cases. Each test case contains a single integer n (1≤n≤109) — the number of cards. It is guaranteed that the sum of n over all test cases does not exceed 109.

// Output
// For each test case output a single integer — the number of pyramids you will have constructed in the end.

// Example
// inputCopy
// 5
// 3
// 14
// 15
// 24
// 1

// outputCopy
// 1
// 2
// 1
// 3
// 0

// Note

// In the first test, you construct a pyramid of height 1 with 2 cards. There is 1 card remaining, which is not enough to build a pyramid.
// In the second test, you build two pyramids, each of height 2, with no cards remaining.
// In the third test, you build one pyramid of height 3, with no cards remaining.
// In the fourth test, you build one pyramid of height 3 with 9 cards remaining. Then you build a pyramid of height 2 with 2 cards remaining. Then you build a final pyramid of height 1 with no cards remaining.
// In the fifth test, one card is not enough to build any pyramids.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to calculate the number of cards in a pyramid of height h
long long int cardsInPyramid(long long int h)
{
    return (3 * h * h + h) / 2;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        if (n == 1)
        {
            cout << "0" << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << "1" << endl;
            continue;
        }

        int pyramidCount = 0;
        int height = 0;

        // while (n >= 2)
        // {
        //     // Calculating the maximum height pyramid that can be built with the given number of cards
        //     int h = (sqrt(1 + 8 * n) - 1) / 2;

        //     // Checking if we can actually build a pyramid of this height
        //     if (h * (3 * h + 1) / 2 <= n)
        //     {
        //         // Reducing the number of cards
        //         n -= h * (3 * h + 1) / 2;
        //         // Incrementing the pyramid count
        //         pyramidCount++;
        //     }
        //     else
        //     {
        //         // If we can't build a pyramid, break out of the loop
        //         break;
        //     }
        // }

        //Keeping building pyramids until it's not possible to build another one
        while (true)
        {
            long long int cardsNeeded = cardsInPyramid(height + 1);
            if (cardsNeeded <= n)
            {
                //Increment pyramid count
                pyramidCount++;
                //Reduce the number of cards
                n -= cardsNeeded;
                //Increment height
                height++;
            }
            else
            {
                break; //If we can't build a pyramid, break out of the loop
            }
        }

        cout << pyramidCount << endl;
    }

    return 0;
}
