// B. National Project

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Your company was appointed to lay new asphalt on the highway of length n. You know that every day you can either repair one unit of the highway (lay new asphalt over one unit of the highway) or skip repairing. Skipping the repair is necessary because of the climate. The climate in your region is periodical: there are g days when the weather is good and if you lay new asphalt these days it becomes high-quality pavement; after that, the weather during the next b days is bad, and if you lay new asphalt these days it becomes low-quality pavement; again g good days, b bad days and so on. You can be sure that you start repairing at the start of a good season, in other words, days 1,2,…,g are good. You don't really care about the quality of the highway, you just want to make sure that at least half of the highway will have high-quality pavement. For example, if the n=5 then at least 3 units of the highway should have high quality; if n=4 then at least 2 units should have high quality. What is the minimum number of days is needed to finish the repair of the whole highway?

// Input
// The first line contains a single integer T (1≤T≤104) — the number of test cases. Next T lines contain test cases — one per line. Each line contains three integers n, g and b (1≤n,g,b≤109) — the length of the highway and the number of good and bad days respectively.

// Output
// Print T integers — one per test case. For each test case, print the minimum number of days required to repair the whole highway if at least half of it should have high quality.

// Example
// inputCopy
// 3
// 5 1 1
// 8 10 10
// 1000000 1 1000000

// outputCopy
// 5
// 8
// 499999500000

// Note
// In the first test case, you can just lay new asphalt each day, since days 1,3,5 are good.
// In the second test case, you can also lay new asphalt each day, since days 1-8 are good.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long long int n, g ,b;
//     cin >> n >> g >> b;

//     if(g>=b || g==n)
//     {
//         cout << n << endl;
//         return;
//     }
//     else
//     {
//         long long int x = ceil((float)n/2) * g;
//         long long int y = ceil((float)n/2) * b - x;

//         cout << y << endl;
//     }

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

// ALternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, g, b;
    cin >> n >> g >> b;

    long long required_good_days = (n + 1) / 2;
    long long full_cycles = required_good_days / g;
    long long remaining_good_days = required_good_days % g;
    
    long long total_days;
    if (remaining_good_days > 0)
    {
        total_days = full_cycles * (g + b) + remaining_good_days;
    }
    else
    {
        total_days = full_cycles * (g + b) - b;
    }

    //Ensuring total days are at least n
    total_days = max(total_days, n);

    cout << total_days << endl;
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
