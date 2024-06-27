// B. Yet Another Coin Problem

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have 5 different types of coins, each with a value equal to one of the first 5 triangular numbers: 1, 3, 6, 10, and 15. These coin types are available in abundance. Your goal is to find the minimum number of these coins required such that their total value sums up to exactly n. We can show that the answer always exists.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains an integer n (1≤n≤109) — the target value.

// Output
// For each test case, output a single number — the minimum number of coins required.

// Example
// inputCopy
// 14
// 1
// 2
// 3
// 5
// 7
// 11
// 12
// 14
// 16
// 17
// 18
// 20
// 98
// 402931328
// outputCopy
// 1
// 2
// 1
// 3
// 2
// 2
// 2
// 3
// 2
// 3
// 2
// 2
// 8
// 26862090

// Note

// In the first test case, for n=1, the answer is 1 since only one 1 value coin is sufficient. 1=1⋅1.
// In the fourth test case, for n=5, the answer is 3, which can be achieved using two 1 value coins and one 3 value coin. 5=2⋅1+1⋅3.
// In the seventh test case, for n=12, the answer is 2, which can be achieved using two 6 value coins.
// In the ninth test case, for n=16, the answer is 2, which can be achieved using one 1 value coin and one 15 value coin or using one 10 value coin and one 6 value coin. 16=1⋅1+1⋅15=1⋅6+1⋅10.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     // Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         // Target value
//         long long int n;
//         cin >> n;

//         if (n==1 || n==3 || n==6 || n==10 || n==15)
//         {
//             cout << "1" << endl;
//             continue;
//         }

//         // Array representing the values of the 5 types of coins
//         int coins[] = {15, 10, 6, 3, 1};

//         int n1 = n, n2 = n, n3 = n, n4 = n, n5 = n;
//         int count1 = 0;
//         for(int i=0; i<5; i++)
//         {
//             count1 += n1 / coins[i];
//             n1 %= coins[i];
//         }
//         int count2 = 0;
//         for(int i=1; i<5; i++)
//         {
//             count2 += n2 / coins[i];
//             n2 %= coins[i];
//         }
//         int count3 = 0;
//         for(int i=2; i<5; i++)
//         {
//             count3 += n3 / coins[i];
//             n3 %= coins[i];
//         }
//         int count4 = 0;
//         for(int i=3; i<5; i++)
//         {
//             count4 += n4 / coins[i];
//             n4 %= coins[i];
//         }
//         int count5 = 0;
//         for(int i=4; i<5; i++)
//         {
//             count5 += n5 / coins[i];
//             n5 %= coins[i];
//         }

//         int minCoins = INT_MAX;
//         minCoins = min(count1, minCoins);
//         minCoins = min(count2, minCoins);
//         minCoins = min(count3, minCoins);
//         minCoins = min(count4, minCoins);
//         minCoins = min(count5, minCoins);

//         cout << minCoins << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     // Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         // Target value
//         long long int n;
//         cin >> n;

//         // Array representing the values of the 5 types of coins
//         int coins[] = {15, 10, 6, 3, 1};

//         int minCoins = INT_MAX;

//         // Try all possible combinations of coins
//         for (int c1 = 0; c1 <= n / coins[0]; c1++)
//         {
//             for (int c2 = 0; c2 <= n / coins[1]; c2++)
//             {
//                 for (int c3 = 0; c3 <= n / coins[2]; c3++)
//                 {
//                     for (int c4 = 0; c4 <= n / coins[3]; c4++)
//                     {
//                         for (int c5 = 0; c5 <= n / coins[4]; c5++)
//                         {
//                             if (c1 * coins[0] + c2 * coins[1] + c3 * coins[2] + c4 * coins[3] + c5 * coins[4] == n)
//                             {
//                                 minCoins = min(minCoins, c1 + c2 + c3 + c4 + c5);
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         cout << minCoins << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    // Array representing the values of the 5 types of coins
    vector<int> coins = {1, 3, 6, 10, 15};

    while (t--)
    {
        // Target value
        long long int n;
        cin >> n;

        // Initialize dp array
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Dynamic programming
        for (int coin : coins)
        {
            for (int j = coin; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }

        cout << dp[n] << endl;
    }

    return 0;
}
