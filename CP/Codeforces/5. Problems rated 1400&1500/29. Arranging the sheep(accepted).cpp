// E. Arranging The Sheep

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are playing the game "Arranging The Sheep". The goal of this game is to make the sheep line up. The level in the game is described by a string of length n, consisting of the characters '.' (empty space) and '*' (sheep). In one move, you can move any sheep one square to the left or one square to the right, if the corresponding square exists and is empty. The game ends as soon as the sheep are lined up, that is, there should be no empty cells between any sheep.

// For example, if n=6 and the level is described by the string "**.*..", then the following game scenario is possible:
// the sheep at the 4 position moves to the right, the state of the level: "**..*.";
// the sheep at the 2 position moves to the right, the state of the level: "*.*.*.";
// the sheep at the 1 position moves to the right, the state of the level: ".**.*.";
// the sheep at the 3 position moves to the right, the state of the level: ".*.**.";
// the sheep at the 2 position moves to the right, the state of the level: "..***.";
// the sheep are lined up and the game ends.

// For a given level, determine the minimum number of moves you need to make to complete the level.

// Input
// The first line contains one integer t (1≤t≤104). Then t test cases follow. The first line of each test case contains one integer n (1≤n≤106). The second line of each test case contains a string of length n, consisting of the characters '.' (empty space) and '*' (sheep) — the description of the level. It is guaranteed that the sum of n over all test cases does not exceed 106.

// Output
// For each test case output the minimum number of moves you need to make to complete the level.

// Example
// inputCopy
// 5
// 6
// **.*..
// 5
// *****
// 3
// .*.
// 3
// ...
// 10
// *.*...*.**

// outputCopy
// 1
// 0
// 0
// 0
// 9

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

//     string s;
//     cin >> s;

//     int leftmostIDX = 0;
//     int rightmostIDX = 0;
//     bool allStars = true;
//     bool noStars = true;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]=='*')
//         {
//             if(!leftmostIDX)
//             {
//                 leftmostIDX = i;
//             }
//             else
//             {
//                 rightmostIDX = i;
//             }
//         }

//         if(s[i]=='*')
//         {
//             noStars = false;
//         }
//         if(s[i]=='.')
//         {
//             allStars = false;
//         }
//     }

//     if(allStars || noStars)
//     {
//         cout << "0" << endl;
//         return;
//     }

//     vector<int> left;
//     int lastIndexOfStar = 0;
//     for(int i=leftmostIDX+1; i<=rightmostIDX; i++)
//     {
//         if(s[i]=='*')
//         {
//             left.push_back(abs(lastIndexOfStar-i));
//             lastIndexOfStar = i;
//         }
//     }

//     int sum1 = 0;
//     for(int i=0; i<left.size(); i++)
//     {
//         sum1 += left[i];
//     }

//     vector<int> right;
//     lastIndexOfStar = 0;
//     for(int i=rightmostIDX-1; i>=leftmostIDX; i--)
//     {
//         if(s[i]=='*')
//         {
//             right.push_back(abs(lastIndexOfStar-i));
//             lastIndexOfStar = i;
//         }
//     }

//     int sum2 = 0;
//     for(int i=0; i<right.size(); i++)
//     {
//         sum2 += right[i];
//     }

//     int answer = min(sum1,sum2);
//     cout << answer << endl;

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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //Inputs
    int n;
    cin >> n;

    string sheeps;
    cin >> sheeps;

    //Counting the number of sheep in the level
    int sheepCount = 0;
    for (auto cell : sheeps)
    {
        sheepCount += (cell == '*' ? 1 : 0);
    }

    //Finding the position of the middle sheep
    int middleSheepPos = -1;
    int currentSheepCount = -1;
    for (int i = 0; i < n; i++)
    {
        if (sheeps[i] == '*')
        {
            currentSheepCount++;
            if (currentSheepCount == sheepCount / 2)
            {
                middleSheepPos = i;
            }
        }
    }

    //Calculating the total number of moves required
    long long totalMoves = 0;
    int currentPosition = middleSheepPos - sheepCount / 2;
    for (int i = 0; i < n; i++)
    {
        if (sheeps[i] == '*')
        {
            totalMoves += abs(currentPosition - i);
            currentPosition++;
        }
    }

    cout << totalMoves << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}
