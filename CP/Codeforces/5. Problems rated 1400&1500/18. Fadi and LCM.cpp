// C. Fadi and LCM

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Today, Osama gave Fadi an integer X, and Fadi was wondering about the minimum possible value of max(a,b) such that LCM(a,b) equals X. Both a and b should be positive integers. LCM(a,b) is the smallest positive integer that is divisible by both a and b. For example, LCM(6,8)=24, LCM(4,12)=12, LCM(2,3)=6. Of course, Fadi immediately knew the answer. Can you be just like Fadi and find any such pair?

// Input
// The first and only line contains an integer X (1≤X≤1012).

// Output
// Print two positive integers, a and b, such that the value of max(a,b) is minimum possible and LCM(a,b) equals X. If there are several possible such pairs, you can print any.

// Examples
// inputCopy
// 2
// outputCopy
// 1 2
// inputCopy
// 6
// outputCopy
// 2 3
// inputCopy
// 4
// outputCopy
// 1 4
// inputCopy
// 1
// outputCopy
// 1 1

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// // int lcm(int a, int b)
// // {
// //     for(int i=min(a,b); i<=a*b; i++)
// //     {
// //         if(a%i==0 && b%i==0)
// //         {
// //             return i;
// //         }
// //     }
// // }

// int gcd(int a, int b)
// {
//     for(int i=1; i<min(a,b); i++)
//     {
//         if(a%i==0 && b%i==0)
//         {
//             return i;
//         }
//     }

//     return 0;
// }

// int lcm(int a, int b)
// {
//     return (a*b)/gcd(a,b);
// }

// void solve()
// {
//     long long int x;
//     cin >> x;

//     for(int i=1; i<=x/2; i++)
//     {
//         if(lcm(i,x-i)==x)
//         {
//             cout << i << " " << x-i << endl;
//             return;
//         }
//     }
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// long long int lcm(long long int a, long long int b)
// {
//     return (a*b)/__gcd(a,b);
// }

// int32_t main()
// {
//     long long int x;
//     cin >> x;

//     long long int answer = 0;
//     for(int i=1; i*i<=x; i++)
//     {
//         if(x%i==0 && lcm(i,x/i)==x)
//         {
//             answer = i;
//         }
//     }

//     cout << answer << " " << x/answer << endl;
//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    long long int x;
    cin >> x;

    //IMPortant!
    //Factorizing x
    vector<int> factors;
    for(int i=2; i*i<=x; i++)
    {
        if(x%i==0)
        {
            long long int curr = 1;
            while(x%i==0)
            {
                x = x/i;
                curr = curr*i;
            }

            factors.push_back(curr);
        }
    }

    //If there's any prime factor left, add it to the vector f
    if (x>1) factors.push_back(x);

    //Array size
    int n = factors.size();

    //Initializing variables to store the minimum possible max(a, b)
    long long int ax = 1e18, bx = 1e18;

    //Generating all possible combinations of a and b
    for(int i=0; i<(1<<n); i++)
    {
        long long int x1=1, x2=1;
        for (int j = 0; j < n; j++)
        {
            //Deciding whether f[j] should be included in a or b
            if ((i >> j) & 1) x1 *= factors[j];
            else x2 *= factors[j];
        }

        //Updating the minimum max(a, b) found so far
        if (max(x1, x2) < max(ax, bx))
        {
            ax = x1;
            bx = x2;
        }
    }

    //Outputs
    cout << ax << " " << bx << endl;
    
    return;
}

int32_t main()
{
    fastio;
    solve();

    return 0;
}
