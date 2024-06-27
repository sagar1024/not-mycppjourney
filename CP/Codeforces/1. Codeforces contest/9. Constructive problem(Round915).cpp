// A. Constructive Problems

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Gridlandia has been hit by flooding and now has to reconstruct all of it's cities. Gridlandia can be described by an n×m matrix. Initially, all of its cities are in economic collapse. The government can choose to rebuild certain cities. Additionally, any collapsed city which has at least one vertically neighboring rebuilt city and at least one horizontally neighboring rebuilt city can ask for aid from them and become rebuilt without help from the government. More formally, collapsed city positioned in (i,j) can become rebuilt if both of the following conditions are satisfied:

// At least one of cities with positions (i+1,j) and (i−1,j) is rebuilt;
// At least one of cities with positions (i,j+1) and (i,j−1) is rebuilt.

// If the city is located on the border of the matrix and has only one horizontally or vertically neighbouring city, then we consider only that city.

// "A picture and an illustration"

// Illustration of two possible ways cities can be rebuilt by adjacent aid. White cells are collapsed cities, yellow cells are initially rebuilt cities (either by the government or adjacent aid), and orange cells are rebuilt cities after adjacent aid.
// The government wants to know the minimum number of cities it has to rebuild such that after some time all the cities can be rebuild.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The only line of each test case contains two integers n and m (2≤n,m≤100) — the sizes of Gridlandia.

// Output
// For each test case, output a single integer — the minimum number of cities the government needs to rebuild.

// Example
// Input
// 3
// 2 2
// 5 7
// 3 2

// Output
// 2
// 7
// 3

// Note
// In the first test case, it's enough for the government to rebuild cities (1,2) and (2,1).

// In the second test case, it's enough for the government to rebuild cities (1,4), (2,2), (3,1), (3,6), (4,3), (5,5), (5,7).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Dimensions of the city
        int n, m;
        cin >> n >> m;

        //Main logic
        //The number of cities to be rebuilt by the govt will be equal to the longer dimension of the city
        //Not a logic, but an observation
        int longerDimension = max(n, m);

        cout << longerDimension << endl;
    }

    return 0;
}
