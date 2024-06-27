// A. Dragons

// time limit per test: 2 seconds
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

// If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength xi, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.

// Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

// Input
// The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). Then n lines follow: the i-th line contains space-separated integers xi and yi (1 ≤ xi ≤ 104, 0 ≤ yi ≤ 104) — the i-th dragon's strength and the bonus for defeating it.

// Output
// On a single line print "YES" (without the quotes), if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

// Utility header to use std::pair
#include <utility>

using namespace std;

int main()
{
    // Here, s is Kirito's strength and n is the number of dragons
    int s, n;
    cin >> s >> n;

    // Storing the values in arrays like this
    //  vector<int> dragonStrength(n);
    //  vector<int> bonusPoints(n);

    // for(int i=0; i<n; i++)
    // {
    //     cin >> dragonStrength[i];
    //     cin >> bonusPoints[i];
    // }

    // Creating pair of dragon strength and its bonus points
    vector<pair<int, int>> dragons;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        // Input the pairs in the above vector pair
        dragons.push_back(make_pair(x, y));
    }

    // Sorting the array to arrange the dragons in order of their strength i.e weakest to strongest
    sort(dragons.begin(), dragons.end());

    // Initializing the result as YES
    string result = "YES";

    // Iterating over each dragon combat
    // for (int i = 0; i < n; i++)
    // {
    //     // Kirito gets destroyed
    //     if (s <= dragons[i])
    //     {
    //         result = "NO";
    //         break;
    //     }

    //     // Kirito defeats the dragon
    //     else if (s > dragons[i])
    //     {
    //         s += dragons[i];
    //         continue;
    //     }
    // }

    // Iterating over each dragon the correct way
    for (const auto dragon : dragons)
    {
        // Kirito gets destroyed
        if (s <= dragon.first)
        {
            result = "NO";
            break;
        }
        // Kirito defeats the dragon
        else if (s > dragon.first)
        {
            s += dragon.second;
            continue;
        }
    }

    cout << result << endl;

    return 0;
}

