// E. Accidental Victory

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A championship is held in Berland, in which n players participate. The player with the number i has ai (ai≥1) tokens. The championship consists of n−1 games, which are played according to the following rules:

// in each game, two random players with non-zero tokens are selected;
// the player with more tokens is considered the winner of the game (in case of a tie, the winner is chosen randomly);
// the winning player takes all of the loser's tokens;

// The last player with non-zero tokens is the winner of the championship. All random decisions that are made during the championship are made equally probable and independently. For example, if n=4, a=[1,2,4,3], then one of the options for the game (there could be other options) is:

// during the first game, the first and fourth players were selected. The fourth player has more tokens, so he takes the first player's tokens. Now a=[0,2,4,4];
// during the second game, the fourth and third players were selected. They have the same number of tokens, but in a random way, the third player is the winner. Now a=[0,2,8,0];
// during the third game, the second and third players were selected. The third player has more tokens, so he takes the second player's tokens. Now a=[0,0,10,0];
// the third player is declared the winner of the championship.

// Championship winners will receive personalized prizes. Therefore, the judges want to know in advance which players have a chance of winning, i.e have a non-zero probability of winning the championship. You have been asked to find all such players.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow. The first line of each test case consists of one positive integer n (1≤n≤2⋅105) — the number of players in the championship. The second line of each test case contains n positive integers a1,a2,…,an (1≤ai≤109) — the number of tokens the players have. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print the number of players who have a nonzero probability of winning the championship. On the next line print the numbers of these players in increasing order. Players are numbered starting from one in the order in which they appear in the input.

// Example
// inputCopy
// 2
// 4
// 1 2 4 3
// 5
// 1 1 1 1 1
// outputCopy
// 3
// 2 3 4 
// 5
// 1 2 3 4 5 

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n;
    cin >> n;

    vector<long long int> givenArray(n);
    unordered_map<int,long long int> mp(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
        mp.insert({i+1,givenArray[i]});
    }

    sort(givenArray.begin(), givenArray.end());

    vector<long long int> cumSum(n+1,0);
    cumSum[0] = givenArray[0];
    long long int winnerLoserLine = 0; //Indexes
    for(int i=1; i<n; i++)
    {
        if(cumSum[i]<givenArray[i])
        {
            winnerLoserLine = i;
        }

        cumSum[i] += cumSum[i-1]+givenArray[i];
    }

    //Creating an array of winners' indexes
    //vector<long long int> winners(n+1);
    //for(int i=0; i<winnerLoserLine; i++)
    //{
    //    winners.push_back(givenArray[i]);
    //}

    //Custom comparator to sort the map by values
    auto comp = [](const pair<int, long long int>& a, const pair<int, long long int>& b)
    {
        return a.second < b.second; //Sorting in ascending order of values
    };

    vector<pair<int, long long int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), comp);

    vector<int> winners; //Storing the indexes of winners
    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        if(it->second > 0) //If the number of tokens is greater than zero
        {
            winners.push_back(it->first); //Adding the player number to the winners vector
        }
    }

    cout << winners.size() << endl;
    for(int i = 0; i < winners.size(); i++)
    {
        cout << winners[i] << " ";
    }

    cout << endl;
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
