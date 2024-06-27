// B. Large Addition

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A digit is large if it is between 5 and 9, inclusive. A positive integer is large if all of its digits are large. You are given an integer x. Can it be the sum of two large positive integers with the same number of digits?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The only line of each test case contains a single integer x (10≤x≤1018).

// Output
// For each test case, output YES if x satisfies the condition, and NO otherwise. You can output YES and NO in any case (for example, strings yES, yes, and Yes will be recognized as a positive response).

// Example
// inputCopy
// 11
// 1337
// 200
// 1393938
// 1434
// 98765432123456789
// 11111111111111111
// 420
// 1984
// 10
// 69
// 119
// outputCopy
// YES
// NO
// YES
// YES
// NO
// YES
// NO
// YES
// YES
// NO
// NO

// Note
// In the first test case, we can have 658+679=1337.
// In the second test case, it can be shown that no numbers of equal length and only consisting of large digits can add to 200.
// In the third test case, we can have 696969+696969=1393938.
// In the fourth test case, we can have 777+657=1434.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    string x;
    cin >> x;

    char lastChar = x[x.size()-1];
    if(lastChar=='9')
    {
        cout << "NO" << endl;
        return;
    }

    long long int number = stoll(x);

    string s1(x.size()-1, '5');
    string s2(x.size()-1, '9');

    long long int minSum = stoll(s1) + stoll(s1);
    long long int maxSum = stoll(s2) + stoll(s2);
    if(number>=minSum && number<=maxSum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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
