// A. Jeff and Digits

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Jeff's got n cards, each card contains either digit 0, or digit 5. Jeff can choose several cards and put them in a line so that he gets some number. What is the largest possible number divisible by 90 Jeff can make from the cards he's got? Jeff must make the number without leading zero. At that, we assume that number 0 doesn't contain any leading zeroes. Jeff doesn't have to use all the cards.

// Input
// The first line contains integer n (1 ≤ n ≤ 103). The next line contains n integers a1, a2, ..., an (ai = 0 or ai = 5). Number ai represents the digit that is written on the i-th card.

// Output
// In a single line print the answer to the problem — the maximum number, divisible by 90. If you can't make any divisible by 90 number from the cards, print -1.

// Examples
// inputCopy
// 4
// 5 0 5 0
// outputCopy
// 0
// inputCopy
// 11
// 5 5 5 5 5 5 5 5 0 5 5
// outputCopy
// 5555555550

// Note
// In the first test you can make only one number that is a multiple of 90 — 0.
// In the second test you can make number 5555555550, it is a multiple of 90.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cardDigits(n);
    for(int i=0; i<n; i++)
    {
        cin >> cardDigits[i];
    }

    int sum = 0;
    int count0 = 0;
    for(int i=0; i<n; i++)
    {
        sum += cardDigits[i];
        if(cardDigits[i]==0)
        {
            count0++;
        }
    }

    //Checking the presence of 0 to be a multiple of 90
    if(count0==0 && sum!=0)
    {
        cout << -1 << endl;
        return 0;
    }
    //Checking the condition of divisibility by 9
    if(sum%9!=0)
    {
        if(count0!=0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return 0;
    }
    
    sort(cardDigits.begin(), cardDigits.end(), greater<int>());
    for(int i=0; i<n; i++)
    {
        cout << cardDigits[i];
    }
    cout << endl;

    return 0;
}

//Wrong question
//5555555550 is not divisible by 90