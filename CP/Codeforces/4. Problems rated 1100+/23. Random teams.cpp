// B. Random Teams

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// n participants of the competition were split into m teams in some manner so that each team has at least one participant. After the competition each pair of participants from the same team became friends. Your task is to write a program that will find the minimum and the maximum number of pairs of friends that could have formed by the end of the competition.

// Input
// The only line of input contains two integers n and m, separated by a single space (1 ≤ m ≤ n ≤ 109) — the number of participants and the number of teams respectively.

// Output
// The only line of the output should contain two integers kmin and kmax — the minimum possible number of pairs of friends and the maximum possible number of pairs of friends respectively.

// Examples
// inputCopy
// 5 1
// outputCopy
// 10 10

// inputCopy
// 3 2
// outputCopy
// 1 1

// inputCopy
// 6 3
// outputCopy
// 3 6

// Note
// In the first sample all the participants get into one team, so there will be exactly ten pairs of friends.
// In the second sample at any possible arrangement one team will always have two participants and the other team will always have one participant. Thus, the number of pairs of friends will always be equal to one.
// In the third sample minimum number of newly formed friendships can be achieved if participants were split on teams consisting of 2 people, maximum number can be achieved if participants were split on teams of 1, 1 and 4 people.

//My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Func to calc the fact of n
// int factorial(int n)
// {
//     int fact = 1;
//     for(int i=n; i>=1; i--)
//     {
//         fact *= i;
//     }

//     return fact;
// }

// //Func to calc the combination of 2 players out of n
// int combination(int n, int r)
// {
//     int comb = factorial(n)/(factorial(n-r)*factorial(r));
//     return comb;
// }

// int main()
// {
//     //Num of participants
//     //Num of teams
//     long long int n, m;
//     cin >> n >> m;

//     //MAIN logic
//     //Minimum pairs can be achieved when the players are equally divided among teams
//     long long int minimumPairs = 0;
//     if(n%m==0)
//     {
//         //Players are equally divided
//         //AND
//         //Each team has x players
//         long long int x = n/m;
//         long long int pairs = combination(x,2);

//         minimumPairs = m*pairs;
//     }
//     else
//     {
//         //Players are almost equally divided
//         //BUT
//         //Here m-1 teams have x players
//         //AND
//         //One team has x+remainder players

//         // long long int x = round(static_cast<float>(n/m));
//         // long long int remainder = n - (m-1)*x;

//         // long long int pairs = combination(x,2);
//         // long long int pairs2 = combination(remainder,2);

//         // minimumPairs = (m-1)*pairs + pairs2;

//         //Alternate logic -
//         //Number of participants per team
//         long long int x = n / m;
//         //Remaining participants after distributing evenly
//         long long int remainder = n % m;
//         //Pairs formed from teams with x participants
//         long long int pairs = (m - remainder) * combination(x, 2);
//         //Pairs formed from teams with x+1 participants
//         pairs += remainder * combination(x + 1, 2);
//         minimumPairs = pairs;
//     }

//     //Maximum pairs can be achieved when majority of the players are in one team
//     //Here we are putting 1 player in m-1 teams
//     //AND one team will have all the remaining players
//     long long int maximumPairs = combination((n-(m-1)), 2);

//     cout << minimumPairs << " " << maximumPairs << endl;

//     return 0;
// }

//Alternate soln(optimized using chatgpt)(time limit exceeded again) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // Function to calculate combinations (n choose r) using dynamic programming
// long long int combination(int n, int r)
// {
//     if (r == 0 || r == n) return 1;
//     vector<long long int> C(r + 1, 0);
//     C[0] = 1;
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = min(i, r); j > 0; --j)
//         {
//             C[j] = (C[j] + C[j - 1]);
//         }
//     }

//     return C[r];
// }

// int main()
// {
//     long long int n, m;
//     cin >> n >> m;

//     // Calculate minimum pairs
//     long long int x = n / m;
//     long long int remainder = n % m;

//     long long int minimumPairs = (m - remainder) * combination(x, 2) + remainder * combination(x + 1, 2);

//     // Calculate maximum pairs
//     long long int maximumPairs = combination(n - m + 1, 2);

//     cout << minimumPairs << " " << maximumPairs << endl;

//     return 0;
// }

//Alternate soln(using graphs) -

//If you restate the problem in terms of graph theory, it can be formulated as follows: There is a graph consisting of n vertices and m connected components. Inside each connected component, each pair of vertices connected by an edge of the component. In other words, each connected component is a full mesh. What is the smallest and the largest number of edges which may contain such a graph? Consider the process of constructing a graph of n vertices and m connected components. To begin, assume that each of the m component contains a single peak. It remains to distribute the remaining n — m vertices so as to minimize or maximize the number of edges. Note that when adding a new vertex in the connected component of size k, the number of edges is increased by k (new vertex is connected to each of the existing one edge). Consequently, in order to minimize the number of ribs formed on each step required each time to enhance top component connected smallest size. If you act according to this strategy, after the distribution of vertices on the connected components appears component size and component size. Similarly, in order to maximize the number of edges in each step must be added to the next vertex in the component connectivity greatest dimension. If you act according to such a strategy, then a single connected component of size n — m + 1, the remaining connected components will consist of a single vertex. Knowing the number of connected components and their sizes, you can count the total number of edges. For a full mesh components consisting of k vertices, the number of edges equals. It should be remembered about the need to use a 64-bit data type to store the number of edges, which depends quadratically on the value of n.

//Approach -

//To minimize the number of edges, we should distribute the vertices among the connected components such that each component has the smallest possible size. This means adding one vertex at a time to each component until all vertices are distributed. To maximize the number of edges, we should add the remaining vertices to the largest connected component until all vertices are distributed. Once we have determined the sizes of all connected components, we can calculate the minimum and maximum number of edges accordingly.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    //MAIN logic
    //Calculate the minimum number of edges
    long long min_edges = 0;

    //If the teams are non-Divisible
    //When n/m is <2
    if(n/m>1 && n/m<2)
    {
        int x = ceil(static_cast<float>(n/m));
        int remainder = floor(static_cast<float>(n/m));

        //Calc the pairs/combinations
        int a = x*(x-1)/2;
        int b = remainder*(remainder-1)/2;

        min_edges = a*(m-1) + b;
    }
    //When n/m is >=2
    //There are more than 2 players in each team
    else if(n/m>=2)
    {
        //Minimum size of each connected component
        //long long min_size = round(static_cast<float>(n / m));
        long long min_size = n/m;
        //Remaining vertices after distribution
        long long remainder = n%m;

        //Add edges for the remaining vertices
        min_edges += remainder*(min_size*(min_size-1)/2);
        //Add edges for the other components
        min_edges += (m-remainder)*(min_size*(min_size-1)/2);
    }
    //If the teams are divisible
    else if(n%m==0)
    {
        int x = n/m;
        min_edges = m*(x*(x-1)/2);
    }

    //Calculate the maximum number of edges
    //Number of edges in the largest connected component
    long long max_edges = (n-m+1) * (n-m)/2;

    cout << min_edges << " " << max_edges << endl;

    return 0;
}
