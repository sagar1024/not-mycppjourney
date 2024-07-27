// E. Scuza

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Timur has a stairway with n steps. The i-th step is ai meters higher than its predecessor. The first step is a1 meters higher than the ground, and the ground starts at 0 meters. The stairs for the first test case. Timur has q questions, each denoted by an integer k1,…,kq. For each question ki, you have to print the maximum possible height Timur can achieve by climbing the steps if his legs are of length ki. Timur can only climb the j-th step if his legs are of length at least aj. In other words, ki≥aj for each step j climbed. Note that you should answer each question independently.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases. The first line of each test case contains two integers n,q (1≤n,q≤2⋅105) — the number of steps and the number of questions, respectively. The second line of each test case contains n integers (1≤ai≤109) — the height of the steps. The third line of each test case contains q integers (0≤ki≤109) — the numbers for each question. It is guaranteed that the sum of n does not exceed 2⋅105, and the sum of q does not exceed 2⋅105.

// Output
// For each test case, output a single line containing q integers, the answer for each question. Please note, that the answer for some questions won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

// Example
// inputCopy
// 3
// 4 5
// 1 2 1 5
// 1 2 4 9 10
// 2 2
// 1 1
// 0 1
// 3 1
// 1000000000 1000000000 1000000000
// 1000000000
// outputCopy
// 1 4 4 9 9
// 0 2
// 3000000000

// Note
// Consider the first test case, pictured in the statement.
// If Timur's legs have length 1, then he can only climb stair 1, so the highest he can reach is 1 meter.
// If Timur's legs have length 2 or 4, then he can only climb stairs 1, 2, and 3, so the highest he can reach is 1+2+1=4 meters.
// If Timur's legs have length 9 or 10, then he can climb the whole staircase, so the highest he can reach is 1+2+1+5=9 meters.
// In the first question of the second test case, Timur has no legs, so he cannot go up even a single step. :(

// My original soln(tle on tc5) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<long long int> steps(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> steps[i];
//     }

//     vector<long long int> result;
//     for(int i=0; i<q; i++)
//     {
//         long long int legSize;
//         cin >> legSize;

//         long long int ans = 0;
//         int x = 0;
//         while(legSize>=steps[x] && x<n)
//         {
//             ans += steps[x];
//             x++;
//         }

//         result.push_back(ans);
//     }

//     //Output
//     for(auto x: result)
//     {
//         cout << x << " ";
//     }

//     cout << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// bool canJumpThisHigh(vector<long long int> &givArray, int currIdx, long long int currQues)
// {
//     bool yes = true;
//     for(int i=0; i<=currIdx; i++)
//     {
//         if(currQues>=givArray[i])
//         {
//             continue;
//         }
//         else
//         {
//             yes = false;
//             break;
//         }
//     }

//     return yes;
// }

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<long long int> steps(n);
//     vector<long long int> prefSum(n);
//     long long int sum = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> steps[i];
//         sum += steps[i];
//         prefSum[i] = sum;
//     }

//     vector<long long int> result;
//     while(q--)
//     {
//         long long int question;
//         cin >> question;

//         int left=0, right=n-1;
//         long long int ans = 0;
//         while(left<=right)
//         {
//             int mid = (left+right)/2;
//             //long long int x = prefSum[mid];
//             if(canJumpThisHigh(steps,mid,question))
//             {
//                 ans = mid;
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//         }

//         long long int res = prefSum[ans];
//         result.push_back(res);
//     }

//     for(auto x: result)
//     {
//         cout << x << " ";
//     }

//     cout << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<long long> steps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> steps[i];
    }

    vector<long long> prefixSum(n);
    prefixSum[0] = steps[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + steps[i];
    }

    while (q--)
    {
        long long legSize;
        cin >> legSize;

        //Finding the largest index
        //Such that steps[index] <= legSize
        //Using binary search
        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (steps[mid] <= legSize)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (ans == -1)
        {
            cout << "0 ";
        }
        else
        {
            cout << prefixSum[ans] << " ";
        }
    }

    cout << endl;
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
