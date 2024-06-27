// A. Sequence with Digits
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's define the following recurrence:

// an+1=an+minDigit(an)⋅maxDigit(an).

// Here minDigit(x) and maxDigit(x) are the minimal and maximal digits in the decimal representation of x without leading zeroes. For examples refer to notes. Your task is calculate aK for given a1 and K.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of independent test cases. Each test case consists of a single line containing two integers a1 and K (1≤a1≤1018, 1≤K≤1016) separated by a space.

// Output
// For each test case print one integer aK on a separate line.

// Example
// inputCopy
// 8
// 1 4
// 487 1
// 487 2
// 487 3
// 487 4
// 487 5
// 487 6
// 487 7
// outputCopy
// 42
// 487
// 519
// 528
// 544
// 564
// 588
// 628

// Note
// a1=487
// a2=a1+minDigit(a1)⋅maxDigit(a1)=487+min(4,8,7)⋅max(4,8,7)=487+4⋅8=519
// a3=a2+minDigit(a2)⋅maxDigit(a2)=519+min(5,1,9)⋅max(5,1,9)=519+1⋅9=528
// a4=a3+minDigit(a3)⋅maxDigit(a3)=528+min(5,2,8)⋅max(5,2,8)=528+2⋅8=544
// a5=a4+minDigit(a4)⋅maxDigit(a4)=544+min(5,4,4)⋅max(5,4,4)=544+4⋅5=564
// a6=a5+minDigit(a5)⋅maxDigit(a5)=564+min(5,6,4)⋅max(5,6,4)=564+4⋅6=588
// a7=a6+minDigit(a6)⋅maxDigit(a6)=588+min(5,8,8)⋅max(5,8,8)=588+5⋅8=628

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int minDigit(long long int n)
// {
//     string s = to_string(n);
//     int minNum = INT_MAX;
//     for(int i=0; i<s.size(); i++)
//     {
//         minNum = min((int)s[i], minNum);
//     }
//     return minNum;
// }

// int maxDigit(long long int n)
// {
//     string s = to_string(n);
//     int maxNum = INT_MIN;
//     for(int i=0; i<s.size(); i++)
//     {
//         maxNum = max((int)s[i], maxNum);
//     }

//     return maxNum;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         long long int a1, k;
//         cin >> a1 >> k;

//         long long int result = 0;
//         for(long long int i=0; i<k; i++)
//         {
//             result += a1 + minDigit(a1) * maxDigit(a1);
//         }

//         cout << result << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <string>

using namespace std;

int minDigit(long long int n)
{
    int minNum = 9; // Initialize minNum to the maximum possible digit
    while (n)
    {
        minNum = min(minNum, int(n % 10)); // Update minNum with the minimum digit
        n /= 10;                           // Move to the next digit
    }
    return minNum;
}

int maxDigit(long long int n)
{
    int maxNum = 0; // Initialize maxNum to the minimum possible digit
    while (n)
    {
        maxNum = max(maxNum, int(n % 10)); // Update maxNum with the maximum digit
        n /= 10;                           // Move to the next digit
    }
    return maxNum;
}

long long int calculateAK(long long int a1, long long int k)
{
    if (k == 1)
        return a1; // Base case: if k = 1, return a1

    for (long long int i = 1; i < k; ++i)
    {
        int minD = minDigit(a1);
        int maxD = maxDigit(a1);
        if (minD == 0 || maxD == 0 || a1 == 0)
            break;         // If any digit or a1 becomes zero, terminate
        a1 += minD * maxD; // Update a1 according to the recurrence relation
    }

    return a1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int a1, k;
        cin >> a1 >> k;

        cout << calculateAK(a1, k) << endl;
    }

    return 0;
}
