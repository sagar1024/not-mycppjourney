// C. Numbers on Whiteboard

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Numbers 1,2,3,…n (each integer from 1 to n once) are written on a board. In one operation you can erase any two numbers a and b from the board and write one integer a+b2 rounded up instead. You should perform the given operation n−1 times and make the resulting number that will be left on the board as small as possible. For example, if n=4, the following course of action is optimal:

// choose a=4 and b=2, so the new number is 3, and the whiteboard contains [1,3,3];
// choose a=3 and b=3, so the new number is 3, and the whiteboard contains [1,3];
// choose a=1 and b=3, so the new number is 2, and the whiteboard contains [2].

// It's easy to see that after n−1 operations, there will be left only one number. Your goal is to minimize it.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. The only line of each test case contains one integer n (2≤n≤2⋅105) — the number of integers written on the board initially. It's guaranteed that the total sum of n over test cases doesn't exceed 2⋅105.

// Output
// For each test case, in the first line, print the minimum possible number left on the board after n−1 operations. Each of the next n−1 lines should contain two integers — numbers a and b chosen and erased in each operation.

// Example
// inputCopy
// 1
// 4
// outputCopy
// 2
// 2 4
// 3 3
// 3 1

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
        //Num of numbers on the whiteboard
        int n;
        cin >> n;

        //Array of nums
        vector<int> numbers(n);
        for(int i=0; i<n; i++)
        {
            numbers[i] = i+1;
        }

        //Sorting it in descending order
        sort(numbers.rbegin(), numbers.rend());

        //Vector to store pairs of integers
        //Where each pair represents the two numbers
        //Chosen and erased in each operation
        vector<pair<int, int>> operands;

        //Stores the remaining num after performing the operation
        //Starts from 1st number i.e largest
        int remaining = numbers[0];

        //Loop starts from 2nd number i.e second largest
        for(int i=1; i<n; i++)
        {
            //Storing the operands' pairs in an array
            operands.push_back({remaining, numbers[i]});

            //Updating the "remaining"
            //Performing the operation
            //AND
            //Storing the result in "remaining"
            //Rounded up
            remaining = (remaining+numbers[i]+1)/2;
        }

        //Output the last remaining result
        cout << remaining << endl;

        //Output the operands
        //const auto is used for automatic type deduction
        for(const auto &op: operands)
        {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}
