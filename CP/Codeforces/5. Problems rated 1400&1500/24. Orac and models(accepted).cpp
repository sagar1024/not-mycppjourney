// B. Orac and Models

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n models in the shop numbered from 1 to n, with sizes s1,s2,…,sn. Orac will buy some of the models and will arrange them in the order of increasing numbers (i.e. indices, but not sizes). Orac thinks that the obtained arrangement is beatiful, if for any two adjacent models with indices ij and ij+1 (note that ij<ij+1, because Orac arranged them properly), ij+1 is divisible by ij and sij<sij+1. For example, for 6 models with sizes {3,6,7,7,7,7}, he can buy models with indices 1, 2, and 6, and the obtained arrangement will be beautiful. Also, note that the arrangement with exactly one model is also considered beautiful. Orac wants to know the maximum number of models that he can buy, and he may ask you these queries many times.

// Input
// The first line contains one integer t (1≤t≤100): the number of queries. Each query contains two lines. The first line contains one integer n (1≤n≤100000): the number of models in the shop, and the second line contains n integers s1,…,sn (1≤si≤109): the sizes of models. It is guaranteed that the total sum of n is at most 100000.

// Output
// Print t lines, the i-th of them should contain the maximum number of models that Orac can buy for the i-th query.

// Example
// inputCopy
// 4
// 4
// 5 3 4 6
// 7
// 1 4 2 3 6 4 9
// 5
// 5 4 3 2 1
// 1
// 9

// outputCopy
// 2
// 3
// 1
// 1

// Note

// In the first query, for example, Orac can buy models with indices 2 and 4, the arrangement will be beautiful because 4 is divisible by 2 and 6 is more than 3. By enumerating, we can easily find that there are no beautiful arrangements with more than two models.
// In the second query, Orac can buy models with indices 1, 3, and 6. By enumerating, we can easily find that there are no beautiful arrangements with more than three models.
// In the third query, there are no beautiful arrangements with more than one model.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     //Storing the elements and their indexes
//     vector<long long int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     vector<vector<long long int>> divisors(n, vector<long long int>(n));
//     for(int i=1; i<=n; i++)
//     {
//         vector<long long int> divisorsOfCurrElement(n+1);
//         for(int j=1; j*i<=n; j++)
//         {
//             if(j%i==0)
//             {
//                 divisorsOfCurrElement.push_back(j);
//             }
//         }

//         divisors.push_back(divisorsOfCurrElement);
//     }

//     long long int count = 1;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(givenArray[i]<givenArray[j])
//             {
//                 count++;
//             }
//         }
//     }

//     cout << count << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

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
const int MAXN = 500005;

int a[MAXN], f[MAXN];

int main()
{
    //Test cases
    int T;
    cin >> T;

    while (T--)
    {
        //Inputs
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        //MAIN logic
        //Dyn programming
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i*2; j <= n; j += i)
            {
                if (a[i] < a[j])
                {
                    f[j] = max(f[j], f[i] + 1);
                }
            }
        }

        //Finding maximum value
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, f[i]);
        }

        //Output
        cout << ans << endl;
    }

    return 0;
}
