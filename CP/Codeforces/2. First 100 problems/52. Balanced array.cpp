// B. Balanced Array

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a positive integer n, it is guaranteed that n is even (i.e. divisible by 2).

// You want to construct the array a of length n such that:

// The first n2 elements of a are even (divisible by 2)
// The second n2 elements of a are odd (not divisible by 2)
// All elements of a are distinct and positive
// The sum of the first half equals to the sum of the second half (∑i=1n2ai=∑i=n2+1nai).

// If there are multiple answers, you can print any. It is not guaranteed that the answer exists.

// You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

// The only line of the test case contains one integer n (2≤n≤2⋅105) — the length of the array. It is guaranteed that that n is even (i.e. divisible by 2).

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer — "NO" (without quotes), if there is no suitable answer for the given test case or "YES" in the first line and any suitable array a1,a2,…,an (1≤ai≤109) satisfying conditions from the problem statement on the second line.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Length of the array, which is an even number
        int n;
        cin >> n;

        // If the array size becomes odd after dividing by 2
        if ((n / 2) % 2 != 0)
        {
            // Then we will print NO
            cout << "NO" << endl;
        }
        //If the array size remains even, even after dividing by 2
        else
        {
            //Then we will print YES
            cout << "YES" << endl;

            // Vector to store the result
            vector<int> suitableArray(n);
            for (int i = 2; i<=2*n; i++)
            {
                // Even numbers
                if (i % 2 == 0)
                {
                    // First half of the array
                    suitableArray[(i/2)-1] = i;
                }
                // Odd numbers
                else if (i % 2 != 0)
                {
                    // Second half of the array
                    suitableArray[(n/2)-(i/2)] = i;
                }
            }

            // Printing the array
            for (int x : suitableArray)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
