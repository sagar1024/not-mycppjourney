// C. Can I Square?

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Calin has n buckets, the i-th of which contains ai wooden squares of side length 1. Can Calin build a large square using all the given squares?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of buckets. The second line of each test case contains n integers a1,…,an (1≤ai≤109) — the number of squares in each bucket. The sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output "YES" if Calin can build a square using all of the given 1×1 squares, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

// My original soln

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Num of buckets
//         int n;
//         cin >> n;

//         //Num of squares in each bucket
//         vector<int> numOfSquares(n);

//         for(int i=0; i<n; i++)
//         {
//             cin >> numOfSquares[i];
//         }

//         //Total num of squares
//         int totalSquares = 0;

//         for(int i=0; i<n; i++)
//         {
//             totalSquares += numOfSquares[i];
//         }

//         //Main logic
//         //Storing the "integral" value of the root of the total num of squares
//         //The decimal part of the sqrt will be lost
//         int squareSide = sqrt(totalSquares);

//         //Checking whether the sqaure of the square's side gives the exact total num of squares
//         //Only the "integral" square roots can regenerate the total num of squares
//         if(squareSide*squareSide == totalSquares)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

// Chatgpts logic

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Num of buckets
        int n;
        cin >> n;

        // Num of squares in each bucket
        vector<long long int> numOfSquares(n);

        for (int i = 0; i < n; i++)
        {
            cin >> numOfSquares[i];
        }

        // Total num of squares
        long long int totalSquares = 0;
        for (int i = 0; i < n; i++)
        {
            totalSquares += numOfSquares[i];
        }

        // Main logic
        //int squareSide = sqrt(totalSquares);
        // Checking whether the square of the next integer is equal to the total num of squares
        //if ((squareSide + 1) * (squareSide + 1) == totalSquares)

        //The cast (int) converts the floating-point square root value to an integer
        //Discarding any decimal part
        if((int)sqrt(totalSquares) * (int)sqrt(totalSquares) == totalSquares)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
