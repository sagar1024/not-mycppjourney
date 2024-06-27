// A. The number of positions

// time limit per test0.5 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Petr stands in line of n people, but he doesn't know exactly which position he occupies. He can say that there are no less than a people standing in front of him and no more than b people standing behind him. Find the number of different positions Petr can occupy.

// Input
// The only line contains three integers n, a and b (0 ≤ a, b < n ≤ 100).

// Output
// Print the single number — the number of the sought positions.

// Examples
// inputCopy
// 3 1 1
// outputCopy
// 2
// inputCopy
// 5 2 3
// outputCopy
// 3

// Note
// The possible positions in the first sample are: 2 and 3 (if we number the positions starting with 1).
// In the second sample they are 3, 4 and 5.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Num of people in line
    int n;
    cin >> n;

    // No less than "a" people standing in front of him
    // Greater than or equal to "a"
    int a;
    cin >> a;

    // No more than "b" people standing behind him
    // Less than or equal to "b"
    int b;
    cin >> b;

    // Main logic
    // Num of diff positions he can occupy
    // If n is less than or equal to a+b+1
    int positions = n - a;

    // Special cases
    if (n>(a+b+1))
    {
        positions = b+1;
    }

    cout << positions << endl;

    return 0;
}

