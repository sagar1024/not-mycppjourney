// B. Divisors of Two Integers

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Recently you have received two positive integer numbers x and y. You forgot them, but you remembered a shuffled list containing all divisors of x (including 1 and x) and all divisors of y (including 1 and y). If d is a divisor of both numbers x and y at the same time, there are two occurrences of d in the list. For example, if x=4 and y=6 then the given list can be any permutation of the list [1,2,4,1,2,3,6]. Some of the possible lists are: [1,1,2,4,6,3,2], [4,6,1,1,2,3,2] or [1,6,3,2,4,1,2]. Your problem is to restore suitable positive integer numbers x and y that would yield the same list of divisors (possibly in different order). It is guaranteed that the answer exists, i.e. the given list of divisors corresponds to some positive integers x and y.

// Input
// The first line contains one integer n (2≤n≤128) — the number of divisors of x and y. The second line of the input contains n integers d1,d2,…,dn (1≤di≤104), where di is either divisor of x or divisor of y. If a number is divisor of both numbers x and y then there are two copies of this number in the list.

// Output
// Print two positive integer numbers x and y — such numbers that merged list of their divisors is the permutation of the given list of integers. It is guaranteed that the answer exists.

// Example
// inputCopy
// 10
// 10 2 8 1 2 4 1 20 4 5

// outputCopy
// 20 8

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<int> divisors(n);
//     for(int  i=0;i<n; i++)
//     {
//         cin >> divisors[i];
//     }

//     sort(divisors.begin(), divisors.end());
//     int powerOf2 = 1;
//     int first = 1;
//     int second = 1;
//     for(int i=0; i<n; i++)
//     {
//         if(divisors[i]==powerOf2)
//         {
//             first *= powerOf2;
//             divisors.erase(i, 1); //Can't erase?
//             powerOf2 *= 2;
//         }
//     }
//     for(int i=0; i<divisors.size(); i++)
//     {
//         second *= divisors[i];
//     }

//     cout << first << " " << second << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> divisors(n);
    for (int i = 0; i < n; i++)
    {
        cin >> divisors[i];
    }

    sort(divisors.begin(), divisors.end());

    //Stores the largest divisor in the given array
    //It is also the first required number
    int x = divisors.back();
    //Pops it off
    divisors.pop_back();

    for (int i = 0; i < divisors.size(); i++)
    {
        //First divisor that will can't divide x(largest div) is the second number
        if (x % divisors[i] != 0)
        {
            cout << divisors[i] << " " << x << endl;
            return 0;
        }
    }

    cout << x << " " << x << endl;

    return 0;
}
