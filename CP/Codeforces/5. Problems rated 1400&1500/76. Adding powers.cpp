// C. Adding Powers

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Suppose you are performing the following algorithm. There is an array v1,v2,…,vn filled with zeroes at start. The following operation is applied to the array several times — at i-th step (0-indexed) you can:

// either choose position pos (1≤pos≤n) and increase vpos by ki;
// or not choose any position and skip this step.

// You can choose how the algorithm would behave on each step and when to stop it. The question is: can you make array v equal to the given array a (vj=aj for each j) after some step?

// Input
// The first line contains one integer T (1≤T≤1000) — the number of test cases. Next 2T lines contain test cases — two lines per test case. The first line of each test case contains two integers n and k (1≤n≤30, 2≤k≤100) — the size of arrays v and a and value k used in the algorithm. The second line contains n integers a1,a2,…,an (0≤ai≤1016) — the array you'd like to achieve.

// Output
// For each test case print YES (case insensitive) if you can achieve the array a after some step or NO (case insensitive) otherwise.

// Example
// inputCopy
// 5
// 4 100
// 0 0 0 0
// 1 2
// 1
// 3 4
// 1 4 1
// 3 2
// 0 1 3
// 3 9
// 0 59049 810
// outputCopy
// YES
// YES
// NO
// NO
// YES

// Note
// In the first test case, you can stop the algorithm before the 0-th step, or don't choose any position several times and stop the algorithm.
// In the second test case, you can add k0 to v1 and stop the algorithm.
// In the third test case, you can't make two 1 in the array v.
// In the fifth test case, you can skip 90 and 91, then add 92 and 93 to v3, skip 94 and finally, add 95 to v2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<long long int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     //MAIN logic
//     sort(givenArray.begin(), givenArray.end());
//     bool can = true;
//     int power = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(givenArray[i]==0)
//         {
//             continue;
//         }

//         //int loopBreaker = 0;
//         while(givenArray[i]>0)
//         {
//             if(givenArray[i]==pow(k,power))
//             {
//                 can = true;
//                 //Break from while loop
//                 break;
//             }

//             // loopBreaker++;
//             // if(loopBreaker>10000007)
//             // {
//             //     can = false;
//             //     break;
//             // }

//             //Power keeps on increasing
//             power++;

//             if(power>100)
//             {
//                 break;
//             }
//         }

//         if(can==false)
//         {
//             break;
//         }
//     }

//     if(can) cout << "YES" << endl;
//     else cout << "NO" << endl;

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
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

//Function to get the mask for a given number 'a' and base 'k'
long long getMask(long long a, long long k)
{
    long long tmp = a;
    long long res = 0;

    int cnt = 0;
    while (tmp > 0)
    {
        //Check if the remainder is greater than 1
        if (tmp % k > 1) return -1;

        //Add the remainder to the result at the appropriate position
        res |= (tmp % k) << cnt;
        tmp /= k;
        cnt++;
    }

    return res;
}

int32_t main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        long long k;

        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            long long num;
            cin >> num;

            //Getting the masks for each element in the array
            a[i] = getMask(num, k);
        }

        //Filtering out null values
        vector<long long> b;
        for (auto x : a)
        {
            if (x != -1)
            {
                b.push_back(x);
            }
        }

        //If the number of non-null elements is less than 'n', output "NO"
        if (b.size() < n)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            //Calculating the result by performing bitwise OR operation on all elements
            long long res = -1;
            for (auto x : b)
            {
                if (res < 0 || (res & x) > 0)
                {
                    res = -1;
                    break;
                }

                res |= x;
            }

            //If the result is less than 0, output "NO", otherwise output "YES"
            if (res < 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}
