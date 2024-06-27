// A. Everyone Loves to Sleep

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vlad, like everyone else, loves to sleep very much. Every day Vlad has to do n things, each at a certain time. For each of these things, he has an alarm clock set, the i-th of them is triggered on hi hours miminutes every day (0≤hi<24,0≤mi<60). Vlad uses the 24-hour time format, so after h=12,m=59 comes h=13,m=0 and after h=23,m=59 comes h=0,m=0. This time Vlad went to bed at H hours M minutes (0≤H<24,0≤M<60) and asks you to answer: how much he will be able to sleep until the next alarm clock. If any alarm clock rings at the time when he went to bed, then he will sleep for a period of time of length 0.

// Input
// The first line of input data contains an integer t (1≤t≤100) — the number of test cases in the test. The first line of the case contains three integers n, H and M (1≤n≤10,0≤H<24,0≤M<60) — the number of alarms and the time Vlad went to bed. The following n lines contain two numbers each hi and mi (0≤hi<24,0≤mi<60) — the time of the i alarm. It is acceptable that two or more alarms will trigger at the same time. Numbers describing time do not contain leading zeros.

// Output
// Output t lines, each containing the answer to the corresponding test case. As an answer, output two numbers  — the number of hours and minutes that Vlad will sleep, respectively. If any alarm clock rings at the time when he went to bed, the answer will be 0 0.

// Example
// Input
// 3
// 1 6 13
// 8 0
// 3 6 0
// 12 30
// 14 45
// 6 0
// 2 23 35
// 20 15
// 10 30

// Output
// 1 47
// 0 0
// 10 55

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Number of alarms
//         int n;
//         cin >> n;

//         //Time when vlad went to bed
//         int h, m;
//         cin >> h >> m;

//         //The min time Vlad will be able to sleep
//         pair<int, int> minRemainingTime;

//         for(int i=0; i<n; i++)
//         {
//             //Time of the ith alarm
//             int hi, mi;
//             cin >> hi >> mi;

//             //Main logic
//             //Remaining time
//             // int remaining_h = h-hi;
//             // int remaining_m = m-mi;

//             pair<int, int> remainingTime;
//             remainingTime = make_pair(abs((24-h)-(24-hi))-1, 60-(m-mi));

//             minRemainingTime = remainingTime;

//             if(remainingTime.first < minRemainingTime.first)
//             {
//                 minRemainingTime = remainingTime;
//             }
//         }

//         cout << minRemainingTime.first << " " << minRemainingTime.second << endl;
//     }

//     return 0;
// }

// Chatgpts soln

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, H, M;
        cin >> n >> H >> M;

        int total_minutes_asleep = H * 60 + M; // Convert hours to minutes

        int min_remaining = 24 * 60; // Set a high initial value for minimum remaining time

        for (int i = 0; i < n; ++i)
        {
            int hi, mi;
            cin >> hi >> mi;

            int alarm_time = hi * 60 + mi; // Convert alarm time to minutes

            // Calculate the difference in time
            int diff = (alarm_time - total_minutes_asleep + 24 * 60) % (24 * 60);

            // Update the minimum remaining time if needed
            min_remaining = min(min_remaining, diff);
        }

        // Convert the remaining minutes to hours and minutes
        int hours_remaining = min_remaining / 60;
        int minutes_remaining = min_remaining % 60;

        cout << hours_remaining << " " << minutes_remaining << endl;
    }

    return 0;
}
