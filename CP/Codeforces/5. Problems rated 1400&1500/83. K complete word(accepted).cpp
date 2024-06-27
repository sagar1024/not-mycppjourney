// C. K-Complete Word

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// Word s of length n is called k-complete if

// s is a palindrome, i.e. si=sn+1−i for all 1≤i≤n;
// s has a period of k, i.e. si=sk+i for all 1≤i≤n−k.

// For example, "abaaba" is a 3-complete word, while "abccba" is not. Bob is given a word s of length n consisting of only lowercase Latin letters and an integer k, such that n is divisible by k. He wants to convert s to any k-complete word. To do this Bob can choose some i (1≤i≤n) and replace the letter at position i with some other lowercase Latin letter. So now Bob wants to know the minimum number of letters he has to replace to convert s to any k-complete word. Note that Bob can do zero changes if the word s is already k-complete. You are required to answer t test cases independently.

// Input
// The first line contains a single integer t (1≤t≤105) — the number of test cases. The first line of each test case contains two integers n and k (1≤k<n≤2⋅105, n is divisible by k). The second line of each test case contains a word s of length n. It is guaranteed that word s only contains lowercase Latin letters. And it is guaranteed that the sum of n over all test cases will not exceed 2⋅105.

// Output
// For each test case, output one integer, representing the minimum number of characters he has to replace to convert s to any k-complete word.

// Example
// inputCopy
// 4
// 6 2
// abaaba
// 6 3
// abaaba
// 36 9
// hippopotomonstrosesquippedaliophobia
// 21 7
// wudixiaoxingxingheclp
// outputCopy
// 2
// 0
// 23
// 16

// Note
// In the first test case, one optimal solution is aaaaaa.
// In the second test case, the given word itself is k-complete.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to calculate the difference needed to make segments palindromic
int differ(const vector<vector<int>> &count, int u, int v)
{
    int total = 0, mx = 0;
    for (int j = 0; j < 26; ++j)
    {
        total += count[u][j] + count[v][j];
        mx = max(mx, count[u][j] + count[v][j]);
    }
    return total - mx;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    vector<vector<int>> count(k, vector<int>(26, 0));

    for(int i=0; i<n; i++) count[i%k][s[i]-'a']++;
    for(int i=0; i<k; i++) ans += differ(count, i, k-i-1);

    cout << ans/2 << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
