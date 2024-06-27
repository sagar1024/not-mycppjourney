// B. Han Solo and Lazer Gun

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n Imperial stormtroopers on the field. The battle field is a plane with Cartesian coordinate system. Each stormtrooper is associated with his coordinates (x, y) on this plane. Han Solo has the newest duplex lazer gun to fight these stormtroopers. It is situated at the point (x0, y0). In one shot it can can destroy all the stormtroopers, situated on some line that crosses point (x0, y0). Your task is to determine what minimum number of shots Han Solo needs to defeat all the stormtroopers. The gun is the newest invention, it shoots very quickly and even after a very large number of shots the stormtroopers don't have enough time to realize what's happening and change their location.

// Input
// The first line contains three integers n, x0 и y0 (1 ≤ n ≤ 1000,  - 104 ≤ x0, y0 ≤ 104) — the number of stormtroopers on the battle field and the coordinates of your gun. Next n lines contain two integers each xi, yi ( - 104 ≤ xi, yi ≤ 104) — the coordinates of the stormtroopers on the battlefield. It is guaranteed that no stormtrooper stands at the same point with the gun. Multiple stormtroopers can stand at the same point.

// Output
// Print a single integer — the minimum number of shots Han Solo needs to destroy all the stormtroopers.

// Examples
// inputCopy
// 4 0 0
// 1 1
// 2 2
// 2 0
// -1 -1
// outputCopy
// 2

// inputCopy
// 2 1 2
// 1 1
// 1 0
// outputCopy
// 1

// Note
// Explanation to the first and second samples from the statement, respectively:
// (figure1) & (figure2)

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n, x0, y0;
//     cin >> n >> x0 >> y0;

//     vector<pair<int,int>> stormtroopers(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> stormtroopers[i].first;
//         cin >> stormtroopers[i].second;
//     }

//     //To store unique slope values
//     unordered_set<float> slopes(n);

//     //Counting the num of stormtroopers having the same abscissa i.e x value
//     //This case if not handled separately, will generate logical error i.e division by 0 which is ND
//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         //Handling case when slope = infinite
//         if(stormtroopers[i].first == x0)
//         {
//             //Only one shot is enough
//             count = 1;
//         }
//         //Slope of current stormtroopers with respect to the HanSolo's position
//         float currSlope = (stormtroopers[i].second - y0) / (stormtroopers[i].first - x0);
//         slopes.insert(currSlope);
//     }

//     cout << slopes.size()+count << endl;
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;

    vector<pair<int, int>> stormtroopers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> stormtroopers[i].first >> stormtroopers[i].second;
    }

    //Ek teer se anek nishane using slope
    //We only need to store the unique slopes
    set<double> slopes;

    //Special case for slope = infinite
    bool vertical = false;

    for (const auto &trooper : stormtroopers)
    {
        int dx = trooper.first - x0;
        int dy = trooper.second - y0;

        //If dx is 0, the slope will be ND
        //It will be division by 0 error
        if (dx == 0)
        {
            vertical = true;
        }
        else
        {
            //Storing the unique slopes
            //AND
            //Then calculating its size to find out the num of shots needed
            slopes.insert(static_cast<double>(dy) / dx);
        }
    }

    int shots = slopes.size() + (vertical ? 1 : 0);
    cout << shots << endl;

    return 0;
}
