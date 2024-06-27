// B. Bad Prices

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp analyzes the prices of the new berPhone. At his disposal are the prices for n last days: a1,a2,…,an, where ai is the price of berPhone on the day i. Polycarp considers the price on the day i to be bad if later (that is, a day with a greater number) berPhone was sold at a lower price. For example, if n=6 and a=[3,9,4,6,7,5], then the number of days with a bad price is 3 — these are days 2 (a2=9), 4 (a4=6) and 5 (a5=7). Print the number of days with a bad price. You have to answer t independent data sets.

// Input
// The first line contains an integer t (1≤t≤10000) — the number of sets of input data in the test. Input data sets must be processed independently, one after another. Each input data set consists of two lines. The first line contains an integer n (1≤n≤150000) — the number of days. The second line contains n integers a1,a2,…,an (1≤ai≤106), where ai is the price on the i-th day. It is guaranteed that the sum of n over all data sets in the test does not exceed 150000.

// Output
// Print t integers, the j-th of which should be equal to the number of days with a bad price in the j-th input data set.

// Example
// inputCopy
// 5
// 6
// 3 9 4 6 7 5
// 1
// 1000000
// 2
// 2 1
// 10
// 31 41 59 26 53 58 97 93 23 84
// 7
// 3 2 1 2 3 4 5

// outputCopy
// 3
// 0
// 1
// 8
// 2

// My original soln(time limit exceeded) -

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
//         //Num of days
//         int n;
//         cin >> n;

//         //Prices
//         vector<int> prices(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> prices[i];
//         }

//         //MAIN logic
//         int badPriceCount = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 //If we find even a single(upcoming) day with a lower price
//                 //We will count it as a bad price day and break the inner for loop
//                 //AND check for the next day
//                 if(prices[i]>prices[j])
//                 {
//                     badPriceCount++;
//                     break;
//                 }
//             }
//         }

//         //Output
//         cout << badPriceCount << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> prices(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        stack<int> stk; // Stack to store indices of days with bad prices
        int badPriceCount = 0;

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && prices[i] < prices[stk.top()])
            {
                stk.pop(); // Pop the index of previous bad price day
                badPriceCount++;
            }
            stk.push(i); // Push the current day's index
        }

        cout << badPriceCount << endl;
    }

    return 0;
}
