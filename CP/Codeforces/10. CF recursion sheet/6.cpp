// F. Print Even Indices

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a number N and an array A of N numbers. Print the numbers in even indices in a reversed order. Note: Assume array A is 0-based indexing. Solve this problem using recursion.

// Input
// First line contains a number N (1 ≤ N ≤ 103) number of elements. Second line contains N numbers ( - 109 ≤ Ai ≤ 109).

// Output
// Print numbers in even indices in a reversed order separated by spaces.

// Examples
// inputCopy
// 4
// 1 4 2 7
// outputCopy
// 2 1
// inputCopy
// 7
// 1 5 8 2 3 9 11
// outputCopy
// 11 3 8 1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve(vector<long long int> &a, int &n, int counter)
// {
//     if(counter>n)
//     {
//         //cout << a[counter] << endl;
//         return;
//     }
//     solve(a,n,counter+2);
//     cout << a[counter] << " ";
//     return;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int counter = 0;
//     solve(a,n,counter);

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve(const vector<long long> &a, int counter)
{
    if (counter < 0)
    {
        return;
    }

    if(counter==0)
    {
        cout << a[counter];
    }
    else
    {
        cout << a[counter] << " ";
    }

    solve(a, counter - 2);
    return;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    //Starting from the largest even index less than n
    int startIndex = (n-1) % 2 == 0 ? n-1 : n-2;
    solve(a, startIndex);

    return 0;
}
