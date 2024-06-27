// B. AGAGA XOOORRR

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Baby Ehab is known for his love for a certain operation. He has an array a of length n, and he decided to keep doing the following operation on it: he picks 2 adjacent elements; he then removes them and places a single integer in their place: their bitwise XOR. Note that the length of the array decreases by one. Now he asks you if he can make all elements of the array equal. Since babies like to make your life harder, he requires that you leave at least 2 elements remaining.

// Input
// The first line contains an integer t (1≤t≤15) — the number of test cases you need to solve. The first line of each test case contains an integers n (2≤n≤2000) — the number of elements in the array a. The second line contains n space-separated integers a1, a2, …, an (0≤ai<230) — the elements of the array a.

// Output
// If Baby Ehab can make all elements equal while leaving at least 2 elements standing, print "YES". Otherwise, print "NO".

// Example
// inputCopy
// 2
// 3
// 0 2 2
// 4
// 2 3 1 10

// outputCopy
// YES
// NO

// Note
// In the first sample, he can remove the first 2 elements, 0 and 2, and replace them by 0⊕2=2. The array will be [2,2], so all the elements are equal.
// In the second sample, there's no way to make all the elements equal.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    //Inputs
    int n;
    cin >> n;

    vector<long long int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    //MAIN logic
    //Calc the xor of all elements
    long long int currXOR = 0;
    for(int i=0; i<n; i++)
    {
        currXOR ^= givenArray[i];
    }

    //The last two elements need to be equal
    //The xor of equal elements is 0
    //So if the xor of all elements is 0
    //Then it is possible to make the array elements equal
    if(currXOR==0) cout << "YES" << endl;
    else cout << "NO" << endl;

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
