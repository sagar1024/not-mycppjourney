// A. Towers

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Little Vasya has received a young builder’s kit. The kit consists of several wooden bars, the lengths of all of them are known. The bars can be put one on the top of the other if their lengths are the same. Vasya wants to construct the minimal number of towers from the bars. Help Vasya to use the bars in the best way possible.

// Input
// The first line contains an integer N (1 ≤ N ≤ 1000) — the number of bars at Vasya’s disposal. The second line contains N space-separated integers li — the lengths of the bars. All the lengths are natural numbers not exceeding 1000.

// Output
// In one line output two numbers — the height of the largest tower and their total number. Remember that Vasya should use all the bars.

// Examples
// inputCopy
// 3
// 1 2 3
// outputCopy
// 1 3

// inputCopy
// 4
// 6 5 6 7
// outputCopy
// 2 3

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> lengths(n);
    for(int i=0; i<n; i++)
    {
        cin >> lengths[i];
    }

    //Initializing array with 0s is important
    //Array size is 1000+1 to accomodate 1000th number
    int numFreq[1001] = {0};
    for(int i=0; i<n; i++)
    {
        numFreq[lengths[i]]++;
    }

    int largestTower = 0;
    int totalNumOfTowers = 0;
    for(int i=0; i<1001; i++)
    {
        //Num with max occurences
        largestTower = max(numFreq[i], largestTower);

        //Counting the total num of towers
        //Having atleast one wooden bar
        if(numFreq[i]>0)
        {
            totalNumOfTowers++;
        }
    }

    cout << largestTower << " " << totalNumOfTowers << endl;

    return 0;
}
