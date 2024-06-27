// C. K-th Not Divisible by n

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two positive integers n and k. Print the k-th positive integer that is not divisible by n. For example, if n=3, and k=7, then all numbers that are not divisible by 3 are: 1,2,4,5,7,8,10,11,13…. The 7-th number among them is 10.

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Next, t test cases are given, one per line. Each test case is two positive integers n (2≤n≤109) and k (1≤k≤109).

// Output
// For each test case print the k-th positive integer that is not divisible by n.

// Example
// inputCopy
// 6
// 3 7
// 4 12
// 2 1000000000
// 7 97
// 1000000000 1000000000
// 2 1

// outputCopy
// 10
// 15
// 1999999999
// 113
// 1000000001
// 1

//My original soln -

//Approach -
//Find the multiples of n, group them in a set
//Subtract the set of natural nums by it
//Then print the kth element of the resulting array

//My original soln -

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
//         //Inputs
//         long long int n, k;
//         cin >> n >> k;

//         //Set to find and store multiples of n
//         set<long long int> multiples;

//         //Starting from the number itself
//         //Iterating till just enough to get the kth num
//         //Updating i+=n to insert only the multiples
//         for(long long int i=n; i<=n*(k+1); i+=n)
//         {
//             multiples.insert(i);
//         }

//         //Storing the kth num
//         long long int reqNum = 0;

//         //The count() function in C++ is a standard library function
//         //It is used to count the occurrences of a specific element in a container(array, vector, set)
//         //It returns the number of elements in the container that are equal to the specified value
//         for(long long int i=1; i<=k+((k+(n-1))/n); i++)
//         {
//             //Counting the occurrences of a specific multiple of n
//             //In set, each element is unique, so its either present(1) or not present(0)
//             //Checks if the value i is present in the set "multiples"
//             if(!multiples.count(i))
//             {
//                 reqNum = i;
//                 k--;
//             }
//             if(k==0)
//             {
//                 break;
//             }
//         }

//         cout << reqNum << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int n, k;
        cin >> n >> k;

        //MAIN logic
        long long int shiftedRight = (k-1)/(n-1);
        long long int answer = k + shiftedRight;

        cout << answer << endl;
    }

    return 0;
}
