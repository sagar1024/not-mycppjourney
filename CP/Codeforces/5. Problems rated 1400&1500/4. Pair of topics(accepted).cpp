// D. Pair of Topics

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The next lecture in a high school requires two topics to be discussed. The i-th topic is interesting by ai units for the teacher and by bi units for the students. The pair of topics i and j (i<j) is called good if ai+aj>bi+bj (i.e. it is more interesting for the teacher). Your task is to find the number of good pairs of topics.

// Input
// The first line of the input contains one integer n (2≤n≤2⋅105) — the number of topics. The second line of the input contains n integers a1,a2,…,an (1≤ai≤109), where ai is the interestingness of the i-th topic for the teacher. The third line of the input contains n integers b1,b2,…,bn(1≤bi≤109), where bi is the interestingness of the i-th topic for the students.

// Output
// Print one integer — the number of good pairs of topic.

// Examples
// inputCopy
// 5
// 4 8 2 6 2
// 4 5 4 1 3
// outputCopy
// 7
// inputCopy
// 4
// 1 3 2 4
// 1 3 2 4
// outputCopy
// 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n), b(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    vector<long long int> diff(n);
    for(int i=0; i<n; i++)
    {
        diff[i] = a[i]-b[i];
    }

    // int count = 0;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=i+1; j<n; j++)
    //     {
    //         if(c[i]+c[j]>0)
    //         {
    //             count++;
    //         }
    //     }
    // }

    sort(diff.begin(), diff.end());
    
    long long int count = 0;
    int left = 0, right = n-1;

    while(left<right)
    {
        if(diff[left]+diff[right]>0)
        {
            count += right - left;
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << count << endl;

    return 0;
}
