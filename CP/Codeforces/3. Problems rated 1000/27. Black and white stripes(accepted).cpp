// D. Black and White Stripe

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have a stripe of checkered paper of length n. Each cell is either white or black. What is the minimum number of cells that must be recolored from white to black in order to have a segment of k consecutive black cells on the stripe? If the input data is such that a segment of k consecutive black cells already exists, then print 0.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. Next, descriptions of t test cases follow. The first line of the input contains two integers n and k (1≤k≤n≤2⋅105). The second line consists of the letters 'W' (white) and 'B' (black). The line length is n. It is guaranteed that the sum of values n does not exceed 2⋅105.

// Output
// For each of t test cases print an integer — the minimum number of cells that need to be repainted from white to black in order to have a segment of k consecutive black cells.

// Example
// inputCopy
// 4
// 5 3
// BBWBW
// 5 5
// BBWBW
// 5 1
// BBWBW
// 1 1
// W
// outputCopy
// 1
// 2
// 0
// 1

// Note
// In the first test case, s="BBWBW" and k=3. It is enough to recolor s3 and get s="BBBBW". This string contains a segment of length k=3 consisting of the letters 'B'.
// In the second test case of the example s="BBWBW" and k=5. It is enough to recolor s3 and s5 and get s="BBBBB". This string contains a segment of length k=5 consisting of the letters 'B'.
// In the third test case of the example s="BBWBW" and k=1. The string s already contains a segment of length k=1 consisting of the letters 'B'.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<char> checkeredPaper(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> checkeredPaper[i];
//     }

//     int countB = 0;
//     int totalCountB = 0;
//     int maxCountB = 0;

//     int countW = 0;
//     int totalCountW = 0;
//     int maxCountW = 0;

//     for(int i=0; i<n; i++)
//     {
//         if(checkeredPaper[i]=='B')
//         {
//             countB++;
//             countW = 0;
//             totalCountB += 1;
//             maxCountB = max(countB, maxCountB);
//         }
//         else if(checkeredPaper[i]=='W')
//         {
//             countW++;
//             countB = 0;
//             totalCountW += 1;
//             maxCountW = max(countW, maxCountW);
//         }
//     }

//     cout << max(0, k-maxCountB) << endl;
//     return;
// }

// int main()
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

// void solve()
// {
//     //Length of the checkered paper and the required length of black cells
//     int n, k;
//     cin >> n >> k;

//     //Given checkered paper
//     string s;
//     cin >> s;

//     // vector<char> checkeredPaper(n);
//     // for(int i=0; i<n; i++)
//     // {
//     //     checkeredPaper[i] = s[i];
//     // }

//     //Either find max num of Bs
//     int countB = 0;
//     int maxCountB = INT_MIN;

//     //OR find min num of Ws
//     //int countW = 0;
//     //Initialize minCountW to the maximum possible value
//     //int minCountW = INT_MAX;

//     for(int i=0; i<n-k; i++)
//     {
//         //Setting count to 0 for every new grp of k cells
//         countB = 0;

//         for(int j=i; j<=(i+k-1); j++)
//         {
//             if(s[j]=='B')
//             {
//                 countB++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         //Storing max num of Bs after searching every contiguous grp of k cells
//         maxCountB = max(countB, maxCountB);
//     }

//     cout << max(0, k-maxCountB) << endl;
//     return;
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Calling the function
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <algorithm>
// #include <climits>

// using namespace std;

// void solve()
// {
//     // Length of the checkered paper and the required length of black cells
//     int n, k;
//     cin >> n >> k;

//     // Given checkered paper
//     string s;
//     cin >> s;

//     int countB = 0;
//     int maxCountB = 0;

//     for (int i = 0; i < k; i++)
//     {
//         // Count the initial black cells in the first k characters
//         if (s[i] == 'B')
//         {
//             countB++;
//         }
//     }

//     maxCountB = countB;

//     for (int i = k; i < n; i++)
//     {
//         // Update the count of black cells in the sliding window
//         if (s[i - k] == 'B')
//         {
//             countB--;
//         }
//         if (s[i] == 'B')
//         {
//             countB++;
//         }

//         // Update the maximum count of black cells
//         maxCountB = max(countB, maxCountB);
//     }

//     // Calculate the minimum number of cells that need to be repainted
//     cout << k - maxCountB << endl;
// }

// int main()
// {
//     // Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         // Calling the function
//         solve();
//     }

//     return 0;
// }

// Alternate soln(from editorial) -

// #include <bits/stdc++.h>
// using namespace std;

// #define forn(i, n) for (int i = 0; i < int(n); i++)

// int main()
// {
//     int t;
//     cin >> t;

//     forn(tt, t)
//     {
//         int n, k;
//         cin >> n >> k;

//         string s;
//         cin >> s;

//         vector<int> w(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             w[i] = w[i - 1] + int(s[i - 1] == 'W');
//         }

//         int result = INT_MAX;
//         for (int i = k; i <= n; i++)
//         {
//             result = min(result, w[i] - w[i - k]);
//         }

//         cout << result << endl;
//     }
// }

// Alternate soln(modified) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

int main()
{
    int t;
    cin >> t;

    forn(tt, t)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        //Vector size is n+1 to store a prefix sum array
        //AND also to handle array out of bounds exception
        vector<int> whites(n+1);
        for(int i=1; i<=n; i++)
        {
            //Here the "int(whites[i]=='W')" converts the boolean expression to an integer i.e 0 or 1
            //Positions with whites will have "+1" extra than the positions with blacks
            whites[i] = whites[i-1] + int(s[i-1]=='W');
        }

        //Comparing ad storing the values
        int result = INT_MAX;
        //Iterating through the checkered paper starting from the position k
        //Calculating the minimum recoloring needed
        //By finding the difference between the current prefix sum and the one k positions earlier
        for(int i=k; i<=n; i++)
        {
            result = min(result, whites[i] - whites[i-k]);
        }

        cout << result << endl;
    }
    
    return 0;
}
