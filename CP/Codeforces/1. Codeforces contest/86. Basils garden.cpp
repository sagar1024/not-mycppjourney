// C. Basil's Garden

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n flowers in a row, the i-th of them initially has a positive height of hi meters. Every second, the wind will blow from the left, causing the height of some flowers to decrease. Specifically, every second, for each i from 1 to n, in this order, the following happens: If i=n or hi>hi+1, the value of hi changes to max(0,hi−1). How many seconds will pass before hi=0 for all 1≤i≤n for the first time?

// Input
// Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤105) — the number of flowers. The second line of each test case contains n integers h1,h2,…,hn (1≤hi≤109) — the heights of the flowers. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output a single integer — the number of seconds that will pass before hi=0 for all 1≤i≤n.

// Example
// inputCopy
// 4
// 3
// 1 1 2
// 2
// 3 1
// 1
// 9
// 5
// 7 4 4 3 2
// outputCopy
// 4
// 3
// 9
// 7

// Note
// In the first test case, the flower heights change as follows: [1,1,2]→[1,1,1]→[1,1,0]→[1,0,0]→[0,0,0].
// In the second test case, the flower heights change as follows: [3,1]→[2,0]→[1,0]→[0,0].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long int> h(n);
        for(int i=0; i<n; i++)
        {
            cin >> h[i];
        }

        int seconds = 0;
        bool allZero = false;
        while(!allZero)
        {
            allZero = true;
            for(int i=n-1; i>=0; i--)
            {
                if(h[i]<=0) continue;

                if(i==n-1)
                {
                    h[i]--;
                    if(h[i]>=h[i-1])
                    {
                        seconds++;
                        continue;
                    }
                    if(h[i]!=0) allZero &= false;
                }
                while(h[i]<h[i-1] && i-1>=0)
                {
                    h[i-1]--;
                    i--;
                    if(h[i-1]!=0 && i-1>=0) allZero &= false;
                }
            }

            seconds++;
        }

        cout << seconds << endl;
    }

    return 0;
}
