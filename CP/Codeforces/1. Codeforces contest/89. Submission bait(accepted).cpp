// A. Submission Bait

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Alice and Bob are playing a game in an array a of size n. They take turns to do operations, with Alice starting first. The player who can not operate will lose. At first, a variable mx is set to 0. In one operation, a player can do: Choose an index i (1≤i≤n) such that ai≥mx and set mx to ai. Then, set ai to 0. Determine whether Alice has a winning strategy.

// Input
// The first line contains an integer t (1≤t≤103) — the number of test cases. For each test case: The first line contains an integer n (2≤n≤50) — the size of the array. The second line contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array.

// Output
// For each test case, if Alice has a winning strategy, output "YES". Otherwise, output "NO". You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// inputCopy
// 5
// 2
// 2 1
// 2
// 1 1
// 3
// 3 3 3
// 4
// 3 3 4 4
// 4
// 1 2 2 2
// outputCopy
// YES
// NO
// YES
// NO
// YES

// Note
// In the first test case, Alice can choose i=1 since a1=2≥mx=0.
// After Alice's operation, a=[0,1] and mx=2. Bob can not do any operation. Alice wins.
// In the second test case, Alice doesn't have a winning strategy.
// For example, if Alice chooses i=1, after Alice's operation: a=[0,1] and mx=1. Then, Bob can choose i=2 since a2=1≥mx=1. After Bob's operation: a=[0,0] and mx=1. Alice can not do any operation. Bob wins.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     int maxx = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         maxx = max(maxx, a[i]);
//     }

//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(a[i]==maxx) count++;
//     }

//     if(count%2!=0) cout << "YES" << endl;
//     else cout << "NO" << endl;

//     return;
// }

// int32_t main()
// {   
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(100);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    bool yes = false;
    for(int i=0; i<100; i++)
    {
        if(freq[i]%2!=0)
        {
            yes = true;
            break;
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;

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
