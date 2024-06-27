// A. Vacations

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vasya has n days of vacations! So he decided to improve his IT skills and do sport. Vasya knows the following information about each of this n days: whether that gym opened and whether a contest was carried out in the Internet on that day. For the i-th day there are four options:

// on this day the gym is closed and the contest is not carried out;
// on this day the gym is closed and the contest is carried out;
// on this day the gym is open and the contest is not carried out;
// on this day the gym is open and the contest is carried out.

// On each of days Vasya can either have a rest or write the contest (if it is carried out on this day), or do sport (if the gym is open on this day). Find the minimum number of days on which Vasya will have a rest (it means, he will not do sport and write the contest at the same time). The only limitation that Vasya has — he does not want to do the same activity on two consecutive days: it means, he will not do sport on two consecutive days, and write the contest on two consecutive days.

// Input
// The first line contains a positive integer n (1 ≤ n ≤ 100) — the number of days of Vasya's vacations. The second line contains the sequence of integers a1, a2, ..., an (0 ≤ ai ≤ 3) separated by space, where:

// ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
// ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
// ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
// ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.

// Output
// Print the minimum possible number of days on which Vasya will have a rest. Remember that Vasya refuses:

// to do sport on any two consecutive days,
// to write the contest on any two consecutive days.

// Examples
// inputCopy
// 4
// 1 3 2 0
// outputCopy
// 2
// inputCopy
// 7
// 1 3 3 2 1 2 3
// outputCopy
// 0
// inputCopy
// 2
// 2 2
// outputCopy
// 1

// Note

// In the first test Vasya can write the contest on the day number 1 and do sport on the day number 3. Thus, he will have a rest for only 2 days.
// In the second test Vasya should write contests on days number 1, 3, 5 and 7, in other days do sport. Thus, he will not have a rest for a single day.
// In the third test Vasya can do sport either on a day number 1 or number 2. He can not do sport in two days, because it will be contrary to the his limitation. Thus, he will have a rest for only one day.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     //Min num of rest days
//     int restDays = 0;

//     vector<int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         int x;
//         cin >> x;

//         //If x==0, increment the rest days
//         //When x==0, no gym no contest
//         if(x==0)
//         {
//             restDays++;
//         }
//         //Gym as well as contest
//         //But can attend only one
//         else if(x==3)
//         {
//             continue;
//         }
//         else
//         {
//             a[i] = x+1;
//         }
//     }

//     //Iterating over the days without 1s
//     for(int i=0; i<a.size(); i++)
//     {
//         if(a[i]==2)
//         {
//             if(a[i-1]==2 && (i-1)>=0)
//             {
//                 restDays++;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         else if(a[i]==3 && (i-1)>=0)
//         {
//             if(a[i-1]==3)
//             {
//                 restDays++;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//     }

//     int result = restDays;
//     cout << result << endl;

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Inputs
//     int n;
//     cin >> n;

//     vector<int> activities(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> activities[i];
//     }

//     //Initializing the dynamic programming array
//     vector<vector<int>> dp(n, vector<int>(3, 0));

//     //Updating the dp array for the first day
//     for (int j = 0; j < 3; j++)
//     {
//         if (j == 0)
//         {
//             //If Vasya had a rest on the first day
//             dp[0][j] = 1;
//         }
//         else if (activities[0] == 1 || activities[0] == 3)
//         {
//             //If there is a contest on the first day
//             dp[0][j] = 1;
//         }
//         else if (activities[0] == 2 || activities[0] == 3)
//         {
//             //If the gym is open on the first day
//             dp[0][j] = 1;
//         }
//     }

//     //Updating the dp array for the rest of the days
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             //Transition for the day i
//             if (j == 0)
//             {
//                 dp[i][j] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
//             }
//             else if (activities[i] == 1 || activities[i] == 3)
//             {
//                 dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
//             }
//             else if (activities[i] == 2 || activities[i] == 3)
//             {
//                 dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
//             }
//         }
//     }

//     //Max days w/o rest
//     int maxDaysWithoutRest = *max_element(dp[n - 1].begin(), dp[n - 1].end());

//     //Outputs
//     int minRestDays = n - maxDaysWithoutRest;
//     cout << minRestDays << endl;

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<vector<int>> dp(n, vector<int>(3,0));

//     //Updating the dp array for the first day
//     for(int j = 0; j < 3; j++)
//     {
//         if(j == 0)
//         {
//             //If Vasya had a rest on the first day
//             dp[0][j] = 1;
//         }
//         else if(a[0] == 1 || a[0] == 3)
//         {
//             //If there is a contest on the first day
//             dp[0][j] = 1;
//         }
//         else if(a[0] == 2 || a[0] == 3)
//         {
//             //If the gym is open on the first day
//             dp[0][j] = 1;
//         }
//     }

//     //Updating the dp array for the rest of the days
//     for(int i = 1; i < n; i++)
//     {
//         for(int j = 0; j < 3; j++)
//         {
//             //Transition for the day i
//             if(j == 0)
//             {
//                 dp[i][j] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
//             }
//             else if(a[i] == 1 || a[i] == 3)
//             {
//                 dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
//             }
//             else if(a[i] == 2 || a[i] == 3)
//             {
//                 dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
//             }
//         }
//     }

//     //Max days without rest
//     int maxDaysWithoutRest = *max_element(dp[n - 1].begin(), dp[n - 1].end());

//     //Outputs
//     int minRestDays = n - maxDaysWithoutRest;
//     cout << minRestDays << endl;

//     return 0;
// }

// Alternate soln -

// #include <bits/stdc++.h>

// typedef long long ll;
// #define mod 1000000007
// #define pb push_back
// #define mp(a, b) make_pair(a, b)
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define vll vector<ll>
// #define vii vector<int>
// #define vpii vector<pii>
// #define vpll vector<pll>
// #define ff first
// #define ss second
// #define matrix vector<vll>
// #define all(v) v.begin(), v.end()
// #define PQ priority_queue

// using namespace std;

// ll pow(ll a, ll b)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             res *= a;
//         }

//         b /= 2;
//         a *= a;
//     }

//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     //Inputs
//     int n;
//     cin >> n;

//     //Given array
//     vll a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     //DP vector
//     vector<vll> dp(n, vll(3));
//     if (a[0] == 1 || a[0] == 3)
//     {
//         dp[0][1]++;
//     }
//     if (a[0] == 2 || a[0] == 3)
//     {
//         dp[0][2]++;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));

//         dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
//         if (a[i] == 1 || a[i] == 3)
//         {
//             dp[i][1]++;
//         }

//         dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
//         if (a[i] == 2 || a[i] == 3)
//         {
//             dp[i][2]++;
//         }
//     }

//     //Outputs
//     cout << n - max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //For better I/O perf
    ios::sync_with_stdio(0);
    cin.tie(0);

    //Inputs
    int n;
    cin >> n;

    //Given array
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //DP array
    vector<vector<int>> dp(n, vector<int>(3));

    //For the first day
    //Contest
    if (a[0] == 1 || a[0] == 3)
    {
        dp[0][1]++;
    }
    //Gym
    if (a[0] == 2 || a[0] == 3)
    {
        dp[0][2]++;
    }

    //Logic for the subsequent days
    for (int i = 1; i < n; i++)
    {
        //Rest
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        //Contest
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
        if (a[i] == 1 || a[i] == 3)
        {
            dp[i][1]++;
        }

        //Gym
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        if (a[i] == 2 || a[i] == 3)
        {
            dp[i][2]++;
        }
    }

    //Outputs
    cout << n - max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";

    return 0;
}
