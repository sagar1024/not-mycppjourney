// A. Bad Ugly Numbers

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a integer n (n>0). Find any integer s which satisfies these conditions, or report that there are no such numbers:

// In the decimal representation of s:
// s>0,
// s consists of n digits,
// no digit in s equals 0,
// s is not divisible by any of it's digits.

// Input
// The input consists of multiple test cases. The first line of the input contains a single integer t (1≤t≤400), the number of test cases. The next t lines each describe a test case. Each test case contains one positive integer n (1≤n≤105). It is guaranteed that the sum of n for all test cases does not exceed 105.

// Output
// For each test case, print an integer s which satisfies the conditions described above, or "-1" (without quotes), if no such number exists. If there are multiple possible solutions for s, print any solution.

// Example
// inputCopy
// 4
// 1
// 2
// 3
// 4
// outputCopy
// -1
// 57
// 239
// 6789

// Note
// In the first test case, there are no possible solutions for s consisting of one digit, because any such solution is divisible by itself.
// For the second test case, the possible solutions are: 23, 27, 29, 34, 37, 38, 43, 46, 47, 49, 53, 54, 56, 57, 58, 59, 67, 68, 69, 73, 74, 76, 78, 79, 83, 86, 87, 89, 94, 97, and 98.
// For the third test case, one possible solution is 239 because 239 is not divisible by 2, 3 or 9 and has three digits (none of which equals zero).

//Tricky one!
//My original soln

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        //Because 1 is divisible by itself
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }

        //Main logic
        //Start with smallest integer like 2
        //Then append "3" n-1 times
        //To avoid divisibility by 2

        string s = "2";
        for(int i=1; i<=n-1; i++)
        {
            s += 3;
        }

        //If n is greater than 2
        //Append "9" to the remaining digits to avoid divisibility by 3
        if(n>2)
        {
            s += "9";
        }

        cout << s << endl;
    }

    return 0;
}
