// A. Journey Planning

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Tanya wants to go on a journey across the cities of Berland. There are n cities situated along the main railroad line of Berland, and these cities are numbered from 1 to n. Tanya plans her journey as follows. First of all, she will choose some city c1 to start her journey. She will visit it, and after that go to some other city c2>c1, then to some other city c3>c2, and so on, until she chooses to end her journey in some city ck>ck−1. So, the sequence of visited cities [c1,c2,…,ck] should be strictly increasing. There are some additional constraints on the sequence of cities Tanya visits. Each city i has a beauty value bi associated with it. If there is only one city in Tanya's journey, these beauty values imply no additional constraints. But if there are multiple cities in the sequence, then for any pair of adjacent cities ci and ci+1, the condition ci+1−ci=bci+1−bci must hold. For example, if n=8 and b=[3,4,4,6,6,7,8,9], there are several three possible ways to plan a journey:

// c=[1,2,4];
// c=[3,5,6,8];
// c=[7] (a journey consisting of one city is also valid).

// There are some additional ways to plan a journey that are not listed above. Tanya wants her journey to be as beautiful as possible. The beauty value of the whole journey is the sum of beauty values over all visited cities. Can you help her to choose the optimal plan, that is, to maximize the beauty value of the journey?

// Input
// The first line contains one integer n (1≤n≤2⋅105) — the number of cities in Berland. The second line contains n integers b1, b2, ..., bn (1≤bi≤4⋅105), where bi is the beauty value of the i-th city.

// Output
// Print one integer — the maximum beauty of a journey Tanya can choose.

// Examples
// inputCopy
// 6
// 10 7 1 9 10 15
// outputCopy
// 26
// inputCopy
// 1
// 400000
// outputCopy
// 400000
// inputCopy
// 7
// 8 9 26 11 12 29 14
// outputCopy
// 55

// Note
// The optimal journey plan in the first example is c=[2,4,5].
// The optimal journey plan in the second example is c=[1].
// The optimal journey plan in the third example is c=[3,6].

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<int> beauty(n);
//     for(int i=0; i<n; i++) cin >> beauty[i];

//     int maxBeauty = 0;
//     for(int i=0; i<n; i++)
//     {
//         int currSum = beauty[i];
//         int currBeauty = beauty[i];
//         for(int j=i+1; j<n; j++)
//         {
//             if(beauty[j]-currBeauty == j-i)
//             {
//                 currSum += beauty[j];
//                 currBeauty = beauty[j];
//             }
//         }

//         maxBeauty = max(currSum, maxBeauty);
//     }

//     cout << maxBeauty << endl;

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //Mapping the "diff btw the element and its index"
    //With "total sum of elements having same diff"
    unordered_map<int, long long> beautySum;
    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;

        //CRUX of the logic
        beautySum[i - b] += b;
    }

    long long maxBeauty = 0;
    for (auto &[key, value] : beautySum)
    {
        maxBeauty = max(maxBeauty, value);
    }

    cout << maxBeauty << endl;

    return 0;
}
