// B. Kuriyama Mirai's Stones

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kuriyama Mirai has killed many monsters and got many (namely n) stones. She numbers the stones from 1 to n. The cost of the i-th stone is vi. Kuriyama Mirai wants to know something about these stones so she will ask you two kinds of questions: She will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her. Let ui be the cost of the i-th cheapest stone (the cost that will be on the i-th place if we arrange all the stone costs in non-decreasing order). This time she will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her . For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu" and then become unhappy.

// Input
// The first line contains an integer n (1 ≤ n ≤ 105). The second line contains n integers: v1, v2, ..., vn (1 ≤ vi ≤ 109) — costs of the stones. The third line contains an integer m (1 ≤ m ≤ 105) — the number of Kuriyama Mirai's questions. Then follow m lines, each line contains three integers type, l and r (1 ≤ l ≤ r ≤ n; 1 ≤ type ≤ 2), describing a question. If type equal to 1, then you should output the answer for the first question, else you should output the answer for the second one.

// Output
// Print m lines. Each line must contain an integer — the answer to Kuriyama Mirai's question. Print the answers to the questions in the order of input.

// Examples
// inputCopy
// 6
// 6 4 2 7 2 7
// 3
// 2 3 6
// 1 3 4
// 1 1 6
// outputCopy
// 24
// 9
// 28

// inputCopy
// 4
// 5 5 2 3
// 10
// 1 2 4
// 2 1 4
// 1 1 1
// 2 1 4
// 2 1 2
// 1 1 1
// 1 3 3
// 1 1 3
// 1 4 4
// 1 2 2
// outputCopy
// 10
// 15
// 5
// 15
// 5
// 5
// 2
// 12
// 3
// 5

// Note
// Please note that the answers to the questions may overflow 32-bit integer type.

//My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<long long int> costs(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> costs[i];
//     }

//     vector<long long int> costs2 = costs;
//     sort(costs2.begin(), costs2.end());

//     int m;
//     cin >> m;

//     for(int i=0; i<m; i++)
//     {
//         //Total cost sum from L to R
//         long long int totalCost = 0;

//         int type, l, r;
//         cin >> type >> l >> r;

//         if(type==1)
//         {
//             for(int x=l-1; x<=r-1; x++)
//             {
//                 totalCost += costs[x];
//             }
//         }
//         else if(type==2)
//         {
//             for(int y=l-1; y<=r-1; y++)
//             {
//                 totalCost += costs2[y];
//             }
//         }

//         cout << totalCost << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long int> costs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    //1-based indexing
    vector<long long int> cumSum(n+1);
    for(int i=1; i<=n; i++)
    {
        cumSum[i] += cumSum[i-1] + costs[i-1];
    }

    //Sorting the costs array
    vector<long long int> sortedCosts = costs;
    sort(sortedCosts.begin(), sortedCosts.end());

    //Preprocessing cumulative sums
    //For the sorted costs array

    //1-based indexing
    vector<long long int> cumSumSorted(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cumSumSorted[i] = cumSumSorted[i-1] + sortedCosts[i-1];
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;

        long long int totalCost = 0;
        if(type == 1)
        {
            // Preprocess cumulative sums for the original costs array
            // vector<long long int> cumSum(n + 1);
            // for(int j = 1; j <= n; j++)
            // {
            //     cumSum[j] = cumSum[j - 1] + costs[j - 1];
            // }

            // Calculate total cost for original costs
            //Here we take "r" and "l-1"
            //Because we made the cumulative sum arrays using 1-based indexing
            //But the arrays are always 0-based indexed
            //That is why we are subtracting the cumSum till "r-1" by cumSum till "l"
            totalCost = cumSum[r] - cumSum[l-1];
        }
        else if(type == 2)
        {
            // Calculate total cost for sorted costs using preprocessed cumulative sums
            totalCost = cumSumSorted[r] - cumSumSorted[l-1];
        }

        cout << totalCost << endl;
    }

    return 0;
}
