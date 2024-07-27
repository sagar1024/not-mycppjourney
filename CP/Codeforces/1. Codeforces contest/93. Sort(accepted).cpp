// C. Sort

// time limit per test5 seconds
// memory limit per test256 megabytes

// You are given two strings a and b of length n. Then, you are (forced against your will) to answer q queries. For each query, you are given a range bounded by l and r. In one operation, you can choose an integer i (l≤i≤r) and set ai=x where x is any character you desire. Output the minimum number of operations you must perform such that sorted(a[l..r])=sorted(b[l..r]). The operations you perform on one query does not affect other queries. For an arbitrary string c, sorted(c[l..r]) denotes the substring consisting of characters cl,cl+1,...,cr sorted in lexicographical order.

// Input
// The first line contains t (1≤t≤1000) – the number of test cases. The first line of each test case contains two integers n and q (1≤n,q≤2⋅105) – the length of both strings and the number of queries. The following line contains a of length n. It is guaranteed a only contains lowercase latin letters. The following line contains b of length n. It is guaranteed b only contains lowercase latin letters. The following q lines contain two integers l and r (1≤l≤r≤n) – the range of the query. It is guaranteed the sum of n and q over all test cases does not exceed 2⋅105.

// Output
// For each query, output an integer, the minimum number of operations you need to perform in a new line.

// Example
// InputCopy
// 3
// 5 3
// abcde
// edcba
// 1 5
// 1 4
// 3 3
// 4 2
// zzde
// azbe
// 1 3
// 1 4
// 6 3
// uwuwuw
// wuwuwu
// 2 4
// 1 3
// 1 6
// OutputCopy
// 0
// 1
// 0
// 2
// 2
// 1
// 1
// 0

// Note
// For the first query, sorted(a[1..5])= abcde and sorted(b[1..5])= abcde, so no operations are necessary.
// For the second query, you need to set a1= e. Then, sorted(a[1..4])=sorted(b[1..4])= bcde.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int ALPHABET_SIZE = 26;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        //Initializing prefix sum arrays
        vector<vector<int>> prefixA(n + 1, vector<int>(ALPHABET_SIZE, 0));
        vector<vector<int>> prefixB(n + 1, vector<int>(ALPHABET_SIZE, 0));
        
        //Filling prefix sums for 'a'
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                prefixA[i][j] = prefixA[i - 1][j];
            }
            prefixA[i][a[i - 1] - 'a']++;
        }

        //Filling prefix sums for 'b'
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                prefixB[i][j] = prefixB[i - 1][j];
            }

            prefixB[i][b[i - 1] - 'a']++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            
            //Calculating frequencies in range [l, r]
            vector<int> freqA(ALPHABET_SIZE, 0);
            vector<int> freqB(ALPHABET_SIZE, 0);
            
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                freqA[j] = prefixA[r][j] - prefixA[l - 1][j];
                freqB[j] = prefixB[r][j] - prefixB[l - 1][j];
            }
            
            //Calculating number of changes needed
            int changes = 0;
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                if (freqA[j] > freqB[j]) {
                    changes += freqA[j] - freqB[j];
                }
            }
            
            cout << changes << endl;
        }
    }
    
    return 0;
}
