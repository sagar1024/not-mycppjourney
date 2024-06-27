// C. Journey

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n cities and n - 1 roads in the Seven Kingdoms, each road connects two cities and we can reach any city from any other by the roads. Theon and Yara Greyjoy are on a horse in the first city, they are starting traveling through the roads. But the weather is foggy, so they can’t see where the horse brings them. When the horse reaches a city (including the first one), it goes to one of the cities connected to the current city. But it is a strange horse, it only goes to cities in which they weren't before. In each such city, the horse goes with equal probabilities and it stops when there are no such cities. Let the length of each road be 1. The journey starts in the city 1. What is the expected length (expected value of length) of their journey? You can read about expected (average) value by the link https://en.wikipedia.org/wiki/Expected_value.

// Input
// The first line contains a single integer n (1 ≤ n ≤ 100000) — number of cities. Then n - 1 lines follow. The i-th line of these lines contains two integers ui and vi (1 ≤ ui, vi ≤ n, ui ≠ vi) — the cities connected by the i-th road. It is guaranteed that one can reach any city from any other by the roads.

// Output
// Print a number — the expected length of their journey. The journey starts in the city 1. Your answer will be considered correct if its absolute or relative error does not exceed 10 - 6. Namely: let's assume that your answer is a, and the answer of the jury is b. The checker program will consider your answer correct, if .

// Examples
// inputCopy
// 4
// 1 2
// 1 3
// 2 4
// outputCopy
// 1.500000000000000
// inputCopy
// 5
// 1 2
// 1 3
// 3 4
// 2 5
// outputCopy
// 2.000000000000000

// Note
// In the first sample, their journey may end in cities 3 or 4 with equal probability. The distance to city 3 is 1 and to city 4 is 2, so the expected length is 1.5.
// In the second sample, their journey may end in city 4 or 5. The distance to the both cities is 2, so the expected length is 2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> roads(n+1);
//     for(int i=0; i<n-1; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         roads[x].push_back(y);
//         roads[y].push_back(x);
//     }

//     //Array to store the length of all possible routes to complete the journey
//     vector<int> possibleLengths;

//     //Curr len as we iterate thru the graph
//     int currentLenth = 0;
//     double expectedLength = 0;

//     //DFS implementation
//     //Visit every unvisited node and keep the currLen in track
//     //Store the length of each possible journey in an array
//     //Calc the avg of the possible lengths

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <vector>
// #include <iomanip>
// #include <bits/stdc++.h>

// using namespace std;

// vector<vector<int>> adj; //Adjacency list representation of the graph
// vector<bool> visited; //To keep track of visited cities

// //Here, u is the current city, depth is the current length
// void dfs(int u, int depth, int &totalLength, int &totalJourneys)
// {
//     visited[u] = true;
//     bool hasUnvisitedNeighbor = false;

//     for (int v : adj[u])
//     {
//         if (!visited[v])
//         {
//             hasUnvisitedNeighbor = true;
//             dfs(v, depth + 1, totalLength, totalJourneys);
//             totalJourneys++;
//         }
//     }

//     if (!hasUnvisitedNeighbor)
//     {
//         totalLength += depth;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     adj.resize(n+1);
//     visited.resize(n+1, false);

//     //Input the graph
//     for (int i=0; i < n-1; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int totalLength = 0;
//     int totalJourneys = 0;
//     dfs(1, 0, totalLength, totalJourneys);

//     //Calculating the expected length
//     double expectedLength = static_cast<double>(totalLength) / totalJourneys;

//     //Output the result
//     cout << fixed << setprecision(15) << expectedLength << endl;

//     return 0;
// }

// Alternate soln(wa on tc5) -

// #include <iostream>
// #include <vector>
// #include <iomanip>
// #include <bits/stdc++.h>

// using namespace std;

// vector<vector<int>> adj; //Adjacency list representation of the graph
// vector<bool> visited; //To keep track of visited cities

// //DFS function
// void dfs(int u, int depth, int &totalLength, int &totalJourneys)
// {
//     visited[u] = true;
//     bool hasUnvisitedNeighbor = false;

//     for (int v : adj[u])
//     {
//         if (!visited[v])
//         {
//             hasUnvisitedNeighbor = true;
//             dfs(v, depth + 1, totalLength, totalJourneys);
//         }
//     }

//     if (!hasUnvisitedNeighbor)
//     {
//         totalLength += depth;
//         totalJourneys++;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     adj.resize(n + 1);
//     visited.resize(n + 1, false);

//     //Input the graph
//     for (int i = 0; i < n - 1; ++i)
//     {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int totalLength = 0;
//     int totalJourneys = 0;

//     dfs(1, 0, totalLength, totalJourneys);

//     //Calculating the expected length
//     double expectedLength = static_cast<double>(totalLength) / totalJourneys;

//     cout << fixed << setprecision(15) << expectedLength << endl;
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int MAX_N = 2e5 + 17;

//Global vars
vector<int> adj[MAX_N];

//DFS
ld calculateExpectedLength(int currentCity = 0, int parentCity = -1)
{
    ld sum = 0;
    for (int nextCity : adj[currentCity])
    {
        if (nextCity != parentCity)
        {
            sum += calculateExpectedLength(nextCity, currentCity) + 1;
        }
    }

    //If the current city has neighbors
    //Excluding the parent city
    //Return the average length
    return sum ? sum / (adj[currentCity].size() - (parentCity != -1)) : 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //Cities
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;

        city1--, city2--;
        
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    //Expected length of the journey
    cout << fixed << setprecision(7) << calculateExpectedLength() << '\n';

    return 0;
}
