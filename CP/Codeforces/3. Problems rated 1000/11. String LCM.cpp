// B. String LCM

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Let's define a multiplication operation between a string a and a positive integer x: a⋅x is the string that is a result of writing x copies of a one after another. For example, "abc" ⋅ 2 = "abcabc", "a" ⋅ 5 = "aaaaa". A string a is divisible by another string b if there exists an integer x such that b⋅x=a. For example, "abababab" is divisible by "ab", but is not divisible by "ababab" or "aa". LCM of two strings s and t (defined as LCM(s,t)) is the shortest non-empty string that is divisible by both s and t. You are given two strings s and t. Find LCM(s,t) or report that it does not exist. It can be shown that if LCM(s,t) exists, it is unique.

// Input
// The first line contains one integer q (1≤q≤2000) — the number of test cases. Each test case consists of two lines, containing strings s and t (1≤|s|,|t|≤20). Each character in each of these strings is either 'a' or 'b'.

// Output
// For each test case, print LCM(s,t) if it exists; otherwise, print -1. It can be shown that if LCM(s,t) exists, it is unique.

// Example
// inputCopy
// 3
// baba
// ba
// aa
// aaa
// aba
// ab
// outputCopy
// baba
// aaaaaa
// -1

// Note
// In the first test case, "baba" = "baba" ⋅ 1 = "ba" ⋅ 2.
// In the second test case, "aaaaaa" = "aa" ⋅ 3 = "aaa" ⋅ 2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int q;
//     cin >> q;

//     while (q--)
//     {
//         // String 1
//         string s;
//         cin >> s;

//         // String 2
//         string t;
//         cin >> t;

//         int lenS = s.size();
//         int lenT = t.size();

//         // if (max(lenS, lenT) % min(lenS, lenT) != 0)
//         // {
//         //     cout << -1 << endl;
//         //     continue;
//         // }

//         if(lenS%lenT== 0 && lenT%lenS==0)
//         {
//             cout << s << endl;
//             continue;
//         }

//         if (lenS > lenT)
//         {
//             // Checking if the patter t exists in s
//             bool patternExists = true;
//             for (int i = 0; i < s.size(); i++)
//             {
//                 // Checking if s is a multiple of t
//                 if (s[i] != t[i % lenT])
//                 {
//                     patternExists = false;
//                     break;
//                 }
//             }

//             // If pattern exists, finding the lcm
//             if (patternExists)
//             {
//                 // Calculate the lcm of lengths
//                 int lcm = (lenS * lenT) / __gcd(lenS, lenT);
//                 // Getting the lcm string
//                 string lcmString = s.substr(0, lcm);

//                 // Printing the string
//                 cout << lcmString << endl;
//                 continue;
//             }
//             // Pattern doesnt exists
//             else
//             {
//                 cout << -1 << endl;
//             }
//         }
//         else if(lenS<lenT)
//         {
//             bool patternExists = true;
//             for(int i=0; i<t.size(); i++)
//             {
//                 if(t[i]!=s[i%lenS])
//                 {
//                     patternExists = false;
//                     break;
//                 }
//             }

//             if(patternExists)
//             {
//                 int lcm = lenS*lenT/__gcd(lenS,lenT);
//                 string lcmString = s.substr(0,lcm);
//                 cout << lcmString << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << -1 << endl;
//             }
//         }
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Function to calculate GCD
// int gcd(int a, int b)
// {
//     if (b==0) {
//         return a;
//     }
//     return gcd(b, a%b);
// }

// //Function to calculate LCM
// int lcm(int a, int b)
// {
//     return (a/gcd(a, b))*b;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         string s;
//         cin >> s;

//         string t;
//         cin >> t;

//         int x = s.size();
//         int y = t.size();

//         //MAIN LOGIC
//         if(x%y!=0 && y%x!=0)
//         {
//             cout << -1 << endl;
//             continue;
//         }

//         int a = max(x,y);
//         int b = min(x,y);

//         int stringLcm = lcm(x,y);

//         bool rightPattern = false;

//         if(stringLcm == a)
//         {
//             //Checking if a is only made up of b strings
//             for(int i=0; i<a/b; i++)
//             {
//                 for(int j=0; j<b; j++)
//                 {
//                     if(s[i]==t[j])
//                     {
//                         rightPattern = true;
//                     }
//                     else
//                     {
//                         rightPattern = false;
//                     }
//                     //Update the "i" iterator
//                     i++;
//                 }
//             }

//             if(rightPattern)
//             {
//                 cout << "longer string" << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << -1 << endl;
//                 continue;
//             }
//         }
//         if(stringLcm > x && stringLcm > y)
//         {
//             //Checking if a and b are homogenous string and contain same char
//             bool homogenous = false;

//             for(int i=0; i<a; i++)
//             {
//                 for(int j=0; j<b; j++)
//                 {
//                     if(s[i]==t[j])
//                     {
//                         homogenous = true;
//                     }
//                     else
//                     {
//                         homogenous = false;
//                         break;
//                     }
//                 }
//             }

//             if(homogenous)
//             {
//                 cout << "multiplication of two strings" << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << -1 << endl;
//             }
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate GCD
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s, t;
        cin >> s >> t;

        int x = s.size();
        int y = t.size();

        // MAIN LOGIC
        if (x%y!=0 && y%x!=0)
        {
            //Checking homogeneity of the string
            bool homogeneousStrings = false;

            for(int i=0; i<s.size(); i++)
            {
                for(int j=0; j<t.size(); j++)
                {
                    if(s[i]==t[j])
                    {
                        homogeneousStrings = true;
                    }
                    else
                    {
                        homogeneousStrings = false;
                        break;
                    }
                }
            }
            if(homogeneousStrings)
            {
                for(int x=0; x<s.size(); x++)
                {
                    cout << t;
                }

                cout << endl;
                continue;
            }
            else
            {
                cout << -1 << endl;
                continue;
            }
        }

        int a = max(x, y);
        int b = min(x, y);

        //Numerical LCM of the string lengths
        int stringLcm = lcm(x, y);

        //Checking if the strings have the right pattern
        //String s being made of only t 
        bool rightPattern = false;

        if (stringLcm == a)
        {
            // Checking if a is only made up of b strings
            for (int i=0; i<a/b; i++)
            {
                for (int j=0; j<b; j++)
                {
                    if (s[i] == t[j])
                    {
                        rightPattern = true;
                    }
                    else
                    {
                        rightPattern = false;
                    }

                    // Update the "i" iterator
                    i++;
                }
            }
            if (rightPattern)
            {
                cout << s << endl;
                continue;
            }
            else
            {
                cout << -1 << endl;
                continue;
            }
        }

        //When both string are not multiple/divisor of each other
        if (stringLcm > x && stringLcm > y)
        {
            // Checking if a and b are homogeneous strings and contain the same char
            bool homogeneous = true;

            for (int i = 0; i < a; i++)
            {
                if (s[i % x] != t[i % y])
                {
                    homogeneous = false;
                    break;
                }
            }
            if (homogeneous)
            {
                // Calculate the multiplication of two strings
                int repetitions = stringLcm / a;
                string result = "";
                for (int i = 0; i < repetitions; i++)
                {
                    result += s;
                }

                cout << result << endl;
                continue;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
