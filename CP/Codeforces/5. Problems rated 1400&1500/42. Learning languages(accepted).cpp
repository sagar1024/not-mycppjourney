// A. Learning Languages

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The "BerCorp" company has got n employees. These employees can use m approved official languages for the formal correspondence. The languages are numbered with integers from 1 to m. For each employee we have the list of languages, which he knows. This list could be empty, i. e. an employee may know no official languages. But the employees are willing to learn any number of official languages, as long as the company pays their lessons. A study course in one language for one employee costs 1 berdollar. Find the minimum sum of money the company needs to spend so as any employee could correspond to any other one (their correspondence can be indirect, i. e. other employees can help out translating).

// Input
// The first line contains two integers n and m (2 ≤ n, m ≤ 100) — the number of employees and the number of languages. Then n lines follow — each employee's language list. At the beginning of the i-th line is integer ki (0 ≤ ki ≤ m) — the number of languages the i-th employee knows. Next, the i-th line contains ki integers — aij (1 ≤ aij ≤ m) — the identifiers of languages the i-th employee knows. It is guaranteed that all the identifiers in one list are distinct. Note that an employee may know zero languages. The numbers in the lines are separated by single spaces.

// Output
// Print a single integer — the minimum amount of money to pay so that in the end every employee could write a letter to every other one (other employees can help out translating).

// Examples
// inputCopy
// 5 5
// 1 2
// 2 2 3
// 2 3 4
// 2 4 5
// 1 5
// outputCopy
// 0
// inputCopy
// 8 7
// 0
// 3 1 2 3
// 1 1
// 2 5 4
// 2 6 7
// 1 3
// 2 7 4
// 1 1
// outputCopy
// 2
// inputCopy
// 2 2
// 1 2
// 0
// outputCopy
// 1

// Note
// In the second sample the employee 1 can learn language 2, and employee 8 can learn language 4.
// In the third sample employee 2 must learn language 2.

//My original soln(tutorial help) -

#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int n, m;
bool visited[MAX_N];
bool knows[MAX_N][MAX_M];

//Depth-first search function to traverse the graph
//Its' only function is to update the visited status of nodes
//Here "start" is the center of the ripple in dfs wave
void DFS(int start)
{
    visited[start] = true;

    //For every wave of traversal, we will try reach as many(all) nodes as possible
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            //Trying to iterate thru each emp and their lang stack
            for (int j = 0; j < m; j++)
            {
                //Checking if the emp knows jth language and whether it is connected to the curr node(curr emp)
                if (knows[i][j] && knows[start][j])
                {
                    DFS(i);
                }
            }
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        int ans = 0;
        bool allZero = true;

        //Memset is a function used in C and C++ to set a block of memory to a particular value
        //It takes three arguments: a pointer to the memory block to fill, the value to fill the memory with, and the number of bytes to fill
        memset(visited, false, sizeof(visited));
        memset(knows, false, sizeof(knows));

        //Languages known by each employee
        for (int i = 0; i < n; i++)
        {
            //Num of lang the curr emp knows
            int k;
            cin >> k;

            //Languages
            for (int j = 0; j < k; j++)
            {
                int lang;
                cin >> lang;

                knows[i][lang - 1] = true;
                allZero = false;
            }
        }

        //Counting connected components using DFS
        for (int i = 0; i < n; i++)
        {
            //Visited array is initially all false
            if (!visited[i])
            {
                //Call dfs wave from the starting point "i"
                //Node "i" is the center of the ripples
                //Updates the "visited" status of nodes connected to ith node
                DFS(i);
                ans++;
            }
        }

        //Minimum number of edges to add
        if(allZero)
        {
            cout << ans << endl;
        }
        else
        {
            cout << ans - 1 << endl;
        }
    }

    return 0;
}
