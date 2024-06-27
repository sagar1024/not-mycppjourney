// A. Rating Increase

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Monocarp is a great solver of adhoc problems. Recently, he participated in an Educational Codeforces Round, and gained rating!

// Monocarp knew that, before the round, his rating was a. After the round, it increased to b (b>a). He wrote both values one after another to not forget them. However, he wrote them so close to each other, that he can't tell now where the first value ends and the second value starts.

// Please, help him find some values a and b such that:
// neither of them has a leading zero;
// both of them are strictly greater than 0;
// b>a;
// they produce the given value ab when written one after another. If there are multiple answers, you can print any of them.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. The only line of each testcase consists of a single string ab of length from 2 to 8 that:
// consists only of digits;
// doesn't start with a zero.

// Output
// For each testcase, determine if such values a and b exist. If they don't, print -1. Otherwise, print two integers a and b.

// If there are multiple answers, you can print any of them.

// Example
// Input
// 5
// 20002001
// 391125
// 200200
// 2001000
// 12

// Output
// 2000 2001
// 39 1125
// -1
// 200 1000
// 1 2

// Note
// In the second testcase, printing 3 and 91125 is also valid.
// In the third testcase, 20 and 0200 is not valid, because b has a leading zero. 200 and 200 is not valid, because 200 is not strictly greater than 200.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        for(int i=0; i<s.length(); i++)
        {
            //Substring from 0 to i-1
            string a = s.substr(0, i);
            //Substring from i till the end
            string b = s.substr(i);

            if(b[0]=='0' || a[0]=='0')
            {
                continue;
            }

            //Converting substring to int
            int ax = stoi(a);
            int bx = stoi(b);

            if(ax>0 && bx>0 && bx>ax)
            {
                cout << a << " " << b << endl;
                break;
            }
        }
    }

    return 0;
}

