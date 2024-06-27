// D. Non-zero Segments

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kolya got an integer array a1,a2,…,an. The array can contain both positive and negative integers, but Kolya doesn't like 0, so the array doesn't contain any zeros. Kolya doesn't like that the sum of some subsegments of his array can be 0. The subsegment is some consecutive segment of elements of the array. You have to help Kolya and change his array in such a way that it doesn't contain any subsegments with the sum 0. To reach this goal, you can insert any integers between any pair of adjacent elements of the array (integers can be really any: positive, negative, 0, any by absolute value, even such a huge that they can't be represented in most standard programming languages). Your task is to find the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0.

// Input
// The first line of the input contains one integer n (2≤n≤200000) — the number of elements in Kolya's array. The second line of the input contains n integers a1,a2,…,an (−109≤ai≤109,ai≠0) — the description of Kolya's array.

// Output
// Print the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0.

// Examples
// inputCopy
// 4
// 1 -5 3 2
// outputCopy
// 1
// inputCopy
// 5
// 4 -2 3 -9 2
// outputCopy
// 0
// inputCopy
// 9
// -1 1 -1 1 -1 1 1 -1 -1
// outputCopy
// 6
// inputCopy
// 8
// 16 -5 -11 -15 10 5 4 -4
// outputCopy
// 3

// Note
// Consider the first example. There is only one subsegment with the sum 0. It starts in the second element and ends in the fourth element. It's enough to insert one element so the array doesn't contain any subsegments with the sum equal to zero. For example, it is possible to insert the integer 1 between second and third elements of the array.
// There are no subsegments having sum 0 in the second example so you don't need to do anything.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         int sum = 0;
//         for(int j=i; j<n; j++)
//         {
//             sum += a[j];
//             if(sum==0)
//             {
//                 count++;
//                 break;
//             }
//         }
//     }

//     cout << count << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    unordered_set<long long int> seen;
    long long int prefixSum = 0;
    
    int count = 0;
    seen.insert(prefixSum);
    for(int i=0; i<n; i++)
    {
        prefixSum += a[i];

        //Checking if the current prefix sum has been seen before
        if(seen.count(prefixSum))
        {
            count++;

            //Resetting the set and prefix sum to break the zero-sum subsegment
            seen.clear();
            seen.insert(0);
            prefixSum = a[i];
        }

        seen.insert(prefixSum);
    }

    cout << count << endl;
    return 0;
}
