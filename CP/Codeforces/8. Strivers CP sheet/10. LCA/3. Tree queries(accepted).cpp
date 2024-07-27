// E. Tree Queries

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a rooted tree consisting of n vertices numbered from 1 to n. The root of the tree is a vertex number 1. A tree is a connected undirected graph with n−1 edges. You are given m queries. The i-th query consists of the set of ki distinct vertices vi[1],vi[2],…,vi[ki]. Your task is to say if there is a path from the root to some vertex u such that each of the given k vertices is either belongs to this path or has the distance 1 to some vertex of this path.

// Input
// The first line of the input contains two integers n and m (2≤n≤2⋅105, 1≤m≤2⋅105) — the number of vertices in the tree and the number of queries. Each of the next n−1 lines describes an edge of the tree. Edge i is denoted by two integers ui and vi, the labels of vertices it connects (1≤ui,vi≤n,ui≠vi). It is guaranteed that the given edges form a tree. The next m lines describe queries. The i-th line describes the i-th query and starts with the integer ki (1≤ki≤n) — the number of vertices in the current query. Then ki integers follow: vi[1],vi[2],…,vi[ki] (1≤vi[j]≤n), where vi[j] is the j-th vertex of the i-th query. It is guaranteed that all vertices in a single query are distinct. It is guaranteed that the sum of ki does not exceed 2⋅105 (∑i=1mki≤2⋅105).

// Output
// For each query, print the answer — "YES", if there is a path from the root to some vertex u such that each of the given k vertices is either belongs to this path or has the distance 1 to some vertex of this path and "NO" otherwise.

// Example
// inputCopy
// 10 6
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 7
// 7 8
// 7 9
// 9 10
// 4 3 8 9 10
// 3 2 4 6
// 3 2 1 5
// 3 4 8 2
// 2 6 10
// 3 5 4 7
// outputCopy
// YES
// YES
// YES
// YES
// NO
// NO

// Note
// The picture corresponding to the example:

// Consider the queries.
// The first query is [3,8,9,10]. The answer is "YES" as you can choose the path from the root 1 to the vertex u=10. Then vertices [3,9,10] belong to the path from 1 to 10 and the vertex 8 has distance 1 to the vertex 7 which also belongs to this path.
// The second query is [2,4,6]. The answer is "YES" as you can choose the path to the vertex u=2. Then the vertex 4 has distance 1 to the vertex 1 which belongs to this path and the vertex 6 has distance 1 to the vertex 2 which belongs to this path.
// The third query is [2,1,5]. The answer is "YES" as you can choose the path to the vertex u=5 and all vertices of the query belong to this path.
// The fourth query is [4,8,2]. The answer is "YES" as you can choose the path to the vertex u=9 so vertices 2 and 4 both have distance 1 to the vertex 1 which belongs to this path and the vertex 8 has distance 1 to the vertex 7 which belongs to this path.
// The fifth and the sixth queries both have answer "NO" because you cannot choose suitable vertex u.

// My first soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// vector<vector<int>> tree;
// vector<int> depth, parent;

// void bfs(int root)
// {
//     queue<int> q;
//     q.push(root);
//     depth[root] = 0;
//     parent[root] = -1;
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         for (int neighbor : tree[node])
//         {
//             if (neighbor != parent[node])
//             {
//                 parent[neighbor] = node;
//                 depth[neighbor] = depth[node] + 1;
//                 q.push(neighbor);
//             }
//         }
//     }
// }

// bool is_on_or_near_path(int u, set<int> &path_nodes)
// {
//     //Checking if u is on the path or one of its neighbors is on the path
//     if (path_nodes.find(u) != path_nodes.end()) return true;
//     for (int neighbor : tree[u])
//     {
//         if (path_nodes.find(neighbor) != path_nodes.end()) return true;
//     }

//     return false;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     tree.resize(n + 1);
//     depth.resize(n + 1);
//     parent.resize(n + 1);
//     for (int i = 0; i < n - 1; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }

//     bfs(1);
//     while (m--)
//     {
//         int k;
//         cin >> k;

//         vector<int> query_vertices(k);
//         for (int i = 0; i < k; ++i)
//         {
//             cin >> query_vertices[i];
//         }

//         //Finding the deepest node in the query
//         int deepest_node = query_vertices[0];
//         for (int v : query_vertices)
//         {
//             if (depth[v] > depth[deepest_node])
//             {
//                 deepest_node = v;
//             }
//         }

//         //Collecting nodes on the path from root to deepest_node
//         set<int> path_nodes;
//         int current = deepest_node;
//         while (current != -1)
//         {
//             path_nodes.insert(current);
//             current = parent[current];
//         }

//         bool valid = true;
//         for (int v : query_vertices)
//         {
//             if (!is_on_or_near_path(v, path_nodes))
//             {
//                 valid = false;
//                 break;
//             }
//         }

//         if (valid) cout << "YES\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int time_counter;
vector<int> parent, depth;
vector<int> time_in, time_out;
vector<vector<int>> graph;

void dfs(int node, int par = -1, int dep = 0)
{
    parent[node] = par;
    depth[node] = dep;
    time_in[node] = time_counter++;
    for (int neighbor : graph[node])
    {
        if (neighbor == par)
            continue;
        dfs(neighbor, node, dep + 1);
    }

    time_out[node] = time_counter++;
}

bool isAncestor(int ancestor, int node)
{
    return time_in[ancestor] <= time_in[node] && time_out[node] <= time_out[ancestor];
}

int main()
{
    int n, m;
    cin >> n >> m;

    time_counter = 0;
    parent = depth = vector<int>(n);
    time_in = time_out = vector<int>(n);
    graph = vector<vector<int>>(n);

    //Reading the tree edges
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //Performing DFS from root (node 0)
    dfs(0);

    //Processing each query
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        vector<int> query_nodes(k);
        for (int &node : query_nodes)
        {
            cin >> node;
            --node;
        }

        //Finding the deepest node in the query
        int deepest_node = query_nodes[0];
        for (int node : query_nodes)
        {
            if (depth[deepest_node] < depth[node])
            {
                deepest_node = node;
            }
        }

        //Adjusting the nodes to their parent if they are not the deepest node
        for (int &node : query_nodes)
        {
            if (node == deepest_node) continue;
            if (parent[node] != -1) node = parent[node];
        }

        //Checking if all adjusted nodes are ancestors of the deepest node
        bool valid = true;
        for (int node : query_nodes)
        {
            valid &= isAncestor(node, deepest_node);
        }

        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
