// B. Karen and Coffee

// time limit per test2.5 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// To stay woke and attentive during classes, Karen needs some coffee! Karen, a coffee aficionado, wants to know the optimal temperature for brewing the perfect cup of coffee. Indeed, she has spent some time reading several recipe books, including the universally acclaimed "The Art of the Covfefe". She knows n coffee recipes. The i-th recipe suggests that coffee should be brewed between li and ri degrees, inclusive, to achieve the optimal taste. Karen thinks that a temperature is admissible if at least k recipes recommend it. Karen has a rather fickle mind, and so she asks q questions. In each question, given that she only wants to prepare coffee with a temperature between a and b, inclusive, can you tell her how many admissible integer temperatures fall within the range?

// Input
// The first line of input contains three integers, n, k (1 ≤ k ≤ n ≤ 200000), and q (1 ≤ q ≤ 200000), the number of recipes, the minimum number of recipes a certain temperature must be recommended by to be admissible, and the number of questions Karen has, respectively. The next n lines describe the recipes. Specifically, the i-th line among these contains two integers li and ri (1 ≤ li ≤ ri ≤ 200000), describing that the i-th recipe suggests that the coffee be brewed between li and ri degrees, inclusive. The next q lines describe the questions. Each of these lines contains a and b, (1 ≤ a ≤ b ≤ 200000), describing that she wants to know the number of admissible integer temperatures between a and b degrees, inclusive.

// Output
// For each question, output a single integer on a line by itself, the number of admissible integer temperatures between a and b degrees, inclusive.

// Examples
// inputCopy
// 3 2 4
// 91 94
// 92 97
// 97 99
// 92 94
// 93 97
// 95 96
// 90 100
// outputCopy
// 3
// 3
// 0
// 4
// inputCopy
// 2 1 1
// 1 1
// 200000 200000
// 90 100
// outputCopy
// 0

// Note

// In the first test case, Karen knows 3 recipes.

// The first one recommends brewing the coffee between 91 and 94 degrees, inclusive.
// The second one recommends brewing the coffee between 92 and 97 degrees, inclusive.
// The third one recommends brewing the coffee between 97 and 99 degrees, inclusive.
// A temperature is admissible if at least 2 recipes recommend it.

// She asks 4 questions.

// In her first question, she wants to know the number of admissible integer temperatures between 92 and 94 degrees, inclusive. There are 3: 92, 93 and 94 degrees are all admissible.
// In her second question, she wants to know the number of admissible integer temperatures between 93 and 97 degrees, inclusive. There are 3: 93, 94 and 97 degrees are all admissible.
// In her third question, she wants to know the number of admissible integer temperatures between 95 and 96 degrees, inclusive. There are none.
// In her final question, she wants to know the number of admissible integer temperatures between 90 and 100 degrees, inclusive. There are 4: 92, 93, 94 and 97 degrees are all admissible.

// In the second test case, Karen knows 2 recipes.

// The first one, "wikiHow to make Cold Brew Coffee", recommends brewing the coffee at exactly 1 degree.
// The second one, "What good is coffee that isn't brewed at at least 36.3306 times the temperature of the surface of the sun?", recommends brewing the coffee at exactly 200000 degrees.

// A temperature is admissible if at least 1 recipe recommends it.

// In her first and only question, she wants to know the number of admissible integer temperatures that are actually reasonable. There are none.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

const int MAX_N = 200005;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    //Number of recipes at each temperature
    vector<int> frequency(MAX_N);

    //Processing each recipe
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        ++frequency[l];
        --frequency[r + 1];
    }

    //Cumulative sum to calculate the number of admissible temperatures
    int cumulative_sum = 0;
    for (int i = 0; i < frequency.size(); ++i)
    {
        cumulative_sum += frequency[i];
        frequency[i] = (cumulative_sum >= k) ? 1 : 0;
    }

    //Cumulative sum again to answer queries efficiently
    vector<int> prefix_sum(MAX_N);
    for (int i = 1; i < prefix_sum.size(); ++i)
    {
        prefix_sum[i] = frequency[i - 1] + prefix_sum[i - 1];
    }

    //Answer queries
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r + 1] - prefix_sum[l] << endl;
    }
}

int32_t main()
{
    fastio;
    solve();

    return 0;
}
