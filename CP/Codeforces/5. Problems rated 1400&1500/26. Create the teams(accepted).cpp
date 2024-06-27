// C. Create The Teams

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n programmers that you want to split into several non-empty teams. The skill of the i-th programmer is ai. You want to assemble the maximum number of teams from them. There is a restriction for each team: the number of programmers in the team multiplied by the minimum skill among all programmers in the team must be at least x. Each programmer should belong to at most one team. Some programmers may be left without a team. Calculate the maximum number of teams that you can assemble.

// Input
// The first line contains the integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains two integers n and x (1≤n≤105;1≤x≤109) — the number of programmers and the restriction of team skill respectively. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the skill of the i-th programmer. The sum of n over all inputs does not exceed 105.

// Output
// For each test case print one integer — the maximum number of teams that you can assemble.

// Example
// inputCopy
// 3
// 5 10
// 7 11 2 9 5
// 4 8
// 2 4 2 3
// 4 11
// 1 3 3 7
// outputCopy
// 2
// 1
// 0

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
//     long long int x;
//     cin >> n >> x;

//     vector<long long int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     sort(givenArray.begin(), givenArray.end(), greater<int>());
//     vector<vector<long long int>> teamsFormed;

//     int teamMemberCount = 1;
//     vector<long long int> currentTeamInMaking;
//     for(int i=0; i<n; i++)
//     {
//         if((givenArray[i]*teamMemberCount)>x)
//         {
//             teamsFormed.push_back(currentTeamInMaking);
//             teamMemberCount = 1;
//             //CLearing the vector
//             currentTeamInMaking.clear();
//         }
//         else
//         {
//             teamMemberCount++;
//         }
//     }

//     int maxTeams = teamsFormed.size();
//     cout << maxTeams << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

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
    //Inputs
    int n;
    long long int x;
    cin >> n >> x;

    vector<long long int> givenArray(n);
    for (int i = 0; i < n; i++)
    {
        cin >> givenArray[i];
    }

    //MAIN logic
    //Sorting the array in descending order to make things easy
    sort(givenArray.begin(), givenArray.end(), greater<int>());

    int maxTeams = 0;

    //Team should have atleast one member
    int currentTeamSize = 1;

    for (int i = 0; i < n; i++)
    {
        //Here the givenArray[i] will always be the smallest element in the current team
        if ((givenArray[i] * (currentTeamSize)) >= x)
        {
            //When the condition is satisfied(i.e restriction is cleared)
            //Increase the num of teams formed
            maxTeams++;
            currentTeamSize = 1;
        }
        else
        {
            //Else increase the number of current team size
            //To allow more people to come and join, in hopes of clearing the restriction
            currentTeamSize++;
        }
    }

    //Output
    cout << maxTeams << endl;

    return;
}

int32_t main()
{
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
