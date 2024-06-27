// B. Lovely Palindromes

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Pari has a friend who loves palindrome numbers. A palindrome number is a number that reads the same forward or backward. For example 12321, 100001 and 1 are palindrome numbers, while 112 and 1021 are not. Pari is trying to love them too, but only very special and gifted people can understand the beauty behind palindrome numbers. Pari loves integers with even length (i.e. the numbers with even number of digits), so she tries to see a lot of big palindrome numbers with even length (like a 2-digit 11 or 6-digit 122221), so maybe she could see something in them. Now Pari asks you to write a program that gets a huge integer n from the input and tells what is the n-th even-length positive palindrome number?

// Input
// The only line of the input contains a single integer n (1 ≤ n ≤ 10100 000).

// Output
// Print the n-th even-length palindrome number.

// Examples
// inputCopy
// 1
// outputCopy
// 11
// inputCopy
// 10
// outputCopy
// 1001

// Note
// The first 10 even-length palindrome numbers are 11, 22, 33, ... , 88, 99 and 1001.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //int n;
    string n;
    cin >> n;

    //string s = to_string(n);
    //string s = n + "";

    //Main logic
    //The n-th even-length palindrome number is same as that number plus same number but reversed
    //string reqPalindrome = s;
    // for(int i=s.size()-1; i>=0; i--)
    // {
    //     //reqPalindrome.append(s[i]);
    //     reqPalindrome += s[i];
    // }
    
    string reqPalindrome = n;

    //Reversing the digits and
    //Appending them to the main digit string
    reverse(n.begin(), n.end());
    reqPalindrome += n;

    cout << reqPalindrome << endl;

    return 0;
}

