// B. Pashmak and Flowers

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible! Your task is to write a program which calculates two things:

// The maximum beauty difference of flowers that Pashmak can give to Parmida.
// The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.

// Input
// The first line of the input contains n (2 ≤ n ≤ 2·105). In the next line there are n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109).

// Output
// The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

// Examples
// inputCopy
// 2
// 1 2
// outputCopy
// 1 1

// inputCopy
// 3
// 1 4 5
// outputCopy
// 4 1

// inputCopy
// 5
// 3 1 2 3 1
// outputCopy
// 2 4

// Note
// In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:
// choosing the first and the second flowers;
// choosing the first and the fifth flowers;
// choosing the fourth and the second flowers;
// choosing the fourth and the fifth flowers.

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Inputs
    // Num of flowers
    long long int n;
    cin >> n;

    // Beauty of each flower
    vector<long long int> flowerBeauty(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> flowerBeauty[i];
    }

    // Sorting from least beautiful to most beautiful
    sort(flowerBeauty.begin(), flowerBeauty.end());

    long long int leastBeautiful = flowerBeauty[0];
    long long int mostBeautiful = flowerBeauty[n - 1];

    // Required pair of flowers
    long long int maxDiff = abs(leastBeautiful - mostBeautiful);

    // Counting the num of least and most beautiful flowers
    //  long long int countL = 0;
    //  long long int countM = 0;

    // for(int i=0; i<n; i++)
    // {
    //     if(flowerBeauty[i]==leastBeautiful)
    //     {
    //         countL++;
    //     }
    //     else if(flowerBeauty[i]==mostBeautiful)
    //     {
    //         countM++;
    //     }
    // }

    // //Num of ways the flowers can be picked
    // long long int numOfWays = max(1LL, countL*countM);

    // Counting the number of least and most beautiful flowers
    long long int numOfWays = 0;

    long long int countL = 0;
    long long int countM = 0;

    countL = count(flowerBeauty.begin(), flowerBeauty.end(), leastBeautiful);
    countM = count(flowerBeauty.begin(), flowerBeauty.end(), mostBeautiful);

    // Number of ways the flowers can be picked
    numOfWays = (leastBeautiful == mostBeautiful) ? (n*(n-1)/2) : (countL*countM);

    cout << maxDiff << " " << numOfWays << endl;

    return 0;
}
