// B. Nene and the Card Game

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You and Nene are playing a card game. The deck with 2n cards is used to play this game. Each card has an integer from 1 to n on it, and each of integers 1 through n appears exactly on 2 cards. Additionally, there is a table where cards are placed during the game (initially, the table is empty). In the beginning of the game, these 2n cards are distributed between you and Nene so that each player receives n cards. After it, you and Nene alternatively take 2n turns, i.e. each person takes n turns, starting with you. On each turn: The player whose turn is it selects one of the cards in his hand. Let x be the number on it. The player whose turn is it receives 1 point if there is already a card with the integer x on the table (otherwise, he receives no points). After it, he places the selected card with the integer x on the table. Note that turns are made publicly: each player can see all the cards on the table at each moment. Nene is very smart so she always selects cards optimally in order to maximize her score in the end of the game (after 2n rounds). If she has several optimal moves, she selects the move that minimizes your score in the end of the game. More formally, Nene always takes turns optimally in order to maximize her score in the end of the game in the first place and to minimize your score in the end of the game in the second place. Assuming that the cards are already distributed and cards in your hand have integers a1,a2,…,an written on them, what is the maximum number of points you can get by taking your turns optimally?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of test cases follows. The first line contains a single integer n (1≤n≤2⋅105) — the number of cards you and Nene receive in the beginning of the game. The second line contains n integers a1,a2,…,an (1≤ai≤n) — the integers on the cards in your hand. It is guaranteed that each integer from 1 through n appears in the sequence a1,a2,…,an at most 2 times. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer: the maximum number of points you can get.

// Example
// inputCopy
// 5
// 4
// 1 1 2 3
// 8
// 7 4 1 2 8 8 5 5
// 8
// 7 1 4 5 3 4 2 6
// 3
// 1 2 3
// 1
// 1
// outputCopy
// 1
// 2
// 1
// 0
// 0

// Note
// In the first test case, the integers written on your cards are 1, 1, 2 and 3. The integers written on Nene's cards are 2, 3, 4 and 4. The game may proceed as follows:

// You select one of the cards with an integer 1 written on it and place it on the table.
// Nene selects one of the cards with an integer 4 written on it and places it on the table.
// You select the card with an integer 1 written on it, receive 1 point, and place the selected card on the table.
// Nene selects the card with an integer 4 written on it, receive 1 point, and places the selected card on the table.
// You select the card with an integer 2 written on it and place it on the table.
// Nene selects the card with an integer 2 written on it, receive 1 point, and places the selected card on the table.
// You select the card with an integer 3 written on it and place it on the table.
// Nene selects the card with an integer 3 written on it, receive 1 point, and places the selected card on the table.
// At the end of the game, you scored 1 point, and Nene scored 3. It can be shown that you cannot score more than 1 point if Nene plays optimally, so the answer is 1.

// In the second test case, if both players play optimally, you score 2 points and Nene scores 6 points.

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

    vector<int> cards(n);
    vector<int> freq(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> cards[i];
        freq[cards[i]]++;
    }

    int maxPoints = 0;
    for(int i=1; i<=n; i++)
    {
        if(freq[i]==2)
        {
            maxPoints++;
        }
    }

    cout << maxPoints << endl;
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
