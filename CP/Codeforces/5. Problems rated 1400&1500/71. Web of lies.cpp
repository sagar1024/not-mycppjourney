// A. Web of Lies

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// When you play the game of thrones, you win, or you die. There is no middle ground. Cersei Lannister, A Game of Thrones by George R. R. Martin There are n nobles, numbered from 1 to n. Noble i has a power of i. There are also m "friendships". A friendship between nobles a and b is always mutual. A noble is defined to be vulnerable if both of the following conditions are satisfied:

// the noble has at least one friend, and
// all of that noble's friends have a higher power.

// You will have to process the following three types of queries. Add a friendship between nobles u and v. Remove a friendship between nobles u and v. Calculate the answer to the following process. The process: all vulnerable nobles are simultaneously killed, and all their friendships end. Then, it is possible that new nobles become vulnerable. The process repeats itself until no nobles are vulnerable. It can be proven that the process will end in finite time. After the process is complete, you need to calculate the number of remaining nobles. Note that the results of the process are not carried over between queries, that is, every process starts with all nobles being alive!

// Input
// The first line contains the integers n and m (1≤n≤2⋅105, 0≤m≤2⋅105) — the number of nobles and number of original friendships respectively. The next m lines each contain the integers u and v (1≤u,v≤n, u≠v), describing a friendship. No friendship is listed twice. The next line contains the integer q (1≤q≤2⋅105) — the number of queries. The next q lines contain the queries themselves, each query has one of the following three formats. 1 u v (1≤u,v≤n, u≠v) — add a friendship between u and v. It is guaranteed that u and v are not friends at this moment.2 u v (1≤u,v≤n, u≠v) — remove a friendship between u and v. It is guaranteed that u and v are friends at this moment.3 — print the answer to the process described in the statement.

// Output
// For each type 3 query print one integer to a new line. It is guaranteed that there will be at least one type 3 query.

// Examples
// inputCopy
// 4 3
// 2 1
// 1 3
// 3 4
// 4
// 3
// 1 2 3
// 2 3 1
// 3
// outputCopy
// 2
// 1
// inputCopy
// 4 3
// 2 3
// 3 4
// 4 1
// 1
// 3
// outputCopy
// 1

// Note

// Consider the first example. In the first type 3 query, we have the diagram below.
// In the first round of the process, noble 1 is weaker than all of his friends (2 and 3), and is thus killed. No other noble is vulnerable in round 1. In round 2, noble 3 is weaker than his only friend, noble 4, and is therefore killed. At this point, the process ends, and the answer is 2.
// In the second type 3 query, the only surviving noble is 4.
// The second example consists of only one type 3 query. In the first round, two nobles are killed, and in the second round, one noble is killed. The final answer is 1, since only one noble survives.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adjList(n+1);
//     for(int i=0; i<m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     //Queries
//     int q;
//     cin >> q;

//     vector<vector<int>> queries;
//     for(int i=0; i<q; i++)
//     {
//         //Query type
//         int q;
//         cin >> q;

//         if(q==1)
//         {
//             int x, y;
//             cin >> x >> y;

//             //Add friendship between x and y
//             adjList[x].push_back(y);
//             adjList[y].push_back(x);
//         }
//         else if(q==2)
//         {
//             int x, y;
//             cin >> x >> y;

//             //Remove friendship between x and y
//             //Implementation
//         }
//         else if(q==3)
//         {
//             //Calculating the process
//             //Implementation
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Initialize adjacency list for friendships
    vector<vector<int>> adjList(n + 1);

    // Read the list of initial friendships
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        // Add friendships to adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int q;
    cin >> q;

    // Process queries
    for (int i = 0; i < q; ++i)
    {
        // Read query type
        int queryType;
        cin >> queryType;

        if (queryType == 1)
        {
            // Add friendship
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else if (queryType == 2)
        {
            // Remove friendship
            int u, v;
            cin >> u >> v;

            // Find and remove edge from adjacency list
            auto it = find(adjList[u].begin(), adjList[u].end(), v);
            if (it != adjList[u].end())
            {
                adjList[u].erase(it);
            }

            it = find(adjList[v].begin(), adjList[v].end(), u);
            if (it != adjList[v].end())
            {
                adjList[v].erase(it);
            }
        }
        else if (queryType == 3)
        {
            // Calculate answer to the process
            // Process to kill vulnerable nobles and find remaining ones
            vector<bool> isVulnerable(n + 1, false);
            queue<int> vulnerableNobles;
            for (int j = 1; j <= n; ++j)
            {
                if (adjList[j].empty())
                {
                    continue; // Skip if noble has no friends
                }

                bool allFriendsAreStronger = true;
                for (int friendId : adjList[j])
                {
                    if (friendId < j)
                    {
                        allFriendsAreStronger = false;
                        break;
                    }
                }

                if (!allFriendsAreStronger)
                {
                    isVulnerable[j] = true;
                    vulnerableNobles.push(j);
                }
            }

            // Process to eliminate vulnerable nobles and their friendships
            while (!vulnerableNobles.empty())
            {
                int noble = vulnerableNobles.front();
                vulnerableNobles.pop();

                // Kill noble
                isVulnerable[noble] = false;

                // Remove noble from friends' adjacency lists
                for (int friendId : adjList[noble])
                {
                    auto it = find(adjList[friendId].begin(), adjList[friendId].end(), noble);
                    if (it != adjList[friendId].end())
                    {
                        adjList[friendId].erase(it);

                        // Check if friend became vulnerable
                        if (adjList[friendId].size() < friendId && !isVulnerable[friendId])
                        {
                            isVulnerable[friendId] = true;
                            vulnerableNobles.push(friendId);
                        }
                    }
                }
            }

            // Count remaining nobles
            int remainingNobles = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (!adjList[j].empty())
                {
                    ++remainingNobles;
                }
            }

            cout << remainingNobles << endl;
        }
    }

    return 0;
}
