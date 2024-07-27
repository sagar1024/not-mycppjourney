// A. Circumference of a Tree

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Hopefully you know how to find the diameter of a tree. That's the first part of tree basics, after all! But this problem is completely different: now, you need to find the circumference of a tree! As you probably know, pi is equal to the ratio between something's circumferance and its diameter. Also, as you may not know, math is a lie and pi is really equal to 3. Rumor has it, this is where the number tree(3) comes from. Assuming pi equals 3, what is the circumference of the given tree?

// Input
// The first line will contain a single integer n, the number of nodes in the tree. n−1 lines follow, each containing two different integers, describing the edges of the tree. Additional constraint on input: these edges will form a tree. Here 1≤n≤3∗105.

// Output
// Output a single integer: the circumference of the tree.

// Examples
// inputCopy
// 1
// outputCopy
// 0
// inputCopy
// 3
// 3 2
// 2 1
// outputCopy
// 6
// inputCopy
// 5
// 4 2
// 1 4
// 5 4
// 3 4
// outputCopy
// 6

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

pair<int,int> bfs(int start, int n)
{
    vector<int> distance(n,-1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    int farthest_node = start; //Starting from the start
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int neighbor: adj[node])
        {
            //Only visiting unvisited nodes
            if(distance[neighbor]==-1)
            {
                distance[neighbor] = distance[node]+1;
                q.push(neighbor);
                if(distance[neighbor] > distance[farthest_node])
                {
                    farthest_node = neighbor;   
                }
            }
        }
    }

    return {farthest_node, distance[farthest_node]};
}

int32_t main()
{
    int n;
    cin >> n;

    if(n==1)
    {
        cout << "0" << endl;
        return 0;
    }

    adj.resize(n);
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Making pair of farthest node and its distance
    //BFS arguments are start point and number of nodes
    pair<int,int> first_bfs = bfs(0,n);
    pair<int,int> second_bfs = bfs(first_bfs.first,n);

    int diameter = second_bfs.second;
    int circumference = 3*diameter;

    cout << circumference << endl;

    return 0;
}
