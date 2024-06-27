// B. Amr and Pins

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Amr loves Geometry. One day he came up with a very interesting problem. Amr has a circle of radius r and center in point (x, y). He wants the circle center to be in new position (x', y'). In one step Amr can put a pin to the border of the circle in a certain point, then rotate the circle around that pin by any angle and finally remove the pin. Help Amr to achieve his goal in minimum number of steps.

// Input
// Input consists of 5 space-separated integers r, x, y, x' y' (1 ≤ r ≤ 105,  - 105 ≤ x, y, x', y' ≤ 105), circle radius, coordinates of original center of the circle and coordinates of destination center of the circle respectively.

// Output
// Output a single integer — minimum number of steps required to move the center of the circle to the destination point.

// Examples
// inputCopy
// 2 0 0 0 4
// outputCopy
// 1
// inputCopy
// 1 1 1 4 4
// outputCopy
// 3
// inputCopy
// 4 5 6 5 6
// outputCopy
// 0

// Note
// In the first sample test the optimal way is to put a pin at point (0, 2) and rotate the circle by 180 degrees counter-clockwise (or clockwise, no matter).
// Figure - A dart with coordinates

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

int32_t main()
{
    //Fast IO
    fastio;

    int r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    //Use double instead of float
    double euclideanDist = sqrt(pow((x-x1),2)+pow((y-y1),2));

    //int minSteps = ceil((float)euclideanDist/r) - 1;
    int minSteps = ceil(euclideanDist/(2*r));

    cout << minSteps << endl;

    return 0;
}
