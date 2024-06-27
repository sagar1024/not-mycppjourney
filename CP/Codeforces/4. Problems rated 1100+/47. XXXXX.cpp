// A. XXXXX

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ehab loves number theory, but for some reason he hates the number x. Given an array a, find the length of its longest subarray such that the sum of its elements isn't divisible by x, or determine that such subarray doesn't exist. An array a is a subarray of an array b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

// Input
// The first line contains an integer t (1≤t≤5) — the number of test cases you need to solve. The description of the test cases follows. The first line of each test case contains 2 integers n and x (1≤n≤105, 1≤x≤104) — the number of elements in the array a and the number that Ehab hates. The second line contains n space-separated integers a1, a2, …, an (0≤ai≤104) — the elements of the array a.

// Output
// For each testcase, print the length of the longest subarray whose sum isn't divisible by x. If there's no such subarray, print −1.

// Example
// inputCopy
// 3
// 3 3
// 1 2 3
// 3 4
// 1 2 3
// 2 2
// 0 6
// outputCopy
// 2
// 3
// -1

// Note
// In the first test case, the subarray [2,3] has sum of elements 5, which isn't divisible by 3.
// In the second test case, the sum of elements of the whole array is 6, which isn't divisible by 4.
// In the third test case, all subarrays have an even sum, so the answer is −1.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         //Length of array
//         //Disliked num
//         int n, x;
//         cin >> n >> x;

//         //Given array
//         vector<int> elements(n);
//         vector<int> remainderArray(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> elements[i];
//             remainderArray[i] = elements[i]%x;
//         }

//         //MAIN logic
//         int elementCount = 0;
//         int maxCount = 0;
//         int subarraySum = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i; j<n; j++)
//             {
//                 if(subarraySum==x)
//                 {
//                     break;
//                 }
//                 subarraySum += remainderArray[j];
//                 elementCount = (j-i)+1;
//             }
//             maxCount = max(elementCount, maxCount);
//         }

//         //Output
//         if(subarraySum==0)
//         {
//             cout << "-1" << endl;
//         }
//         else
//         {
//             cout << maxCount << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Inputs
        int n, x;
        cin >> n >> x;

        // Given array
        vector<int> elements(n);
        for (int i = 0; i < n; i++)
        {
            cin >> elements[i];
        }

        // MAIN logic
        int maxCount = -1;
        int sum = 0;
        unordered_map<int, int> prefixSumIndex;

        for (int i = 0; i < n; i++)
        {
            sum += elements[i];
            int remainder = sum % x;

            if (remainder != 0)
            {
                maxCount = max(maxCount, i + 1);
            }

            if (prefixSumIndex.count(remainder))
            {
                maxCount = max(maxCount, i - prefixSumIndex[remainder]);
            }
            else
            {
                prefixSumIndex[remainder] = i;
            }
        }

        // Output
        cout << maxCount << endl;
    }

    return 0;
}
