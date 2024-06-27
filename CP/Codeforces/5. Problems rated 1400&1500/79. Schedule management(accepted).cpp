// C. Schedule Management

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n workers and m tasks. The workers are numbered from 1 to n. Each task i has a value ai — the index of worker who is proficient in this task. Every task should have a worker assigned to it. If a worker is proficient in the task, they complete it in 1 hour. Otherwise, it takes them 2 hours. The workers work in parallel, independently of each other. Each worker can only work on one task at once. Assign the workers to all tasks in such a way that the tasks are completed as early as possible. The work starts at time 0. What's the minimum time all tasks can be completed by?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. The first line of each testcase contains two integers n and m (1≤n≤m≤2⋅105) — the number of workers and the number of tasks. The second line contains m integers a1,a2,…,am (1≤ai≤n) — the index of the worker proficient in the i-th task. The sum of m over all testcases doesn't exceed 2⋅105.

// Output
// For each testcase, print a single integer — the minimum time all tasks can be completed by.

// Example
// inputCopy
// 4
// 2 4
// 1 2 1 2
// 2 4
// 1 1 1 1
// 5 5
// 5 1 3 2 4
// 1 1
// 1

// outputCopy
// 2
// 3
// 1
// 1

// Note

// In the first testcase, the first worker works on tasks 1 and 3, and the second worker works on tasks 2 and 4. Since they both are proficient in the corresponding tasks, they take 1 hour on each. Both of them complete 2 tasks in 2 hours. Thus, all tasks are completed by 2 hours.
// In the second testcase, it's optimal to assign the first worker to tasks 1,2 and 3 and the second worker to task 4. The first worker spends 3 hours, the second worker spends 2 hours (since they are not proficient in the taken task).
// In the third example, each worker can be assigned to the task they are proficient at. Thus, each of them complete their task in 1 hour.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //Workers and tasks
    int n, m;
    cin >> n >> m;

    //Workers' index who is good in ith task
    vector<int> a(m);
    for(int i=0; i<m; i++)
    {
        cin >> a[i];
        
        //Since the given array is 1 based indexed
        a[i]--;
    }

    //Freq array
    vector<int> count(n);
    for(int i=0; i<m; i++)
    {
        count[a[i]]++;
    }

    //Lambda function, defined w/o a name
    //Func to check if a particular time x is enough to complete all tasks
    auto check = [&](int x)
    {
        long long int freePerson = 0, needHelp = 0;
        for(int i=0; i<n; i++)
        {
            if(x >= count[i])
            {
                freePerson += (x-count[i])/2; //Since an unskilled worker need 2 hrs to complete one task
            }
            else
            {
                needHelp += count[i]-x;
            }
        }
        
        //All tasks can be completed
        //If there are more free people than people in need
        return needHelp<=freePerson;
    };

    //By setting r to 2 * m, we ensure that our binary search range is large enough to include the maximum possible time required to complete the tasks
    int left = 0, right = 2*m;
    int res = -1;

    while(left<=right)
    {
        int mid = (left+right)/2;
        if(check(mid))
        {
            res = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout << res << endl;
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
