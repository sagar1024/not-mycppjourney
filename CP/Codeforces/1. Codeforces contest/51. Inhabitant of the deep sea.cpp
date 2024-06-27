// C. Inhabitant of the Deep Sea

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// n ships set out to explore the depths of the ocean. The ships are numbered from 1 to n and follow each other in ascending order; the i-th ship has a durability of ai. The Kraken attacked the ships k times in a specific order. First, it attacks the first of the ships, then the last, then the first again, and so on. Each attack by the Kraken reduces the durability of the ship by 1. When the durability of the ship drops to 0, it sinks and is no longer subjected to attacks (thus the ship ceases to be the first or last, and the Kraken only attacks the ships that have not yet sunk). If all the ships have sunk, the Kraken has nothing to attack and it swims away.

// For example, if n=4, k=5, and a=[1,2,4,3], the following will happen:

// The Kraken attacks the first ship, its durability becomes zero and now a=[2,4,3];
// The Kraken attacks the last ship, now a=[2,4,2];
// The Kraken attacks the first ship, now a=[1,4,2];
// The Kraken attacks the last ship, now a=[1,4,1];
// The Kraken attacks the first ship, its durability becomes zero and now a=[4,1].
// How many ships were sunk after the Kraken's attack?

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two integers n and k (1≤n≤2⋅105, 1≤k≤1015) — the number of ships and how many times the Kraken will attack the ships. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the durability of the ships. It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

// Output
// For each test case, output the number of ships sunk by the Kraken on a separate line.

// Example
// inputCopy
// 6
// 4 5
// 1 2 4 3
// 4 6
// 1 2 4 3
// 5 20
// 2 7 1 8 2
// 2 2
// 3 2
// 2 15
// 1 5
// 2 7
// 5 2
// outputCopy
// 2
// 3
// 5
// 0
// 2
// 2

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     long long int k;
//     cin >> k;

//     vector<long long int> durability(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> durability[i];
//     }

//     int shipsDrowned = 0;
//     int x = 0;
//     while(k>0 && !durability.empty())
//     {
//         if(x%2==0)
//         {
//             durability.front()--;
//             k--;

//             if(durability.front() == 0)
//             {
//                 durability.erase(durability.begin());
//                 shipsDrowned++;
//             }
//             x++;
//         }
//         else
//         {
//             durability.back()--;
//             k--;

//             if(durability.back() == 0)
//             {
//                 durability.pop_back();
//                 shipsDrowned++;
//             }
//             x++;
//         }
//     }

//     cout << shipsDrowned << endl;
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

// Alternate soln -

// #include <iostream>
// #include <vector>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     long long int k;
//     cin >> k;

//     vector<long long int> durability(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> durability[i];
//     }

//     int shipsDrowned = 0;
//     int i = 0, j = n - 1; // Pointers to the first and last elements
//     while (k > 0 && i <= j)
//     {
//         if (durability[i] <= durability[j])
//         {
//             int need = min(k, durability[i]);
//             durability[i] -= need;
//             k -= need;
//             if (durability[i] == 0)
//             {
//                 shipsDrowned++;
//                 i++; // Move pointer to the next element
//             }
//         }
//         else
//         {
//             int need = min(k, durability[j]);
//             durability[j] -= need;
//             k -= need;
//             if (durability[j] == 0)
//             {
//                 shipsDrowned++;
//                 j--; // Move pointer to the previous element
//             }
//         }
//     }

//     cout << shipsDrowned << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }
