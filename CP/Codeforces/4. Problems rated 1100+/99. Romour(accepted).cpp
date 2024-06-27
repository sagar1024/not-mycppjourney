// C. Rumor

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vova promised himself that he would never play computer games... But recently Firestorm — a well-known game developing company — published their newest game, World of Farcraft, and it became really popular. Of course, Vova started playing it. Now he tries to solve a quest. The task is to come to a settlement named Overcity and spread a rumor in it. Vova knows that there are n characters in Overcity. Some characters are friends to each other, and they share information they got. Also Vova knows that he can bribe each character so he or she starts spreading the rumor; i-th character wants ci gold in exchange for spreading the rumor. When a character hears the rumor, he tells it to all his friends, and they start spreading the rumor to their friends (for free), and so on. The quest is finished when all n characters know the rumor. What is the minimum amount of gold Vova needs to spend in order to finish the quest? Take a look at the notes if you think you haven't understood the problem completely.

// Input
// The first line contains two integer numbers n and m (1 ≤ n ≤ 105, 0 ≤ m ≤ 105) — the number of characters in Overcity and the number of pairs of friends. The second line contains n integer numbers ci (0 ≤ ci ≤ 109) — the amount of gold i-th character asks to start spreading the rumor. Then m lines follow, each containing a pair of numbers (xi, yi) which represent that characters xi and yi are friends (1 ≤ xi, yi ≤ n, xi ≠ yi). It is guaranteed that each pair is listed at most once.

// Output
// Print one number — the minimum amount of gold Vova has to spend in order to finish the quest.

// Examples
// inputCopy
// 5 2
// 2 5 3 4 8
// 1 4
// 4 5
// outputCopy
// 10

// inputCopy
// 10 0
// 1 2 3 4 5 6 7 8 9 10
// outputCopy
// 55

// inputCopy
// 10 5
// 1 6 2 7 3 8 4 9 5 10
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10
// outputCopy
// 15

// Note
// In the first example the best decision is to bribe the first character (he will spread the rumor to fourth character, and the fourth one will spread it to fifth). Also Vova has to bribe the second and the third characters, so they know the rumor.
// In the second example Vova has to bribe everyone.
// In the third example the optimal decision is to bribe the first, the third, the fifth, the seventh and the ninth characters.

// Original approach -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Number of people & number of friend pairs
//     int n, m;
//     cin >> n >> m;

//     vector<long long int> askedBribe(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> askedBribe[i];
//     }

//     //Adjacency matrix
//     //Stores the friendship pairs
//     vector<vector<int>> adj(n);
//     for(int i=0; i<m; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         //Zero-based indexing
//         x--;
//         y--;

//         //Symmetric matrix?
//         adj[x-1].push_back(y-1);
//         adj[y-1].push_back(x-1);
//     }

//     //Answer variable
//     long long int totalKharcha = 0;

//     //BFS for each node
//     for(int start=0; start<n; start++)
//     {
//         if(askedBribe[start]==0)
//         {
//             continue;
//         }

//         //USing a queue to store friends
//         queue<int> q;
//         vector<bool> visited(n);

//         //Once we push the index of the bribe asker, set the visit state to true
//         q.push(start);
//         visited[start] = true;

//         //Performing BFS
//         while(!q.empty())
//         {
//             //Store the asked price in the total and then pop it
//             int u = q.front();
//             q.pop();

//             //Add the current bribe
//             totalKharcha += askedBribe[u];

//             //Visit neighbors
//             for(int v: adj[u])
//             {
//                 //Visit the unvisited nodes
//                 if(!visited[v])
//                 {
//                     visited[v] = true;
//                     q.push(v);
//                 }
//             }
//         }
//     }

//     //Output
//     cout << totalKharcha << endl;

//     return 0;
// }

// Alternate approach -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to perform dfs
//The parameters are passed by reference
//Parameters are -
//Current index
//Adjacency matrix
//Asked bribe array
//Boolean array visited
//Comparison variable

void dfs(int u, const vector<vector<int>> &adj, const vector<long long> &askedBribe, vector<bool> &visited, long long &componentMin)
{
    visited[u] = true;
    componentMin = min(componentMin, askedBribe[u]);

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            //Recursive func call
            dfs(v, adj, askedBribe, visited, componentMin);
        }
    }
}

int main()
{
    //INputs
    int n, m;
    cin >> n >> m;

    vector<long long> askedBribe(n);
    for (int i = 0; i < n; i++)
    {
        cin >> askedBribe[i];
    }

    //Adjacency matrix
    //Friendship links
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    //To keep track of the nodes visited
    //Ignoring the visited onces in the next iteration
    vector<bool> visited(n, false);

    //Answer variable
    long long totalKharcha = 0;
    for (int i = 0; i < n; i++)
    {
        //This condition check if a particular node have been visited before in the recursive function
        if (!visited[i])
        {
            //Finding the min bribe to minimize the cost
            long long componentMin = LLONG_MAX;

            //Dfs function call
            dfs(i, adj, askedBribe, visited, componentMin);
            totalKharcha += componentMin;
        }
    }

    //Outputs
    cout << totalKharcha << endl;
    return 0;
}
