// B. Informatics in MAC

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In the Master's Assistance Center, Nyam-Nyam was given a homework assignment in informatics. There is an array a of length n, and you want to divide it into k>1 subsegments† in such a way that the MEX‡ on each subsegment is equal to the same integer. Help Nyam-Nyam find any suitable division, or determine that it does not exist. A division of an array into k subsegments is defined as k pairs of integers (l1,r1),(l2,r2),…,(lk,rk) such that li≤ri and for each 1≤j≤k−1, lj+1=rj+1, and also l1=1 and rk=n. These pairs represent the subsegments themselves. ‡MEX of an array is the smallest non-negative integer that does not belong to the array.

// For example:

// MEX of the array [2,2,1] is 0, because 0 does not belong to the array.
// MEX of the array [3,1,0,1] is 2, because 0 and 1 belong to the array, but 2 does not.
// MEX of the array [0,3,1,2] is 4, because 0, 1, 2, and 3 belong to the array, but 4 does not.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤105) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (0≤ai<n) — the elements of the array a. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output a single integer −1 if a suitable division does not exist. Otherwise, on the first line, output an integer k (2≤k≤n) — the number of subsegments in the division. Then output k lines — the division into subsegments. The i-th line should contain two integers li and ri (1≤li≤ri≤n) — the boundaries of the i-th subsegment. The following conditions must be satisfied:

// For all 1≤j≤k−1, lj+1=rj+1;
// l1=1, rk=n.

// If there are multiple possible solutions, output any of them.

// Example
// inputCopy
// 5
// 2
// 0 0
// 5
// 0 1 2 3 4
// 8
// 0 1 7 1 0 1 0 3
// 3
// 2 2 2
// 4
// 0 1 2 0
// outputCopy
// 2
// 1 1
// 2 2
// -1
// 3
// 1 3
// 4 5
// 6 8
// 3
// 1 1
// 2 2
// 3 3
// -1

// Note
// In the first test case, the array a can be divided into 2 subsegments with boundaries [1,1] and [2,2]:

// MEX of the first subsegment [0] is 1, as 0 belongs to the subsegment, but 1 does not.
// MEX of the second subsegment [0] is 1, as 0 belongs to the subsegment, but 1 does not.

// In the second test case, it can be proven that the required division does not exist.

// In the third test case, the array a can be divided into 3 subsegments with boundaries [1,3], [4,5], [6,8]:

// MEX of the first subsegment [0,1,7] is 2, as 0 and 1 belong to the subsegment, but 2 does not.
// MEX of the second subsegment [1,0] is 2, as 0 and 1 belong to the subsegment, but 2 does not.
// MEX of the third subsegment [1,0,3] is 2, as 0 and 1 belong to the subsegment, but 2 does not.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> a(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i];

//         }

//         vector<int> unsortedA = a;

//         sort(a.begin(), a.end());
//         vector<int> sortedA = a;

//         if(unsortedA == sortedA)
//         {
//             cout << n << endl;
//             for(int i=1; i<=n; i++)
//             {
//                 cout << i << " " << i << endl;
//             }
//             continue;
//         }

//         bool divisionPossible = false;
//         int lastContinuousNumber = 0;
//         int lastContinuousNumberValue = 0;

//         for(int i=1; i<n; i++)
//         {
//             if(sortedA[i]==lastContinuousNumber && lastContinuousNumber)
//             {
//                 lastContinuousNumber++;
//             }
//             if(sortedA[i-1]+1<sortedA[i])
//             {
//                 divisionPossible = true;
//                 lastContinuousNumberValue = sortedA[i-1];

//                 if(!lastContinuousNumber) lastContinuousNumber++;
//             }
//         }

//         int count = 0;
//         if(!divisionPossible)
//         {
//             cout << "-1" << endl;
//             continue;
//         }
//         else
//         {
//             cout << lastContinuousNumber << endl;
//             for(int i=0; i<n; i++)
//             {
//                 if(a[i]==lastContinuousNumberValue)
//                 {
//                     if(i==0)
//                     {
//                         cout << 1 << " " << i+1 << endl;
//                     }
//                     else
//                     {
//                         //How to print the 1-based indexes of the subsegments each of which carries the lastContinuousNumberValue?

//                     }
//                 }
//             }
//         }
//     }
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputs
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());

        //Checking if the array is already sorted
        bool alreadySorted = (a == sortedA);

        //If already sorted, each element is a separate subsegment
        if (alreadySorted)
        {
            cout << n << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " " << i + 1 << endl;
            }

            continue;
        }

        //Finding the last continuous number
        int lastContinuousNumber = 0;
        for (int i = 1; i < n; i++)
        {
            if (sortedA[i - 1] + 1 < sortedA[i])
            {
                lastContinuousNumber = sortedA[i - 1];
                break;
            }
        }

        //If no continuous number found, division is not possible
        if (lastContinuousNumber == 0)
        {
            cout << -1 << endl;
            continue;
        }

        //Counting the number of subsegments
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == lastContinuousNumber)
            {
                k++;
            }
        }

        //Output the number of subsegments
        cout << k << endl;

        //Output the subsegments
        int start = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == lastContinuousNumber)
            {
                cout << start << " " << i + 1 << endl;
                start = i + 2;
            }
        }
    }

    return 0;
}
