// B. Bogosort

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a1,a2,…,an. Array is good if for each pair of indexes i<j the condition j−aj≠i−ai holds. Can you shuffle this array so that it becomes good? To shuffle an array means to reorder its elements arbitrarily (leaving the initial order is also an option). For example, if a=[1,1,3,5], then shuffled arrays [1,3,5,1], [3,5,1,1] and [5,3,1,1] are good, but shuffled arrays [3,1,5,1], [1,1,3,5] and [1,1,5,3] aren't. It's guaranteed that it's always possible to shuffle an array to meet this condition.

// Input
// The first line contains one integer t (1≤t≤100) — the number of test cases. The first line of each test case contains one integer n (1≤n≤100) — the length of array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100).

// Output
// For each test case print the shuffled version of the array a which is good.

// Example
// inputCopy
// 3
// 1
// 7
// 4
// 1 1 3 5
// 6
// 3 2 1 5 6 4
// outputCopy
// 7
// 1 5 1 3
// 2 4 6 1 3 5

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int a;
//         cin >> a;

//         vector<int> elements(a);
//         for(int i=0; i<a; i++)
//         {
//             cin >> elements[i];
//         }

//         sort(elements.begin(), elements.end());

//         vector<int> result;
//         for(int i=1; i<a; i++)
//         {
//             if((i-elements[i])!=((i-1)-elements[i-1]))
//             {
//                 result.push_back(elements[i-1]);
//             }
//         }

//         for(int i=0; i<a; i++)
//         {
//             cout << result[i] << " " << endl;
//         }
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a;
        cin >> a;

        vector<int> elements(a);
        for(int i=0; i<a; i++)
        {
            cin >> elements[i];
        }

        //Main logic
        sort(elements.begin(), elements.end());
        reverse(elements.begin(), elements.end());

        //Printing the output
        for(int i=0; i<a; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
