// A. Winner

// time limit per test1 second
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// The winner of the card game popular in Berland "Berlogging" is determined according to the following rules. If at the end of the game there is only one player with the maximum number of points, he is the winner. The situation becomes more difficult if the number of such players is more than one. During each round a player gains or loses a particular number of points. In the course of the game the number of points is registered in the line "name score", where name is a player's name, and score is the number of points gained in this round, which is an integer number. If score is negative, this means that the player has lost in the round. So, if two or more players have the maximum number of points (say, it equals to m) at the end of the game, than wins the one of them who scored at least m points first. Initially each player has 0 points. It's guaranteed that at the end of the game at least one player has a positive number of points.

// Input
// The first line contains an integer number n (1  ≤  n  ≤  1000), n is the number of rounds played. Then follow n lines, containing the information about the rounds in "name score" format in chronological order, where name is a string of lower-case Latin letters with the length from 1 to 32, and score is an integer number between -1000 and 1000, inclusive.

// Output
// Print the name of the winner.

// Examples
// inputCopy
// 3
// mike 3
// andrew 5
// mike 2
// outputCopy
// andrew
// inputCopy
// 3
// andrew 3
// andrew 2
// mike 5
// outputCopy
// andrew

//My original approach -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// int32_t main()
// {
//     fastio;

//     int n;
//     cin >> n;

//     vector<pair<string, int>> nameScore(n);
//     int i = 0;
//     forn(i,n)
//     {
//         string s;
//         cin >> s;

//         string name = "";
//         string score1 = "";

//         for(int i=0; i<s.size(); i++)
//         {
//             if(s[i]== ' ')
//             {
//                 for(int j=i; j<n; j++)
//                 {
//                     score1 += s[j];
//                 }
//                 break;
//             }
//             name += s[i];
//         }

//         int score2 = stoi(score1);

//         nameScore[i].first = name;
//         nameScore[i].second = score2;
//     }

//     string winner = "";
//     for(int i=0; i<n; i++)
//     {

//     }

//     return 0;
// }

//Alternate approach -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

int32_t main()
{
    //For fast I/O
    fastio;

    //Inputs
    int n;
    cin >> n;

    //Name and score
    string s[10000];
    int a[10000];

    //Storing the scores using a map
    //unordered_map<string, int> scoreBoard(n);
    map<string, long int> scoreBoard;
    for(int i=0; i<n; i++)
    {
        cin >> s[i] >> a[i];
        scoreBoard[s[i]] += a[i];        
    }

    //Finding the maxx score
    long int maxx = 0;
    for(int i=0; i<n; i++)
    {
        maxx = max(scoreBoard[s[i]], maxx);
    }

    //MAIN logic
    //Now we know the max score we will recreate a new scoreboard
    //At each round we will check if the current score of the player is greater or equal to the maxx number
    //If it is also equal to the maxx number then it is the answer(the players name)
    map<string, long int> scoreBoard2;
    string answer = "";
    for(int i=0; i<n; i++)
    {
        scoreBoard2[s[i]] += a[i];
        if((scoreBoard2[s[i]]>=maxx) && (scoreBoard[s[i]] == maxx))
        {
            answer = s[i];
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
