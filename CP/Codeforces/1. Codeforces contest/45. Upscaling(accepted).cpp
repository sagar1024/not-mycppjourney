// B. Upscaling

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an integer n. Output a 2n×2n checkerboard made of 2×2 squares alternating '#' and '.', with the top-left cell being '#'.

// (Figure representing the checkerboard for different n)
// The picture above shows the answers for n=1,2,3,4.

// Input
// The first line contains an integer t (1≤t≤20) — the number of test cases. The only line of each test case contains a single integer n (1≤n≤20) — it means you need to output a checkerboard of side length 2n.

// Output
// For each test case, output 2n lines, each containing 2n characters without spaces — the checkerboard, as described in the statement. Do not output empty lines between test cases.

// Example
// inputCopy
// 4
// 1
// 2
// 3
// 4
// outputCopy
// ##
// ##
// ##..
// ##..
// ..##
// ..##
// ##..##
// ##..##
// ..##..
// ..##..
// ##..##
// ##..##
// ##..##..
// ##..##..
// ..##..##
// ..##..##
// ##..##..
// ##..##..
// ..##..##
// ..##..##

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        int n;
        cin >> n;

        for (int i=1; i<=n; i++)
        {
            if (i % 2 != 0)
            {
                for (int j = 1; j<=n; j++)
                {
                    if(j%2!=0)
                    {
                        cout << "##";
                    }
                    else
                    {
                        cout << "..";
                    }
                }
                cout << endl;

                for (int j = 1; j <= n; j++)
                {
                    if(j%2!=0)
                    {
                        cout << "##";
                    }
                    else
                    {
                        cout << "..";
                    }
                }
                cout << endl;
            }
            else
            {
                for (int j = 1; j <= n; j++)
                {
                    if(j%2!=0)
                    {
                        cout << "..";
                    }
                    else
                    {
                        cout << "##";
                    }
                }
                cout << endl;

                for (int j = 1; j <= n; j++)
                {
                    if(j%2!=0)
                    {
                        cout << "..";
                    }
                    else
                    {
                        cout << "##";
                    }
                }
                cout << endl;
            }
        }

        continue;
    }

    return 0;
}
