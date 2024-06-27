// B. Sort the Array

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers. Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.

// Input
// The first line of the input contains an integer n (1 ≤ n ≤ 105) — the size of array a. The second line contains n distinct space-separated integers: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109).

// Output
// Print "yes" or "no" (without quotes), depending on the answer. If your answer is "yes", then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print any of them.

// Examples
// inputCopy
// 3
// 3 2 1
// outputCopy
// yes
// 1 3
// inputCopy
// 4
// 2 1 3 4
// outputCopy
// yes
// 1 2
// inputCopy
// 4
// 3 1 2 4
// outputCopy
// no
// inputCopy
// 2
// 1 2
// outputCopy
// yes
// 1 1

// Note
// Sample 1. You can reverse the entire array to get [1, 2, 3], which is sorted.
// Sample 3. No segment can be reversed such that the array will be sorted.

// Definitions
// A segment [l, r] of array a is the sequence a[l], a[l + 1], ..., a[r].
// If you have an array a of size n and you reverse its segment [l, r], the array will become:
// a[1], a[2], ..., a[l - 2], a[l - 1], a[r], a[r - 1], ..., a[l + 1], a[l], a[r + 1], a[r + 2], ..., a[n - 1], a[n].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> integers(n);
    for(int i=0; i<n; i++)
    {
        cin >> integers[i];
    }

    int left = 0;
    int right = 0;

    for(int i=0; i<n-1; i++)
    {
        if(integers[i]>integers[i+1])
        {
            if(!left)
            {
                left = i+1;
            }
        }
        if(integers[i]<integers[i+1])
        {
            if(!right)
            {
                right = i+1;
            }
        }
    }

    vector<int> reqArray(n,0);
    bool sortingPossible = true;

    for(int i=left; i<right-1; i++)
    {
        if(integers[i]>integers[i+1])
        {
            sortingPossible = false;
        }
        reqArray.push_back(integers[i]);
    }

    //Sorting the segment
    reverse(reqArray.begin(), reqArray.end());

    if(sortingPossible)
    {
        cout << "yes" << endl;

        for(int i=0; i<sizeof(reqArray); i++)
        {
            cout << reqArray[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}

