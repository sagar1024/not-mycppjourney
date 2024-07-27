// C. Sloth Naptime

// time limit per test5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// As probably know, sloths live on trees. Accordingly, David has a pet sloth which he lets play on his unweighted trees when he solves programming problems. Occasionally, David will notice that his sloth is located on a particular node a in the tree, and ask it to move to some other node b. Of course, the sloth is as well-intentioned as can be, but alas, it only has enough energy to move across at most c edges. If the sloth needs to cross fewer than c edges to get to node b, it will get there and then take a nap. Otherwise, it will get as close as possible before it retires and hangs idly awaiting further digestion. Where will the sloth end up? Also, since this happens quite often, David would like you to answer q queries, each one of the similar form.

// Input
// The first line will contain a single integer n, the number of nodes in the tree. The following n−1 lines will contain two integers u and v, describing the edges in the tree. These edges will form a tree. After that, there will be a single line containing an integer q, the number of times David will motivate his sloth to move. q lines follow, each containing three integers a, b, and c: the node the sloth starts on, the node David asks the sloth to move to, and the energy the sloth has when starting.
// 1≤n,q≤3∗105
// 1≤a,b,c,u,v≤n

// Output
// For each query, output a single integer: the id of the node that the sloth must sleep at.

// Examples
// inputCopy
// 1
// 1
// 1 1 1
// outputCopy
// 1
// inputCopy
// 3
// 3 2
// 2 1
// 3
// 2 2 2
// 1 1 2
// 3 3 3
// outputCopy
// 2
// 1
// 3
// inputCopy
// 5
// 4 2
// 1 4
// 5 4
// 3 4
// 5
// 3 5 2
// 3 5 4
// 1 5 5
// 4 5 4
// 1 5 4
// outputCopy
// 5
// 5
// 5
// 5
// 5

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int32_t main()
{
    int n;
    cin >> n;

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

    int q;
    cin >> q;

    while(q--)
    {
        //Start, end and energy
        int a, b, c;
        cin >> a >> b >> c;
    }

    return 0;
}
