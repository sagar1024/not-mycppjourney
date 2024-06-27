// B. Maximum Cost Deletion
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s of length n consisting only of the characters 0 and 1. You perform the following operation until the string becomes empty: choose some consecutive substring of equal characters, erase it from the string and glue the remaining two parts together (any of them can be empty) in the same order. For example, if you erase the substring 111 from the string 111110, you will get the string 110. When you delete a substring of length l, you get a⋅l+b points. Your task is to calculate the maximum number of points that you can score in total, if you have to make the given string empty.

// Input
// The first line contains a single integer t (1≤t≤2000) — the number of testcases. The first line of each testcase contains three integers n, a and b (1≤n≤100;−100≤a,b≤100) — the length of the string s and the parameters a and b. The second line contains the string s. The string s consists only of the characters 0 and 1.

// Output
// For each testcase, print a single integer — the maximum number of points that you can score.

// Example
// inputCopy
// 3
// 3 2 0
// 000
// 5 -2 5
// 11001
// 6 1 -4
// 100111
// outputCopy
// 6
// 15
// -2

// Note
// In the first example, it is enough to delete the entire string, then we will get 2⋅3+0=6 points.
// In the second example, if we delete characters one by one, then for each deleted character we will get (−2)⋅1+5=3 points, i. e. 15 points in total.
// In the third example, we can delete the substring 00 from the string 100111, we get 1⋅2+(−4)=−2 points, and the string will be equal to 1111, removing it entirely we get 1⋅4+(−4)=0 points. In total, we got −2 points for 2 operations.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Length of the string
        int n;
        cin >> n;

        // Parameters
        int a, b;
        cin >> a >> b;

        // Given string
        string s;
        cin >> s;

        //Main logic
        int totalScore = 0;
        if (a > b)
        {
            for (int i = 0; i < n;)
            {
                char currentChar = s[i];
                int count = 0;

                while (i < n && s[i] == currentChar)
                {
                    count++;
                    i++;
                }

                totalScore += a*count + b;

                //Constructing the new string after removing the identified substring
                s.erase(i-count,count);

                //Updating the index 
                i = i-count+1;
                n = s.size(); //Updating the length of the string
            }

            cout << totalScore << endl;
        }
        else
        {
            //Here the length of each substr(l) will be 1
            //Hence, a*l+b becomes a+b
            totalScore = n*(a + b);

            cout << totalScore << endl;
        }
    }

    return 0;
}
