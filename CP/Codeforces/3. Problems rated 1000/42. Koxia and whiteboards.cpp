// A. Koxia and Whiteboards
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kiyora has n whiteboards numbered from 1 to n. Initially, the i-th whiteboard has the integer ai written on it. Koxia performs m operations. The j-th operation is to choose one of the whiteboards and change the integer written on it to bj. Find the maximum possible sum of integers written on the whiteboards after performing all m operations.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. The description of test cases follows. The first line of each test case contains two integers n and m (1≤n,m≤100). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109). The third line of each test case contains m integers b1,b2,…,bm (1≤bi≤109).

// Output
// For each test case, output a single integer — the maximum possible sum of integers written on whiteboards after performing all m operations.

// Example
// inputCopy
// 4
// 3 2
// 1 2 3
// 4 5
// 2 3
// 1 2
// 3 4 5
// 1 1
// 100
// 1
// 5 3
// 1 1 1 1 1
// 1000000000 1000000000 1000000000
// outputCopy
// 12
// 9
// 1
// 3000000002

// Note
// In the first test case, Koxia can perform the operations as follows:

// Choose the 1-st whiteboard and rewrite the integer written on it to b1=4.
// Choose the 2-nd whiteboard and rewrite to b2=5.

// After performing all operations, the numbers on the three whiteboards are 4, 5and 3 respectively, and their sum is 12. It can be proven that this is the maximum possible sum achievable.

// In the second test case, Koxia can perform the operations as follows:

// Choose the 2-nd whiteboard and rewrite to b1=3.
// Choose the 1-st whiteboard and rewrite to b2=4.
// Choose the 2-nd whiteboard and rewrite to b3=5.

// The sum is 4+5=9. It can be proven that this is the maximum possible sum achievable.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>
// //To use swap()
// #include <algorithm>

// using namespace std;

// //Func to swap two nums
// //Taking the args by reference is imp
// // void swapThem(int &x, int &y)
// // {
// //     x = x+y;
// //     y = x-y;
// //     x = x-y;
// // }

// //Func to solve the prob
// void solve()
// {
//     //Inputs
//     int n, m;
//     cin >> n >> m;

//     vector<long long int> a(n);
//     vector<long long int> b(m);

//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }
//     for(int i=0; i<m; i++)
//     {
//         cin >> b[i];
//     }

//     //Sorting the arrays
//     //Ascending
//     sort(a.begin(), a.end());
//     //Descending
//     sort(b.rbegin(), b.rend());

//     //MAIN logic
//     for(int i=0; i<min(n,m); i++)
//     {
//         //Swapping
//         //Biggest nums of array "b" with smallest nums of array "a"
//         // if(a[i]<b[i])
//         // {
//         //     swapThem(a[i], b[i]);
//         // }
//         // else
//         // {
//         //     break;
//         // }

//         //Since we have to perform all m operations
//         //Here we should not check the condition "if(a[i]<b[i])"
//         swap(a[i], b[i]);
//     }

//     long long int totalSum = 0;
//     for(int i=0; i<n; i++)
//     {
//         totalSum += a[i];
//     }

//     //Calculating total sum w/o using a loop
//     //int totalSum = accumulate(a.begin(), a.end(), 0);

//     cout << totalSum << endl;
//     return;
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Calling the func
//         solve();
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
        int n, m;
        cin >> n >> m;

        vector<long long int> a(n+m);
        for(int i=0; i<(n+m); i++)
        {
            cin >> a[i];
        }

        reverse(a.begin(), a.end());

        long long int answer = 0;

        for(int i=0; i<n; i++)
        {
            answer += a[i];
        }

        cout << answer << endl;
    }

    return 0;
}

//Wrong question

//The code couldnt pass test case 2
//It doesnt even shows the input of the tests
//My soln is perfect as per my knowledge
