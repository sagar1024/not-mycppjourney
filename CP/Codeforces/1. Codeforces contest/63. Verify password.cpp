// A. Verify Password

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Monocarp is working on his new site, and the current challenge is to make the users pick strong passwords. Monocarp decided that strong passwords should satisfy the following conditions:

// password should consist only of lowercase Latin letters and digits;
// there should be no digit that comes after a letter (so, after each letter, there is either another letter or the string ends);
// all digits should be sorted in the non-decreasing order;
// all letters should be sorted in the non-decreasing order.

// Note that it's allowed for the password to have only letters or only digits. Monocarp managed to implement the first condition, but he struggles with the remaining ones. Can you help him to verify the passwords?

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of testcases. The first line of each testcase contains a single integer n (1≤n≤20) — the length of the password. The second line contains a string, consisting of exactly n characters. Each character is either a lowercase Latin letter or a digit.

// Output
// For each testcase, print "YES" if the given password is strong and "NO" otherwise.

// Example
// inputCopy
// 5
// 4
// 12ac
// 5
// 123wa
// 9
// allllmost
// 5
// ac123
// 6
// 011679
// outputCopy
// YES
// NO
// YES
// NO
// YES

// Note
// In the second testcase, the letters are not sorted in the non-decreasing order.
// In the fourth testcase, there is a digit that comes after a letter — digit '1' after a letter 'c'.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     //MAIN logic
//     vector<int> resultingArray;
//     int lastDigitIdx = 0;

//     for(int i=0; i<n; i++)
//     {
//         if(s[i]-'0'>=0 && s[i]-'0'<=9)
//         {
//             resultingArray.push_back(s[i]-'0');
//             lastDigitIdx = i;
//         }
//         else
//         {
//             resultingArray.push_back(s[i]-'a');
//         }
//     }

//     bool strong = true;
//     for(int i=1; i<=lastDigitIdx; i++)
//     {
//         if(resultingArray[i-1]>resultingArray[i])
//         {
//             strong = false;
//         }
//     }
//     for(int i=lastDigitIdx+2; i<resultingArray.size(); i++)
//     {
//         if(resultingArray[i-1]>resultingArray[i])
//         {
//             strong = false;
//         }
//     }

//     if(strong) cout << "YES"<< endl;
//     else cout << "NO" << endl;

//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    //Extracting digits and letters
    vector<char> digits;
    vector<char> letters;
    bool digitFollowedByLetter = false;

    for (int i = 0; i < n; ++i)
    {
        if (isdigit(s[i]))
        {
            digits.push_back(s[i]);
            if (!letters.empty())
            {
                digitFollowedByLetter = true;
            }
        }
        else
        {
            letters.push_back(s[i]);
        }
    }

    //Checking if digits and letters are sorted and if no digit is followed by a letter
    bool isDigitsSorted = is_sorted(digits.begin(), digits.end());
    bool isLettersSorted = is_sorted(letters.begin(), letters.end());

    if (isDigitsSorted && isLettersSorted && !digitFollowedByLetter)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
