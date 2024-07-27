// D. Fun

// time limit per test2 seconds
// memory limit per test256 megabytes

// Counting is Fun! — satyam343Given two integers n and x, find the number of triplets (a,b,c) of positive integers such that ab+ac+bc≤n and a+b+c≤x. Note that order matters (e.g. (1,1,2) and (1,2,1) are treated as different) and a, b, c must be strictly greater than 0.

// Input
// The first line contains a single integer t (1≤t≤104)  — the number of test cases. Each test case contains two integers n and x (1≤n,x≤106). It is guaranteed that the sum of n over all test cases does not exceed 106 and that the sum of x over all test cases does not exceed 106.

// Output
// Output a single integer — the number of triplets (a,b,c) of positive integers such that ab+ac+bc≤n and a+b+c≤x.

// Example
// InputCopy
// 4
// 7 4
// 10 5
// 7 1000
// 900000 400000
// OutputCopy
// 4
// 10
// 7
// 1768016938

// Note
// In the first test case, the triplets are (1,1,1), (1,1,2), (1,2,1), and (2,1,1).
// In the second test case, the triplets are (1,1,1), (1,1,2), (1,1,3), (1,2,1), (1,2,2), (1,3,1), (2,1,1), (2,1,2), (2,2,1), and (3,1,1).

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int countTriplets(int n, int x)
// {
//     int count = 0;
//     for (int a = 1; a <= x - 2; a++)
//     {
//         for (int b = 1; b <= x - a - 1; b++)
//         {
//             int max_c = min(x - a - b, (n - a * b) / (a + b));
//             if (max_c >= 1)
//             {
//                 count += max_c;
//             }
//         }
//     }

//     return count;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, x;
//         cin >> n >> x;

//         long long ans = countTriplets(n,x);
//         cout << ans << endl;
//     }
    
//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll countTriplets(long long int n, long long int x)
{
    ll count = 0;
    for (ll a = 1; a <= x-2; a++)
    {
        ll max_bc = n-a*(x-a);
        ll max_b = min(x-a-1, max_bc);

        ll left = 1, right = max_b;
        while (left <= right)
        {
            ll max_c = min(x-a-left, (n-a*left) / (a+left));
            if (max_c >= 1)
            {
                count += right - left + 1;
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, x;
        cin >> n >> x;
        
        cout << countTriplets(n, x) << endl;
    }

    return 0;
}
