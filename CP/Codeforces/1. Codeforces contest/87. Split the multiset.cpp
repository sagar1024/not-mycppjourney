// A. Split the Multiset

// time limit per test1 second
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// A multiset is a set of numbers in which there can be equal elements, and the order of the numbers does not matter. For example, {2,2,4} is a multiset. You have a multiset S. Initially, the multiset contains only one positive integer n. That is, S={n}. Additionally, there is a given positive integer k. In one operation, you can select any positive integer u in S and remove one copy of u from S. Then, insert no more than k positive integers into S so that the sum of all inserted integers is equal to u. Find the minimum number of operations to make S contain n ones.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows. The only line of each testcase contains two integers n,k (1≤n≤1000,2≤k≤1000).

// Output
// For each testcase, print one integer, which is the required answer.

// Example
// inputCopy
// 4
// 1 5
// 5 2
// 6 3
// 16 4
// outputCopy
// 0
// 4
// 3
// 5

// Note
// For the first test case, initially S={1}, already satisfying the requirement. Therefore, we need zero operations.

// For the second test case, initially S={5}. We can apply the following operations:
// Select u=5, remove u from S, and insert 2,3 into S. Now, S={2,3}.
// Select u=2, remove u from S, and insert 1,1 into S. Now, S={1,1,3}.
// Select u=3, remove u from S, and insert 1,2 into S. Now, S={1,1,1,2}.
// Select u=2, remove u from S, and insert 1,1 into S. Now, S={1,1,1,1,1}.
// Using 4 operations in total, we achieve the goal.

// For the third test case, initially S={6}. We can apply the following operations:
// Select u=6, remove u from S, and insert 1,2,3 into S. Now, S={1,2,3}.
// Select u=2, remove u from S, and insert 1,1 into S. Now, S={1,1,1,3}.
// Select u=3, remove u from S, and insert 1,1,1 into S. Now, S={1,1,1,1,1,1}.
// Using 3 operations in total, we achieve the goal.

// For the fourth test case, initially S={16}. We can apply the following operations:
// Select u=16, remove u from S, and insert 4,4,4,4 into S. Now, S={4,4,4,4}.
// Repeat for 4 times: select u=4, remove u from S, and insert 1,1,1,1 into S.
// Using 5 operations in total, we achieve the goal.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int min_ops(int n, int k)
// {
//     int ops = 0;
//     if (n == 1) return 0;

//     queue<int> q;
//     q.push(n);
//     while (!q.empty())
//     {
//         int k2 = k;
//         auto curr = q.front();
//         q.pop();

//         if (curr == 1) continue;
//         if (curr <= k2)
//         {
//             while (curr--)
//             {
//                 q.push(1);
//             }
//             ops++;
//             continue;
//         }

//         int x = curr / k2;
//         int y = curr % k2;
//         if ((x+y) <= k2)
//         {
//             while (x--)
//             {
//                 q.push(k2);
//             }
//             if (y > 0)
//             {
//                 q.push(y);
//             }
//         }
//         else
//         {
//             k2 -= 1;
//             while(k2--)
//             {
//                 q.push(x);
//             }
//             q.push(x+y);
//         }

//         //Updation
//         ops++;
//     }

//     return ops;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         cout << min_ops(n, k);
//         cout << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min_operations(int n, int k)
{
    if (n == 1) return 0;
    queue<pair<int, int>> q;    // {current value, operation count}
    q.push({n, 0});
    while (!q.empty())
    {
        auto [current_val, ops] = q.front();
        q.pop();

        // If we reach the value 1, we return the operation count
        if (current_val == 1) return ops+1;

        // Try to split the current value
        for (int i = 1; i <= k; i++)
        {
            int next_val = current_val - i;
            if (next_val <= 0) continue; // Invalid state, as we can't have non-positive values
            q.push({next_val, ops + 1});
        }
    }

    return -1; // Should never reach here if n and k are valid
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << min_operations(n, k);
        cout << endl;
    }

    return 0;
}
