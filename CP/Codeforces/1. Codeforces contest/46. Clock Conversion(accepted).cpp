// C. Clock Conversion

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given the time in 24-hour format, output the equivalent time in 12-hour format.

// 24-hour format divides the day into 24 hours from 00 to 23, each of which has 60 minutes from 00 to 59.
// 12-hour format divides the day into two halves: the first half is AM, and the second half is PM. In each half, the hours are numbered in the order 12,01,02,03,…,11. Each hour has 60 minutes numbered from 00 to 59.

// Input
// The first line contains a single integer t (1≤t≤1440) — the number of test cases. The only line of each test case contains a string s of length 5 with format hh:mm representing a valid time in the 24-hour format. hh represents the hour from 00 to 23, and mm represents the minute from 00 to 59. The input will always be a valid time in 24-hour format.

// Output
// For each test case, output two strings separated by a space ("hh:mm AM" or "hh:mm PM"), which are the 12-hour equivalent to the time provided in the test case (without quotes). You should output the time exactly as indicated; in particular, you should not remove leading zeroes.

// Example
// inputCopy
// 11
// 09:41
// 18:06
// 12:14
// 00:59
// 00:00
// 14:34
// 01:01
// 19:07
// 11:59
// 12:00
// 21:37
// outputCopy
// 09:41 AM
// 06:06 PM
// 12:14 PM
// 12:59 AM
// 12:00 AM
// 02:34 PM
// 01:01 AM
// 07:07 PM
// 11:59 AM
// 12:00 PM
// 09:37 PM

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         string s;
//         cin >> s;

//         int hour = (s[0]-'0')*10 + s[1]-'0';
//         int minute = (s[3]-'0')*10 + s[4]-'0';

//         //For new hour
//         int newHour = 0;
//         string newHourr = "";

//         if(hour==0)
//         {
//             newHour = 12;
//             newHourr += newHour;
//         }
//         else if(hour<12)
//         {
//             newHour = hour;
//             if(newHour<10)
//             {
//                 newHourr = "0"+hour;
//             }
//         }
//         else
//         {
//             newHour = hour - 12;
//             if(newHour<10)
//             {
//                 newHourr = "0"+hour;
//             }
//         }

//         //Output
//         if(hour<12)
//         {
//             cout << newHourr << ":" << minute << " AM" << endl;
//         }
//         else
//         {
//             cout << newHourr << ":" << minute << " PM" << endl;
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
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //INputs
        string s;
        cin >> s;

        int hour = (s[0] - '0') * 10 + s[1] - '0';
        int minute = (s[3] - '0') * 10 + s[4] - '0';

        // For new hour
        int newHour = 0;
        string newHourStr = "";

        if (hour == 0)
        {
            newHour = 12;
            newHourStr += to_string(newHour);
        }
        else if (hour < 13)
        {
            newHour = hour;
            if (newHour < 10)
            {
                newHourStr = "0" + to_string(newHour);
            }
            else
            {
                newHourStr = to_string(newHour);
            }
        }
        else
        {
            newHour = hour - 12;
            if (newHour < 10)
            {
                newHourStr = "0" + to_string(newHour);
            }
            else
            {
                newHourStr = to_string(newHour);
            }
        }

        // Outputs
        if (hour < 12)
        {
            cout << newHourStr << ":" << setw(2) << setfill('0') << minute << " AM" << endl;
        }
        else
        {
            cout << newHourStr << ":" << setw(2) << setfill('0') << minute << " PM" << endl;
        }
    }

    return 0;
}
