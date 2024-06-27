// E. Special Elements

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// Pay attention to the non-standard memory limit in this problem. In order to cut off efficient solutions from inefficient ones in this problem, the time limit is rather strict. Prefer to use compiled statically typed languages (e.g. C++). If you use Python, then submit solutions on PyPy. Try to write an efficient solution. The array a=[a1,a2,…,an] (1≤ai≤n) is given. Its element ai is called special if there exists a pair of indices l and r (1≤l<r≤n) such that ai=al+al+1+…+ar. In other words, an element is called special if it can be represented as the sum of two or more consecutive elements of an array (no matter if they are special or not). Print the number of special elements of the given array a. For example, if n=9 and a=[3,1,4,1,5,9,2,6,5], then the answer is 5:

// a3=4 is a special element, since a3=4=a1+a2=3+1;
// a5=5 is a special element, since a5=5=a2+a3=1+4;
// a6=9 is a special element, since a6=9=a1+a2+a3+a4=3+1+4+1;
// a8=6 is a special element, since a8=6=a2+a3+a4=1+4+1;
// a9=5 is a special element, since a9=5=a2+a3=1+4.

// Please note that some of the elements of the array a may be equal — if several elements are equal and special, then all of them should be counted in the answer.

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Then t test cases follow. Each test case is given in two lines. The first line contains an integer n (1≤n≤8000) — the length of the array a. The second line contains integers a1,a2,…,an (1≤ai≤n). It is guaranteed that the sum of the values of n for all test cases in the input does not exceed 8000.

// Output
// Print t numbers — the number of special elements for each of the given arrays.

// Example
// inputCopy
// 5
// 9
// 3 1 4 1 5 9 2 6 5
// 3
// 1 1 2
// 5
// 1 1 1 1 1
// 8
// 8 7 6 5 4 3 2 1
// 1
// 1
// outputCopy
// 5
// 1
// 0
// 4
// 0

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i, n) for (int i = 0; i < n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> givenArray(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     int totalSpecialElements = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int currSum = 0;
//         for (int j = i; j < n; j++)
//         {
//             currSum += givenArray[j];

//             // How to know if the currsum is in given array?
//             // Example -
//             // vector<int> myVector = {1, 5, 3, 2, 5};
//             // Find the (first) occurrence of 5
//             // int valueToFind = 5;
//             // auto it = find(myVector.begin(), myVector.end(), valueToFind);
//             // if (it != myVector.end())
//             // {
//             //     cout << "Element " << valueToFind << " found at index: " << distance(myVector.begin(), it) << endl;
//             // }
//             // else
//             // {
//             //     cout << "Element " << valueToFind << " not found" << endl;
//             // }
            
//             auto iterator = find(givenArray.begin(), givenArray.end(), currSum);
//             if (iterator != givenArray.end())
//             {
//                 totalSpecialElements++;
//             }
//         }
//     }

//     cout << totalSpecialElements << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

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
    vector<int> freq(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
        freq[givenArray[i]]++;
    }

    int specialElementCount = 0;

    //Using two pointers left and rigth
    for(int left=0; left<n; left++)
    {
        int sum = 0;
        for(int right=left; right<n; right++)
        {
            //Calc the contiguous subarray sum of each subarray
            sum += givenArray[right];

            //Avoid the case when both pointer are pointing to the same element
            if(left==right)
            {
                continue;
            }

            //If sum is > n then it is of no use
            //The result of sum of elements should be within n
            if(sum<=n)
            {
                //There might be occurences of the same element twice or thrice
                //So we are adding them all at the same time
                specialElementCount += freq[sum];
                freq[sum] = 0;
            }
        }
    }

    cout << specialElementCount << endl;
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
