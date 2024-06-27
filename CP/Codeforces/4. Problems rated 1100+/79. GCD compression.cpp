// B. GCD Compression

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ashish has an array a of consisting of 2n positive integers. He wants to compress a into an array b of size n−1. To do this, he first discards exactly 2 (any two) elements from a. He then performs the following operation until there are no elements left in a: Remove any two elements from a and append their sum to b. The compressed array b has to have a special property. The greatest common divisor (gcd) of all its elements should be greater than 1. Recall that the gcd of an array of positive integers is the biggest integer that is a divisor of all integers in the array. It can be proven that it is always possible to compress array a into an array b of size n−1 such that gcd(b1,b2...,bn−1)>1. Help Ashish find a way to do so.

// Input
// The first line contains a single integer t (1≤t≤10) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤1000). The second line of each test case contains 2n integers a1,a2,…,a2n (1≤ai≤1000) — the elements of the array a.

// Output
// For each test case, output n−1 lines — the operations performed to compress the array a to the array b. The initial discard of the two elements is not an operation, you don't need to output anything about it. The i-th line should contain two integers, the indices (1—based) of the two elements from the array a that are used in the i-th operation. All 2n−2 indices should be distinct integers from 1 to 2n. You don't need to output two initially discarded elements from a. If there are multiple answers, you can find any.

// Example
// inputCopy
// 3
// 3
// 1 2 3 4 5 6
// 2
// 5 7 9 10
// 5
// 1 3 3 4 5 90 100 101 2 3

// outputCopy
// 3 6
// 4 5
// 3 4
// 1 9
// 2 3
// 4 5
// 6 10

// Note
// In the first test case, b={3+6,4+5}={9,9} and gcd(9,9)=9.
// In the second test case, b={9+10}={19} and gcd(19)=19.
// In the third test case, b={1+2,3+3,4+5,90+3}={3,6,9,93} and gcd(3,6,9,93)=3.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    //Test cases
    int t;
    cin >> t;

    //Array to store the original array
    int a[N];

    while(t--)
    {
        //Inputs
        int n;
        cin >> n;

        //Dividing the given array into even and odd elements
        vector<int> even, odd;
        for(int i=1; i<=2*n; i++)
        {
            cin >> a[i];
            if(a[i]%2==0)
            {
                //Storing the index of the numbers of the original array
                //In their respective array i.e even or odd
                even.push_back(i);
            }
            else
            {
                odd.push_back(i);
            }
        }

        //Answer array to store the required pairs
        vector<pair<int,int>> answer;

        //Making the pairs of even and odd elements
        for(int i=0; i<even.size()-1; i+=2)
        {
            answer.push_back({even[i], even[i+1]});
        }
        for(int i=0; i<odd.size()-1; i+=2)
        {
            answer.push_back({odd[i], odd[i+1]});
        }

        //Outputs
        for(int i=0; i<n-1; i++)
        {
            cout << answer[i].first << " " << answer[i].second << endl;
        }
    }

    return 0;
}
