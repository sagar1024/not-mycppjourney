// B. Ternary String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s such that each its character is either 1, 2, or 3. You have to choose the shortest contiguous substring of s such that it contains each of these three characters at least once. A contiguous substring of string s is a string that can be obtained from s by removing some (possibly zero) characters from the beginning of s and some (possibly zero) characters from the end of s.

// Input
// The first line contains one integer t (1≤t≤20000) — the number of test cases. Each test case consists of one line containing the string s (1≤|s|≤200000). It is guaranteed that each character of s is either 1, 2, or 3. The sum of lengths of all strings in all test cases does not exceed 200000.

// Output
// For each test case, print one integer — the length of the shortest contiguous substring of s containing all three types of characters at least once. If there is no such substring, print 0 instead.

// Example
// inputCopy
// 7
// 123
// 12222133333332
// 112233
// 332211
// 12121212
// 333333
// 31121
// outputCopy
// 3
// 3
// 4
// 4
// 0
// 0
// 4

// Note
// Consider the example test:
// In the first test case, the substring 123 can be used.
// In the second test case, the substring 213 can be used.
// In the third test case, the substring 1223 can be used.
// In the fourth test case, the substring 3221 can be used.
// In the fifth test case, there is no character 3 in s.
// In the sixth test case, there is no character 1 in s.
// In the seventh test case, the substring 3112 can be used.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;

//     bool found1 = false;
//     bool found2 = false;
//     bool found3 = false;
    
//     int start, end;
//     int substringSize = 0;
//     int minSubstringSize = INT_MAX;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]=='1')
//         {
//             found1 = true;
//             if(found2==false && found3==false)
//             {
//                 start = i;
//             }
//             else if(found2==true && found3==true)
//             {
//                 end = i;
//             }
//         }
//         else if(s[i]=='2')
//         {
//             found2 = true;
//             if(found1==false && found3==false)
//             {
//                 start = i;
//             }
//             else if(found1==true && found3==true)
//             {
//                 end = i;
//             }
//         }
//         else if(s[i]=='3')
//         {
//             found3 = true;
//             if(found1==false && found2==false)
//             {
//                 start = i;
//             }
//             else if(found1==true && found2==true)
//             {
//                 end = i;
//             }
//         }

//         //Finding the minimum
//         if(found1 && found2 && found3)
//         {
//             substringSize = abs(start-end);
//             minSubstringSize = min(substringSize, minSubstringSize);
//             break;
//         }
//     }

//     if(found1&&found2&&found3)
//     {
//         cout << minSubstringSize+1 << endl;
//     }
//     else
//     {
//         cout << "0" << endl;
//     }

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln(chatgpt) -

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        
        int ans = 1e9; //10 raised to power 9
        int n = s.size();

        vector<pair<char, int>> c;

        //Count the consecutive characters and store in vector c
        for(auto x: s)
        {
            if (c.empty() || c.back().first != x)
            {
                //constructs a new element in-place at the end of the vector
                //It constructs the element directly within the vector
                //Without the need for an additional copy or move operation
                //It forwards its arguments to the constructor of the element being inserted
                //emplace_back() is more efficient than push_back() when constructing elements
                //Especially for types that are not copyable or movable
                c.emplace_back(x, 1);
            }
            else
            {
                //Returns a reference to the last element of the vector
                c.back().second++;
            }
        }

        int m = c.size();

        //Checking each character group to find the minimum substring length
        for(int i=1; i<m-1; i++)
        {
            if (c[i-1].first != c[i+1].first)
            {
                ans = min(ans, c[i].second + 2);
            }
        }

        //If no valid substring found, set ans to 0
        if (ans > n)
        {
            ans = 0;
        }

        cout << ans << endl;
    }

    return 0;
}
