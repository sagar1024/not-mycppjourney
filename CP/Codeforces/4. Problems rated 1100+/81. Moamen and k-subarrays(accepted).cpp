// B. Moamen and k-subarrays

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Moamen has an array of n distinct integers. He wants to sort that array in non-decreasing order by doing the following operations in order exactly once:

// Split the array into exactly k non-empty subarrays such that each element belongs to exactly one subarray.
// Reorder these subarrays arbitrary.
// Merge the subarrays in their new order.

// A sequence a is a subarray of a sequence b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. Can you tell Moamen if there is a way to sort the array in non-decreasing order using the operations written above?

// Input
// The first line contains a single integer t (1≤t≤103) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and k (1≤k≤n≤105). The second line contains n integers a1,a2,…,an (0≤|ai|≤109). It is guaranteed that all numbers are distinct. It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

// Output
// For each test case, you should output a single string. If Moamen can sort the array in non-decreasing order, output "YES" (without quotes). Otherwise, output "NO" (without quotes). You can print each letter of "YES" and "NO" in any case (upper or lower).

// Example
// inputCopy
// 3
// 5 4
// 6 3 4 2 1
// 4 2
// 1 -4 0 -2
// 5 1
// 1 2 3 4 5
// outputCopy
// Yes
// No
// Yes

// Note
// In the first test case, a=[6,3,4,2,1], and k=4, so we can do the operations as follows:

// Split a into {[6],[3,4],[2],[1]}.
// Reorder them: {[1],[2],[3,4],[6]}.
// Merge them: [1,2,3,4,6], so now the array is sorted.

// In the second test case, there is no way to sort the array by splitting it into only 2 subarrays.

// As an example, if we split it into {[1,−4],[0,−2]}, we can reorder them into {[1,−4],[0,−2]} or {[0,−2],[1,−4]}. However, after merging the subarrays, it is impossible to get a sorted array.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         vector<long long int> a(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i];
//         }

//         bool canSort = false;
//         int count = n-(k-1);
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1; j<i+count; j++)
//             {
//                 if(a[j-1]<=a[j])
//                 {
//                     canSort = true;
//                 }
//                 else
//                 {
//                     canSort = false;
//                 }
//             }

//             if(canSort)
//             {
//                 break;
//             }
//         }

//         if(canSort)
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
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        //To keep track of the number of disjoint subsequences in the sorted array
        int ans = 1;
        //Iterating through the sorted vector v starting from the second element (i = 1)
        //For each pair of adjacent elements, it checks if their corresponding indices in the original array are not consecutive
        //If they are not consecutive, it means they belong to different disjoint subsequences, so ans is incremented
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1].second + 1 != v[i].second)
            {
                ans++;
            }
        }

        //Means it's possible to sort the array using k or fewer non-empty subarrays
        cout << (ans <= k ? "YES" : "NO") << endl;
    }

    return 0;
}
