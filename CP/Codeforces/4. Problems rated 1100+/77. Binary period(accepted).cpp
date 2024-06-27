// B. Binary Period

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's say string s has period k if si=si+k for all i from 1 to |s|−k (|s| means length of string s) and k is the minimum positive integer with this property. Some examples of a period: for s="0101" the period is k=2, for s="0000" the period is k=1, for s="010" the period is k=2, for s="0011" the period is k=4. You are given string t consisting only of 0's and 1's and you need to find such string s that:

// String s consists only of 0's and 1's;
// The length of s doesn't exceed 2⋅|t|;
// String t is a subsequence of string s;
// String s has smallest possible period among all strings that meet conditions 1—3.

// Let us recall that t is a subsequence of s if t can be derived from s by deleting zero or more elements (any) without changing the order of the remaining elements. For example, t="011" is a subsequence of s="10101".

// Input
// The first line contains single integer T (1≤T≤100) — the number of test cases. Next T lines contain test cases — one per line. Each line contains string t (1≤|t|≤100) consisting only of 0's and 1's.

// Output
// Print one string for each test case — string s you needed to find. If there are multiple solutions print any one of them.

// Example
// inputCopy
// 4
// 00
// 01
// 111
// 110
// outputCopy
// 00
// 01
// 11111
// 1010

// Note
// In the first and second test cases, s=t since it's already one of the optimal solutions. Answers have periods equal to 1 and 2, respectively.
// In the third test case, there are shorter optimal solutions, but it's okay since we don't need to minimize the string s. String s has period equal to 1.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         string s;
//         cin >> s;

//         //MAIN logic
//         bool oneExists = false;
//         bool zeroExists = false;

//         int oneIdx = 0;
//         int zeroIdx = 0;

//         for(int i=0; i<s.size(); i++)
//         {
//             if(s[i]=='0' && zeroIdx == 0)
//             {
//                 zeroIdx = i;
//                 zeroExists = true;
//             }
//             if(s[i]=='1' && oneIdx == 0)
//             {
//                 oneIdx = i;
//                 oneExists = true;
//             }
//         }

//         //Outputs
//         //If the string is all 0s or 1s
//         if(!oneExists || !zeroExists)
//         {
//             cout << s << endl;
//             continue;
//         }
//         else
//         {
//             //When 1 comes before 0
//             if(oneExists<zeroExists)
//             {
//                 for(int i=0; i<s.size(); i+=2)
//                 {
//                     cout << "10";
//                 }
//                 cout << endl;
//             }
//             //When 0 comes before 1
//             else
//             {
//                 for(int i=0; i<s.size(); i+=2)
//                 {
//                     cout << "01";
//                 }
//                 cout << endl;
//             }
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        string t;
        cin >> t;

        //Convert to char
        //Store the distinct values
        //Append t.length times
        unordered_set<char> distinctChars(t.begin(), t.end());
        string distinctString(distinctChars.begin(), distinctChars.end());

        //Answer string
        string s;
        for (int i = 0; i < t.length(); i++)
        {
            s += distinctString;
        }

        //Output 01010101... irrespective of the input string
        cout << s << endl;
    }

    return 0;
}
