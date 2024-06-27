// A. Vlad and the Best of Five

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vladislav has a string of length 5, whose characters are each either A or B. Which letter appears most frequently: A or B?

// Input
// The first line of the input contains an integer t (1≤t≤32) — the number of test cases. The only line of each test case contains a string of length 5 consisting of letters A and B. All t strings in a test are different (distinct).

// Output
// For each test case, output one letter (A or B) denoting the character that appears most frequently in the string.

// Example
// inputCopy
// 8
// ABABB
// ABABA
// BBBAB
// AAAAA
// BBBBB
// BABAA
// AAAAB
// BAAAA
// outputCopy
// B
// A
// B
// A
// B
// A
// A
// A

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int countA = 0;
    int countB = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='A')
        {
            countA++;
        }
        else if(s[i]=='B')
        {
            countB++;
        }
    }

    if(countA>=countB)
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "B" << endl;
    }

    return;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
