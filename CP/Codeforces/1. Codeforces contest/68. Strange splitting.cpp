// A. Strange Splitting

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Define the range of a non-empty array to be the maximum value minus the minimum value. For example, the range of [1,4,2] is 4−1=3. You are given an array a1,a2,…,an of length n≥3. It is guaranteed a is sorted. You have to color each element of a red or blue so that:

// the range of the red elements does not equal the range of the blue elements, and
// there is at least one element of each color.

// If there does not exist any such coloring, you should report it.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases. The first line of each test case contains an integer n (3≤n≤50) — the length of the array. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109). It is guaranteed a1≤a2≤…≤an−1≤an.

// Output
// For each test case, if it is impossible to color a to satisfy all the constraints, output NO. Otherwise, first output YES. Then, output a string s of length n. For 1≤i≤n, if you color ai red, si should be R. For 1≤i≤n, if you color ai blue, si should be B.

// Example
// inputCopy
// 7
// 4
// 1 1 2 2
// 5
// 1 2 3 4 5
// 3
// 3 3 3
// 4
// 1 2 2 2
// 3
// 1 2 2
// 3
// 1 1 2
// 3
// 1 9 84
// outputCopy
// YES
// RBRR
// YES
// BBRBB
// NO
// YES
// RBBR
// YES
// RRB
// YES
// BRR
// YES
// BRB

// Note
// In the first test case, given the array [1,1,2,2], we can color the second element blue and the remaining elements red; then the range of the red elements [1,2,2] is 2−1=1, and the range of the blue elements [1] is 1−1=0.
// In the second test case, we can color the first, second, fourth and fifth elements [1,2,4,5] blue and the remaining elements [3] red. The range of the red elements is 3−3=0 and the range of the blue elements is 5−1=4, which are different.
// In the third test case, it can be shown there is no way to color a=[3,3,3] to satisfy the constraints.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     bool allEqual = true;
//     for(int i=1; i<n; i++)
//     {
//         if(a[i-1]!=a[i])
//         {
//             allEqual = false;
//         }
//     }

//     if(allEqual)
//     {
//         cout << "NO" << endl;
//     }
//     else
//     {
//         cout << "YES" << endl;

//         string ans;
//         for(int i=0; i<n; i++)
//         {
//             if(i==0 || i==n-1)
//             {
//                 ans += 'R';
//             }
//             else
//             {
//                 ans += 'B';
//             }
//         }
//         cout << ans << endl;
//     }

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

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool allEqual = true;
    unordered_set<int> st;
    vector<int> freq(1000000009);
    for (int i = 1; i < n; i++)
    {
        st.insert(a[i]);
        freq[a[i]]++;
        if (a[i] != a[0])
        {
            allEqual = false;
            break;
        }
    }

    if (allEqual)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        string s(n, 'B');

        //Coloring the first part 'R' until we reach an element different from the first one
        s[0] = 'R';
        if(st.size()==2)
        {
            //Write the code to make the element red which occurs more than the other one

        }
        if (st.size() > 2)
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i] != a[0])
                {
                    s[i] = 'B';
                    break;
                }
                s[i] = 'R';
            }
        }

        cout << s << endl;
    }

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
