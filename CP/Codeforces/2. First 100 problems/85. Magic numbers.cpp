// A. Magic Numbers

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not. You're given a number. Determine if it is a magic number or not.

// Input
// The first line of input contains an integer n, (1 ≤ n ≤ 109). This number doesn't contain leading zeros.

// Output
// Print "YES" if n is a magic number or print "NO" if it's not.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    string s = "" + n;

    //s.append("00");

    bool magicNum = false;

    for(int i=0; i<s.length(); i++)
    {
        // Main logic
        // if((s[i]==1) || (s[i]==1 && s[i+1]==4) || (s[i]==1 && s[i+1]==4 && s[i+2]==4))
        // {
        //     magicNum = true;
        // }
        if(s.substr(i,1)=="1" || s.substr(i,2)=="14" || s.substr(i,3)=="144")
        {
            magicNum = true;
        }
    }

    if(magicNum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
