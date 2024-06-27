// A. Medium Number

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given three distinct integers a, b, and c, find the medium number between all of them. The medium number is the number that is neither the minimum nor the maximum of the given three numbers. For example, the median of 5,2,6 is 5, since the minimum is 2 and the maximum is 6.

// Input
// The first line contains a single integer t (1≤t≤6840) — the number of test cases.

// The description of each test case consists of three distinct integers a, b, c (1≤a,b,c≤20).

// Output
// For each test case, output a single integer — the medium number of the three numbers.

// Example
// Input
// 9
// 5 2 6
// 14 3 4
// 20 2 1
// 1 2 3
// 11 19 12
// 10 8 20
// 6 20 3
// 4 1 3
// 19 8 4
// Output
// 5
// 4
// 2
// 2
// 12
// 10
// 6
// 3
// 8

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
        //Vector to store the three numbers
        vector<int> threeNum(3);

        for(int i=0; i<3; i++)
        {
            cin >> threeNum[i];
        }

        //Sorting the numbers
        sort(threeNum.begin(), threeNum.end());

        //Output the middle element
        cout << threeNum[1] << endl;
    }

    return 0;
}
