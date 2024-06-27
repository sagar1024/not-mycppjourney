// C. Unique Number

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a positive number x. Find the smallest positive integer number that has the sum of digits equal to x and all digits are distinct (unique).

// Input
// The first line contains a single positive integer t (1≤t≤50) — the number of test cases in the test. Then t test cases follow. Each test case consists of a single integer number x (1≤x≤50).

// Output
// Output t answers to the test cases:
// if a positive integer number with the sum of digits equal to x and all digits are different exists, print the smallest such number;
// otherwise print -1.

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int x;
//         cin >> x;

//         //We cant generate a number greater than 45 using single digit numbers from 1 to 9
//         if(x>45)
//         {
//             cout << -1 << endl;
//         }

//         //Initializing an empty vector
//         vector<int> uniqueNum(x);
//         //Main logic
//         for (int i=9; i>0; i--)
//         {
//             while (x>0)
//             {
//                 if (x>i)
//                 {
//                     //Subtracting the bigger numbers first will give us the required smallest positive unique number
//                     x = x-i;
//                     uniqueNum.push_back(i);
//                 }
//             }
//         }

//         //Sorting the numbers to get the smallest +ve number
//         sort(uniqueNum.begin(), uniqueNum.end());
//         //Printing the output
//         for(int x: uniqueNum)
//         {
//             cout << x;
//         }
//     }

//     return 0;
// }

// Chatgpts soln

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (x > 45)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> uniqueNum;

        for (int i = 9; i > 0 && x > 0; --i)
        {
            if (x >= i)
            {
                uniqueNum.push_back(i);
                x -= i;
            }
        }

        sort(uniqueNum.begin(), uniqueNum.end());

        for (int num : uniqueNum)
        {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}
