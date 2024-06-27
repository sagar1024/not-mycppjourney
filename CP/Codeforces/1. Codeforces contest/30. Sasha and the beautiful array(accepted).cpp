// A. Sasha and the Beautiful Array

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Sasha decided to give his girlfriend an array a1,a2,…,an. He found out that his girlfriend evaluates the beauty of the array as the sum of the values (ai−ai−1) for all integers i from 2 to n. Help Sasha and tell him the maximum beauty of the array a that he can obtain, if he can rearrange its elements in any way.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.

// Output
// For each test case, output a single integer — the maximum beauty of the array a that can be obtained.

// Example
// inputCopy
// 5
// 3
// 2 1 3
// 3
// 69 69 69
// 5
// 100 54 80 43 90
// 4
// 3 4 3 3
// 2
// 2 1
// outputCopy
// 2
// 0
// 57
// 1
// 1

// Note
// In the first test case, the elements of the array a can be rearranged to make a=[1,2,3]. Then its beauty will be equal to (a2−a1)+(a3−a2)=(2−1)+(3−2)=2.
// In the second test case, there is no need to rearrange the elements of the array a. Then its beauty will be equal to 0.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long int> elements(n);
        for(int i=0; i<n; i++)
        {
            cin >> elements[i];
        }

        sort(elements.begin(), elements.end());

        vector<long long int> difference;
        for(int i=1; i<n; i++)
        {
            difference.push_back(elements[i]-elements[i-1]);
        }

        int totalSum = 0;
        for(int i=0; i<difference.size(); i++)
        {
            totalSum += difference[i];
        }

        cout << totalSum << endl;
    }

    return 0;
}
