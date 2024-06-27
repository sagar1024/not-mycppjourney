// A. Contest Proposal

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A contest contains n problems and the difficulty of the i-th problem is expected to be at most bi. There are already n problem proposals and the difficulty of the i-th problem is ai. Initially, both a1,a2,…,an and b1,b2,…,bn are sorted in non-decreasing order. Some of the problems may be more difficult than expected, so the writers must propose more problems. When a new problem with difficulty w is proposed, the most difficult problem will be deleted from the contest, and the problems will be sorted in a way that the difficulties are non-decreasing. In other words, in each operation, you choose an integer w, insert it into the array a, sort array a in non-decreasing order, and remove the last element from it. Find the minimum number of new problems to make ai≤bi for all i.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains only one positive integer n (1≤n≤100), representing the number of problems. The second line of each test case contains an array a of length n (1≤a1≤a2≤⋯≤an≤109). The third line of each test case contains an array b of length n (1≤b1≤b2≤⋯≤bn≤109).

// Output
// For each test case, print an integer as your answer in a new line.

// Example
// inputCopy
// 2
// 6
// 1000 1400 2000 2000 2200 2700
// 800 1200 1500 1800 2200 3000
// 6
// 4 5 6 7 8 9
// 1 2 3 4 5 6
// outputCopy
// 2
// 3

// Note
// In the first test case:

// Propose a problem with difficulty w=800 and a becomes [800,1000,1400,2000,2000,2200].
// Propose a problem with difficulty w=1800 and a becomes [800,1000,1400,1800,2000,2000].
// It can be proved that it's impossible to reach the goal by proposing fewer new problems.

// In the second test case:

// Propose a problem with difficulty w=1 and a becomes [1,4,5,6,7,8].
// Propose a problem with difficulty w=2 and a becomes [1,2,4,5,6,7].
// Propose a problem with difficulty w=3 and a becomes [1,2,3,4,5,6].
// It can be proved that it's impossible to reach the goal by proposing fewer new problems.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n), b(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }

//     int count = 0;
//     bool solved = false;
//     while (!solved)
//     {
//         int index = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] <= b[i])
//             {
//                 solved = true;
//             }
//             else
//             {
//                 solved = false;
//                 index = i;
//                 break;
//             }
//         }

//         if (!solved)
//         {
//             a.insert(a.begin() + index, b[index]);
//             for (int i = index + 1; i < n; i++)
//             {
//                 a[i] = a[i - 1];
//             }

//             count++;
//         }
//     }

//     cout << count << endl;

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n), b(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }

//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] > b[i])
//         {
//             int diff = a[i] - b[i];
//             a[i] = b[i];
//             count++;

//             for (int j = i + 1; j < n && diff > 0; j++)
//             {
//                 int decrease = min(diff, (int)(a[j] - a[j - 1]));
//                 a[j] -= decrease;
//                 diff -= decrease;
//             }
//         }
//     }

//     cout << count << endl;
//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] > b[i])
        {
            a.insert(a.begin() + i, b[i]);
            count++;
            a.pop_back();
        }
    }

    cout << count << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
