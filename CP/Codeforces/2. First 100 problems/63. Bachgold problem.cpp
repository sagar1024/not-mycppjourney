// A. Bachgold Problem

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Bachgold problem is very easy to formulate. Given a positive integer n represent it as a sum of maximum possible number of prime numbers. One can prove that such representation exists for any integer greater than 1. Recall that integer k is called prime if it is greater than 1 and has exactly two positive integer divisors — 1 and k.

// Input
// The only line of the input contains a single integer n (2 ≤ n ≤ 100 000).

// Output
// The first line of the output contains a single integer k — maximum possible number of primes in representation. The second line should contain k primes with their sum equal to n. You can print them in any order. If there are several optimal solution, print any of them.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Func to check whether a number is prime or not
bool isPrime(int x)
{
    if(x<2)
    {
        return false;
    }
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    //Array of natural num till n
    vector<int> setOfNum(n);
    for(int i=0; i<n; i++)
    {
        setOfNum[i] = i+1;
    }

    //To count the number of prime numbers
    int k = 0;
    //To keep track of the sum of elements
    int sum = 0;
    //To store the prime nums in an array
    vector<int> primeNums(k);

    for(int i=0; i<n; i++)
    {
        if(isPrime(i))
        {
            k++;
            primeNums[i] = i;
        }
    }

    cout << k << endl;

    return 0;
}
