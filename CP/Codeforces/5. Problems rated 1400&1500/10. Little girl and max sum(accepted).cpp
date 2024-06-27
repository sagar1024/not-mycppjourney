// C. Little Girl and Maximum Sum

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The little girl loves the problems on array queries very much. One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1≤li≤ri≤n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive. The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.

// Input
// The first line contains two space-separated integers n (1≤n≤2⋅105) and q (1≤q≤2⋅105) — the number of elements in the array and the number of queries, correspondingly. The next line contains n space-separated integers ai (1≤ai≤2⋅105) — the array elements. Each of the following q lines contains two space-separated integers li and ri (1≤li≤ri≤n) — the i-th query.

// Output
// In a single line print, a single integer — the maximum sum of query replies after the array elements are reordered. Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Examples
// inputCopy
// 3 3
// 5 3 2
// 1 2
// 2 3
// 1 3
// outputCopy
// 25
// inputCopy
// 5 3
// 5 2 4 1 3
// 1 5
// 2 3
// 2 3
// outputCopy
// 33

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     //Inputs
//     int n, q;
//     cin >> n >> q;

//     vector<int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     //Reverse sort
//     sort(givenArray.begin(), givenArray.end(), greater<int>());

//     vector<pair<int,int>> freq(n+1, {0,0});
//     for(int i=0; i<q; i++)
//     {
//         int a, b;
//         cin >> a >> b;

//         freq[i].first = i;

//         //Storing the freq of each number coming under the range(of each query)
//         for(int j=a; j<b; j++)
//         {
//             freq[j].second++;
//         }
//     }

//     //How do I reverse sort the freq array on the basis of its second element?
//     //Sorting freq array based on the frequency
//     sort(freq.begin(), freq.end(), [](const pair<int,int>& a, const pair<int,int>& b)
//     {
//         return a.second > b.second;
//     });

//     //Calculating the max Sum
//     //First q elements multiplied by their freq will give the req maxSum
//     int maxSum = 0;
//     for(int i = 0; i < q; i++)
//     {
//         maxSum += givenArray[freq[i].first] * freq[i].second;
//     }

//     //Outputs
//     cout << maxSum << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     //Inputs
//     int n, q;
//     cin >> n >> q;

//     vector<int> givenArray(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     //Reverse sort the given array
//     sort(givenArray.begin(), givenArray.end(), greater<int>());

//     //Initialize frequency array with zeros
//     vector<int> freq(n + 1, 0);

//     //Calculate frequency of elements in query ranges
//     for (int i = 0; i < q; i++)
//     {
//         int a, b;
//         cin >> a >> b;

//         //Storing the freq of each number coming under the range (of each query)
//         for(int j=a; j<=b; j++)
//         {
//             freq[j]++;
//         }
//     }

//     //Reverse sort the freq array
//     sort(freq.begin(), freq.end(), greater<int>());

//     int maxSum = 0;
//     for(int i=0; i<n; i++)
//     {
//         maxSum += givenArray[i]*freq[i];
//     }

//     //Output
//     cout << maxSum << endl;

//     return;
// }

// int main()
// {
//     solve();
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    //Inputs
    int n, q;
    cin >> n >> q;

    vector<int> givenArray(n);
    for (int i = 0; i < n; i++)
    {
        cin >> givenArray[i];
    }

    //Sorting the given array
    sort(givenArray.begin(), givenArray.end(), greater<int>());

    //Initializing frequency array with zeros
    vector<int> freq(n + 1, 0);

    //Calculating frequency of elements in query ranges
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        //Incrementing frequency of starting index
        freq[a - 1]++;
        //Decrementing frequency of next index if within array bounds
        if (b < n) freq[b]--;
    }

    //Calculating cumulative frequencies
    for (int i = 1; i < n; i++)
    {
        freq[i] += freq[i - 1];
    }

    //Sorting the frequencies in descending order
    sort(freq.begin(), freq.end(), greater<int>());

    //Calculating maximum sum
    long long maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += (long long)givenArray[i] * freq[i];
    }

    //Output
    cout << maxSum << endl;
}

int main()
{
    //Calling the func
    solve();
    return 0;
}
