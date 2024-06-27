// A. To My Critics

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Suneet has three digits a, b, and c. Since math isn't his strongest point, he asks you to determine if you can choose any two digits to make a sum greater or equal to 10.

// Output "YES" if there is such a pair, and "NO" otherwise.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. The only line of each test case contains three digits a, b, c (0≤a,b,c≤9).

// Output
// For each test case, output "YES" if such a pair exists, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    //Main logic
    bool pairExists = false;
    if(a+b>=10 || b+c>=10 || c+a>=10)
    {
        pairExists = true;
    }
    if(pairExists)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        //Calling the function
        solve();
    }

    return 0;
}
