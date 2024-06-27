// A. Moving Chips

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// There is a ribbon divided into n cells, numbered from 1 to n from left to right. Each cell either contains a chip or is free. You can perform the following operation any number of times (possibly zero): choose a chip and move it to the closest free cell to the left. You can choose any chip that you want, provided that there is at least one free cell to the left of it. When you move the chip, the cell where it was before the operation becomes free. Your goal is to move the chips in such a way that they form a single block, without any free cells between them. What is the minimum number of operations you have to perform?

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases. Each test case consists of two lines:

// the first line contains one integer n (2≤n≤50) — the number of cells;
// the second line contains n integers a1,a2,…,an (0≤ai≤1); ai=0 means that the i-th cell is free; ai=1 means that the i-th cell contains a chip.

// Additional constraint on the input: in each test case, at least one cell contains a chip.

// Output
// For each test case, print one integer — the minimum number of operations you have to perform so that all chips form a single block without any free cells between them.

// Example
// inputCopy
// 5
// 8
// 0 1 1 1 0 1 1 0
// 6
// 0 1 0 0 0 0
// 6
// 1 1 1 1 1 1
// 5
// 1 0 1 0 1
// 9
// 0 1 1 0 0 0 1 1 0
// outputCopy
// 1
// 0
// 0
// 2
// 3

// Note
// In the first example, you can perform the operation on the chip in the 7-th cell. The closest free cell to the left is the 5-th cell, so it moves there. After that, all chips form a single block.
// In the second example, all chips are already in a single block. Same for the third example.

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

        vector<int> elements(n);
        int first1 = -1;
        int last1 = -1;
        // for(int i=0; i<n; i++)
        // {
        //     cin >> elements[i];
        //     if(elements[i]==1 && first1==0)
        //     {
        //         first1 = i;
        //     }
        //     if(elements[i]==1)
        //     {
        //         last1 = i;
        //     }
        // }
        for (int i = 0; i < n; ++i)
        {
            cin >> elements[i];
            if (elements[i] == 1)
            {
                if (first1 == -1)
                {
                    first1 = i;
                }
                last1 = i;
            }
        }

        int count = 0;
        for(int i=first1; i<=last1; i++)
        {
            if(elements[i]==0)
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
