// A. Entertainment in MAC

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Congratulations, you have been accepted to the Master's Assistance Center! However, you were extremely bored in class and got tired of doing nothing, so you came up with a game for yourself. You are given a string s and an even integer n. There are two types of operations that you can apply to it:

// Add the reversed string s to the end of the string s (for example, if s= cpm, then after applying the operation s= cpmmpc).
// Reverse the current string s (for example, if s= cpm, then after applying the operation s= mpc).

// It is required to determine the lexicographically smallest† string that can be obtained after applying exactly n operations. Note that you can apply operations of different types in any order, but you must apply exactly n operations in total. A string a is lexicographically smaller than a string b if and only if one of the following holds:

// a is a prefix of b, but a≠b;
// in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single even integer n (2≤n≤109) — the number of operations applied to the string s. The second line of each test case contains a single string s (1≤|s|≤100), consisting of lowercase English letters, — the string to which the operations are applied.

// Output
// For each test case, output a single line — the lexicographically smallest string that can be obtained after applying exactly n operations.

// Example
// inputCopy
// 5
// 4
// cpm
// 2
// grib
// 10
// kupitimilablodarbuz
// 1000000000
// capybara
// 6
// abacaba
// outputCopy
// cpm
// birggrib
// kupitimilablodarbuz
// arabypaccapybara
// abacaba

// Note
// In the first test case, you can apply the operation of the second type (i.e., reverse the string s) 4 times. Then the string s will remain equal to cpm.
// In the second test case, you can do the following:
// Apply the operation of the second type, after which s will become equal to birg.
// Apply operation of the first type (i.e., add the reversed string s to the end of the string s), after which s will become equal to birggrib.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         long long int n;
//         cin >> n;

//         string s;
//         cin >> s;

//         //Alternate output
//         string s1 = s;
//         reverse(s1.begin(), s1.end());
//         string s2 = s1 + s;

//         // int firstLetter = s[0] - 'a';
//         // int lastLetter = s[s.size()-1] - 'a';

//         // if(tolower(firstLetter)<=tolower(lastLetter)) cout << s << endl;
//         // else cout << s2 << endl;

//         //Special case
//         if (s.size() == 1)
//         {
//             cout << s << endl;
//             continue;
//         }

//         int size = s.size() - 1;
//         bool left = false;
//         bool right = false;
//         for(int i=0; i<size/2; i++)
//         {
//             if(s[i]<=s[size-i])
//             {
//                 left = true;
//                 break;
//             }
//             else
//             {
//                 right = true;
//                 break;
//             }
//         }

//         if(left) cout << s << endl;
//         if(right) cout << s2 << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        long long int n;
        cin >> n;

        string s;
        cin >> s;

        string s1 = s;
        reverse(s1.begin(), s1.end());
        string s2 = s1 + s;

        //Special case
        if (s.size() == 1)
        {
            cout << s << endl;
            continue;
        }

        int size = s.size() - 1;
        bool left = false;
        bool right = false;
        for (int i = 0; i < size / 2 + 1; i++)
        {
            if (s[i] < s[size - i])
            {
                left = true;
                break;
            }
            else if (s[i] > s[size - i])
            {
                right = true;
                break;
            }
        }

        //Outputs
        if (left)
        {
            cout << s << endl;
        }
        else if (right)
        {
            cout << s2 << endl;
        }
        else
        {
            cout << s << endl;
        }
    }

    return 0;
}
