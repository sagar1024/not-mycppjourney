// D. Product of Binary Decimals

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's call a number a binary decimal if it is a positive integer and all digits in its decimal notation are either 0 or 1. For example, 1010111 is a binary decimal, while 10201 and 787788 are not. Given a number n, you are asked whether or not it is possible to represent n as a product of some (not necessarily distinct) binary decimals.

// Input
// The first line contains a single integer t (1≤t≤5⋅104) — the number of test cases. The only line of each test case contains a single integer n (1≤n≤105).

// Output
// For each test case, output "YES" (without quotes) if n can be represented as a product of binary decimals, and "NO" (without quotes) otherwise. You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will be recognized as a positive response).

// Example
// inputCopy
// 11
// 121
// 1
// 14641
// 12221
// 10110
// 100000
// 99
// 112
// 2024
// 12421
// 1001
// outputCopy
// YES
// YES
// YES
// YES
// YES
// YES
// NO
// NO
// NO
// NO
// YES

// Note
// The first five test cases can be represented as a product of binary decimals as follows:
// 121=11×11.
// 1=1 is already a binary decimal.
// 14641=11×11×11×11.
// 12221=11×11×101.
// 10110=10110 is already a binary decimal.

// My original soln -

// #include <iostream>
// #include <bitset>
// #include <bits/stdc++.h>

// using namespace std;

// bool isBinaryDecimal(int x)
// {
//     while (x > 0)
//     {
//         int digit = x % 10;
//         if (digit != 0 && digit != 1)
//         {
//             return false;
//         }
//         x /= 10;
//     }
//     return true;
// }

// bool canBeRepresented(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         if (isBinaryDecimal(i))
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (isBinaryDecimal(j))
//                 {
//                     for (int k = 1; k <= n; k++)
//                     {
//                         if (isBinaryDecimal(k))
//                         {
//                             for (int l = 1; l <= n; l++)
//                             {
//                                 if (isBinaryDecimal(l))
//                                 {
//                                     int product = i*j*k*l;
//                                     if (product == n)
//                                     {
//                                         return true;
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

// int32_t main()
// {
//     ios ::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         if (canBeRepresented(n))
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             cout << "NO\n";
//         }
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>

// using namespace std;

// bool isBinaryDecimal(int x)
// {
//     while (x > 0)
//     {
//         int digit = x % 10;
//         if (digit != 0 && digit != 1)
//         {
//             return false;
//         }
//         x /= 10;
//     }
//     return true;
// }

// bool canBeRepresented(int n)
// {
//     //Storing all binary number within the range of n
//     vector<int> binaryNumbers;
//     for (int i = 1; i <= n; i++)
//     {
//         if (isBinaryDecimal(i))
//         {
//             binaryNumbers.push_back(i);
//         }
//     }

//     //All possible subarrays' product
//     int size = binaryNumbers.size();

//     //Optimizing by iterating from front and behind
//     //Iterating from front
//     for (int i=0; i<size; i++)
//     {
//         for(int j=0; j<size; j++)
//         {
//             //Iterating from behind
//             for(int k=size-1; k>=0; k--)
//             {
//                 for(int l=size-1; l>=0; l--)
//                 {
//                     int product = binaryNumbers[i]*binaryNumbers[j]*binaryNumbers[k]*binaryNumbers[l];
//                     if(product==n)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     ios :: sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     //Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         if (canBeRepresented(n))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isBinaryDecimal(int x)
{
    while (x > 0)
    {
        int digit = x % 10;
        if (digit != 0 && digit != 1)
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> binaryNumbers;
    for (int i = 1; i <= 100000; i++)
    {
        if (isBinaryDecimal(i))
        {
            binaryNumbers.push_back(i);
        }
    }

    int size = binaryNumbers.size();
    vector<long long int> possibleProducts;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                for (int l = 0; l < size; l++)
                {
                    int product = binaryNumbers[i] * binaryNumbers[j] * binaryNumbers[k] * binaryNumbers[l];
                    possibleProducts.push_back(product);
                }
            }
        }
    }

    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool answer = false;
        for(int i=0; i<possibleProducts.size(); i++)
        {
            if(possibleProducts[i]==n)
            {
                answer = true;
            }
        }

        if(answer) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
