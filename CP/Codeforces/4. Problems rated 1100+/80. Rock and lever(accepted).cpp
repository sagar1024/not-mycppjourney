// B. Rock and Lever

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// "You must lift the dam. With a lever. I will give it to you.
// You must block the canal. With a rock. I will not give the rock to you."

// Danik urgently needs rock and lever! Obviously, the easiest way to get these things is to ask Hermit Lizard for them. Hermit Lizard agreed to give Danik the lever. But to get a stone, Danik needs to solve the following task. You are given a positive integer n, and an array a of positive integers. The task is to calculate the number of such pairs (i,j) that i<j and ai & aj≥ai⊕aj, where & denotes the bitwise AND operation, and ⊕ denotes the bitwise XOR operation. Danik has solved this task. But can you solve it?

// Input
// Each test contains multiple test cases. The first line contains one positive integer t (1≤t≤10) denoting the number of test cases. Description of the test cases follows. The first line of each test case contains one positive integer n (1≤n≤105) — length of the array. The second line contains n positive integers ai (1≤ai≤109) — elements of the array. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For every test case print one non-negative integer — the answer to the problem.

// Example
// inputCopy
// 5
// 5
// 1 4 3 7 10
// 3
// 1 1 1
// 4
// 6 2 5 3
// 2
// 2 4
// 1
// 1
// outputCopy
// 1
// 3
// 2
// 0
// 0

// Note
// In the first test case there is only one pair: (4,7): for it 4 & 7=4, and 4⊕7=3.
// In the second test case all pairs are good.
// In the third test case there are two pairs: (6,5) and (2,3).
// In the fourth test case there are no good pairs.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define lli long long int
// #define vll vector<long long int>

// const int N = 2e5 + 5;

// int a[N];

// //MAIN logic func
// void solve()
// {
//     //Inputs
//     lli n;
//     cin >> n;

//     //vll a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     //Counting the num of pairs
//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             //Crux
//             if((a[i]&a[j]) >= (a[i]^a[j]))
//             {
//                 count++;
//             }
//         }
//     }

//     //Output
//     cout << count << endl;
//     return;
// }

// int32_t main()
// {
//     //For better I/O perf
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

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

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int64_t ans = 0;
        vector<int> cnt(30, 0);

        //Counting the frequency of elements that satisfy the condition for each bit position
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                //This line checks if the i-th element a[i] falls within a specific range defined by the bit position j
                //Specifically, it checks if a[i] is greater than or equal to 2^j and less than 2^(j+1)
                //If this condition is true, it means that the i-th element has a set bit at the j-th position
                //If so, it increments the counter cnt[j], which keeps track of how many elements have a set bit at the j-th position in their binary representation.
                if (a[i] >= (1 << j) && a[i] < (1 << (j + 1)))
                {
                    cnt[j]++;
                }
            }
        }

        //Calculating the number of pairs for each bit position
        //This loop iterates through each bit position j from 0 to 29 (assuming 30-bit integers). For each position j
        //It calculates the number of pairs of elements with a set bit at that position by using the formula cnt[j] * (cnt[j] - 1) / 2, where cnt[j]
        //Since each pair is counted twice (once for each element), we divide the product cnt[j] * (cnt[j] - 1) by 2 to avoid double counting
        for (int j = 0; j < 30; j++)
        {
            ans += 1LL * cnt[j] * (cnt[j] - 1) / 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
