// C. Removing Smallest Multiples

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a set S, which contains the first n positive integers: 1,2,…,n. You can perform the following operation on S any number of times (possibly zero): Choose a positive integer k where 1≤k≤n, such that there exists a multiple of k in S. Then, delete the smallest multiple of k from S. This operation requires a cost of k. You are given a set T, which is a subset of S. Find the minimum possible total cost of operations such that S would be transformed into T. We can show that such a transformation is always possible.

// Input
// The first line of the input contains a single integer t (1≤t≤10000) — the number of test cases. The description of the test cases follows. The first line contains a single positive integer n (1≤n≤106). The second line of each test case contains a binary string of length n, describing the set T. The i-th character of the string is '1' if and only if i is an element of T, and '0' otherwise. It is guaranteed that the sum of n over all test cases does not exceed 106.

// Output
// For each test case, output one non-negative integer — the minimum possible total cost of operations such that S would be transformed into T.

// Example
// inputCopy
// 6
// 6
// 111111
// 7
// 1101001
// 4
// 0000
// 4
// 0010
// 8
// 10010101
// 15
// 110011100101100

// outputCopy
// 0
// 11
// 4
// 4
// 17
// 60

// Note
// In the first test case, we shall not perform any operations as S is already equal to T, which is the set {1,2,3,4,5,6}.
// In the second test case, initially, S={1,2,3,4,5,6,7}, and T={1,2,4,7}. We shall perform the following operations:
// Choose k=3, then delete 3 from S.
// Choose k=3, then delete 6 from S.
// Choose k=5, then delete 5 from S.
// The total cost is 3+3+5=11. It can be shown that this is the smallest cost possible.
// In the third test case, initially, S={1,2,3,4} and T={} (empty set). We shall perform 4 operations of k=1 to delete 1, 2, 3, and 4.
// In the fourth test case, initially, S={1,2,3,4} and T={3}. We shall perform two operations with k=1 to delete 1 and 2, then perform one operation with k=2 to delete 4.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long int n;
//     cin >> n;

//     set<int> originalElements;
//     for(int i=1; i<=n; i++)
//     {
//         originalElements.insert(i);
//     }

//     string t;
//     cin >> t;

//     set<int> currElements;
//     for(int i=0; i<n; i++)
//     {
//         if(t[i]=='1')
//         {
//             currElements.insert(i+1);
//         }
//     }

//     vector<int> removedElements;
//     set_difference(originalElements.begin(), originalElements.end(), currElements.begin(), currElements.end(), back_inserter(removedElements));

//     sort(removedElements.begin(), removedElements.end());
//     int len = removedElements.size();
//     long long int ans = 0;
//     while(!removedElements.empty())
//     {
//         long long int a = removedElements[0];
//         for(int i=0; i<len; i++)
//         {
//             if(removedElements[i]%a==0) ans += a;
//             removedElements.erase(removedElements.begin()+i);
//             i--;
//             len--;
//         }
//     }

//     cout << ans << endl;

//     return;
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long int n;
    cin >> n;

    string str;
    cin >> str;

    vector<bool> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        if(str[i-1]=='1')
        {
            a[i] = true;
        }
    }

    vector<int> cost(n+1,0);
    vector<bool> visited(n+1,false);

    //Calculating the cost for each element in set S
    //Starting from the bigger elements
    long long int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int multiple = i; multiple <= n; multiple += i)
        {
            if(a[multiple]) break;
            if(visited[multiple]) continue;

            cost[multiple] = i;
            visited[multiple] = true;
        }
    }

    //Total cost
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            ans += cost[i];
        }
    }

    cout << ans << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
