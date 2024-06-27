// C. Choose the Different Ones!

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given an array a of n integers, an array b of m integers, and an even number k.

// Your task is to determine whether it is possible to choose exactly k2 elements from both arrays in such a way that among the chosen elements, every integer from 1 to k is included.

// For example:

// If a=[2,3,8,5,6,5], b=[1,3,4,10,5], k=6, then it is possible to choose elements with values 2,3,6 from array a and elements with values 1,4,5 from array b. In this case, all numbers from 1 to k=6 will be included among the chosen elements.
// If a=[2,3,4,5,6,5], b=[1,3,8,10,3], k=6, then it is not possible to choose elements in the required way.

// Note that you are not required to find a way to choose the elements — your program should only check whether it is possible to choose the elements in the required way.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The descriptions of the test cases follow. The first line of each test case contains three integers n, m, and k (1≤n,m≤2⋅105, 2≤k≤2⋅min(n,m), k is even) — the length of array a, the length of array b, and the number of elements to be chosen, respectively. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the elements of array a. The third line of each test case contains m integers b1,b2,…,bm (1≤bj≤106) — the elements of array b. It is guaranteed that the sum of values n and m over all test cases in a test does not exceed 4⋅105.

// Output
// Output t lines, each of which is the answer to the corresponding test case. As the answer, output "YES" if it is possible to choose k2 numbers from each array in such a way that among the chosen elements, every integer from 1 to k is included. Otherwise, output "NO". You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

// Example
// inputCopy
// 6
// 6 5 6
// 2 3 8 5 6 5
// 1 3 4 10 5
// 6 5 6
// 2 3 4 5 6 5
// 1 3 8 10 3
// 3 3 4
// 1 3 5
// 2 4 6
// 2 5 4
// 1 4
// 7 3 4 4 2
// 1 4 2
// 2
// 6 4 4 2
// 1 5 2
// 3
// 2 2 1 4 3
// outputCopy
// YES
// NO
// YES
// YES
// NO
// NO

// Note
// In the first test case of the example, it is possible to choose elements equal to 2, 3, and 6 from array a and elements equal to 1, 4, and 5 from array b. Thus, all numbers from 1 to k=6 are included among the chosen elements.
// In the second test case of the example, it can be shown that it is not possible to choose exactly three elements from each array in the required way.
// In the third test case of the example, it is possible to choose elements equal to 1 and 3 from array a and elements equal to 2 and 4 from array b. Thus, all numbers from 1 to k=4 are included among the chosen elements.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         long int n, m, k;
//         cin >> n >> m >> k;

//         vector<long int> a(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i];
//         }

//         sort(a.begin(), a.end());

//         vector<long int> b(m);
//         for(int i=0; i<m; i++)
//         {
//             cin >> b[i];
//         }

//         sort(b.begin(), b.end());

//         vector<int> kIntegers(k,0);
//         for(int i=0; i<min(n,m); i++)
//         {
//             if(a[i]<=k)
//             {
//                 kIntegers[a[i]-1]++;
//             }
//             if(b[i]<=k)
//             {
//                 kIntegers[b[i]-1]++;
//             }
//         }

//         bool possible = true;
//         for(int i=0; i<k; i++)
//         {
//             if(kIntegers[i]==0)
//             {
//                 possible = false;
//             }
//         }

//         if(possible)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long int n, m, k;
        cin >> n >> m >> k;

        vector<long int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<long int> b(m);
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        // Sort the arrays if required, not necessary for this problem
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        vector<int> kIntegers(k, 0);

        // Consider the top k/2 elements from both arrays
        for(int i = 0; i < min(n, k / 2); i++)
        {
            if(a[i] <= k) {
                kIntegers[a[i] - 1]++;
            }
        }

        for(int i = 0; i < min(m, k / 2); i++)
        {
            if(b[i] <= k) {
                kIntegers[b[i] - 1]++;
            }
        }

        bool possible = true;
        for(int i = 0; i < k; i++)
        {
            if(kIntegers[i] == 0) {
                possible = false;
                break;
            }
        }

        if(possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
