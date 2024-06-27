// D. Palindrome Degree

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// String s of length n is called k-palindrome, if it is a palindrome itself, and its prefix and suffix of length  are (k - 1)-palindromes. By definition, any string (even empty) is 0-palindrome. Let's call the palindrome degree of string s such a maximum number k, for which s is k-palindrome. For example, "abaaba" has degree equals to 3. You are given a string. Your task is to find the sum of the palindrome degrees of all its prefixes.

// Input
// The first line of the input data contains a non-empty string, consisting of Latin letters and digits. The length of the string does not exceed 5·106. The string is case-sensitive.

// Output
// Output the only number — the sum of the polindrome degrees of all the string's prefixes.

// Examples
// inputCopy
// a2A
// outputCopy
// 1

// inputCopy
// abacaba
// outputCopy
// 6

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// const long long int mod = 1e9+7;
// const long long int N = 1e5+5;

// bool isPalindrome(string s)
// {
//     int left = 0, right = s.size() - 1;
//     while (left < right)
//     {
//         if (s[left] != s[right])
//         {
//             return false;
//         }
//         left++;
//         right--;
//     }

//     return true;
// }

// void solve()
// {
//     string s;
//     cin >> s;

//     string curr;
//     int sum = 0; // Sum of palindrome degrees
//     for (int i = 0; i < s.size(); i++)
//     {
//         curr += s[i];
//         if (isPalindrome(curr))
//         {
//             sum += sum + 1;
//         }
//     }

//     cout << sum << endl;
//     return;
// }

// int32_t main()
// {
//     solve();
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//Check if a substring s[l:r] is a palindrome
bool isPalindrome(const string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

long long computePalindromeDegrees(const string &s)
{
    int n = s.size();
    
    vector<int> dp(n, 0);
    long long sum_degrees = 0;

    //Processing each prefix of the string
    for (int i = 0; i < n; ++i)
    {
        int max_degree = 0;
        for (int length = 1; length <= (i + 1); length *= 2)
        {
            if (i + 1 >= 2 * length && isPalindrome(s, i + 1 - 2 * length, i))
            {
                max_degree = max(max_degree, dp[i + 1 - length] + 1);
            }
            else if (i + 1 >= length && isPalindrome(s, i + 1 - length, i))
            {
                max_degree = max(max_degree, 1);
            }
        }
        dp[i] = max_degree;
        sum_degrees += dp[i];
    }

    return sum_degrees;
}

int main()
{
    string s;
    cin >> s;

    cout << computePalindromeDegrees(s) << endl;
    return 0;
}
