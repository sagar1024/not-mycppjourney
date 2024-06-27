// B. Kefa and Company

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kefa wants to celebrate his first big salary by going to restaurant. However, he needs company. Kefa has n friends, each friend will agree to go to the restaurant if Kefa asks. Each friend is characterized by the amount of money he has and the friendship factor in respect to Kefa. The parrot doesn't want any friend to feel poor compared to somebody else in the company (Kefa doesn't count). A friend feels poor if in the company there is someone who has at least d units of money more than he does. Also, Kefa wants the total friendship factor of the members of the company to be maximum. Help him invite an optimal company!

// Input
// The first line of the input contains two space-separated integers, n and d (1 ≤ n ≤ 105, 1<=d<=109) — the number of Kefa's friends and the minimum difference between the amount of money in order to feel poor, respectively. Next n lines contain the descriptions of Kefa's friends, the (i + 1)-th line contains the description of the i-th friend of type mi, si (0 ≤ mi, si ≤ 109) — the amount of money and the friendship factor, respectively.

// Output
// Print the maximum total friendship factir that can be reached.

// Examples
// inputCopy
// 4 5
// 75 5
// 0 100
// 150 20
// 75 1
// outputCopy
// 100

// inputCopy
// 5 100
// 0 7
// 11 32
// 99 10
// 46 8
// 87 54
// outputCopy
// 111

// Note
// In the first sample test the most profitable strategy is to form a company from only the second friend. At all other variants the total degree of friendship will be worse.
// In the second sample test we can take all the friends.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define ll long long int
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// int32_t main()
// {
//     //Fast input output
//     fastio;

//     //Inputs
//     //Kefas friends
//     int n;
//     cin >> n;

//     //Minimum difference between the amount of money in order to feel poor
//     ll d;
//     cin >> d;

//     //The amount of money and the friendship factor
//     vector<pair<ll, ll>> aboutFriend(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> aboutFriend[i].first;
//         cin >> aboutFriend[i].second;
//     }

//     sort(aboutFriend.begin(), aboutFriend.end());

//     int minDiff = 0;
//     int friendShip = 0;
//     int totalFriendship = 0;
//     for(int i=0; i<n; i++)
//     {
//         minDiff = 0;
//         int j = 0;

//         while(minDiff>=d)
//         {
//             minDiff += aboutFriend[j].first;
//             friendShip += aboutFriend[j].second;
//             j++;
//         }
//         totalFriendship = max(friendShip, totalFriendship);
//     }

//     cout << totalFriendship << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Fast input output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //Inputs
    int n;
    cin >> n;

    long long d;
    cin >> d;

    vector<pair<long long, long long>> friends(n);
    for (int i=0; i<n; i++)
    {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    long long totalFriendship = 0;
    long long currMoney = 0, currFriendship = 0;
    int j = 0;
    for (int i=0; i<n; i++)
    {
        currMoney += friends[i].first;
        currFriendship += friends[i].second;
        while (j<n && friends[i].first - friends[j].first >= d)
        {
            currMoney -= friends[j].first;
            currFriendship -= friends[j].second;
            j++;
        }

        totalFriendship = max(totalFriendship, currFriendship);
    }

    cout << totalFriendship << endl;

    return 0;
}
