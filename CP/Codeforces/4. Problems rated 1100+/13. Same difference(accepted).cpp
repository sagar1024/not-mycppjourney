// D. Same Differences

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a of n integers. Count the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

// Input
// The first line contains one integer t (1≤t≤104). Then t test cases follow. The first line of each test case contains one integer n (1≤n≤2⋅105). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — array a. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case output the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

// Example
// inputCopy
// 4
// 6
// 3 5 1 4 6 6
// 3
// 1 2 3
// 4
// 1 3 3 4
// 6
// 1 6 3 4 5 6

// outputCopy
// 1
// 3
// 3
// 10

//My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Array size
//         long int n;
//         cin >> n;

//         //Given array
//         vector<long int> integers(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> integers[i];
//         }

//         //MAIN logic
//         //Counter variable(for num of pairs)
//         int count = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 //Checking the condition
//                 //It true then incrementing the counter
//                 if(i<j && (integers[j]-integers[i]==j-i))
//                 {
//                     count++;
//                 }
//             }
//         }

//         cout << count << endl;
//     }

//     return 0;
// }

//Alternate soln(improved time complexity using hashing) -

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Array size
        long int n;
        cin >> n;

        //Given array
        vector<long int> integers(n);
        for (int i=0; i<n; i++)
        {
            cin >> integers[i];
        }

        //Map to store frequency of differences
        //Difference between elements and its indexes
        //The differences is the key and its freq is the value
        //If the difference is new to map
        //Its default frequency is 0
        //Makes it easy for counting pairs with equal differences
        unordered_map<long int, long int> freq;

        //Counter variable(for num of pairs)
        long long count = 0;

        for (int i=0; i<n; i++)
        {
            //Difference btw element and its index
            long int diff = integers[i] - i;

            //Increment count based on the current frequency of the difference
            //If a "diff" occurs twice, then the freq will be incremented to 1
            //It means that we have found our pair
            count += freq[diff];

            //Update the frequency of the difference
            freq[diff]++;
        }

        cout << count << endl;
    }

    return 0;
}

