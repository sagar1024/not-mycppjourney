// C. Ball in Berland

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// At the school where Vasya is studying, preparations are underway for the graduation ceremony. One of the planned performances is a ball, which will be attended by pairs of boys and girls. Each class must present two couples to the ball. In Vasya's class, a boys and b girls wish to participate. But not all boys and not all girls are ready to dance in pairs. Formally, you know k possible one-boy-one-girl pairs. You need to choose two of these pairs so that no person is in more than one pair.

// For example, if a=3, b=4, k=4 and the couples (1,2), (1,3), (2,2), (3,4) are ready to dance together (in each pair, the boy's number comes first, then the girl's number), then the following combinations of two pairs are possible (not all possible options are listed below):
// (1,3) and (2,2);
// (3,4) and (1,3);

// But the following combinations are not possible:
// (1,3) and (1,2) — the first boy enters two pairs;
// (1,2) and (2,2) — the second girl enters two pairs;

// Find the number of ways to select two pairs that match the condition above. Two ways are considered different if they consist of different pairs.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow. The first line of each test case contains three integers a, b and k (1≤a,b,k≤2⋅105) — the number of boys and girls in the class and the number of couples ready to dance together. The second line of each test case contains k integers a1,a2,…ak. (1≤ai≤a), where ai is the number of the boy in the pair with the number i. The third line of each test case contains k integers b1,b2,…bk. (1≤bi≤b), where bi is the number of the girl in the pair with the number i. It is guaranteed that the sums of a, b, and k over all test cases do not exceed 2⋅105. It is guaranteed that each pair is specified at most once in one test case.

// Output
// For each test case, on a separate line print one integer — the number of ways to choose two pairs that match the condition above.

// Example
// inputCopy
// 3
// 3 4 4
// 1 1 2 3
// 2 3 2 4
// 1 1 1
// 1
// 1
// 2 2 4
// 1 1 2 2
// 1 2 1 2
// outputCopy
// 4
// 0
// 2

// Note
// In the first test case, the following combinations of pairs fit:
// (1,2) and (3,4);
// (1,3) and (2,2);
// (1,3) and (3,4);
// (2,2) and (3,4).

// There is only one pair in the second test case.

// In the third test case, the following combinations of pairs fit:
// (1,1) and (2,2);
// (1,2) and (2,1).

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    //Num of boys, girls, couples ready to dance
    int a, b, k;
    cin >> a >> b >> k;

    //Serial numbers for willing boys(first) and girls(second)
    vector<pair<int,int>> couples(k);
    for(int i=0; i<k; i++)
    {
        cin >> couples[i].first;
    }
    for(int i=0; i<k; i++)
    {
        cin >> couples[i].second;
    }

    int maxWays = 0;
    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(couples[i].first!=couples[j].first && couples[i].second!=couples[j].second && i!=j)
            {
                maxWays++;
            }
        }
    }

    cout << maxWays << endl;

    return;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
