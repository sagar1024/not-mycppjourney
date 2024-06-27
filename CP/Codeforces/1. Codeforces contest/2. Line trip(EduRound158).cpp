// A. Line Trip

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There is a road, which can be represented as a number line. You are located in the point 0 of the number line, and you want to travel from the point 0 to the point x, and back to the point 0.

// You travel by car, which spends 1 liter of gasoline per 1 unit of distance travelled. When you start at the point 0, your car is fully fueled (its gas tank contains the maximum possible amount of fuel).

// There are n gas stations, located in points a1,a2,…,an. When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0 and x.

// You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0 to the point x and back to the point 0.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases.

// Each test case consists of two lines: the first line contains two integers n and x (1≤n≤50; 2≤x≤100); the second line contains n integers a1,a2,…,an (0<a1<a2<⋯<an<x).
// Output
// For each test case, print one integer — the minimum possible volume of the gas tank in your car that will allow you to travel from the point 0 to the point x and back.

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> gasStations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> gasStations[i];
        }

        int minGasTankCounter = 0;

        // for (int i = 1; i <= x; i++)
        // {
        //     if (i + 1 == gasStations[i])
        //     {
        //         minGasTankCounter = 0;
        //     }
        //     minGasTankCounter += 1;
        // }

        for (int i = 1; i <= x; ++i)
        {
            bool isGasStation = false;
            for (int j = 0; j < n; ++j)
            {
                if (gasStations[j]==i)
                {
                    isGasStation = true;
                    break;
                }
            }
            if (isGasStation)
            {
                minGasTankCounter = 0;
            }

            minGasTankCounter += 1;
        }

        cout << minGasTankCounter * 2 << endl;
    }

    return 0;
}

