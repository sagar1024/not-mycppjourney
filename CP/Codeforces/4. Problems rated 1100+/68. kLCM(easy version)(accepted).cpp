// C1. k-LCM (easy version)

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// It is the easy version of the problem. The only difference is that in this version k=3. You are given a positive integer n. Find k positive integers a1,a2,…,ak, such that:

// a1+a2+…+ak=n
// LCM(a1,a2,…,ak)≤n2

// Here LCM is the least common multiple of numbers a1,a2,…,ak. We can show that for given constraints the answer always exists.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The only line of each test case contains two integers n, k (3≤n≤109, k=3).

// Output
// For each test case print k positive integers a1,a2,…,ak, for which all conditions are satisfied.

// Example
// inputCopy
// 3
// 3 3
// 8 3
// 14 3
// outputCopy
// 1 1 1
// 4 2 2
// 2 6 6

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Inputs
        //Here n>=3 and k=3
        long long int n, k;
        cin >> n >> k;

        //MAIN logic
        if(n%2!=0)
        {
            cout << "1" << " " << n/2 << " " << n/2 << endl;
        }
        else
        {
            if(n%4==0)
            {
                cout << n/2 << " " << n/4 << " " << n/4 << endl;
            }
            else
            {
                cout << "2" << " " << n/2-1 << " " << n/2-1 << endl;
            }
        }
    }

    return 0;
}
