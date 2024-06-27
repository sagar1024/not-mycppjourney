// B. Quasi Binary

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A number is called quasibinary if its decimal representation contains only digits 0 or 1. For example, numbers 0, 1, 101, 110011 — are quasibinary and numbers 2, 12, 900 are not. You are given a positive integer n. Represent it as a sum of minimum number of quasibinary numbers.

// Input
// The first line contains a single integer n (1 ≤ n ≤ 106).

// Output
// In the first line print a single integer k — the minimum number of numbers in the representation of number n as a sum of quasibinary numbers. In the second line print k numbers — the elements of the sum. All these numbers should be quasibinary according to the definition above, their sum should equal n. Do not have to print the leading zeroes in the numbers. The order of numbers doesn't matter. If there are multiple possible representations, you are allowed to print any of them.

// Examples
// inputCopy
// 9
// outputCopy
// 9
// 1 1 1 1 1 1 1 1 1

// inputCopy
// 32
// outputCopy
// 3
// 10 11 11

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     vector<vector<long long int>> dp(10, vector<long long int>(n));
//     vector<long long int> nDigits;

//     int digitSum = 0;
//     while (n > 0)
//     {
//         nDigits.push_back(n % 10);
//         digitSum += n % 10;
//         n = n / 10;
//     }

//     vector<long long int> answer;
//     while (digitSum)
//     {
//         long long int reqNum = 0;
//         for (int i = 0; i < nDigits.size(); i++)
//         {
//             if (nDigits[i] != 0)
//             {
//                 reqNum += pow(10, i);
//             }
//             else
//             {
//                 string reqString = to_string(reqNum);
//                 reqString += "0";
//                 reqNum = stoi(reqString);
//             }
//         }

//         answer.push_back(reqNum);
//         digitSum -= nDigits.size();
//     }

//     cout << *max_element(nDigits.begin(), nDigits.end()) << endl;
//     for(int i=0; i<answer.size(); i++)
//     {
//         cout << answer[i] << " ";
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<vector<long long int>> dp(10, vector<long long int>(n));
    
    return 0;
}
