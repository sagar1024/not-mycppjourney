// B. Multiply by 2, divide by 6

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an integer n. In one move, you can either multiply n by two or divide n by 6 (if it is divisible by 6 without the remainder). Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The only line of the test case contains one integer n (1≤n≤109).

// Output
// For each test case, print the answer — the minimum number of moves needed to obtain 1 from n if it's possible to do that or -1 if it's impossible to obtain 1 from n.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int count = 0;

        if (n == 1)
        {
            cout << count << endl;
            continue;
        }

        while (n > 1)
        {
            if (n % 6 == 0)
            {
                n = n / 6;
                count++;
            }
            else
            {
                if(n%3!=0)
                {
                    cout << -1 << endl;
                    break;
                }
                n *= 2;
                count++;
            }
        }
        
        if (n < 1)
        {
            cout << -1 << endl;
        }
        if(n==1)
        {
            cout << count << endl;
        }
    }

    return 0;
}
