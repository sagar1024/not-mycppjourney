// B. Omkar and Last Class of Math

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In Omkar's last class of math, he learned about the least common multiple, or LCM. LCM(a,b) is the smallest positive integer x which is divisible by both a and b. Omkar, having a laudably curious mind, immediately thought of a problem involving the LCM operation: given an integer n, find positive integers a and b such that a+b=n and LCM(a,b) is the minimum value possible. Can you help Omkar solve his ludicrously challenging math problem?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10). Description of the test cases follows. Each test case consists of a single integer n (2≤n≤109).

// Output
// For each test case, output two positive integers a and b, such that a+b=n and LCM(a,b) is the minimum possible.

// Example
// inputCopy
// 3
// 4
// 6
// 9
// outputCopy
// 2 2
// 3 3
// 3 6

// Note
// For the first test case, the numbers we can choose are 1,3 or 2,2. LCM(1,3)=3 and LCM(2,2)=2, so we output 2 2.
// For the second test case, the numbers we can choose are 1,5, 2,4, or 3,3. LCM(1,5)=5, LCM(2,4)=4, and LCM(3,3)=3, so we output 3 3.
// For the third test case, LCM(3,6)=6. It can be shown that there are no other pairs of numbers which sum to 9 that have a lower LCM.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int largestProperFactor(long long int x)
{
    //Initializing result with 1, incase x is prime
    long long int result = 1;
    for(long long int i=2; i<=x; i++)
    {
        if(x%i==0 && x!=i)
        {
            result = i;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int n;
        cin >> n;

        long long int firstNum = largestProperFactor(n);
        long long int secondNum = n - firstNum;

        cout << firstNum << " " << secondNum << endl;
    }

    return 0;
}
