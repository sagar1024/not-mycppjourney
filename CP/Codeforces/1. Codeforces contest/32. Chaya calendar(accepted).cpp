// B. Chaya Calendar

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The Chaya tribe believes that there are n signs of the apocalypse. Over time, it has been found out that the i-th sign occurs every ai years (in years ai, 2⋅ai, 3⋅ai, …). According to the legends, for the apocalypse to happen, the signs must occur sequentially. That is, first they wait for the first sign to occur, then strictly after it, the second sign will occur, and so on. That is, if the i-th sign occurred in the year x, the tribe starts waiting for the occurrence of the (i+1)-th sign, starting from the year x+1. In which year will the n-th sign occur and the apocalypse will happen?

// Input
// The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. Then follow the descriptions of the test cases. The first line of each test case contains a single integer n (1≤n≤100) — the number of signs. The second line of each test case contains n integers a1,a2,a3,…,an (1≤ai≤106) — the periodicities of the signs.

// Output
// For each test case, output a single integer — the year in which all n signs will occur.

// Example
// inputCopy
// 4
// 6
// 3 2 4 5 9 18
// 5
// 1 2 3 4 5
// 5
// 1 1 1 1 1
// 6
// 50 30 711 200 503 1006
// outputCopy
// 36
// 5
// 5
// 2012

// Note
// In the first set of input data of the example:
// The tribe will wait for the first sign in the 3-rd year;
// the tribe will wait for the second sign in the 4-th year (since year 2 have already passed);
// the tribe will wait for the third sign in the 8-th year (since the second sign has already occurred in the 4-th year);
// the tribe will wait for the fourth sign in the 10-th year (since year 5 have already passed);
// the tribe will wait for the fifth sign in the 18-th year (since year 9 have already passed);
// the tribe will wait for the sixth sign in the 36-th year (since the fifth sign has already occurred in the 18-th year).

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
        //Num of signs
        int n;
        cin >> n;

        //Periodicities of the sign
        vector<int> periodicities(n);
        for(int i=0; i<n; i++)
        {
            cin >> periodicities[i];
        }

        int cumSum = 0;
        for(int i=0; i<n; i++)
        {
            if(cumSum < periodicities[i])
            {
                cumSum += periodicities[i]-cumSum;
            }
            else if(cumSum > periodicities[i])
            {
                cumSum += periodicities[i] - cumSum%periodicities[i];
            }
            else
            {
                cumSum += periodicities[i];
            }
        }

        int answer = cumSum;
        cout << answer << endl;
    }

    return 0;
}
