// A. Shuffle Party

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a1,a2,…,an. Initially, ai=i for each 1≤i≤n. The operation swap(k) for an integer k≥2 is defined as follows:

// Let d be the largest divisor† of k which is not equal to k itself. Then swap the elements ad and ak.

// Suppose you perform swap(i) for each i=2,3,…,n in this exact order. Find the position of 1 in the resulting array. In other words, find such j that aj=1 after performing these operations. An integer x is a divisor of y if there exists an integer z such that y=x⋅z.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The only line of each test case contains one integer n (1≤n≤109) — the length of the array a.

// Output
// For each test case, output the position of 1 in the resulting array.

// Example
// inputCopy
// 4
// 1
// 4
// 5
// 120240229
// outputCopy
// 1
// 4
// 4
// 67108864

// Note
// In the first test case, the array is [1] and there are no operations performed.
// In the second test case, a changes as follows:
// Initially, a is [1,2,3,4].
// After performing swap(2), a changes to [2–,1–,3,4] (the elements being swapped are underlined).
// After performing swap(3), a changes to [3–,1,2–,4].
// After performing swap(4), a changes to [3,4–,2,1–].
// Finally, the element 1 lies on index 4 (that is, a4=1). Thus, the answer is 4.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int n;
        cin >> n;

        long long int answer = 0;
        long long int decrementer = 1;
        long long int count = 0;
        while(n>=1)
        {
            n -= decrementer;
            decrementer *= 2;
            count++;
        }

        answer = pow(2, count-1); 
        cout << answer << endl;
    }

    return 0;
}
