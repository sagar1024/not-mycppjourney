// B. Special Numbers

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Theofanis really likes sequences of positive integers, thus his teacher (Yeltsa Kcir) gave him a problem about a sequence that consists of only special numbers. Let's call a positive number special if it can be written as a sum of different non-negative powers of n. For example, for n=4 number 17 is special, because it can be written as 40+42=1+16=17, but 9 is not. Theofanis asks you to help him find the k-th special number if they are sorted in increasing order. Since this number may be too large, output it modulo 109+7.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first and only line of each test case contains two integers n and k (2≤n≤109; 1≤k≤109).

// Output
// For each test case, print one integer — the k-th special number in increasing order modulo 109+7.

// Example
// inputCopy
// 3
// 3 4
// 2 12
// 105 564
// outputCopy
// 9
// 12
// 3595374

// Note
// For n=3 the sequence is [1,3,4,9...]

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// const long long int mod = 1e9+7;

// void solve()
// {
//     long long int n, k;
//     cin >> n >> k;

//     vector<long long int> ans;
//     for(long long int i=0; i<k; i++)
//     {
//         //The ith power of n
//         //The pow function returns a floating-point number
//         //AND
//         //Directly applying the modulus operator to it might lead to precision issues
//         long long int x = (long long int)pow(n,i) % mod;
//         ans.push_back(x);
//         for(int j=1; j<ans.size()-1; j++)
//         {
//             ans.push_back((ans[j]+x)%mod);
//         }
//     }

//     sort(ans.begin(), ans.end());
//     cout << ans[k] << endl;

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
const long long int mod = 1e9 + 7;

//Function to compute power with modulo
long long mod_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve()
{
    long long n, k;
    cin >> n >> k;

    long long result = 0;
    long long power = 1;
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            result = (result + power) % mod;
        }
        power = (power * n) % mod;
        k /= 2;
    }

    cout << result << endl;
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
