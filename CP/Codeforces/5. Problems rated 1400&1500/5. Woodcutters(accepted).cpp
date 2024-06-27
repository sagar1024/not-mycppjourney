// C. Woodcutters

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Little Susie listens to fairy tales before bed every day. Today's fairy tale was about wood cutters and the little girl immediately started imagining the choppers cutting wood. She imagined the situation that is described below. There are n trees located along the road at points with coordinates x1, x2, ..., xn. Each tree has its height hi. Woodcutters can cut down a tree and fell it to the left or to the right. After that it occupies one of the segments [xi - hi, xi] or [xi;xi + hi]. The tree that is not cut down occupies a single point with coordinate xi. Woodcutters can fell a tree if the segment to be occupied by the fallen tree doesn't contain any occupied point. The woodcutters want to process as many trees as possible, so Susie wonders, what is the maximum number of trees to fell.

// Input
// The first line contains integer n (1 ≤ n ≤ 105) — the number of trees. Next n lines contain pairs of integers xi, hi (1 ≤ xi, hi ≤ 109) — the coordinate and the height of the і-th tree. The pairs are given in the order of ascending xi. No two trees are located at the point with the same coordinate.

// Output
// Print a single number — the maximum number of trees that you can cut down by the given rules.

// Examples
// inputCopy
// 5
// 1 2
// 2 1
// 5 10
// 10 9
// 19 1
// outputCopy
// 3
// inputCopy
// 5
// 1 2
// 2 1
// 5 10
// 10 9
// 20 1
// outputCopy
// 4

// Note
// In the first sample you can fell the trees like that:
// fell the 1-st tree to the left — now it occupies segment [ - 1;1]
// fell the 2-nd tree to the right — now it occupies segment [2;3]
// leave the 3-rd tree — it occupies point 5
// leave the 4-th tree — it occupies point 10
// fell the 5-th tree to the right — now it occupies segment [19;20]
// In the second sample you can also fell 4-th tree to the right, after that it will occupy segment [10;19].

#include <bits/stdc++.h>
using namespace std;

#define vll vector<long long int>
#define forn(i, n) for (int i = 0; i < n; i++)

int32_t main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //Inputs
    int n;
    cin >> n;

    vector<pair<long long int, long long int>> trees(n);
    int i = 0;
    forn(i, n)
    {
        cin >> trees[i].first;
        cin >> trees[i].second;
    }

    // Setting count to 2
    // For the first and last tree
    //  int count = 2;
    //  for(int i=2; i<n-1; i++)
    //  {
    //      if(trees[i].first + trees[i].second < trees[i+1].first)
    //      {
    //          count++;
    //      }
    //  }

    int count = 0;

    if (n > 1)
    {
        //For the first and last tree
        count = 2;

        for (int i = 1; i < n - 1; i++)
        {
            //Checking if there's enough space to fall the tree to the left
            if (trees[i].first - trees[i].second > trees[i - 1].first)
            {
                count++;
            }
            //Checking if there's enough space to fall the tree to the right
            else if (trees[i].first + trees[i].second < trees[i + 1].first)
            {
                count++;
                //Adjusting the tree coordinate
                trees[i].first += trees[i].second; 
            }
        }
    }
    else
    {
        //Only one tree
        count = 1;
    }

    //Outputs
    cout << count << endl;
    return 0;
}
