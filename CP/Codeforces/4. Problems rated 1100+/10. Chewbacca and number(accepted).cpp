// A. Chewbaсca and Number

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t. Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

// Input
// The first line contains a single integer x (1 ≤ x ≤ 1018) — the number that Luke Skywalker gave to Chewbacca.

// Output
// Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

// Examples
// inputCopy
// 27
// outputCopy
// 22

// inputCopy
// 4545
// outputCopy
// 4444

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x;
    cin >> x;

    string s = to_string(x);
    string answer = "";

    for(int i=0; i<s.size(); i++)
    {
        //When "9" is in the first place
        //The decimal representation of the final number shouldn't start with a zero
        if(i==0 && s[i]=='9')
        {
            //answer.append(9+"");
            answer += '9';
        }

        //Inverting digits of x
        else if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4')
        {
            //answer.append(s[i]+"");
            answer += s[i];
        }
        else if(s[i]=='5')
        {
            //answer.append(4+"");
            answer += '4';
        }
        else if(s[i]=='6')
        {
            //answer.append(3+"");
            answer += '3';
        }
        else if(s[i]=='7')
        {
            //answer.append(2+"");
            answer += '2';
        }
        else if(s[i]=='8')
        {
            //answer.append(1+"");
            answer += '1';
        }

        //When "9" is NOT in the first place
        else if(s[i]=='9')
        {
            //answer.append(9+"");
            answer += '0';
        }
    }

    cout << answer << endl;

    return 0;
}
