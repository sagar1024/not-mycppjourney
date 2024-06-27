// D. Buying Shovels

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp wants to buy exactly n shovels. The shop sells packages with shovels. The store has k types of packages: the package of the i-th type consists of exactly i shovels (1≤i≤k). The store has an infinite number of packages of each type. Polycarp wants to choose one type of packages and then buy several (one or more) packages of this type. What is the smallest number of packages Polycarp will have to buy to get exactly n shovels? For example, if n=8 and k=7, then Polycarp will buy 2 packages of 4 shovels. Help Polycarp find the minimum number of packages that he needs to buy, given that he:

// will buy exactly n shovels in total;
// the sizes of all packages he will buy are all the same and the number of shovels in each package is an integer from 1 to k, inclusive.

// Input
// The first line contains an integer t (1≤t≤100) — the number of test cases in the input. Then, t test cases follow, one per line. Each test case consists of two positive integers n (1≤n≤109) and k (1≤k≤109) — the number of shovels and the number of types of packages.

// Output
// Print t answers to the test cases. Each answer is a positive integer — the minimum number of packages.

// Example
// inputCopy
// 5
// 8 7
// 8 1
// 6 10
// 999999733 999999732
// 999999733 999999733

// outputCopy
// 2
// 8
// 1
// 999999733
// 1

// Note
// The answer to the first test case was explained in the statement.
// In the second test case, there is only one way to buy 8 shovels — 8 packages of one shovel.
// In the third test case, you need to buy a 1 package of 6 shovels.

//My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// bool isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }
//     if (n <= 3)
//     {
//         return true;
//     }
//     if (n % 2 == 0 || n % 3 == 0)
//     {
//         return false;
//     }
//     for (int i = 5; i * i <= n; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Tot num of shovels
//         //Total types of packages
//         long long int n, k;
//         cin >> n >> k;

//         //MAIN logic
//         if(k==1)
//         {
//             cout << n << endl;
//             continue;
//         }
//         else if(n<=k)
//         {
//             cout << "1" << endl;
//             continue;
//         }
//         else if(isPrime(n) && n>=k)
//         {
//             cout << n << endl;
//             continue;
//         }

//         int packages = 0;
//         int minPackages = INT_MAX;

//         for(long long int i=1; i<=k; i++)
//         {
//             //Dividing n/k to get the num of shovels for a specific type
//             //Making sure that the k value perfectly divides n
//             //ALSO making sure that n/k value is less than the n
//             if(n%i==0 && n/i<=k)
//             {
//                 //Num of packages req
//                 packages = n/i;
//                 minPackages = min(packages, minPackages);
//             }
//         }

//         cout << minPackages << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        long long n, k;
        cin >> n >> k;

        if (k >= n)
        {
            //If the number of packages available is greater than or equal to the required shovels
            //We need only one package
            cout << "1\n";
        }
        else
        {
            //Check for the factors of n up to sqrt(n)
            //If we find a factor less than or equal to k, then the minimum number of packages required would be n divided by that factor
            //If no such factor is found, the minimum number of packages required is n divided by n itself
            long long minPackages = n;

            //OPTIMIZATION
            for (long long i=1; i*i<=n; i++)
            {
                if (n%i==0)
                {
                    if (i<=k)
                    {
                        minPackages = min(minPackages, n/i);
                    }
                    if (n/i<=k)
                    {
                        minPackages = min(minPackages, i);
                    }
                }
            }
            cout << minPackages << endl;
        }
    }

    return 0;
}
