// C. Yet Another Array Restoration

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// We have a secret array. You don't know this array and you have to restore it. However, you know some facts about this array:

// The array consists of n distinct positive (greater than 0) integers.
// The array contains two elements x and y (these elements are known for you) such that x<y.
// If you sort the array in increasing order (such that a1<a2<…<an), differences between all adjacent (consecutive) elements are equal (i.e. a2−a1=a3−a2=…=an−an−1).

// It can be proven that such an array always exists under the constraints given below. Among all possible arrays that satisfy the given conditions, we ask you to restore one which has the minimum possible maximum element. In other words, you have to minimize max(a1,a2,…,an). You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow. The only line of the test case contains three integers n, x and y (2≤n≤50; 1≤x<y≤50) — the length of the array and two elements that are present in the array, respectively.

// Output
// For each test case, print the answer: n integers a1,a2,…,an (1≤ai≤109), where ai is the i-th element of the required array. If there are several answers, you can print any (it also means that the order of elements doesn't matter). It can be proven that such an array always exists under the given constraints.

// Example
// inputCopy
// 5
// 2 1 49
// 5 20 50
// 6 20 50
// 5 3 8
// 9 13 22
// outputCopy
// 1 49
// 20 40 30 50 10
// 26 32 20 38 44 50
// 8 23 18 13 3
// 1 10 13 4 19 22 25 16 7

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, x, y;
//         cin >> n >> x >> y;

//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> ans;

        //Finding the common difference (d)
        int d = (y - x) / (n - 1);

        //Starting from y and add elements to the answer vector
        int cur = y;
        while (n--)
        {
            ans.push_back(cur);
            cur -= d;
        }

        //If x is not found in ans, add it to the vector
        if (find(ans.begin(), ans.end(), x) == ans.end())
        {
            ans.push_back(x);
        }

        //Sorting the vector and print the elements
        sort(ans.begin(), ans.end());
        for (int num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
