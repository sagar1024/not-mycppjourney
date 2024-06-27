// B. Sorted Adjacent Differences

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have array of n numbers a1,a2,…,an. Rearrange these numbers to satisfy |a1−a2|≤|a2−a3|≤…≤|an−1−an|, where |x| denotes absolute value of x. It's always possible to find such rearrangement. Note that all numbers in a are not necessarily different. In other words, some numbers of a may be same. You have to answer independent t test cases.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains single integer n (3≤n≤105) — the length of array a. It is guaranteed that the sum of values of n over all test cases in the input does not exceed 105. The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109).

// Output
// For each test case, print the rearranged version of array a which satisfies given condition. If there are multiple valid rearrangements, print any of them.

// Example
// inputCopy
// 2
// 6
// 5 -2 4 8 6 5
// 4
// 8 1 4 2

// outputCopy
// 5 5 4 6 8 -2
// 1 2 4 8

// Note
// In the first test case, after given rearrangement, |a1−a2|=0≤|a2−a3|=1≤|a3−a4|=2≤|a4−a5|=2≤|a5−a6|=10. There are other possible answers like "5 4 5 6 -2 8".
// In the second test case, after given rearrangement, |a1−a2|=1≤|a2−a3|=2≤|a3−a4|=4. There are other possible answers like "2 4 8 1".

// My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long int> elements(n);
        for (int i = 0; i < n; i++)
        {
            cin >> elements[i];
        }

        // MAIN logic
        // Sorting the array
        sort(elements.begin(), elements.end());

        //Rearrange the array such that adjacent differences are sorted
        vector<long long int> answer(n,0);
        int  mid = (n+1)/2;
        int left = mid-1, right = mid+1;
        for (int i = 0; i < n; i++)
        {
            if(i==0)
            {
                answer[mid-1] = elements[0];
            }
            else if (i % 2 == 0)
            {
                answer[left-1] = elements[i];
                left--;
            }
            else
            {
                answer[right-1] = elements[i];
                right++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
