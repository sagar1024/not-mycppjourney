// D. Remove One Element

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a consisting of n integers. You can remove at most one element from this array. Thus, the final length of the array is n−1or n. Your task is to calculate the maximum possible length of the strictly increasing contiguous subarray of the remaining array. Recall that the contiguous subarray a with indices from l to r is a[l…r]=al,al+1,…,ar. The subarray a[l…r] is called strictly increasing if al<al+1<⋯<ar.

// Input
// The first line of the input contains one integer n (2≤n≤2⋅105) — the number of elements in a. The second line of the input contains n integers a1,a2,…,an (1≤ai≤109), where ai is the i-th element of a.

// Output
// Print one integer — the maximum possible length of the strictly increasing contiguous subarray of the array a after removing at most one element.

// Examples
// inputCopy
// 5
// 1 2 5 3 4
// outputCopy
// 4
// inputCopy
// 2
// 1 2
// outputCopy
// 2
// inputCopy
// 7
// 6 5 4 3 2 4 3
// outputCopy
// 2

// Note

// In the first example, you can delete a3=5. Then the resulting array will be equal to [1,2,3,4] and the length of its largest increasing subarray will be equal to 4.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long int> givenArray(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> givenArray[i];
//     }

//     //MAIN logic
//     int maxLen = 0;
//     int currLen = 0;

//     //Without removing any element
//     for(int i=0; i<n; i++)
//     {
//         maxLen = 0;
//         currLen = 0;
//         for(int j=i+1; j<n; j++)
//         {
//             if(givenArray[j-1]<givenArray[j])
//             {
//                 currLen++;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         maxLen = max(currLen, maxLen);
//     }

//     //Removing one element
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             maxLen = 0;
//             currLen = 0;
//             for(int k=j+1; k<n; k++)
//             {
//                 if(givenArray[k-1]<givenArray[k])
//                 {
//                     currLen++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }

//             maxLen = max(currLen, maxLen);
//         }
//     }

//     cout << maxLen << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n;
    cin >> n;

    vector<long long int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    //MAIN logic
    //Basically we will create two arrays left and right
    //Array left will keep track of increasing elements from left
    //Array right will keep track of the inc elements from right
    //Then we will iterate over the initial array to check if a[i-1]<a[i+1]
    //If yes, then we will add the contiguous increasing elements from both sides
    //From the left as well as from the right wrt the element

    //Two vectors - left and right of size n
    //Here ri means the maximum length of the increasing sequence starting in the position i, and li means the maximum length of the increasing sequence ending in the position i
    //Initially, all 2n values are 1 (the element itself).
    //The array r can be calculated in order from right to left with the following condition: if ai<ai+1 then ri=ri+1+1, otherwise it still remain 1
    //The same with the array l, but we have to calculate its values in order from left to right, and if ai>ai−1 then li=li−1+1, otherwise it still remain 1
    long long int ans = 1;
    vector<long long int> left(n,1), right(n,1);
    for(int i=1; i<n; i++)
    {
        if(givenArray[i-1]<givenArray[i])
        {
            left[i] = left[i-1]+1; //All elements of array left(and right) are initially 1s
        }

        //Updating the ans by the max length of contiguous increasing elements
        ans = max(left[i], ans);
    }
    for(int i=n-2; i>=0; i--)
    {
        if(givenArray[i+1]>givenArray[i])
        {
            right[i] = right[i+1]+1;
        }

        ans = max(right[i], ans);
    }

    //CRUX
    //The initial answer (if we don't remove any element) is the maximum value of the array l(left)
    //And if we remove the i-th element(where i=2…n−1), then we can update the answer with the value li−1+ri+1 if ai−1<ai+1
    for(int i=1; i<n-1; i++)
    {
        if(givenArray[i-1]<givenArray[i+1])
        {
            ans = max(left[i-1]+right[i+1], ans);
        }
    }

    cout << ans << endl;
    return;
}

int32_t main()
{
    fastio;
    solve();

    return 0;
}
