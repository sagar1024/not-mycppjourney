// G. Pyramid

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print a pyramid of height N. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1≤N≤103).

// Output
// Print the pyramid in N lines.

// Examples
// inputCopy
// 1
// outputCopy
// *
// inputCopy
// 2
// outputCopy
//  *
// ***
// inputCopy
// 3
// outputCopy
//   *
//  ***
// *****
// inputCopy
// 4
// outputCopy
//    *
//   ***
//  *****
// *******

// Note
// Don't print any extra space after '*'.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void printPyramid(int n, int counter)
// {
//     //Base case
//     if(counter==n)
//     {
//         //No spaces needed
//         //The stars
//         for(int i=1; i<=2*counter-counter; i++)
//         {
//             if(i==2*counter-counter)
//             {
//                 cout << "*";
//                 break;
//             }
//             cout << "*" << " ";
//         }

//         return;
//     }

//     printPyramid(n,counter+1);

//     //Spaces
//     for(int i=0; i<n-counter; i++)
//     {
//         cout << " " << " ";
//     }

//     //Stars
//     for(int i=1; i<=2*counter-counter; i++)
//     {
//         if(i==2*counter-counter)
//         {
//             cout << "*";
//             break;
//         }
//         cout << "*" << " ";
//     }

//     //New line
//     cout << endl;

//     return;
// }

// int32_t main()
// {
//     int n;
//     cin >> n;

//     printPyramid(n,0);

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printPyramid(int n, int counter)
{
    //Base case
    if (counter == n)
    {
        return;
    }

    //Printing leading spaces
    for (int i = 0; i < n - counter - 1; i++)
    {
        cout << " " << " ";
    }

    //Printing stars
    for (int i = 0; i < 2 * counter + 1; ++i)
    {
        if(i==2*counter)
        {
            cout << "*";
        }
        else
        {
            cout << "*" << " ";
        }
    }

    //Moving to the next line
    cout << endl;

    printPyramid(n, counter + 1);
    return;
}

int main()
{
    int n;
    cin >> n;

    printPyramid(n, 0);

    return 0;
}
