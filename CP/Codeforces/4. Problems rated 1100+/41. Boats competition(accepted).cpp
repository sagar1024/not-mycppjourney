// C. Boats Competition

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n people who want to participate in a boat competition. The weight of the i-th participant is wi. Only teams consisting of two people can participate in this competition. As an organizer, you think that it's fair to allow only teams with the same total weight. So, if there are k teams (a1,b1), (a2,b2), …, (ak,bk), where ai is the weight of the first participant of the i-th team and bi is the weight of the second participant of the i-th team, then the condition a1+b1=a2+b2=⋯=ak+bk=s, where s is the total weight of each team, should be satisfied. Your task is to choose such s that the number of teams people can create is the maximum possible. Note that each participant can be in no more than one team. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow. The first line of the test case contains one integer n (1≤n≤50) — the number of participants. The second line of the test case contains n integers w1,w2,…,wn (1≤wi≤n), where wi is the weight of the i-th participant.

// Output
// For each test case, print one integer k: the maximum number of teams people can compose with the total weight s, if you choose s optimally.

// Example
// inputCopy
// 5
// 5
// 1 2 3 4 5
// 8
// 6 6 6 6 6 6 8 8
// 8
// 1 2 2 1 2 1 1 2
// 3
// 1 3 3
// 6
// 1 1 3 4 2 2

// outputCopy
// 2
// 3
// 4
// 1
// 2

// Note
// In the first test case of the example, we can reach the optimal answer for s=6. Then the first boat is used by participants 1 and 5 and the second boat is used by participants 2 and 4 (indices are the same as weights).
// In the second test case of the example, we can reach the optimal answer for s=12. Then first 6 participants can form 3 pairs.
// In the third test case of the example, we can reach the optimal answer for s=3. The answer is 4 because we have 4 participants with weight 1 and 4 participants with weight 2.
// In the fourth test case of the example, we can reach the optimal answer for s=4 or s=6.
// In the fifth test case of the example, we can reach the optimal answer for s=3. Note that participant with weight 3 can't use the boat because there is no suitable pair for him in the list.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> weights(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> weights[i];
//         }

//         sort(weights.begin(), weights.end());
//         vector<int> allPossibleTeamWeights;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i; j<n; j++)
//             {
//                 int teamWeight = weights[i]+weights[j];
//                 allPossibleTeamWeights.push_back(teamWeight);
//             }
//         }

//         int mostFrequentWt = 0;
//         int count = 0;
//         sort(allPossibleTeamWeights.begin(), allPossibleTeamWeights.end());
//         for(int i=1; i<allPossibleTeamWeights.size(); i++)
//         {
//             if(allPossibleTeamWeights[i-1]==allPossibleTeamWeights[i])
//             {
//                 count++;
//                 mostFrequentWt = max(count, mostFrequentWt);
//             }
//             else
//             {
//                 count = 0;
//             }
//         }

//         int maxTeams = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=n-1; j>=0; j--)
//             {
//                 if(weights[i]+weights[j]==mostFrequentWt)
//                 {
//                     maxTeams++;
//                     i++;
//                     j--;
//                 }
//             }
//         }

//         cout << maxTeams << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Num of participants
        int n;
        cin >> n;

        //Weights
        vector<int> weights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }

        //MAIN logic
        sort(weights.begin(), weights.end());

        //Calculating the maximum possible weight that can form teams
        int maxWeight = weights[n - 1] * 2;

        //Array to store the count of participants with each weight
        vector<int> freq(maxWeight + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[weights[i]]++;
        }

        int maxTeams = 0;

        //Iterate over all possible total weights
        for (int s = 2; s <= maxWeight; s++)
        {
            int teams = 0;
            //For each weight, try to find a pair that sums up to s
            for (int i=1; i<=s/2; i++)
            {
                //CRUX of the prob
                if (i == s-i)
                {
                    //If both participants have the same weight, select half of them
                    teams += freq[i] / 2;
                }
                else
                {
                    //Otherwise
                    //Select the minimum count of participants between the two weights
                    teams += min(freq[i], freq[s-i]);
                }
            }
            //Update the maximum number of teams if necessary
            maxTeams = max(maxTeams, teams);
        }

        cout << maxTeams << endl;
    }

    return 0;
}
