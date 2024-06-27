// A. Cinema Line

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The new "Die Hard" movie has just been released! There are n people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 ruble bill. A "Die Hard" ticket costs 25 rubles. Can the booking clerk sell a ticket to each person and give the change if he initially has no money and sells the tickets strictly in the order people follow in the line?

// Input
// The first line contains integer n (1 ≤ n ≤ 105) — the number of people in the line. The next line contains n integers, each of them equals 25, 50 or 100 — the values of the bills the people have. The numbers are given in the order from the beginning of the line (at the box office) to the end of the line.

// Output
// Print "YES" (without the quotes) if the booking clerk can sell a ticket to each person and give the change. Otherwise print "NO".

// Examples
// inputCopy
// 4
// 25 25 50 50
// outputCopy
// YES

// inputCopy
// 2
// 25 100
// outputCopy
// NO

// inputCopy
// 4
// 50 50 25 25
// outputCopy
// NO

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> rubleBills(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> rubleBills[i];
//     }

//     //Using stack to represent the num of ruble bills the clerk has
//     stack<int> ruble25;
//     stack<int> ruble50;
//     stack<int> ruble100;

//     for(int i=0; i<n; i++)
//     {
//         if(rubleBills[i]==25)
//         {
//             ruble25.push(25);
//         }
//         else if(rubleBills[i]==50)
//         {
//             if(ruble25.empty())
//             {
//                 cout << "NO" << endl;
//                 return 0;
//             }
//             else
//             {
//                 ruble25.pop();
//                 ruble50.push(50);
//             }
//         }
//         else if(rubleBills[i]==100)
//         {
//             if(ruble25.empty() && ruble50.empty())
//             {
//                 cout << "NO" << endl;
//                 return 0;
//             }
//             else if(ruble25.empty())
//             {
//                 ruble50.pop();
//                 if(ruble50.empty())
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//                 ruble50.pop();
//                 ruble100.push(100);
//             }
//             else if(ruble50.empty())
//             {
//                 ruble25.pop();
//                 if(ruble25.empty())
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//                 ruble25.pop();
//                 if(ruble25.empty())
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//                 ruble25.pop();
//                 ruble100.push(100);
//             }
//         }
//     }

//     cout << "YES" << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> ruble25;
    stack<int> ruble50;

    for(int i = 0; i < n; i++)
    {
        int bill;
        cin >> bill;

        if(bill == 25)
        {
            ruble25.push(25);
        }
        else if(bill == 50)
        {
            if(ruble25.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                ruble25.pop();
                ruble50.push(50);
            }
        }
        else if(bill == 100)
        {
            if(ruble50.empty())
            {
                if(ruble25.size() < 3)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                else
                {
                    ruble25.pop();
                    ruble25.pop();
                    ruble25.pop();
                }
            }
            else
            {
                if(ruble25.empty())
                {
                    cout << "NO" << endl;
                    return 0;
                }
                else
                {
                    ruble50.pop();
                    ruble25.pop();
                }
            }
        }
    }

    //Loop ends
    //Without returning 0 in between
    cout << "YES" << endl;

    return 0;
}
