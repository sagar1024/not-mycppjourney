// A. Arpa’s hard exam and Mehrdad’s naive cheat

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There exists an island called Arpa’s land, some beautiful girls live there, as ugly ones do. Mehrdad wants to become minister of Arpa’s land. Arpa has prepared an exam. Exam has only one question, given n, print the last digit of 1378n. Mehrdad has become quite confused and wants you to help him. Please help, although it's a naive cheat.

// Input
// The single line of input contains one integer n (0  ≤  n  ≤  109).

// Output
// Print single integer — the last digit of 1378n.

// Examples
// Input
// 1
// Output
// 8
// Input
// 2
// Output
// 4

// Note
// In the first example, last digit of 13781 = 1378 is 8.
// In the second example, last digit of 13782 = 1378·1378 = 1898884 is 4.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    // Storing the last digit
    // int lastDigit = n%10;

    // if(lastDigit==1 || lastDigit==5 || lastDigit==9)
    // {
    //     cout << 8 << endl;
    // }
    // if(lastDigit==2 || lastDigit==6)
    // {
    //     cout << 4 << endl;
    // }
    // if(lastDigit==3 || lastDigit==7)
    // {
    //     cout << 2 << endl;
    // }
    // if(lastDigit==0 || lastDigit==4 || lastDigit==8)
    // {
    //     cout << 6 << endl;
    // }

    //When the number 8 is raised to any power, it repeats itself after four steps
    //Nullifying all the pack of 4 within a number and storing the number that remained after an incomplete cycle
    int incompleteCycle = n%4;

    if(incompleteCycle==0)
    {
        cout << 6 << endl;
    }
    if(incompleteCycle==1)
    {
        cout << 8 << endl;
    }
    if(incompleteCycle==2)
    {
        cout << 4 << endl;
    }
    if(incompleteCycle==3)
    {
        cout << 2 << endl;
    }

    return 0;
}
