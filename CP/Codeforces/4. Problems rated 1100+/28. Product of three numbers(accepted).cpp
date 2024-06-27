// C. Product of Three Numbers

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given one integer number n. Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n or say that it is impossible to do it. If there are several answers, you can print any. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤100) — the number of test cases. The next n lines describe test cases. The i-th test case is given on a new line as one integer n (2≤n≤109).

// Output
// For each test case, print the answer on it. Print "NO" if it is impossible to represent n as a⋅b⋅c for some distinct integers a,b,c such that 2≤a,b,c. Otherwise, print "YES" and any possible such representation.

// Example
// inputCopy
// 5
// 64
// 32
// 97
// 2
// 12345

// outputCopy
// YES
// 2 4 8 
// NO
// NO
// NO
// YES
// 3 5 823

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Given number
        int n;
        cin >> n;

        //Req nums
        int a=0, b=0, c=0;

        bool foundTheNums = false;

        //Iterating till sqrt of n
        //for(int i=2; i<sqrt(n); i++)
        for(int i=2; i*i<=n; i++)
        {
            //Found the first num
            if(n%i==0)
            {
                //First num
                a = i;
                //Update n
                n = n/i;

                //Iterating for next num
                for(int j=2; j*j<=n; j++)
                {
                    //Found the second num
                    //It should not be equal to the first num
                    if(n%j==0 && j!=a)
                    {
                        //The third num should not be equalt to first num(a)
                        //OR
                        //The second num(b)
                        if(n/j!=a && n/j!=j)
                        {
                            b = j; //2nd
                            c = n/j; //3rd
                            foundTheNums = true;
                            break;
                        }
                    }
                }

                //Output
                if(foundTheNums)
                {
                    cout << "YES" << endl;
                    cout << a << " " << b << " " << c << endl;
                    break;
                }
            }
        }

        //If the loop ends and numbers are not found
        if(!foundTheNums)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
