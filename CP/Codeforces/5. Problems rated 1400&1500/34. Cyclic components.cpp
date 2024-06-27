// E. Cyclic Components

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an undirected graph consisting of n vertices and m edges. Your task is to find the number of connected components which are cycles. Here are some definitions of graph theory. An undirected graph consists of two sets: set of nodes (called vertices) and set of edges. Each edge connects a pair of vertices. All edges are bidirectional (i.e. if a vertex a is connected with a vertex b, a vertex b is also connected with a vertex a). An edge can't connect vertex with itself, there is at most one edge between a pair of vertices. Two vertices u and v belong to the same connected component if and only if there is at least one path along edges connecting u and v. A connected component is a cycle if and only if its vertices can be reordered in such a way that:

// the first vertex is connected with the second vertex by an edge,
// the second vertex is connected with the third vertex by an edge,
// ...
// the last vertex is connected with the first vertex by an edge,
// all the described edges of a cycle are distinct.

// A cycle doesn't contain any other edges except described above. By definition any cycle contains three or more vertices.

// Figure
// Figure caption - There are 6 connected components, 2 of them are cycles: [7,10,16] and [5,11,9,15].

// Input
// The first line contains two integer numbers n and m (1≤n≤2⋅105, 0≤m≤2⋅105) — number of vertices and edges. The following m lines contains edges: edge i is given as a pair of vertices vi, ui (1≤vi,ui≤n, ui≠vi). There is no multiple edges in the given graph, i.e. for each pair (vi,ui) there no other pairs (vi,ui) and (ui,vi) in the list of edges.

// Output
// Print one integer — the number of connected components which are also cycles.

// Examples
// inputCopy
// 5 4
// 1 2
// 3 4
// 5 4
// 3 5
// outputCopy
// 1

// inputCopy
// 17 15
// 1 8
// 1 12
// 5 11
// 11 9
// 9 15
// 15 5
// 4 13
// 3 13
// 4 3
// 10 16
// 7 10
// 16 7
// 14 3
// 14 4
// 17 6
// outputCopy
// 2

// Note
// In the first example only component [3,4,5] is also a cycle.
// The illustration above corresponds to the second example.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Nodes & edges
//     int n, m;
//     cin >> n >> m;

//     vector<pair<int, int>> edges(m);
//     vector<int> freq(200005);
//     for(int i=0; i<m; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         edges[i].first = x;
//         edges[i].second = y;

//         freq[x]++;
//         freq[y]++;
//     }

//     //Potential cyclic nodes
//     vector<int> nodes;
//     for(int i=0; i<freq.size(); i++)
//     {
//         if(freq[i]==2)
//         {
//             nodes.push_back(i);
//         }
//     }
// }

// Alternate soln -

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

//Nodes and edges
int n, m;

//Occurence freq
int deg[N];

//Visited nodes
bool used[N];

//Flag to indicate if a component is a cycle
bool cycle[N];

//Component
vector<int> comp;

//Grid(given)
vector<int> g[N];

//Here v is the current vertex being visited
//Here parent is the parent vertex from which v is reached during the traversal.
bool dfs(int v, int parent)
{
    used[v] = true;
    comp.push_back(v);

    //Assuming the current component is a cycle, initially
    bool isCycle = true;

    //Iterating over all adjacent vertices (to) of the current vertex v in the graph g
    //If an adjacent vertex to has not been visited (!used[to]), the function recursively calls itself (dfs(to, v)) to explore that vertex
    //During the recursive call, parent is updated to v, indicating that v is the parent of to
    //If the recursive call returns false, it means that the component containing v and to is not a cycle. Hence, isCycle is updated to false
    //If an adjacent vertex to has been visited and it's not the parent (to != parent), it means there is a back edge.
    //In this case, the component is not a cycle, so isCycle is set to false.
    for (auto to : g[v])
    {
        if (!used[to])
        {
            isCycle &= dfs(to, v); //Updating the cycle flag recursively
        }
        else if (to != parent)
        {
            isCycle = false; //Found a back edge, not a cycle
        }
    }

    return isCycle;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        //Zero based indexing maybe
        --x, --y;

        //Adjacency matrix(not given)
        //We have to create it using the edges
        g[x].push_back(y);
        g[y].push_back(x);
        
        deg[x]++;
        deg[y]++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        //If the node is unvisited
        if (!used[i])
        {
            //First clear the component array
            comp.clear();

            //Traversing each node i
            //Starting DFS from node 'i' with no parent
            bool isCycle = dfs(i, -1);

            if (isCycle)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
