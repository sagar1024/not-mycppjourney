// B. Regular Bracket Sequence

// time limit per test5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A bracket sequence is called regular if it is possible to obtain correct arithmetic expression by inserting characters «+» and «1» into this sequence. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not. One day Johnny got bracket sequence. He decided to remove some of the brackets from it in order to obtain a regular bracket sequence. What is the maximum length of a regular bracket sequence which can be obtained?

// Input
// Input consists of a single line with non-empty string of «(» and «)» characters. Its length does not exceed 106.

// Output
// Output the maximum possible length of a regular bracket sequence.

// Examples
// inputCopy
// (()))(
// outputCopy
// 4

// inputCopy
// ((()())
// outputCopy
// 6

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    string s;
    cin >> s;

    stack<char> st;

    //Counting the num of brackets to be removed
    int count = 0;

    // for(int i=0; i<s.size(); i++)
    // {
    //     if(st.empty())
    //     {
    //         if(s[i]=='(')
    //         {
    //             st.push(s[i]);
    //         }
    //         else if(s[i]==')')
    //         {
    //             count++;
    //         }
    //     }
    //     if(!st.empty())
    //     {
    //         if(s[i]=='(')
    //         {
    //             st.push(s[i]);
    //         }
    //         else if(s[i]==')')
    //         {
    //             st.pop();
    //         }
    //     }
    // }

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.empty())
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
    }

    count += st.size();

    //Max RBS length
    cout << s.size()-count << endl;

    return;
}

int32_t main()
{
    fastio;
    solve();

    return 0;
}
