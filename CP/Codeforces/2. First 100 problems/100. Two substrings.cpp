// A. Two Substrings

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given string s. Your task is to determine if the given string s contains two non-overlapping substrings "AB" and "BA" (the substrings can go in any order).

// Input
// The only line of input contains a string s of length between 1 and 105 consisting of uppercase Latin letters.

// Output
// Print "YES" (without the quotes), if string s contains two non-overlapping substrings "AB" and "BA", and "NO" otherwise.

// Examples
// Input
// ABA
// Output
// NO

// Input
// BACFAB
// Output
// YES

// Input
// AXBYBXA
// Output
// NO

// Note
// In the first sample test, despite the fact that there are substrings "AB" and "BA", their occurrences overlap, so the answer is "NO".
// In the second sample test there are the following occurrences of the substrings: BACFAB.
// In the third sample test there is no substring "AB" nor substring "BA".

// My original soln

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Substrings
    string sub1 = "AB";
    string sub2 = "BA";

    // Given string
    string s;
    cin >> s;

    // Main logic

    // bool nonOverlapping = false;

    // for(int i=0; i<stringSize; i+=2)
    // {
    //     if((s[i]=='A' && s[i+1]=='B') || (s[i]=='B' && s[i+1]=='A'))
    //     {
    //         nonOverlapping = true;
    //     }
    // }

    // for(int i=0; i<s.size(); i++)
    // {
    //     if(s[i]=='A')
    //     {
    //         if(s[i+1]=='B')
    //         {
    //             nonOverlapping = true;
    //             if(s[i+2]=='A')
    //             {
    //                 if(s[i+3]=='B')
    //                 {
    //                     i++;
    //                     continue;
    //                 }
    //                 nonOverlapping = false;
    //                 break;
    //             }
    //             i++;
    //         }
    //     }
    //     if(s[i]=='B')
    //     {
    //         if(s[i+1]=='A')
    //         {
    //             nonOverlapping = true;
    //             if(s[i+2]=='B')
    //             {
    //                 if(s[i+3]=='A')
    //                 {
    //                     i++;
    //                     continue;
    //                 }
    //                 nonOverlapping = false;
    //                 break;
    //             }
    //             i++;
    //         }
    //     }
    // }

    // if(nonOverlapping)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }

    bool foundAB = false;
    bool foundBA = false;

    for (int i=0; i<s.length()-1; i++)
    {
        if (!foundAB && s[i]=='A' && s[i+1]=='B')
        {
            foundAB = true;
            i++; //Skip to the next character
        }
        else if (!foundBA && s[i]=='B' && s[i+1]=='A')
        {
            foundBA = true;
            i++; //Skip to the next character
        }

        //If the string contains both substrings AB and BA
        if (foundAB && foundBA)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}

//Wrong question
//Problem statement not clear
//My program failed in test case 17
//String ABAXXXAB should give "NO" i.e overlapping because AB and BA are clearly overlappping
//But the answer to the 17th test case shows "YES"!?
