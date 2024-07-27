// D. Three Activities

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Winter holidays are coming up. They are going to last for n days.

// During the holidays, Monocarp wants to try all of these activities exactly once with his friends:
// go skiing;
// watch a movie in a cinema;
// play board games.

// Monocarp knows that, on the i-th day, exactly ai friends will join him for skiing, bi friends will join him for a movie and ci friends will join him for board games. Monocarp also knows that he can't try more than one activity in a single day. Thus, he asks you to help him choose three distinct days x,y,z in such a way that the total number of friends to join him for the activities (ax+by+cz) is maximized.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases. The first line of each testcase contains a single integer n (3≤n≤105) — the duration of the winter holidays in days. The second line contains n integers a1,a2,…,an (1≤ai≤108) — the number of friends that will join Monocarp for skiing on the i-th day. The third line contains n integers b1,b2,…,bn (1≤bi≤108) — the number of friends that will join Monocarp for a movie on the i-th day. The fourth line contains n integers c1,c2,…,cn (1≤ci≤108) — the number of friends that will join Monocarp for board games on the i-th day. The sum of n over all testcases doesn't exceed 105.

// Output
// For each testcase, print a single integer — the maximum total number of friends that can join Monocarp for the activities on three distinct days.

// Example
// inputCopy
// 4
// 3
// 1 10 1
// 10 1 1
// 1 1 10
// 4
// 30 20 10 1
// 30 5 15 20
// 30 25 10 10
// 10
// 5 19 12 3 18 18 6 17 10 13
// 15 17 19 11 16 3 11 17 17 17
// 1 17 18 10 15 8 17 3 13 12
// 10
// 17 5 4 18 12 4 11 2 16 16
// 8 4 14 19 3 12 6 7 5 16
// 3 4 8 11 10 8 10 2 20 3
// outputCopy
// 30
// 75
// 55
// 56

// Note
// In the first testcase, Monocarp can choose day 2 for skiing, day 1 for a movie and day 3 for board games. This way, a2=10 friends will join him for skiing, b1=10 friends will join him for a movie and c3=10 friends will join him for board games. The total number of friends is 30.
// In the second testcase, Monocarp can choose day 1 for skiing, day 4 for a movie and day 2 for board games. 30+20+25=75 friends in total. Note that Monocarp can't choose day 1 for all activities, because he can't try more than one activity in a single day.
// In the third testcase, Monocarp can choose day 2 for skiing, day 3 for a movie and day 7 for board games. 19+19+17=55 friends in total.
// In the fourth testcase, Monocarp can choose day 1 for skiing, day 4 for a movie and day 9 for board games. 17+19+20=56 friends in total.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     //Brute force
//     //Search for the max num of friends gathering(i.e maxx1)
//     //Then search for the next max number of friends(i.e maxx2) by traversing the whole array and excluding the idx1
//     //Then search for the third max num of friends i.e maxx3 excluding idx1 and idx2 columns
//     int maxx1=0, maxx2=0, maxx3=0;
//     int idx1=0, idx2=0, idx3=0;
//     vector<vector<long long int>> friends(3, vector<long long int>(n,0));
//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cin >> friends[i][j];
//             if(friends[i][j]>maxx1)
//             {
//                 maxx1 = friends[i][j];
//                 idx1 = j;
//             }
//         }
//     }

//     return;
// }

// int main()
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
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<vector<long long int>> friends(3, vector<long long int>(n));
//     vector<vector<long long int>> dummy(3,vector<long long int>(n));
//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cin >> friends[i][j];
//         }
//     }

//     long long int ans = 0;
//     dummy = friends;

//     sort(dummy[0].begin(), dummy[0].end(), greater<int>());
//     ans += dummy[0][0];

//     int index1 = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(dummy[0][0]==friends[0][i])
//         {
//             index1 = i;
//         }
//     }

//     sort(dummy[1].begin(), dummy[1].end(), greater<int>());

//     int index2 = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(dummy[1][i] == friends[1][index1])
//         {
//             continue;
//         }
//         else
//         {
//             index2 = i;
//             ans += dummy[1][i];
//             break;
//         }
//     }

//     sort(dummy[2].begin(), dummy[2].end(), greater<int>());
//     for(int i=0; i<n; i++)
//     {
//         if(dummy[2][i]==friends[2][index1] || dummy[2][i]==friends[2][index2])
//         {
//             continue;
//         }
//         else
//         {
//             ans += dummy[2][i];
//             break;
//         }
//     }

//     cout << ans << endl;
//     return;
// }

// int main()
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
// #include <algorithm>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long> a(n), b(n), c(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> b[i];
//     }
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> c[i];
//     }

//     long long max_sum = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             if (i==j) continue; // Ensure different days
//             for (int k = 0; k < n; ++k)
//             {
//                 if (i==k || j==k) continue; // Ensure different days
//                 max_sum = max(max_sum, a[i] + b[j] + c[k]);
//             }
//         }
//     }

//     cout << max_sum << endl;
//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

//Helper function to get the top K elements(i.e top 3 elements in this case) and their indices
vector<pair<long long, int>> get_top_k(const vector<long long> &arr, int k)
{
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < arr.size(); ++i)
    {
        pq.push({arr[i], i});
    }
    vector<pair<long long, int>> result;
    for (int i = 0; i < k && !pq.empty(); ++i)
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

void solve()
{
    int n;
    cin >> n;

    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }

    //Getting the top 3 days for each activity
    vector<pair<long long, int>> top_a = get_top_k(a, 3);
    vector<pair<long long, int>> top_b = get_top_k(b, 3);
    vector<pair<long long, int>> top_c = get_top_k(c, 3);

    long long max_sum = 0;

    //Trying all combinations of top 3 days for each activity
    for (auto [a_val, a_idx] : top_a)
    {
        for (auto [b_val, b_idx] : top_b)
        {
            if (b_idx == a_idx) continue;
            for (auto [c_val, c_idx] : top_c)
            {
                if (c_idx == a_idx || c_idx == b_idx) continue;
                max_sum = max(max_sum, a_val + b_val + c_val);
            }
        }
    }

    cout << max_sum << endl;
    
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
