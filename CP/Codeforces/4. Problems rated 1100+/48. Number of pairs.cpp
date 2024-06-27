// C. Number of Pairs

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a of n integers. Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r). For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

// i=1 and j=2 (4≤5+1≤7);
// i=1 and j=3 (4≤5+2≤7).

// Input
// The first line contains an integer t (1≤t≤104). Then t test cases follow. The first line of each test case contains three integers n,l,r (1≤n≤2⋅105, 1≤l≤r≤109) — the length of the array and the limits on the sum in the pair. The second line contains n integers a1,a2,…,an (1≤ai≤109). It is guaranteed that the sum of n overall test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the number of index pairs (i,j) (i<j), such that l≤ai+aj≤r.

// Example
// inputCopy
// 4
// 3 4 7
// 5 1 2
// 5 5 8
// 5 1 2 4 3
// 4 100 1000
// 1 1 1 1
// 5 9 13
// 2 5 5 1 1

// outputCopy
// 2
// 7
// 0
// 1

// My original soln(memory limit exceeded) -

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
//         long long int n;
//         long long int l, r;
//         cin >> n >> l >> r;

//         vector<long long int> givenInts(n);
//         for(long long int i=0; i<n; i++)
//         {
//             cin >> givenInts[i];
//         }

//         //MAIN logic
//         //Storing the sum of all possible pairs
//         vector<long long int> allPairs;

//         for(long long int i=0; i<n; i++)
//         {
//             for(long long int j=i; j<n; j++)
//             {
//                 if(i!=j)
//                 {
//                     allPairs.push_back(givenInts[i]+givenInts[j]);
//                 }
//             }
//         }

//         long long int count = 0;
//         for(int i=0; i<allPairs.size(); i++)
//         {
//             if(allPairs[i]>=l && allPairs[i]<=r)
//             {
//                 count++;
//             }
//         }

//         cout << count << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         //Inputs
//         int n;
//         long long l, r;
//         cin >> n >> l >> r;

//         vector<long long> givenIntegers(n);
//         for (int i = 0; i < n; ++i)
//         {
//             cin >> givenIntegers[i];
//         }

//         //MAIN logic
//         sort(givenIntegers.begin(), givenIntegers.end());

//         long long count = 0;

//         //Two pointers approach
//         for (int i = 0; i < n; ++i)
//         {
//             //Finding the index of the largest number whose sum with a[i] is less than or equal to r
//             //Here, upper_bound() function to find the index of the largest element that is less than or equal to r - a[i]
//             int idx = upper_bound(givenIntegers.begin(), givenIntegers.end(), r - givenIntegers[i]) - givenIntegers.begin();

//             //Adjusting the index
//             //Decreasing by 1 to exclude a[i] itself
//             --idx;

//             //Adding pairs to count
//             //If the adjusted index idx is greater than i
//             //It means there are valid pairs with the sum falling within the range [l, r]
//             if (idx > i)
//             {
//                 count += idx - i;
//             }
//         }

//         cout << count << endl;
//     }

//     return 0;
// }

// Alternate soln -

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
//         long long int n, l, r;
//         cin >> n >> l >> r;

//         //Given array
//         vector<long long int> elements(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> elements[i];
//         }

//         //MAIN logic
//         //To store the num of pairs whose sum is less than r
//         int countR = 0;
//         //To store the num of pairs whose sum is less than l-1
//         int countL = 0;

//         //For "each" pair
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 //Element can NOT make a pair with itself
//                 if(i!=j)
//                 {
//                     if(elements[i]+elements[j]<=r)
//                     {
//                         countR++;
//                     }
//                     if(elements[i]+elements[j]<=(l-1))
//                     {
//                         countL++;
//                     }
//                 }
//             }
//         }

//         //Output
//         cout << (countR-countL)/2 << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long count = 0;

        for (int i = 0; i < n; ++i)
        {
            int left = i, right = n - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (a[i] + a[mid] >= l && a[i] + a[mid] <= r)
                {
                    count += (mid - i);
                    break;
                }
                else if (a[i] + a[mid] < l)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
