// B. Make Majority

// time limit per test1.5 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// You are given a sequence [a1,…,an] where each element ai is either 0 or 1. You can apply several (possibly zero) operations to the sequence. In each operation, you select two integers 1≤l≤r≤|a| (where |a| is the current length of a) and replace [al,…,ar] with a single element x, where x is the majority of [al,…,ar]. Here, the majority of a sequence consisting of 0 and 1 is defined as follows: suppose there are c0 zeros and c1 ones in the sequence, respectively.

// If c0≥c1, the majority is 0.
// If c0<c1, the majority is 1.

// For example, suppose a=[1,0,0,0,1,1]. If we select l=1,r=2, the resulting sequence will be [0,0,0,1,1]. If we select l=4,r=6, the resulting sequence will be [1,0,0,1]. Determine if you can make a=[1] with a finite number of operations.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤4⋅104). Description of the test cases follows. The first line of each testcase contains one integer n (1≤n≤2⋅105). The second line of each testcase contains a string consisting of 0 and 1, describing the sequence a. It's guaranteed that the sum of n over all testcases does not exceed 2⋅105.

// Output
// For each testcase, if it's possible to make a=[1], print YES. Otherwise, print NO. You can output the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will be recognized as positive responses.

// Example
// inputCopy
// 5
// 1
// 0
// 1
// 1
// 2
// 01
// 9
// 100000001
// 9
// 000011000
// outputCopy
// No
// Yes
// No
// Yes
// No

// Note
// In the fourth testcase of the example, initially a=[1,0,0,0,0,0,0,0,1]. A valid sequence of operations is:
// Select l=2,r=8 and apply the operation. a becomes [1,0,1].
// Select l=1,r=3 and apply the operation. a becomes [1].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n==1)
    {
        if(s=="0") cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    else
    {
        if(s[0]=='1' && s[n-1]=='1') cout << "Yes" << endl;
        else cout << "No" << endl;
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
