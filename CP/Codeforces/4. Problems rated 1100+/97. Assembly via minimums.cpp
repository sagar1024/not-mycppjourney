// C. Assembly via Minimums

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Sasha has an array a of n integers. He got bored and for all i, j (i<j), he wrote down the minimum value of ai and aj. He obtained a new array b of size n⋅(n−1)2. For example, if a= [2,3,5,1], he would write [min(2,3),min(2,5),min(2,1),min(3,5),min(3,1),min(5,1)] = [2,2,1,3,1,1]. Then, he randomly shuffled all the elements of the array b. Unfortunately, he forgot the array a, and your task is to restore any possible array a from which the array b could have been obtained. The elements of array a should be in the range [−109,109].

// Input
// The first line contains a single integer t (1≤t≤200) — the number of test cases. The first line of each test case contains a single integer n (2≤n≤103) — the length of array a. The second line of each test case contains n⋅(n−1)2 integers b1,b2,…,bn⋅(n−1)2 (−109≤bi≤109) — the elements of array b. It is guaranteed that the sum of n over all tests does not exceed 103 and for each array b in the test, there exists an original array.

// Output
// For each test case, output any possible array a of length n.

// Example
// inputCopy
// 5
// 3
// 1 3 1
// 2
// 10
// 4
// 7 5 3 5 3 3
// 5
// 2 2 2 2 2 2 2 2 2 2
// 5
// 3 0 0 -2 0 -2 0 0 -2 -2

// outputCopy
// 1 3 3
// 10 10
// 7 5 3 12
// 2 2 2 2 2
// 0 -2 0 3 5

// Note

// In the first sample, Sasha chose the array [1,3,3], then the array b will look like [min(a1,a2)=1,min(a1,a3)=1,min(a2,a3)=3], after shuffling its elements, the array can look like [1,3,1].
// In the second sample, there is only one pair, so the array [10,10] is suitable. Another suitable array could be [15,10].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long int> b(n*(n-1)/2);
    for(int i=0; i<n*(n-1)/2; i++)
    {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    set<long long int> uniqueElements;
    for(int i=0; i<n*(n-1)/2; i++)
    {
        uniqueElements.insert(b[i]);
    }

    int lastElement = 0;
    for (auto it = uniqueElements.begin(); it != uniqueElements.end(); ++it)
    {
        lastElement = *it;
        cout << *it << " ";
    }

    cout << lastElement << endl;
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
