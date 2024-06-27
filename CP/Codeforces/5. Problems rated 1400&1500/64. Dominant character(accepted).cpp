// C. Dominant Character

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ashish has a string s of length n containing only characters 'a', 'b' and 'c'. He wants to find the length of the smallest substring, which satisfies the following conditions: Length of the substring is at least 2
// 'a' occurs strictly more times in this substring than 'b'
// 'a' occurs strictly more times in this substring than 'c'

// Ashish is busy planning his next Codeforces round. Help him solve the problem. A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

// Input
// The first line contains a single integer t (1≤t≤105) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (2≤n≤106)  — the length of the string s. The second line of each test case contains a string s consisting only of characters 'a', 'b' and 'c'. It is guaranteed that the sum of n over all test cases does not exceed 106.

// Output
// For each test case, output the length of the smallest substring which satisfies the given conditions or print −1 if there is no such substring.

// Example
// inputCopy
// 3
// 2
// aa
// 5
// cbabb
// 8
// cacabccc
// outputCopy
// 2
// -1
// 3

// Note

// Consider the first test case. In the substring "aa", 'a' occurs twice, while 'b' and 'c' occur zero times. Since 'a' occurs strictly more times than 'b' and 'c', the substring "aa" satisfies the condition and the answer is 2. The substring "a" also satisfies this condition, however its length is not at least 2.
// In the second test case, it can be shown that in none of the substrings of "cbabb" does 'a' occur strictly more times than 'b' and 'c' each.
// In the third test case, "cacabccc", the length of the smallest substring that satisfies the conditions is 3.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     //int count = 0;
//     string answer;
//     for(int i=0; i<n; i++)
//     {
//         int a=0, b=0, c=0;
//         for(int j=i; j<n; j++)
//         {
//             if(s[j]=='a')
//             {
//                 a++;
//             }
//             else if(s[j]=='b')
//             {
//                 b++;
//             }
//             else
//             {
//                 c++;
//             }
//         }

//         if(a+b+c>=2 && a>b && a>c)
//         {
//             //Store the current substring in a string
//             //AND update the string whenever a shorter string is encountered
//         }
//     }

//     return;
// }

// int32_t main()
// {
//     fastio;

//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln(tle on test 4) -

// #include <iostream>
// #include <string>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int minLength = INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         //Here j starts from i+2 to ensure the length is at least 2
//         for (int j = i + 2; j <= n; j++)
//         {
//             int countA = 0, countB = 0, countC = 0;
//             for (int k = i; k < j; k++)
//             {
//                 if (s[k] == 'a')
//                     countA++;
//                 else if (s[k] == 'b')
//                     countB++;
//                 else
//                     countC++;
//             }
//             //Condition for 'a' to occur more than 'b' and 'c'
//             if (countA > countB && countA > countC)
//             {
//                 minLength = min(minLength, j - i);
//             }
//         }
//     }

//     if (minLength == INT_MAX)
//     {
//         cout << "-1" << endl;
//     }
//     else
//     {
//         cout << minLength << endl;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int32_t main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int length;
        cin >> length;
        
        string str;
        cin >> str;

        int min_substring_length = 1e9;

        for (int i = 0; i < length; i++)
        {
            vector<int> char_count(3, 0); //Counting of each character 'a', 'b', and 'c'
            char_count[str[i] - 'a']++; //Incrementing count for the current character

            for (int j = i + 1; j < min(length, i + 7); j++)
            {
                char_count[str[j] - 'a']++; //Incrementing count for the next character

                if (char_count[0] > char_count[1] && char_count[0] > char_count[2])
                {
                    min_substring_length = min(min_substring_length, j - i + 1); //Updating minimum substring length
                }
            }
        }

        if (min_substring_length == 1e9)
        {
            min_substring_length = -1;
        }

        cout << min_substring_length << endl;
    }

    return 0;
}
