// D. Cycle Free Flow

// time limit per test4 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an undirected connected weighted graph of n nodes which contains no cycles. For q different pairs of nodes, we would like you to find the maximum flow from the first node in the pair to the second node in the pair. See the definition for max flow below if you don't know what it means. Also, please answer these queries online. Originally, I was going to force you to do this by encrypting stuff, but that would make this problem harder to read and more annoying. So, on your honor, please answer the first query before reading the second query, et cetera. After all, this is just practice for you to get better, right? The maximum flow in a graph between two nodes a and b can be defined as follows: You may pick any path from a to b such that every edge on that path has a positive weight. Then you may subtract 1 from the weight of every edge on that path, and add 1 to your answer. Keep doing this as many times as you would like. The "maximum flow" between the two nodes is the greatest that your answer could possibly be, if you choose your paths optimally at every step.

// Input
// The first line will contain a two integers: n and m, the number of nodes and the number of edges in the graph. The next m lines will each contain three integers: the endpoints u and v of an undirected edge, and the initial weight of that edge w. The next line will contain a single integer q: the number of queries you must answer. Each of the next q lines will contain two integers: a and b, the two nodes you should find the max flow between.

// 2≤n,m,≤3∗105
// 1≤a,b,≤n a≠b
// 1≤w≤109
// u≠v

// Additional constraint on input: the given graph is connected and has no cycles, self-loops, or multi-edges.

// Output
// For each query, please print a single integer: the max flow between nodes a and nodes b for that query.

// Examples
// inputCopy
// 2 1
// 1 2 2768
// 2
// 1 2
// 2 1
// outputCopy
// 2768
// 2768
// inputCopy
// 3 2
// 3 2 4814
// 2 1 1832
// 3
// 2 1
// 1 2
// 3 1
// outputCopy
// 1832
// 1832
// 1832
// inputCopy
// 5 4
// 4 2 10348
// 1 4 2690
// 5 4 9807
// 3 4 8008
// 5
// 5 4
// 1 5
// 5 4
// 5 4
// 1 5
// outputCopy
// 9807
// 2690
// 9807
// 9807
// 2690
// inputCopy
// 5 4
// 1 3 2653
// 4 1 322
// 5 1 8657
// 2 4 4896
// 5
// 4 2
// 2 5
// 2 5
// 1 3
// 4 5
// outputCopy
// 4896
// 322
// 322
// 2653
// 322

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{

}
