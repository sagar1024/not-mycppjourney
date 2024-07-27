// B. Dynamic Diameter

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given n+1 nodes and n−1 edges where the first n nodes are a tree and node n+1 is in its own component. For each node i from 1...n, answer the following question: If an edge was added from node i to node n+1, what would the diameter of the created tree be? (Notice that the n+1 nodes will be a tree if this edge was added).

// Input
// The first line will contain a single integer n, the number of nodes in the tree initial tree. n−1 lines follow, each containing two different integers, describing the edges initially in the tree. Additional constraint on input: these edges will form a tree on the first n nodes. Here 1≤n≤3∗105.

// Output
// Print n integers, each on their own line. The ith is the diameter of the new tree if you were to add an edge from node i to node n+1.

// Examples
// inputCopy
// 1
// outputCopy
// 1
// inputCopy
// 3
// 3 2
// 2 1
// outputCopy
// 3
// 2
// 3
// inputCopy
// 5
// 4 2
// 1 4
// 5 4
// 3 4
// outputCopy
// 3
// 3
// 3
// 2
// 3

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Global variables
// int n;
// vector<int> dist;
// vector<vector<int>> adj;

// //Dfs func
// pair<int,int> dfs(int start)
// {
//     dist.assign(n,-1); //Representing all unvisited nodes
//     dist[start] = 0;

//     //Stack for dfs
//     stack<int> s;
//     s.push(start);

//     int farthest_node = start;
//     int maxDist = 0;

//     while(!s.empty())
//     {
//         int u = s.top();
//         s.pop();

//         for(int v: adj[u])
//         {
//             //Only visiting the unvisited nodes
//             if(dist[v]==-1)
//             {
//                 dist[v] = dist[u]+1;

//                 //Updating the farthest node and maxDist
//                 if(dist[v]>maxDist)
//                 {
//                     maxDist = dist[v];
//                     farthest_node = v;
//                 }

//                 //Pushing the curr node into the stack
//                 //Going more deep to search
//                 s.push(v);
//             }
//         }
//     }

//     return {farthest_node, maxDist};
// }

// int32_t main()
// {
//     //Num of nodes
//     //int n;
//     cin >> n;

//     adj.resize(n);
//     for(int i=0; i<n-1; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         u--;
//         v--;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     //Pair of farthest node and max distance
//     //Dfs argument is the starting position of the traversal
//     pair<int,int> p1 = dfs(0);
//     pair<int,int> p2 = dfs(p1.first);

//     int diameter = p2.second;

//     // Precomputing disances from the two farthest points
//     // int a = p1.first;
//     // int b = p2.first;

//     // vector<int> distA = dist;
//     // vector<int> distB = dfs(b).second;

//     // for(int i=0; i<n; i++)
//     // {
//     //     int newDiameter = max({distA[i]+1, distB[i]+1, diameter});
//     //     cout << newDiameter << endl;
//     // }

//     cout << diameter << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dist;

//Helper function to run DFS and return the farthest node and its distance
pair<int, int> dfs(int start)
{
    dist.assign(n, -1);
    dist[start] = 0;
    stack<int> s;
    s.push(start);

    int farthest_node = start;
    int max_dist = 0;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                if (dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    farthest_node = v;
                }
                s.push(v);
            }
        }
    }

    return {farthest_node, max_dist};
}

vector<int> calculateDistances(int start)
{
    dist.assign(n, -1);
    dist[start] = 0;
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                s.push(v);
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Find one endpoint of the diameter
    pair<int, int> p1 = dfs(0);

    //Find the other endpoint and the actual diameter
    pair<int, int> p2 = dfs(p1.first);
    int diameter = p2.second;

    //Precompute distances from the two farthest points
    int A = p1.first;
    int B = p2.first;
    vector<int> distA = calculateDistances(A);
    vector<int> distB = calculateDistances(B);

    for (int i = 0; i < n; i++)
    {
        int new_diameter = max({distA[i] + 1, distB[i] + 1, diameter});
        cout << new_diameter << endl;
    }

    return 0;
}
