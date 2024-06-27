// B. Preparing Olympiad

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have n problems. You have estimated the difficulty of the i-th one as integer ci. Now you want to prepare a problemset for a contest, using some of the problems you've made. A problemset for the contest must consist of at least two problems. You think that the total difficulty of the problems of the contest must be at least l and at most r. Also, you think that the difference between difficulties of the easiest and the hardest of the chosen problems must be at least x. Find the number of ways to choose a problemset for the contest.

// Input
// The first line contains four integers n, l, r, x (1 ≤ n ≤ 15, 1 ≤ l ≤ r ≤ 109, 1 ≤ x ≤ 106) — the number of problems you have, the minimum and maximum value of total difficulty of the problemset and the minimum difference in difficulty between the hardest problem in the pack and the easiest one, respectively. The second line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 106) — the difficulty of each problem.

// Output
// Print the number of ways to choose a suitable problemset for the contest.

// Examples
// inputCopy
// 3 5 6 1
// 1 2 3
// outputCopy
// 2

// inputCopy
// 4 40 50 10
// 10 20 30 25
// outputCopy
// 2

// inputCopy
// 5 25 35 10
// 10 10 20 10 20
// outputCopy
// 6

// Note
// In the first example two sets are suitable, one consisting of the second and third problem, another one consisting of all three problems.
// In the second example, two sets of problems are suitable — the set of problems with difficulties 10 and 30 as well as the set of problems with difficulties 20 and 30.
// In the third example any set consisting of one problem of difficulty 10 and one problem of difficulty 20 is suitable.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void generateSubsets(vector<int> &problemDifficulty, int index, vector<int> &subset, vector<vector<int>> subsets)
// {
//     if(index == problemDifficulty.size())
//     {
//         subsets.push_back(subset);
//         return;
//     }

//     //Exclude current problem
//     generateSubsets(problemDifficulty, index + 1, subset, subsets);
//     //Include current problem
//     subset.push_back(problemDifficulty[index]);
//     generateSubsets(problemDifficulty, index + 1, subset, subsets);
//     subset.pop_back();
// }

// int32_t main()
// {
//     int n;
//     long long int l, r;
//     int x;

//     cin >> n >> l >> r >> x;

//     vector<int> diffcultyLevel(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> diffcultyLevel[i];
//     }

//     vector<vector<int>> subsets;
//     vector<int> subset;
//     generateSubsets(diffcultyLevel, 0, subset, subsets);

//     int answer = 0;
//     for(auto &subset: subsets)
//     {
//         int totalDiff = accumulate(subset.begin(), subset.end(), 0);
//         int min = *min_element(subset.begin(), subset.end());
//         int max = *max_element(subset.begin(), subset.end());

//         if(totalDiff>=l && totalDiff<=r && max-min>=x)
//         {
//             answer++;
//         }
//     }

//     cout << answer << endl;
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> complexity(n);
    for (int i = 0; i < n; i++)
    {
        cin >> complexity[i];
    }

    int ans = 0;

    //Here 1<<n means 2 raised to power n
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int totalDifficulty = 0;
        int minDifficulty = INT_MAX;
        int maxDifficulty = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            //Here the mask & (1 << i) performs a bitwise AND operation between the mask and the value generated above. This operation retains only those bits that are set to 1 in both mask and (1 << i). If the i-th bit in mask is 1, then the result will be (1 << i) itself, otherwise it will be 0
            //So, if the result of mask & (1 << i) is non-zero, it means that the i-th bit in mask is set to 1. Otherwise, it means the i-th bit in mask is 0. This expression is commonly used to check if a specific bit is set in a bitmask
            if (mask & (1 << i))
            {
                totalDifficulty += complexity[i];
                minDifficulty = min(minDifficulty, complexity[i]);
                maxDifficulty = max(maxDifficulty, complexity[i]);
            }
        }
        //Here the __builtin_popcount(mask) is a GCC built-in function that returns the number of set bits (1s) in the binary representation of mask
        if (__builtin_popcount(mask) >= 2 && totalDifficulty >= l && totalDifficulty <= r && maxDifficulty - minDifficulty >= x)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
