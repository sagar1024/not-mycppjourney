// B. Monsters Attack!

// time limit per test2.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are playing a computer game. The current level of this game can be modeled as a straight line. Your character is in point 0 of this line. There are n monsters trying to kill your character; the i-th monster has health equal to ai and is initially in the point xi. Every second, the following happens:

// first, you fire up to k bullets at monsters. Each bullet targets exactly one monster and decreases its health by 1. For each bullet, you choose its target arbitrary (for example, you can fire all bullets at one monster, fire all bullets at different monsters, or choose any other combination). Any monster can be targeted by a bullet, regardless of its position and any other factors;
// then, all alive monsters with health 0 or less die;
// then, all alive monsters move 1 point closer to you (monsters to the left of you increase their coordinates by 1, monsters to the right of you decrease their coordinates by 1). If any monster reaches your character (moves to the point 0), you lose.

// Can you survive and kill all n monsters without letting any of them reach your character?

// Input
// The first line of the input contains one integer t (1≤t≤3⋅104) — the number of test cases. Each test case consists of three lines:

// the first line contains two integers n and k (1≤n≤3⋅105; 1≤k≤2⋅109);
// the second line contains n integers a1,a2,…,an (1≤ai≤109);
// the third line contains n integers x1,x2,…,xn (−n≤x1<x2<x3<⋯<xn≤n; xi≠0).

// Additional constraint on the input: the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, print YES if you can kill all n monsters before they reach your character, or NO otherwise. You can output each letter of the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will all be recognized as positive responses.

// Example
// inputCopy
// 5
// 3 2
// 1 2 3
// -1 2 3
// 2 1
// 1 1
// -1 1
// 4 10
// 3 4 2 5
// -3 -2 1 3
// 5 3
// 2 1 3 2 5
// -3 -2 3 4 5
// 2 1
// 1 2
// 1 2
// outputCopy
// YES
// NO
// YES
// YES
// NO

// Note
// In the first example, you can act as follows:
// during the 1-st second, fire 1 bullet at the 1-st monster and 1 bullet at the 3-rd monster. Then the 1-st monster dies, the 2-nd and the 3-rd monster move closer;
// during the 2-nd second, fire 2 bullets at the 2-nd monster. Then the 2-nd monster dies, the 3-rd monster moves closer;
// during the 3-rd second, fire 2 bullets at the 3-rd monster. Then the 3-rd monster dies.
// In the second example, you can fire only 1 bullet, so you can kill only one of the two monsters during the 1-st second. Then, the remaining monster moves closer and kills your character.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<pair<long long int, long long int>> healthPosition(n);

        // Input health and position of each monster
        for (int i = 0; i < n; i++)
        {
            cin >> healthPosition[i].first;
            healthPosition[i].first = abs(healthPosition[i].first);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> healthPosition[i].second;
        }

        // Sorting monsters based on their positions
        sort(healthPosition.begin(), healthPosition.end(), [](const pair<int, int> &a, const pair<int, int> &b){ return a.second < b.second; });

        int totHealth = 0;
        vector<pair<long long int, long long int>> totalStrengths;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && healthPosition[i].second == healthPosition[i + 1].second)
            {
                totHealth = healthPosition[i].first + healthPosition[i + 1].first;
                totalStrengths.push_back(make_pair(healthPosition[i].second, totHealth));
                i++;
            }
            else
            {
                totHealth = healthPosition[i].first;
                totalStrengths.push_back(make_pair(healthPosition[i].second, totHealth));
            }
        }

        bool canSurvive = true;
        for (int i = 0; i < totalStrengths.size(); i++)
        {
            if (k * (totalStrengths[i].first) <= totalStrengths[i].second)
            {
                canSurvive = false;
                break;
            }
        }

        if (canSurvive) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
