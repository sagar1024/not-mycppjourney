// B. Mashmokh and ACM

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Mashmokh's boss, Bimokh, didn't like Mashmokh. So he fired him. Mashmokh decided to go to university and participate in ACM instead of finding a new job. He wants to become a member of Bamokh's team. In order to join he was given some programming tasks and one week to solve them. Mashmokh is not a very experienced programmer. Actually he is not a programmer at all. So he wasn't able to solve them. That's why he asked you to help him with these tasks. One of these tasks is the following. A sequence of l integers b1, b2, ..., bl (1 ≤ b1 ≤ b2 ≤ ... ≤ bl ≤ n) is called good if each number divides (without a remainder) by the next number in the sequence. More formally  for all i (1 ≤ i ≤ l - 1). Given n and k find the number of good sequences of length k. As the answer can be rather large print it modulo 1000000007 (109 + 7).

// Input
// The first line of input contains two space-separated integers n, k (1 ≤ n, k ≤ 2000).

// Output
// Output a single integer — the number of good sequences of length k modulo 1000000007 (109 + 7).

// Examples
// inputCopy
// 3 2
// outputCopy
// 5
// inputCopy
// 6 4
// outputCopy
// 39
// inputCopy
// 2 1
// outputCopy
// 2

// Note

// In the first sample the good sequences are: [1, 1], [2, 2], [3, 3], [1, 2], [1, 3].

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// const int MOD = 1e9+7;

// int fact(int n)
// {
//     int product = 1;
//     for(int i=1; i<=n; i++)
//     {
//         product *= i;
//     }

//     return product;
// }

// int comb(int n, int r)
// {
//     return fact(n)/fact(n-r);
// }

// int32_t main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> divisorsOfEachNum;
//     int count = 0;
//     for(int i=1; i<=n; i++)
//     {
//         count = 0;
//         for(int j=1; j<=n; j++)
//         {
//             if(j%i==0)
//             {
//                 count++;
//             }
//         }
//         divisorsOfEachNum.push_back(count);
//     }

//     long long int totalGoodSeq = 0;
//     for(int i=0; i<divisorsOfEachNum.size(); i++)
//     {
//         totalGoodSeq += comb(divisorsOfEachNum[i], k);
//         totalGoodSeq %= MOD;
//     }

//     cout << totalGoodSeq << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Macros
#define MOD 1000000007
#define ull unsigned long long

//Global var
//Unsigned means larger max positive value
ull n, k, dp[2005][2005];

//The result of the function call is added to the variable x, which accumulates the total number of good sequences starting from i
ull call(ull i, ull cnt)
{
    //Base cases
    //If the value is -1, return it
    //If i>n, return 0 as there can be no good sequence
    //If count==k, return 1 as there can be only one good seq
    if (dp[i][cnt] != -1) return dp[i][cnt];
    if(i>n) return 0;
    if (cnt == k) return 1;

    //Total num of good seq starting from i
    ull x = 0;
    for (ull y=1; i*y<=n; y++)
    {
        //Recursive call
        //Here i*y the next multiple of i and the incremented count is total numbers in the sequence
        x += call(i*y, cnt+1) % MOD;
    }

    //This line calculates the result of the function call and assigns it to dp[i][cnt]. It also returns the calculated value 
    return dp[i][cnt] = x % MOD;
}

int main()
{
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Memset is a function used to fill a block of memory with a particular value
    //It takes three arguments: a pointer to the memory block to be filled, the value to be set, and the number of bytes to be set to the value
    //It is commonly used to initialize arrays or other data structures with a specific value
    memset(dp, -1, sizeof dp);

    //Inputs
    cin >> n >> k;
    ull sum = 0;

    for (ull i = 1; i <= n; i++)
    {
        sum += call(i, 1) % MOD;
    }

    //Output
    cout << sum % MOD << endl;

    return 0;
}
