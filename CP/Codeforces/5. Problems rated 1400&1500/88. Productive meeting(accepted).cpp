// D. Productive Meeting

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// An important meeting is to be held and there are exactly n people invited. At any moment, any two people can step back and talk in private. The same two people can talk several (as many as they want) times per meeting. Each person has limited sociability. The sociability of the i-th person is a non-negative integer ai. This means that after exactly ai talks this person leaves the meeting (and does not talk to anyone else anymore). If ai=0, the i-th person leaves the meeting immediately after it starts. A meeting is considered most productive if the maximum possible number of talks took place during it. You are given an array of sociability a, determine which people should talk to each other so that the total number of talks is as large as possible.

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases. The next 2t lines contain descriptions of the test cases. The first line of each test case description contains an integer n (2≤n≤2⋅105) —the number of people in the meeting. The second line consists of n space-separated integers a1,a2,…,an (0≤ai≤2⋅105) — the sociability parameters of all people. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105. It is also guaranteed that the sum of all ai (over all test cases and all i) does not exceed 2⋅105.

// Output
// Print t answers to all test cases. On the first line of each answer print the number k — the maximum number of talks possible in a meeting. On each of the next k lines print two integers i and j (1≤i,j≤n and i≠j) — the numbers of people who will have another talk. If there are several possible answers, you may print any of them.

// Example
// inputCopy
// 8
// 2
// 2 3
// 3
// 1 2 3
// 4
// 1 2 3 4
// 3
// 0 0 2
// 2
// 6 2
// 3
// 0 0 2
// 5
// 8 2 0 1 1
// 5
// 0 1 0 0 6
// outputCopy
// 2
// 1 2
// 1 2
// 3
// 1 3
// 2 3
// 2 3
// 5
// 1 3
// 2 4
// 2 4
// 3 4
// 3 4
// 0
// 2
// 1 2
// 1 2
// 0
// 4
// 1 2
// 1 5
// 1 4
// 1 2
// 1
// 5 2

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //People
    int n;
    cin >> n;

    //Sociability
    vector<int> sociability(n);
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<n; i++)
    {
        cin >> sociability[i];
        if(sociability[i]>0) pq.push({sociability[i], i});
    }

    //Result array
    vector<pair<int,int>> result;

    //Atleast two people with sociability 
    while(pq.size()>1)
    {
        //Highest sociability
        //Priority queue automatically sorts the elements in descending order
        auto [soc1, idx1] = pq.top();
        pq.pop();

        //Second highest sociability
        auto [soc2, idx2] = pq.top();
        pq.pop();

        //They have a talk
        result.push_back({idx1+1, idx2+1});

        //Decrement the soc values
        soc1--;
        soc2--;

        //If they are still socially active
        if(soc1>0) pq.push({soc1,idx1});
        if(soc2>0) pq.push({soc2,idx2});
    }

    //Constructive output
    cout << result.size() << endl;
    for(auto [idx1, idx2]: result)
    {
        cout << idx1 << " " << idx2 << endl;
    }

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
