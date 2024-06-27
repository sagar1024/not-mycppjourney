// F. Final Boss

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are facing the final boss in your favorite video game. The boss enemy has h health. Your character has n attacks. The i'th attack deals ai damage to the boss but has a cooldown of ci turns, meaning the next time you can use this attack is turn x+ci if your current turn is x. Each turn, you can use all attacks that are not currently on cooldown, all at once. If all attacks are on cooldown, you do nothing for the turn and skip to the next turn. Initially, all attacks are not on cooldown. How many turns will you take to beat the boss? The boss is beaten when its health is 0 or less.

// Input
// The first line contains t (1≤t≤104)  – the number of test cases. The first line of each test case contains two integers h and n (1≤h,n≤2⋅105) – the health of the boss and the number of attacks you have. The following line of each test case contains n integers a1,a2,...,an (1≤ai≤2⋅105) – the damage of your attacks. The following line of each test case contains n integers c1,c2,...,cn (1≤ci≤2⋅105) – the cooldown of your attacks. It is guaranteed that the sum of h and n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output an integer, the minimum number of turns required to beat the boss.

// Example
// inputCopy
// 8
// 3 2
// 2 1
// 2 1
// 5 2
// 2 1
// 2 1
// 50 3
// 5 6 7
// 5 6 7
// 50 3
// 2 2 2
// 3 3 3
// 90000 2
// 200000 200000
// 1 1
// 100000 1
// 1
// 200000
// 6 7
// 3 2 3 2 3 1 2
// 6 5 9 5 10 7 7
// 21 6
// 1 1 1 1 1 1
// 5 5 8 10 7 6
// outputCopy
// 1
// 3
// 15
// 25
// 1
// 19999800001
// 1
// 21

// Note
// For the first test case, you can use attacks 1 and 2 on the first turn, dealing 3 damage in total, and slaying the boss.

// For the second case, you can beat the boss in 3 turns by using the following attacks:
// Turn 1: Use attacks 1 and 2, dealing 3 damage to the boss. The boss now has 2 health left.
// Turn 2: Use attack 2, dealing 1 damage to the boss. The boss now has 1 health left.
// Turn 3: Use attack 1, dealing 2 damage to the boss. The boss now has −1 health left. Since its health is less than or equal to 0, you beat the boss.

// For the sixth test case: remember to use 64-bit integers as the answer can get large.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    //Health of the boss, num of types of attacks available
    long long int h, n;
    cin >> h >> n;

    //Damages and cooldowns
    vector<int> damage(n), cooldown(n);
    for (int i = 0; i < n; i++)
        cin >> damage[i];
    for (int i = 0; i < n; i++)
        cin >> cooldown[i];

    //Priority queue to store (cooldown end turn, attack index)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    long long totalDamagePerCycle = 0;
    vector<long long> currentCooldown(n, 0);
    for (int i = 0; i < n; ++i)
    {
        pq.push({cooldown[i], i});
        totalDamagePerCycle += damage[i];
    }

    long long turns = 0;
    while (h > 0)
    {
        turns++;
        h -= totalDamagePerCycle;
        long long minCooldown = pq.top().first;

        vector<pair<long long, int>> temp;
        while (!pq.empty() && pq.top().first <= turns)
        {
            auto [endTurn, idx] = pq.top();
            pq.pop();
            currentCooldown[idx] = turns + cooldown[idx];
            temp.push_back({currentCooldown[idx], idx});
        }

        for (auto [newCooldownEnd, idx] : temp)
        {
            pq.push({newCooldownEnd, idx});
        }
    }

    cout << turns << endl;
    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

