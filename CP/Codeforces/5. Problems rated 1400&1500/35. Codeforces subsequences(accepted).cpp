// B. Codeforces Subsequences

// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// Karl likes Codeforces and subsequences. He wants to find a string of lowercase English letters that contains at least k subsequences codeforces. Out of all possible strings, Karl wants to find a shortest one. Formally, a codeforces subsequence of a string s is a subset of ten characters of s that read codeforces from left to right. For example, codeforces contains codeforces a single time, while codeforcesisawesome contains codeforces four times: codeforcesisawesome, codeforcesisawesome, codeforcesisawesome, codeforcesisawesome. Help Karl find any shortest string that contains at least k codeforces subsequences.

// Input
// The only line contains a single integer k (1≤k≤1016).

// Output
// Print a shortest string of lowercase English letters that contains at least k codeforces subsequences. If there are several such strings, print any of them.

// Examples
// inputCopy
// 1
// outputCopy
// codeforces

// inputCopy
// 3
// outputCopy
// codeforcesss

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     long long int k;
//     cin >> k;

//     string ans = "codeforces";
//     for(int i=1; i<=k-1; i++)
//     {
//         ans += "s";
//     }

//     cout << ans << endl;
//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int N = 1e9+7;

int32_t main()
{
    long long int k;
    cin >> k;

    //Word - "codeforces"
    string word = "codeforces";

    //We will increase them one by one, till the product of all their frequencies is greater than k
    vector<long long int> freq(10,1);

    //Finding the minimum frequency required for product to be >= k
    long long int product = 1;
    long long int idx = 0;
    while (product < k)
    {
        //Resetting the product for each cycle of traversal
        // if(idx%10==0)
        // {
        //     product = 1;
        // }

        //Increasing the frequency
        //MOD 10 because we want to standardized the freq index btw 1 and 10
        freq[idx % 10]++;

        //Divide the product by the previous freq
        //AND
        //Multiplying the product by the updated frequency
        product /= freq[idx % 10] - 1;
        product *= freq[idx % 10];

        //Moving to the next character in "codeforces"
        idx++;
    }

    //Constructing the string
    string ans;
    for (int i = 0; i < 10; i++)
    {
        //Repeating each character according to its frequency
        ans += string(freq[i], word[i]);
    }

    cout << ans << endl;
    return 0;
}
