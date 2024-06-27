// C. Social Distance

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp and his friends want to visit a new restaurant. The restaurant has n tables arranged along a straight line. People are already sitting at some tables. The tables are numbered from 1 to n in the order from left to right. The state of the restaurant is described by a string of length n which contains characters "1" (the table is occupied) and "0" (the table is empty). Restaurant rules prohibit people to sit at a distance of k or less from each other. That is, if a person sits at the table number i, then all tables with numbers from i−k to i+k (except for the i-th) should be free. In other words, the absolute difference of the numbers of any two occupied tables must be strictly greater than k. For example, if n=8 and k=2, then:

// strings "10010001", "10000010", "00000000", "00100000" satisfy the rules of the restaurant;
// strings "10100100", "10011001", "11111111" do not satisfy to the rules of the restaurant, since each of them has a pair of "1" with a distance less than or equal to k=2.

// In particular, if the state of the restaurant is described by a string without "1" or a string with one "1", then the requirement of the restaurant is satisfied. You are given a binary string s that describes the current state of the restaurant. It is guaranteed that the rules of the restaurant are satisfied for the string s. Find the maximum number of free tables that you can occupy so as not to violate the rules of the restaurant. Formally, what is the maximum number of "0" that can be replaced by "1" such that the requirement will still be satisfied? For example, if n=6, k=1, s="100010", then the answer to the problem will be 1, since only the table at position 3 can be occupied such that the rules are still satisfied.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases in the test. Then t test cases follow. Each test case starts with a line containing two integers n and k (1≤k≤n≤2⋅105) — the number of tables in the restaurant and the minimum allowed distance between two people. The second line of each test case contains a binary string s of length n consisting of "0" and "1" — a description of the free and occupied tables in the restaurant. The given string satisfy to the rules of the restaurant — the difference between indices of any two "1" is more than k. The sum of n for all test cases in one test does not exceed 2⋅105.

// Output
// For each test case output one integer — the number of tables that you can occupy so as not to violate the rules of the restaurant. If additional tables cannot be taken, then, obviously, you need to output 0.

// Example
// inputCopy
// 6
// 6 1
// 100010
// 6 2
// 000000
// 5 1
// 10101
// 3 1
// 001
// 2 2
// 00
// 1 1
// 0
// outputCopy
// 1
// 2
// 0
// 1
// 1
// 1

// Note
// The first test case is explained in the statement.
// In the second test case, the answer is 2, since you can choose the first and the sixth table.
// In the third test case, you cannot take any free table without violating the rules of the restaurant.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define lli long long int
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++){}

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     int count1 = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='1')
//         {
//             count1++;
//         }
//     }

//     //int answer = ceil(static_cast<float>(n/(k+1))) - count1;
//     int occupiable_tables = ceil(static_cast<float>(n) / (k + 1));
//     int additional_tables = max(0, occupiable_tables - count1);

//     cout << additional_tables << endl;

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

// void solve()
// {
//     //Inputs
//     int n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     //MAIN logic
//     int total_seats = 0;
//     //Init with -1
//     int block_start = -1;
//     for (int i = 0; i < n; ++i)
//     {
//         //The first "0" will indicate the start of a new block of 0s
//         if (s[i] == '0')
//         {
//             if (block_start == -1)
//             {
//                 block_start = i;
//             }
//         }
//         //If the block has more than one 0s then the following else part will be executed
//         else
//         {
//             //Checking the condition once again, whether the block has started or not
//             if (block_start != -1)
//             {
//                 //Size of the block will be the diff btw its first and last indexes 
//                 int block_size = i - block_start;

//                 //If the block is left most block of the string
//                 //There is "1" right at the end of this block so "k" zeros must be neglected
//                 //And the remaning will be counted
//                 if (block_start == 0)
//                 {
//                     block_size -= k;
//                 }
//                 //If the block is the right most block
//                 //There is "1" at the front of the block so "k" zeros must be ignored
//                 //And add the remaining zeros
//                 else if (i == n)
//                 {
//                     block_size -= k;
//                 }
//                 //If the block is one of the middle blocks
//                 //Remove "k" from both sides
//                 else
//                 {
//                     block_size -= 2 * k;
//                 }

//                 //Count total num of seats which are occupiable while maintaining the rule
//                 //Here "block_size + k" is another way of applying the ceil() function
//                 total_seats += max(0, (block_size + k) / (k + 1));

//                 //Resetting
//                 block_start = -1;
//             }
//         }
//     }

//     // Handling the case of a string consisting only of zeros
//     if (block_start != -1)
//     {
//         total_seats += max(0, (n - block_start + k) / (k + 1));
//     }

//     //Outputs
//     cout << total_seats << endl;

//     return;
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         //Function call
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        //Dynamic programming
        vector<int> dp;
        int count = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
            {
                dp.push_back(count);
                i++;
                count = 0;
            }
            if(s[i]=='0')
            {
                count++;
                if(i==s.size()-1)
                {
                    dp.push_back(count);
                }
            }

            //All zeros
            if(count==n)
            {
                cout << (n+k)/(k+1) << endl;
                break;
            }
        }

        //Next loop
        if(count==n)
        {
            continue;
        }

        int answer = 0;
        for(int i=0; i<dp.size(); i++)
        {
            if(dp[i]>0)
            {
                answer += dp[i]/(k+1);
            }
        }

        //Output
        cout << max(0, answer) << endl;;
    }
    
    return 0;
}
