// C. LR-remainders

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a of length n, a positive integer m, and a string of commands of length n. Each command is either the character 'L' or the character 'R'. Process all n commands in the order they are written in the string s. Processing a command is done as follows:

// First, output the remainder of the product of all elements of the array a when divided by m.
// Then, if the command is 'L', remove the leftmost element from the array a, if the command is 'R', remove the rightmost element from the array a.

// Note that after each move, the length of the array a decreases by 1, and after processing all commands, it will be empty. Write a program that will process all commands in the order they are written in the string s (from left to right).

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases in the input. Then descriptions of t test cases follow. Each test case of the input is given by three lines. The first line contains two integers n and m (1≤n≤2⋅105,1≤m≤104) — the initial length of the array a and the value to take the remainder by. The second line contains n integers a1,a2,…,an (1≤ai≤104) — the elements of the array a. The third line contains a string s consisting of n characters 'L' and 'R'. It is guaranteed that the sum of the values of n for all test cases in a test does not exceed 2⋅105.

// Output
// For each test case, output n integers b1,b2,…,bn, where bi is the remainder when dividing the product of all elements of the current state of the array a by m at the beginning of the execution of the i-th command.

// Example
// inputCopy
// 4
// 4 6
// 3 1 4 2
// LRRL
// 5 1
// 1 1 1 1 1
// LLLLL
// 6 8
// 1 2 3 4 5 6
// RLLLRR
// 1 10000
// 10000
// R
// outputCopy
// 0 2 4 1
// 0 0 0 0 0
// 0 0 0 4 4 4
// 0

// Note

// In the first test case of the example:
// 3⋅1⋅4⋅2mod6=24mod6=0;
// s1=L, so we remove the first element and get the array [1,4,2];
// 1⋅4⋅2mod6=8mod6=2;
// s2=R, so we remove the last element and get the array [1,4];
// 1⋅4mod6=4mod6=4;
// s3=R, so we remove the last element and get the array [1];
// 1mod6=1;
// s4=L, so we remove the first element and get an empty array.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;

//         vector<int> elements(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> elements[i];
//         }

//         string s;
//         cin >> s;

//         vector<int> result;

//         int l = 0;
//         int r = n-1;
//         int product = 1;

//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i]=='L')
//             {
//                 for (int j = 0; j < elements.size(); j++)
//                 {
//                     product *= elements[j];
//                 }
//                 result.push_back(product);
//                 product = 1;

//                 //Delete first element from the array
//                 elements.erase(elements[i]);
//                 l++;
//             }
//             else if(s[i]=='R')
//             {
//                 for(int j=0; j<elements.size(); j++)
//                 {
//                     product *= elements[j];
//                 }
//                 result.push_back(product);
//                 product = 1;

//                 //Delete last element from the array
//                 elements.erase(elements[i]);
//                 r--;
//             }
//         }

//         for(int i=0; i<result.size(); i++)
//         {
//             cout << result[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        vector<long long int> elements(n);
        for (long long int i = 0; i < n; i++)
        {
            cin >> elements[i];
        }

        string s;
        cin >> s;

        vector<long long int> result;

        long long int l = 0;
        long long int r = n - 1;

        for (long long int i = 0; i < s.size(); i++)
        {
            long long int product = 1; //Reset product for each command
            for (long long int j = l; j <= r; j++)
            {
                //Loop through elements within the current bounds
                product *= elements[j];
            }

            long long int x = product % m;
            result.push_back(x);

            if (s[i] == 'L')
            {
                l++;
            }
            else if (s[i] == 'R')
            {
                r--;
            }
        }

        for (long long int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
