// A. Arrival of the General

// time limit per test: 2 seconds
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// A Ministry for Defense sent a general to inspect the Super Secret Military Squad under the command of the Colonel SuperDuper. Having learned the news, the colonel ordered to all n squad soldiers to line up on the parade ground.

// By the military charter the soldiers should stand in the order of non-increasing of their height. But as there's virtually no time to do that, the soldiers lined up in the arbitrary order. However, the general is rather short-sighted and he thinks that the soldiers lined up correctly if the first soldier in the line has the maximum height and the last soldier has the minimum height. Please note that the way other solders are positioned does not matter, including the case when there are several soldiers whose height is maximum or minimum. Only the heights of the first and the last soldier are important.

// For example, the general considers the sequence of heights (4, 3, 4, 2, 1, 1) correct and the sequence (4, 3, 1, 2, 2) wrong.

// Within one second the colonel can swap any two neighboring soldiers. Help him count the minimum time needed to form a line-up which the general will consider correct.

// Input
// The first input line contains the only integer n (2 ≤ n ≤ 100) which represents the number of soldiers in the line. The second line contains integers a1, a2, ..., an (1 ≤ ai ≤ 100) the values of the soldiers' heights in the order of soldiers' heights' increasing in the order from the beginning of the line to its end. The numbers are space-separated. Numbers a1, a2, ..., an are not necessarily different.

// Output
// Print the only integer — the minimum number of seconds the colonel will need to form a line-up the general will like.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    //Number of soldiers
    int n;
    cin >> n;

    //Storing the heights in an array/vector
    vector<int> heights(n);

    //Storing the heights
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    //Number of swaps(or seconds) required
    int swap_count = 0;

    // Initialize max and min with extreme values
    int maxHeight = INT_MIN;
    int minHeight = INT_MAX;

    //Position = Index + 1
    int maxHeightPosition = 0;
    int minHeightPosition = 0;

    // Iterate through the array to find max and min
    for (int i = 0; i < n; i++)
    {
        if (heights[i] > maxHeight)
        {
            // Update max if current element is greater
            maxHeight = heights[i];
            maxHeightPosition = i+1;
        }
        if (heights[i] < minHeight)
        {
            // Update min if current element is smaller
            minHeight = heights[i];
            minHeightPosition = i+1;
        }
    }

    //Swaps required for the tallest soldier
    if (heights[0] != maxHeight)
    {
        //Subtract the maxHeightPosition by 1 to get the number of swaps required to place the tallest in the first
        swap_count += maxHeightPosition - 1;
    }

    //Swaps required for the shortest soldier
    if (heights[n] != minHeight)
    {
        //Subtract the no. of soldiers(n) by minHeightPosition to get the required number of swaps to get the shortest in the last
        swap_count += n - minHeightPosition;
    }

    cout << swap_count << endl;

    return 0;
}