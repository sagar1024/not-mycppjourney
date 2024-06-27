// A. Multiplication Table

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's consider a table consisting of n rows and n columns. The cell located at the intersection of i-th row and j-th column contains number i × j. The rows and columns are numbered starting from 1. You are given a positive integer x. Your task is to count the number of cells in a table that contain number x.

// Input
// The single line contains numbers n and x (1 ≤ n ≤ 105, 1 ≤ x ≤ 109) — the size of the table and the number that we are looking for in the table.

// Output
// Print a single number: the number of times x occurs in the table.

// Examples
// inputCopy
// 10 5
// outputCopy
// 2

// inputCopy
// 6 12
// outputCopy
// 4

// inputCopy
// 5 13
// outputCopy
// 0

// Note
// A table for the second sample test is given below. The occurrences of number 12 are marked bold.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Size of the table
    int n;
    cin >> n;

    //Number that were looking for
    long int x;
    cin >> x;

    int totalOccurences = 0;
    int divisors = 0;

    //Counting the number of divisors
    for(int i=1; i<=n; i++)
    {
        if(x%i==0)
        {
            divisors++;
        }
    }

    //Num of occurences depends on divisors and comparison between n and x
    //If the table size is greater than or equal to the number that we are looking for, then the number of divisors is the total number of occurences 
    if(n>=x)
    {
        totalOccurences = divisors;
    }
    //If the table size is less than the number that we are looking for, then we will subtract the number of divisors by 1
    if(n<x)
    {
        totalOccurences = divisors - 1;
    }

    cout << totalOccurences << endl;

    return 0;
}
