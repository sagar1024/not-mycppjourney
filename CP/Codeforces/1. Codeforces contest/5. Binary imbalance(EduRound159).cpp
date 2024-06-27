// A. Binary Imbalance

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s, consisting only of characters '0' and/or '1'.

// In one operation, you choose a position i from 1 to |s|−1, where |s| is the current length of string s. Then you insert a character between the i-th and the (i+1)-st characters of s. If si=si+1, you insert '1'. If si≠si+1, you insert '0'.

// Is it possible to make the number of zeroes in the string strictly greater than the number of ones, using any number of operations (possibly, none)?

// Input
// The first line contains a single integer t (1≤t≤100) — the number of testcases.

// The first line of each testcase contains an integer n (1≤n≤100).

// The second line contains a string s of length exactly n, consisting only of characters '0' and/or '1'.

// Output
// For each testcase, print "YES" if it's possible to make the number of zeroes in s strictly greater than the number of ones, using any number of operations (possibly, none). Otherwise, print "NO".

// Example
// Input
// 3
// 2
// 00
// 2
// 11
// 2
// 10
// Output
// YES
// NO
// YES

// Note
// In the first testcase, the number of zeroes is already greater than the number of ones.
// In the second testcase, it's impossible to insert any zeroes in the string.
// In the third testcase, you can choose i=1 to insert a zero between the 1-st and the 2-nd characters. Since s1≠s2, you insert a '0'. The resulting string is "100". It has two zeroes and only a single one, so the answer is "YES".

//My original solution -

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
        //Number of integers
        int n;
        cin >> n;

        //Special case
        if(n==1)
        {
            cout << "NO" << endl;
        }

        //String to store binary numbers
        //It takes non-binary input as well
        //That too of any size
        string s;
        cin >> s;

        //Converting string to array
        // vector<int> numbers(n);
        // for(int i=0; i<n; i++)
        // {
        //     cin >> s[i];
        // }

        //Counting 0s and 1s
        // int count0 = 0;
        // int count1 = 0;

        // for(int i=0; i<n; i++)
        // {
        //     if(s[i]=='0')
        //     {
        //         count0++;
        //     }
        //     else if(s[i]=='1')
        //     {
        //         count1++;
        //     }
        // }

        //Counting the number of 0s and 1s being inserted
        // for(int i=0; i<n-1; i++)
        // {
        //     if(numbers[i]!=numbers[i+1])
        //     {
        //         count0++;
        //     }
        //     else if(numbers[i]==numbers[i+1])
        //     {
        //         count1++;
        //     }
        // }

        //Printing the output for each test case
        //Count of 0s should be strictly greater than 1s
        // if(count0>count1)
        // {
        //     cout << "YES" << endl;
        // }
        // else if(count0<=count1)
        // {
        //     cout << "NO" << endl;
        // }

        //Logic - if even one zero is present
        //Then its possible to make 0s strictly greater than 1s
        bool zeroPresent = false;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                zeroPresent = true;
                break;
            }
        }

        //Printing the output
        if(zeroPresent)
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
