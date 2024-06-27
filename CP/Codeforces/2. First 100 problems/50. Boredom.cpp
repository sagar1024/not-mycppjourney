// A. Boredom

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games. One long winter evening he came up with a game and decided to play it. Given a sequence a consisting of n integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 also must be deleted from the sequence. That step brings ak points to the player. Alex is a perfectionist, so he decided to get as many points as possible. Help him.

// Input
// The first line contains integer n (1≤n≤10^5) that shows how many numbers are in Alex's sequence. The second line contains n integers a1, a2, ...,an (1 ≤ ai ≤ 10^5).

// Output
// Print a single integer — the maximum number of points that Alex can earn.

// Examples

// Input
// 2
// 1 2
// Output
// 2

// Input
// 3
// 1 2 3
// Output
// 4

// Input
// 9
// 1 2 1 3 2 2 2 2 3
// Output
// 10

// Note
// Consider the third test example.
// At first step we need to choose any element equal to 2.
// After that step our sequence looks like this [2, 2, 2, 2].
// Then we do 4 steps, on each step we choose any element equals to 2.
// In total we earn 10 points.

// Chatgpt code used as template

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Maximum possible value
const int MAX_N = 1e5 + 5;

// Array to store num's frequency
int freq[MAX_N];

// Array to store max points
// That can be earned at each element
long long dp[MAX_N];

int main()
{
    // Numbers in Alex's sequence
    int n;
    cin >> n;

    // Reading the sequence elements
    // While keeping track of their frequencies
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        // Counting frequency of each number
        freq[num]++;
    }

    // Dynamic programming to compute the maximum points
    // Initialize dp[1] with frequency of 1
    dp[0] = 0;
    dp[1] = freq[1];

    // Calculates max points
    // Calculated using the recurrence relation
    for (int i = 2; i < MAX_N; i++)
    {
        // Recurrence relation
        // In C++, 1LL is a long long integer literal
        // Freq[i] is an element from array at index i
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * freq[i]);
    }

    // Maximum points earned by Alex
    cout << dp[MAX_N - 1] << endl;

    return 0;
}
