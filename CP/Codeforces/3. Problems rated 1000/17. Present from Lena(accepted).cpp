// // B. Present from Lena

// // time limit per test2 seconds
// // memory limit per test256 megabytes
// // inputstandard input
// // outputstandard output

// // Vasya's birthday is approaching and Lena decided to sew a patterned handkerchief to him as a present. Lena chose digits from 0 to n as the pattern. The digits will form a rhombus. The largest digit n should be located in the centre. The digits should decrease as they approach the edges. For example, for n = 5 the handkerchief pattern should look like that:

// //           0
// //         0 1 0
// //       0 1 2 1 0
// //     0 1 2 3 2 1 0
// //   0 1 2 3 4 3 2 1 0
// // 0 1 2 3 4 5 4 3 2 1 0
// //   0 1 2 3 4 3 2 1 0
// //     0 1 2 3 2 1 0
// //       0 1 2 1 0
// //         0 1 0
// //           0

// // Your task is to determine the way the handkerchief will look like by the given n.

// // Input
// // The first line contains the single integer n (2 ≤ n ≤ 9).

// // Output
// // Print a picture for the given n. You should strictly observe the number of spaces before the first digit on each line. Every two adjacent digits in the same line should be separated by exactly one space. There should be no spaces after the last digit at the end of each line.

// // Examples
// // inputCopy
// // 2
// // outputCopy
// //     0
// //   0 1 0
// // 0 1 2 1 0
// //   0 1 0
// //     0

// // inputCopy
// // 3
// // outputCopy
// //       0
// //     0 1 0
// //   0 1 2 1 0
// // 0 1 2 3 2 1 0
// //   0 1 2 1 0
// //     0 1 0
// //       0

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     //For the upper part
//     for(int i=0; i<=n; i++)
//     {
//         //For the spaces
//         for(int j=n; j>0; j--)
//         {
//             cout << "  ";
//         }

//         //For the increasing nums
//         for(int k=0; k<=i; k++)
//         {
//             cout << k;

//             if(k<i)
//             {
//                 cout << " ";
//             }
//         }

//         //For the decreasing nums
//         if(i!=0)
//         {
//             for(int l=i-1; l>=0; l--)
//             {
//                 cout << " " << l;
//             }
//         }

//         cout << endl;
//     }

//     //For the lower part
//     for(int i=n-1; i>=0; i--)
//     {
//         //For the spaces
//         for(int j=n; j>0; j--)
//         {
//             cout << "  ";
//         }

//         //For the increasing nums
//         for(int k=0; k<n; k++)
//         {
//             cout << k;

//             if(k<i)
//             {
//                 cout << " ";
//             }
//         }

//         //For the decreasing nums
//         if(i!=0 || i!=1)
//         {
//             for(int l=n-2; l>=0; l--)
//             {
//                 cout << " " << l;
//             }
//         }

//         cout << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // For the upper part
    for (int i = 0; i <= n; i++)
    {
        // For the spaces
        for (int j = n; j > i; j--)
        {
            cout << "  ";
        }

        // For the increasing nums
        for (int k = 0; k <= i; k++)
        {
            cout << k;

            if (k < i)
            {
                cout << " ";
            }
        }

        // For the decreasing nums
        if (i != 0)
        {
            for (int l = i - 1; l >= 0; l--)
            {
                cout << " " << l;
            }
        }

        cout << endl;
    }

    // For the lower part
    for (int i = n - 1; i >= 0; i--)
    {
        // For the spaces
        for (int j = n; j > i; j--)
        {
            cout << "  ";
        }

        // For the increasing nums
        for (int k = 0; k <= i; k++)
        {
            cout << k;

            if (k < i)
            {
                cout << " ";
            }
        }

        // For the decreasing nums
        if (i != 0)
        {
            for (int l = i - 1; l >= 0; l--)
            {
                cout << " " << l;
            }
        }

        cout << endl;
    }

    return 0;
}

