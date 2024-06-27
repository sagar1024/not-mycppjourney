// A. Fancy Fence

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Emuskald needs a fence around his farm, but he is too lazy to build it himself. So he purchased a fence-building robot. He wants the fence to be a regular polygon. The robot builds the fence along a single path, but it can only make fence corners at a single angle a. Will the robot be able to build the fence Emuskald wants? In other words, is there a regular polygon which angles are equal to a?

// Input
// The first line of input contains an integer t (0 < t < 180) — the number of tests. Each of the following t lines contains a single integer a (0 < a < 180) — the angle the robot can make corners at measured in degrees.

// Output
// For each test, output on a single line "YES" (without quotes), if the robot can build a fence Emuskald wants, and "NO" (without quotes), if it is impossible.

// Examples
// inputCopy
// 3
// 30
// 60
// 90

// outputCopy
// NO
// YES
// YES

// Note
// In the first test case, it is impossible to build the fence, since there is no regular polygon with angle .
// In the second test case, the fence is a regular triangle, and in the last test case — a square.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Given angle
        int a;
        cin >> a;

        //MAIN logic

        //Regular polygon has all sides and angles equal
        //Calc the supplementary angle
        //Here the interior angle is "a"
        //Then the supplementary angle will be (180-a)
        //In polygons, the sum of all supplementary angles is 360
        //If the supplementary angle divides 360 completely
        //Then the regular polygon exists for that angle
        if(360%(180-a)==0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout  << "NO" << endl;
        }
    }

    return 0;
}
