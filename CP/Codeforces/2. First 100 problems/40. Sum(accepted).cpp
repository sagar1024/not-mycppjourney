// A. Sum

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given three integers a, b, and c. Determine if one of them is the sum of the other two.

// Input
// The first line contains a single integer t (1≤t≤9261) — the number of test cases.

// The description of each test case consists of three integers a, b, c (0≤a,b,c≤20).

// Output
// For each test case, output "YES" if one of the numbers is the sum of the other two, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // int maxNum = max(a, b, c);

        // if (maxNum != a && maxNum != b)
        // {
        //     if (maxNum == a + b)
        //     {
        //         cout << "YES";
        //     }
        //     else
        //     {
        //         cout << "NO";
        //     }
        // }

        // else if (maxNum != b && maxNum != c)
        // {
        //     if (maxNum == b + c)
        //     {
        //         cout << "YES";
        //     }
        //     else
        //     {
        //         cout << "NO";
        //     }
        // }

        // else if (maxNum != a && maxNum != c)
        // {
        //     if (maxNum == a + c)
        //     {
        //         cout << "YES";
        //     }
        //     else
        //     {
        //         cout << "NO";
        //     }
        // }

        if (a + b == c || a + c == b || b + c == a)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

