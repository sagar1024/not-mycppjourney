// B. Minor Reduction

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a decimal representation of an integer x without leading zeros. You have to perform the following reduction on it exactly once: take two neighboring digits in x and replace them with their sum without leading zeros (if the sum is 0, it's represented as a single 0). For example, if x=10057, the possible reductions are:

// choose the first and the second digits 1 and 0, replace them with 1+0=1; the result is 1057;
// choose the second and the third digits 0 and 0, replace them with 0+0=0; the result is also 1057;
// choose the third and the fourth digits 0 and 5, replace them with 0+5=5; the result is still 1057;
// choose the fourth and the fifth digits 5 and 7, replace them with 5+7=12; the result is 10012.

// What's the largest number that can be obtained?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. Each testcase consists of a single integer x (10≤x<10200000). x doesn't contain leading zeros. The total length of the decimal representations of x over all testcases doesn't exceed 2⋅105.

// Outputa
// For each testcase, print a single integer — the largest number that can be obtained after the reduction is applied "exactly once". The number should not contain leading zeros.

// Example
// inputCopy
// 2
// 10057
// 90
// outputCopy
// 10012
// 9

// Note

// The first testcase of the example is already explained in the statement.
// In the second testcase, there is only one possible reduction: the first and the second digits.

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string x;
    cin >> x;

    // Dummy string
    string y = x;

    // MAIN logic
    //  string answer;
    //  answer.push_back(x[0]);

    // //Iterating over the given number
    // for(int i=1; i<x.size()-1; i++)
    // {
    //     //Adding the two consecutive nums
    //     int a = (x[i] - '0') + (x[i+1] - '0');
    //     string b = to_string(a);

    //     //Appending the sum to the answer string
    //     answer.append(b);
    // }

    if (x.size() > 3)
    {
        vector<int> dp;
        for (int i = 0; i < x.size() - 1; i++)
        {
            dp.push_back(x[i] - '0' + x[i + 1] - '0');
        }

        //Minor reduction from the left
        if (dp[0] > 10)
        {
            // How to replace the first two string of x by this dp[0] all in strings?
            x.erase(0, 2);
            x.insert(0, to_string(dp[0]));
        }
        // else
        // {
        //     //How to replace the last two strings of x by the dp[dp.size()-1]'s value?
        //     x.erase(x.size() - 2, 2);
        //     x.append(to_string(dp[dp.size() - 1]));
        // }

        //Minor reduction from the right
        y.erase(y.size() - 2, 2);
        y.append(to_string(dp[dp.size() - 1]));

        int a = stoi(x);
        int b = stoi(y);

        cout << min(a, b) << endl;
    }
    //For two digit numbers
    else if(x.size()==2)
    {
        int a = stoi(x);
        int sum = a/10 + a%10;
        cout << sum << endl;
    }
    //For three digit numbers
    else if(x.size()==3)
    {
        int a = x[0]+x[1];
        int b = x[1]+x[2];

        if(a>10)
        {
            x.erase(1, 2);
            x.append(to_string(b));
        }
        else if(a>b)
        {
            x.erase(0, 2);
            x.insert(0, to_string(a));
        }
    }

    return;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
