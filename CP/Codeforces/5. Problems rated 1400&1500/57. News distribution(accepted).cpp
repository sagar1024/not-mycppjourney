// C. News Distribution

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In some social network, there are n users communicating with each other in m groups of friends. Let's analyze the process of distributing some news between users. Initially, some user x receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know. For each user x you have to determine what is the number of users that will know the news if initially only user x starts distributing it.

// Input
// The first line contains two integers n and m (1≤n,m≤5⋅105) — the number of users and the number of groups of friends, respectively. Then m lines follow, each describing a group of friends. The i-th line begins with integer ki (0≤ki≤n) — the number of users in the i-th group. Then ki distinct integers follow, denoting the users belonging to the i-th group. It is guaranteed that ∑i=1mki≤5⋅105.

// Output
// Print n integers. The i-th integer should be equal to the number of users that will know the news if user i starts distributing it.

// Example
// inputCopy
// 7 5
// 3 2 5 4
// 0
// 2 1 2
// 1 1
// 2 6 7
// outputCopy
// 4 4 1 4 4 2 2

// My original soln(memory limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adjMatrix(n+1);

//     for(int i=0; i<m; i++)
//     {
//         int k;
//         cin >> k;

//         vector<int> group(k);
//         for(int j=0; j<k; j++)
//         {
//             cin >> group[j];
//         }

//         for(int u: group)
//         {
//             for(int v: group)
//             {
//                 if(u!=v)
//                 {
//                     adjMatrix[u].push_back(v);
//                 }
//             }
//         }
//     }

//     //Function within a function
//     //Function to perform bfs from a given source
//     auto bfs = [&](int source)
//     {
//         queue<int> q;
//         unordered_set<int> visited;

//         //Start by adding/pushing/inserting the source
//         q.push(source);
//         visited.insert(source);

//         while(!q.empty())
//         {
//             //Iterate the queue from the front
//             int u = q.front();
//             q.pop();

//             //Iterating v in the uth row
//             //Visitting all neighbors of u
//             for(int v: adjMatrix[u])
//             {
//                 //If node v has not yet been visited
//                 if(visited.find(v) == visited.end())
//                 {
//                     q.push(v);
//                     visited.insert(v);
//                 }
//             }
//         }

//         //Num of users who got the news
//         return (int)visited.size();
//     };

//     //Bfs for each user
//     for(int i=1; i<=n; i++)
//     {
//         cout << bfs(i) << " ";
//     }

//     cout << endl;
//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> parent, componentSize;

//Find operation for DSU
int find(int u)
{
    return (parent[u] == u) ? u : (parent[u] = find(parent[u]));
}

//Union operation for DSU
void unionSet(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    if (pu != pv)
    {
        parent[pu] = pv;
        componentSize[pv] += componentSize[pu];
    }
}

void dfs(int u, const vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v, adjList, visited);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);

    //Initializing each component with size 1
    componentSize.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        //Initializing each vertex as its own parent
        parent[i] = i;
    }

    //Constructing the graph
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        vector<int> group(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> group[j];
        }
        //Connecting neighboring vertices within each group
        for (int j = 1; j < k; ++j)
        {
            unionSet(group[j - 1], group[j]);
        }
    }

    //Counting the number of vertices in each component
    vector<int> componentCount(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        componentCount[find(i)]++;
    }

    //Output the result
    for (int i = 1; i <= n; ++i)
    {
        cout << componentCount[find(i)] << " ";
    }

    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}
