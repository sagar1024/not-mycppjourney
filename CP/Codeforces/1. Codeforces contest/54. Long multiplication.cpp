// C. Long Multiplication

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given two integers x and y of the same length, consisting of digits from 1 to 9. You can perform the following operation any number of times (possibly zero): swap the i-th digit in x and the i-th digit in y. For example, if x=73 and y=31, you can swap the 2-nd digits and get x=71 and y=33. Your task is to maximize the product of x and y using the aforementioned operation any number of times. If there are multiple answers, print any of them.

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains a single integer x (1≤x<10100). The second line of each test case contains a single integer y (1≤y<10100). Additional constraint on input: the integers x and y consist only of digits from 1 to 9.

// Output
// For each test case, print two lines — the first line should contain the number x after performing the operations; similarly, the second line should contain the number y after performing the operations. If there are multiple answers, print any of them.

// Example
// inputCopy
// 3
// 73
// 31
// 2
// 5
// 3516
// 3982

// outputCopy
// 71
// 33
// 5
// 2
// 3912
// 3586

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string addStrings(const string &num1, const string &num2)
{
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string sum = "";

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int currentSum = digit1 + digit2 + carry;
        carry = currentSum / 10;
        sum = to_string(currentSum % 10) + sum;
    }

    return sum;
}

void solve()
{
    string x, y;
    cin >> x >> y;

    //Sum of x and y
    string sum = addStrings(x, y);

    //Average
    long long average = stoll(sum) / 2;
    string average2 = to_string(average);

    string answerX = "";
    string answerY = "";

    //Iterating through each digit of x and y
    for (int i = 0; i < x.size(); i++)
    {
        while(x[i]==y[i])
        {
            answerX += x[i];
            answerY += y[i];
            i++;
        }
        if(x[i]>y[i])
        {
            //Add the first digit to x and compare the remaining elements and append the larger ones to y and smallers to x

        }
        else
        {
            //Add the first(larger) digit to y and remaining element are to be compared and largers ones be appended to x and smaller ones to y
        }
    }

    cout << x << endl;
    cout << y << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
