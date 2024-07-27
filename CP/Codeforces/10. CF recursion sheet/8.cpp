// H. Inverted Pyramid

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print an inverted pyramid of height N. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1≤N≤103).

// Output
// Print the pyramid in N lines. Don't print any extra space after '*'.

// Examples
// inputCopy
// 1
// outputCopy
// *
// inputCopy
// 2
// outputCopy
// ***
//  *
// inputCopy
// 3
// outputCopy
// *****
//  ***
//   *
// inputCopy
// 4
// outputCopy
// *******
//  *****
//   ***
//    *

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printPyramid(int n, int counter)
{
    //Base case
    if (counter == 0)
    {
        return;
    }

    printPyramid(n, counter-1);
    for (int i = 0; i < counter - 1; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 2*(n-counter)+1; i++)
    {
        cout << "*";
    }
    
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;

    printPyramid(n, n);

    return 0;
}
