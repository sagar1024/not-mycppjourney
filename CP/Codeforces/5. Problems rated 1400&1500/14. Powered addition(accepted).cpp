// A. Powered Addition

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have an array a of length n. For every positive integer x you are going to perform the following operation during the x-th second: Select some distinct indices i1,i2,…,ik which are between 1 and n inclusive, and add 2x−1 to each corresponding position of a. Formally, aij:=aij+2x−1 for j=1,2,…,k. Note that you are allowed to not select any indices at all. You have to make a nondecreasing as fast as possible. Find the smallest number T such that you can make the array nondecreasing after at most T seconds. Array a is nondecreasing if and only if a1≤a2≤…≤an. You have to answer t independent test cases.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains single integer n (1≤n≤105) — the length of array a. It is guaranteed that the sum of values of n over all test cases in the input does not exceed 105. The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109).

// Output
// For each test case, print the minimum number of seconds in which you can make a nondecreasing.

// Example
// inputCopy
// 3
// 4
// 1 7 6 5
// 5
// 1 2 3 4 5
// 2
// 0 -4

// outputCopy
// 2
// 0
// 3

// Note

// In the first test case, if you select indices 3,4 at the 1-st second and 4 at the 2-nd second, then a will become [1,7,7,8]. There are some other possible ways to make a nondecreasing in 2 seconds, but you can't do it faster.
// In the second test case, a is already nondecreasing, so answer is 0.
// In the third test case, if you do nothing at first 2 seconds and select index 2 at the 3-rd second, a will become [0,0].

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     vll givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     vll diff;
//     for(int i=1; i<n; i++)
//     {
//         if((givenArray[i-1]-givenArray[i])>=0)
//         {
//             continue;
//         }
//         else
//         {
//             long long int difference = givenArray[i-1]-givenArray[i];
//             diff.push_back(difference);
//         }
//     }

//     vll cumulativeSum;
//     long long int currentSum = 0;
//     for(int i=0; i<diff.size(); i++)
//     {
//         currentSum += diff[i];
//         cumulativeSum.push_back(currentSum);
//     }

//     long long int minn = 0;
//     for(int i=0; i<cumulativeSum.size(); i++)
//     {
//         minn = min(cumulativeSum[i], minn);
//     }

//     //Time (to be minimized)
//     // int T = 0;

//     // while(minn!=1)
//     // {
//     //     minn /= 2;
//     //     T++;
//     // }

//     //Calculating the number of bits required to represent the absolute value of minn
//     int T = 0;
//     if (minn != 0)
//     {
//         //Number of bits needed for representation
//         T = log2(abs(minn)) + 1;
//     }

//     cout << T << endl;
//     return;
// }

// int32_t main()
// {
//     fastio;

//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate approach -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n;
    cin >> n;

    vector<long long int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    //Initializing the maximum difference to 0
    long long max_difference = 0;

    //Initializing the maximum value "encountered so far" to a[0] i.e first element
    long long max_value = givenArray[0];

    //Iterating through the array from the second element onwards
    //CRUX
    //Iterating thru the array to calculate the destination value for each array element
    //The destination value is the final value of the element after array becomes nondecreasing
    //We will take the destination value of any element as the maximum element up until now
    //We will subtract the destination value by original value(difference)
    //We will compare the differences and store the maximum difference
    for (int i=1; i<n; i++)
    {
        //Updating the maximum value encountered so far
        max_value = max(max_value, givenArray[i]);

        //Calculating the difference between the current element a[i] and the maximum value
        long long difference = max_value - givenArray[i];

        //Updating the maximum difference if necessary
        max_difference = max(max_difference, difference);
    }

    //Calculating the number of seconds needed
    //Initializing seconds with 0
    //Using left shift operator on 1
    //AND
    //Incrementing seconds while 1<<seconds is greater than maximum difference
    //Here 1<<seconds represents the time T as in the form of 2^x-1
    int seconds = 0;
    while ((1<<seconds)-1 < max_difference)
    {
        seconds++;
    }

    cout << seconds << endl;

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
