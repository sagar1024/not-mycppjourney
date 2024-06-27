// A. Jzzhu and Children

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n children in Jzzhu's school. Jzzhu is going to give some candies to them. Let's number all the children from 1 to n. The i-th child wants to get at least ai candies. Jzzhu asks children to line up. Initially, the i-th child stands at the i-th place of the line. Then Jzzhu start distribution of the candies. He follows the algorithm: Give m candies to the first child of the line. If this child still haven't got enough candies, then the child goes to the end of the line, else the child go home. Repeat the first two steps while the line is not empty. Consider all the children in the order they go home. Jzzhu wants to know, which child will be the last in this order?

// Input
// The first line contains two integers n, m (1 ≤ n ≤ 100; 1 ≤ m ≤ 100). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 100).

// Output
// Output a single integer, representing the number of the last child.

// Examples
// inputCopy
// 5 2
// 1 3 1 4 2
// outputCopy
// 4

// inputCopy
// 6 4
// 1 1 2 2 3 3
// outputCopy
// 6

// Note
// Let's consider the first sample. Firstly child 1 gets 2 candies and go home. Then child 2 gets 2 candies and go to the end of the line. Currently the line looks like [3, 4, 5, 2] (indices of the children in order of the line). Then child 3 gets 2 candies and go home, and then child 4 gets 2 candies and goes to the end of the line. Currently the line looks like [5, 2, 4]. Then child 5 gets 2 candies and goes home. Then child 2 gets two candies and goes home, and finally child 4 gets 2 candies and goes home. Child 4 is the last one who goes home.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     // Num of children candies to each child
//     int n, m;
//     cin >> n >> m;

//     // Num of candies the children wants
//     vector<int> candies;

//     // Child who wants max num of candies will be the last one to go home
//     //  int mostNumOfCandies = 0;
//     //  int positionOfMaxCandies;

//     // for(int i=0; i<n; i++)
//     // {
//     //     cin >> candies[i];

//     //     if(candies[i]>=mostNumOfCandies)
//     //     {
//     //         mostNumOfCandies = candies[i];
//     //         positionOfMaxCandies = i+1;
//     //     }
//     // }

//     // Reading the number of candies each child wants
//     for (int i = 0; i < n; i++)
//     {
//         int candy;
//         cin >> candy;
//         candies.push_back(candy);
//     }

//     // Index of the last child
//     int x = 0;

//     // Simulation of the distribution process
//     while (!candies.empty())
//     {
//         // Flag to check whether the candies were distributed
//         bool distributed = false;

//         // Iterating over each child in the line
//         for (int i = 0; i < candies.size(); i++)
//         {
//             // Distributing the candies to each child
//             candies[i] -= m;

//             // If the current child has enough candies, they go home
//             if (candies[i] <= 0)
//             {
//                 // Remove the child from the line
//                 candies.erase(candies.begin() + i);

//                 // Storing the index of the last child
//                 x = i + 1;

//                 // Adjusting the index after removing
//                 i--;
//             }

//             // Set the flag to indicate candies were distributed
//             distributed = true;
//         }

//         // If no candies were distributed in the last iteration, break the loop
//         if (!distributed)
//         {
//             break;
//         }
//     }

//     cout << x << endl;

//     return 0;
// }

// Alternate soln

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Number of children and candies to each child
    int n, m;
    cin >> n >> m;

    // Number of candies the children want
    vector<int> candies;

    // Reading the number of candies each child wants
    for (int i = 0; i < n; i++)
    {
        int candy;
        cin >> candy;

        candies.push_back(candy);
    }

    // Index of the last child
    int lastChildIndex = 0;

    // Simulation of the distribution process
    while (!candies.empty())
    {
        // Flag to check whether the candies were distributed
        bool distributed = false;

        // Iterating over each child in the line
        for (int i = 0; i < candies.size(); i++)
        {
            // Distributing m candies to the current child
            candies[i] -= m;

            // If the current child has enough candies, they go home
            if (candies[i] <= 0)
            {
                // Remove the child from the line
                candies.erase(candies.begin() + i);

                // Storing the index of the last child
                lastChildIndex = i + 1;

                // Set the flag to indicate candies were distributed
                distributed = true;

                // Adjusting the index after removing
                i--;
            }
        }

        // If no candies were distributed in the last iteration, break the loop
        if (!distributed)
        {
            break;
        }
    }

    cout << lastChildIndex << endl;

    return 0;
}

