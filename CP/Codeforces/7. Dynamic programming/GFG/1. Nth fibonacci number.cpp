//Dynamic programming problem 1 - Nth fibonacci number
//Given a number n, print n-th Fibonacci Number

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }

    //Recusive call
    return fib(n-1)+fib(n-2);
}

int32_t main()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}
