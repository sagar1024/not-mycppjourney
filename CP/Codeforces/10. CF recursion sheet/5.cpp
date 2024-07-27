// E. Base Converssion

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given a number N. Print the binary equivalent of N. Note: Solve this problem using recursion.

// Input
// First line contains a number T (1 ≤ T ≤ 104) number of test cases. Next T lines will contain a number N (1 ≤ N ≤ 109).

// Output
// For each test case print a single line contains the answer according to the required above.

// Example
// inputCopy
// 2
// 10
// 3
// outputCopy
// 1010
// 11

// Note
// To convert decimal number to binary :
// A decimal integer can be converted to binary by dividing it by 2.
// Take the quotient, and keep dividing it by 2, until you reach zero.
// Each time you perform this division, take note of the remainder. Now reverse the remainders list, and you get the number in binary form
// Example to convert 29 to binary - figure.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void calcBinary(long long int &n, string &ans)
{
    if(n==0 || n==1)
    {
        ans += to_string(n);
        return;    
    }

    int remainder = n%2;
    ans += to_string(remainder);
    n /= 2;
    calcBinary(n,ans);

    return;
}

void solve()
{
    long long int n;
    cin >> n;

    string ans = "";
    calcBinary(n,ans);

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
