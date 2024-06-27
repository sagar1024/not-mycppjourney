// B. Two Divisors

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A certain number 1≤x≤109 is chosen. You are given two integers a and b, which are the two largest divisors of the number x. At the same time, the condition 1≤a<b<x is satisfied. For the given numbers a, b, you need to find the value of x. The number y is a divisor of the number x if there is an integer k such that x=y⋅k.

// Input
// Each test consists of several test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Then follows the description of the test cases. The only line of each test cases contains two integers a, b (1≤a<b≤109). It is guaranteed that a, b are the two largest divisors for some number 1≤x≤109.

// Output
// For each test case, output the number x, such that a and b are the two largest divisors of the number x. If there are several answers, print any of them.

// Example
// inputCopy
// 8
// 2 3
// 1 2
// 3 11
// 1 5
// 5 10
// 4 6
// 3 9
// 250000000 500000000
// outputCopy
// 6
// 4
// 33
// 25
// 20
// 12
// 27
// 1000000000

// Note
// For the first test case, all divisors less than 6 are equal to [1,2,3], among them the two largest will be 2 and 3.
// For the third test case, all divisors less than 33 are equal to [1,3,11], among them the two largest will be 3 and 11.
// For the fifth test case, all divisors less than 20 are equal to [1,2,4,5,10], among them the two largest will be 5 and 10.
// For the sixth test case, all divisors less than 12 are equal to [1,2,3,4,6], among them the two largest will be 4 and 6.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Function to calculate GCD (Euclidean algorithm)
int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(long long int a, long long int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        int lcmAB = lcm(a,b);

        long long int x = lcmAB; //Answer variable

        if(lcmAB == max(a,b))
        {
            x = x*(max(a,b)/min(a,b));
        }

        cout << x << endl;
    }

    return 0;
}
