// B. Mahmoud and a Triangle

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Mahmoud has n line segments, the i-th of them has length ai. Ehab challenged him to use exactly 3 line segments to form a non-degenerate triangle. Mahmoud doesn't accept challenges unless he is sure he can win, so he asked you to tell him if he should accept the challenge. Given the lengths of the line segments, check if he can choose exactly 3 of them to form a non-degenerate triangle. Mahmoud should use exactly 3 line segments, he can't concatenate two line segments or change any length. A non-degenerate triangle is a triangle with positive area.

// Input
// The first line contains single integer n (3 ≤ n ≤ 105) — the number of line segments Mahmoud has. The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the lengths of line segments Mahmoud has.

// Output
// In the only line print "YES" if he can choose exactly three line segments and form a non-degenerate triangle with them, and "NO" otherwise.

// Examples
// inputCopy
// 5
// 1 5 3 2 4
// outputCopy
// YES

// inputCopy
// 3
// 4 1 2
// outputCopy
// NO

// Note
// For the first example, he can use line segments with lengths 2, 4 and 5 to form a non-degenerate triangle.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Num of line segments
    int n;
    cin >> n;

    //Lengths of the line segments
    vector<int> lines(n);
    for(int i=0; i<n; i++)
    {
        cin >> lines[i];
    }

    sort(lines.begin(), lines.end());

    bool trianglePossible = false;
    for(int i=0; i<n-2; i++)
    {
        if(lines[i]+lines[i+1]>lines[i+2])
        {
            trianglePossible = true;
            break;
        }
    }

    if(trianglePossible)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

