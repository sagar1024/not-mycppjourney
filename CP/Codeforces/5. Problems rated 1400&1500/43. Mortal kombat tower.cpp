// C. Mortal Kombat Tower

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You and your friend are playing the game Mortal Kombat XI. You are trying to pass a challenge tower. There are n bosses in this tower, numbered from 1 to n. The type of the i-th boss is ai. If the i-th boss is easy then its type is ai=0, otherwise this boss is hard and its type is ai=1. During one session, either you or your friend can kill one or two bosses (neither you nor your friend can skip the session, so the minimum number of bosses killed during one session is at least one). After your friend session, your session begins, then again your friend session begins, your session begins, and so on. The first session is your friend's session. Your friend needs to get good because he can't actually kill hard bosses. To kill them, he uses skip points. One skip point can be used to kill one hard boss. Your task is to find the minimum number of skip points your friend needs to use so you and your friend kill all n bosses in the given order. For example: suppose n=8, a=[1,0,1,1,0,1,1,1]. Then the best course of action is the following:

// your friend kills two first bosses, using one skip point for the first boss;
// you kill the third and the fourth bosses;
// your friend kills the fifth boss;
// you kill the sixth and the seventh bosses;
// your friend kills the last boss, using one skip point, so the tower is completed using two skip points.

// You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The first line of the test case contains one integer n (1≤n≤2⋅105) — the number of bosses. The second line of the test case contains n integers a1,a2,…,an (0≤ai≤1), where ai is the type of the i-th boss. It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer: the minimum number of skip points your friend needs to use so you and your friend kill all n bosses in the given order.

// Example
// inputCopy
// 6
// 8
// 1 0 1 1 0 1 1 1
// 5
// 1 1 1 1 0
// 7
// 1 1 1 1 0 0 1
// 6
// 1 1 1 1 1 1
// 1
// 1
// 1
// 0
// outputCopy
// 2
// 2
// 2
// 2
// 1
// 0

//My original soln(tutorial help) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     //Inputs
//     int n;
//     cin >> n;

//     vector<long long int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     //Result variable
//     long long int skipPoints = 0;

//     //If the first boss is hard, only our friend can kill him
//     skipPoints += givenArray[0]==1;

//     //Iterating from the 2nd boss
//     for(int i=1; i<n; i++)
//     {
//         //No effort required to kill easy bosses
//         if(givenArray[i]==0)
//         {
//             continue;
//         }

//         //Second pointer j to trace the array further
//         //It will keep iterating/tracing the array till j<n & given array curr element is 1
//         int j = i;
//         while(j<n && givenArray[i]==1)
//         {
//             j++;
//         }

//         //Adding the skip points
//         //If the substring has "111111"
//         //There are 6 ones
//         //Our friend will kill first
//         //We will kill next 2
//         //Then again our friend will take down 1
//         //AND we will take down remaining 2
//         //Skip points is 1/3rd of total 1s
//         skipPoints += (j-i)/3;

//         //Adjusting iterator i
//         //Subtracting by one because it will get incremented by for loop's i++
//         //To counter that we sub by 1
//         i = j-1;
//     }

//     cout << skipPoints << endl;

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

//Alternate soln(tutorial help) -

#include <iostream>
#include <vector>
#include <array>
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

void solve()
{
    //Inputs
    int n;
    cin >> n;

    vector<int> bosses(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bosses[i];
    }

    //Here dp[i][who] stores the minimum skip points needed to defeat the first i bosses
    //AND whose turn it is next (0 for friend, 1 for player)
    vector<array<int, 2>> dp(n + 1, {INF, INF});

    //Base case: no skip points needed to defeat 0 bosses
    dp[0][1] = 0;

    //Dynamic programming
    for (int i = 0; i < n; i++)
    {
        for (int who = 0; who < 2; who++)
        {
            //Trying defeating 1 or 2 bosses
            for (int fight = 1; fight <= min(n - i, 2); fight++)
            {
                //Calculating the hardness of the bosses being fought
                int hardness = bosses[i] + (fight > 1 ? bosses[i + 1] : 0);

                //Updating dp array
                dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hardness);
            }
        }
    }
    
    cout << min(dp[n][0], dp[n][1]) << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }

    return 0;
}
