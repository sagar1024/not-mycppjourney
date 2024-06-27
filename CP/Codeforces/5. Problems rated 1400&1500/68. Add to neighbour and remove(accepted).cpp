// D. Add to Neighbour and Remove

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp was given an array of a[1…n] of n integers. He can perform the following operation with the array a no more than n times: Polycarp selects the index i and adds the value ai to one of his choice of its neighbors. More formally, Polycarp adds the value of ai to ai−1 or to ai+1 (if such a neighbor does not exist, then it is impossible to add to it). After adding it, Polycarp removes the i-th element from the a array. During this step the length of a is decreased by 1. The two items above together denote one single operation.

// For example, if Polycarp has an array a=[3,1,6,6,2], then it can perform the following sequence of operations with it:

// Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[4,6,6,2].
// Polycarp selects i=1 and adds the value ai to (i+1)-th element: a=[10,6,2].
// Polycarp selects i=3 and adds the value ai to (i−1)-th element: a=[10,8].
// Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[18].
// Note that Polycarp could stop performing operations at any time.

// Polycarp wondered how many minimum operations he would need to perform to make all the elements of a equal (i.e., he wants all ai are equal to each other).

// Input
// The first line contains a single integer t (1≤t≤3000) — the number of test cases in the test. Then t test cases follow. The first line of each test case contains a single integer n (1≤n≤3000) — the length of the array. The next line contains n integers a1,a2,…,an (1≤ai≤105) — array a. It is guaranteed that the sum of n over all test cases does not exceed 3000.

// Output
// For each test case, output a single number — the minimum number of operations that Polycarp needs to perform so that all elements of the a array are the same (equal).

// Example
// inputCopy
// 4
// 5
// 3 1 6 6 2
// 4
// 1 2 2 1
// 3
// 2 2 2
// 4
// 6 3 2 1
// outputCopy
// 4
// 2
// 0
// 2

// Note

// In the first test case of the example, the answer can be constructed like this (just one way among many other ways):
// [3,1,6,6,2] −→−−−−−−−i=4, add to left [3,1,12,2] −→−−−−−−−−i=2, add to right [3,13,2] −→−−−−−−−−i=1, add to right [16,2] −→−−−−−−−i=2, add to left [18]. All elements of the array [18] are the same.

// In the second test case of the example, the answer can be constructed like this (just one way among other ways):
// [1,2,2,1] −→−−−−−−−−i=1, add to right [3,2,1] −→−−−−−−−i=3, add to left [3,3]. All elements of the array [3,3] are the same.

// In the third test case of the example, Polycarp doesn't need to perform any operations since [2,2,2] contains equal (same) elements only.

// In the fourth test case of the example, the answer can be constructed like this (just one way among other ways):
// [6,3,2,1] −→−−−−−−−−i=3, add to right [6,3,3] −→−−−−−−−i=3, add to left [6,6]. All elements of the array [6,6] are the same.

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// bool equalElements(vector<int> givenArray)
// {
//     bool equal = true;
//     for(int i=1; i<givenArray.size(); i++)
//     {
//         if(givenArray[i-1]!=givenArray[i])
//         {
//             equal = false;
//         }
//     }

//     return equal;
// }

void solve()
{
    int n;
    cin >> n;

    vector<int> givenArray(n);
    long long int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> givenArray[i];
        totalSum += givenArray[i];
    }

    //MAIN logic
    // long int count = 0;
    // while (!equalElements(givenArray))
    // {
    //     for (int i = 1; i < n - 1; i++)
    //     {
    //         if (givenArray[i - 1] < givenArray[i + 1])
    //         {
    //             givenArray[i - 1] += givenArray[i];
    //             givenArray.erase(givenArray.begin() + i);
    //             i--;
    //             n--;
    //         }
    //         else if (givenArray[i - 1] > givenArray[i + 1])
    //         {
    //             givenArray[i + 1] += givenArray[i];
    //             givenArray.erase(givenArray.begin() + i);
    //             i--;
    //             n--;
    //         }
    //         else
    //         {
    //             continue;
    //         }

    //         count++;
    //     }
    // }

    // cout << count << endl;
    // return;

    //Possible way to divide the elements
    for(int division=n; division>=1; division--)
    {
        //Proceeding only if the curr num properly divides the total sum
        if(totalSum%division==0)
        {
            //The sum of each division
            //Once the current sum reaches the target sum, we make it 0 again for the next division
            //If the current sum exceeds the target sum, we break the loop and try diff division
            long long int targetSum = totalSum/division;
            long long int currSum = 0;

            bool possible = true;

            for(int i=0; i<n; i++)
            {
                //Keep adding elements of each division
                currSum += givenArray[i];
                if(currSum>targetSum)
                {
                    possible = false;
                    break;
                }
                else if(currSum == targetSum)
                {
                    currSum = 0;
                }
            }

            //Loop ends with possible==true
            if(possible)
            {
                //Minimum number of elements that need to be removed
                //From the array to achieve the desired grouping where each group has the same sum
                cout << n - division << endl;
                return;
            }
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
