// F. Equalize the Array

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp was gifted an array a of length n. Polycarp considers an array beautiful if there exists a number C, such that each number in the array occurs either zero or C times. Polycarp wants to remove some elements from the array a to make it beautiful. For example, if n=6 and a=[1,3,2,1,4,2], then the following options are possible to make the array a array beautiful:

// Polycarp removes elements at positions 2 and 5, array a becomes equal to [1,2,1,2];
// Polycarp removes elements at positions 1 and 6, array a becomes equal to [3,2,1,4];
// Polycarp removes elements at positions 1,2 and 6, array a becomes equal to [2,1,4];

// Help Polycarp determine the minimum number of elements to remove from the array a to make it beautiful.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow. The first line of each test case consists of one integer n (1≤n≤2⋅105) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — array a. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer — the minimum number of elements that Polycarp has to remove from the array a to make it beautiful.

// Example
// inputCopy
// 3
// 6
// 1 3 2 1 4 2
// 4
// 100 100 4 100
// 8
// 1 2 3 3 3 2 6 6

// outputCopy
// 2
// 1
// 2

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     vector<int> freq(1000000009);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         freq[a[i]]++;
//     }

//     int minCount = 0;
//     int freqLen = freq.size();
//     freq.resize(freqLen);
//     for(int i=0; i<n; i++)
//     {
//         int currCount = 0;
//         for(int j=0; j<freqLen; j++)
//         {
//             if(freq[j]>=a[i]) currCount += freq[j] - a[i];
//             else currCount += freq[j];
//         }

//         minCount = min(currCount, minCount);
//     }

//     cout << minCount << endl;
//     return;
// }

// int32_t main()
// {
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
// const int N = 1000000009;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> a(n);
//     unordered_map<int,int> freq;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         freq[a[i]]++;
//     }

//     //Freq of frequencies
//     unordered_map<int,int> freqq;
//     for(const auto &pair: freq)
//     {
//         freqq[pair.second]++;
//     }

//     //Creating a vector of pairs to store the freqq and sort it
//     vector<pair<int,int>> freqqVec(freqq.begin(), freqq.end());
//     sort(freqqVec.begin(), freqqVec.end());

//     //Calc the minimum deletions
//     int minRemovals = n;
//     int totalElements = n;
//     int elementsToBeRemoved = 0;
//     for(const auto& [freqq,freqqqq]: freqqVec)
//     {
//         minRemovals = min(totalElements-freqq*freqqqq-elementsToBeRemoved, minRemovals);
//         elementsToBeRemoved += freqq*freqqqq;
//     }

//     cout << minRemovals << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> frequencyCount;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        frequencyCount[x]++;
    }

    //Frequency of frequencies
    map<int, int> countOfFrequencies;
    for (const auto &[value, count] : frequencyCount)
    {
        countOfFrequencies[count]++;
    }

    //Calc the minimum deletions
    int minDeletions = n;
    int leftSum = 0;
    int rightSum = n;
    int uniqueFrequencies = frequencyCount.size();
    for (const auto &[freq, count] : countOfFrequencies)
    {
        minDeletions = min(minDeletions, leftSum + rightSum - uniqueFrequencies * freq);
        leftSum += freq * count;
        rightSum -= freq * count;
        uniqueFrequencies -= count;
    }

    cout << minDeletions << endl;

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    
    return 0;
}
