// C. Divisibility by Eight

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a non-negative integer n, its decimal representation consists of at most 100 digits and doesn't contain leading zeroes. Your task is to determine if it is possible in this case to remove some of the digits (possibly not remove any digit at all) so that the result contains at least one digit, forms a non-negative integer, doesn't have leading zeroes and is divisible by 8. After the removing, it is forbidden to rearrange the digits. If a solution exists, you should print it.

// Input
// The single line of the input contains a non-negative integer n. The representation of number n doesn't contain any leading zeroes and its length doesn't exceed 100 digits.

// Output
// Print "NO" (without quotes), if there is no such way to remove some digits from number n. Otherwise, print "YES" in the first line and the resulting number after removing digits from number n in the second line. The printed number must be divisible by 8. If there are multiple possible answers, you may print any of them.

// Examples
// inputCopy
// 3454
// outputCopy
// YES
// 344
// inputCopy
// 10
// outputCopy
// YES
// 0
// inputCopy
// 111111
// outputCopy
// NO

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     //Inputs
//     string s;
//     cin >> s;

//     int n = s.size();

//     string answer;

//     //int currentDigits = 0;
//     bool divisible = false;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             for(int k=0; k<n; k++)
//             {
//                 //Number can be divided by eight if and only if its last three digits form a number that can be divided by eight
//                 //check += s[i]+s[j]+s[k];
//                 // currentDigits = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
//                 // if(currentDigits%8==0)
//                 // {
//                 //     answer = currentDigits;
//                 //     divisible = true;
//                 //     break;
//                 // }

//                 string num = "";
//                 num += s[i];
//                 num += s[j];
//                 num += s[k];
                
//                 int digits = stoi(num);
//                 if (digits % 8 == 0)
//                 {
//                     divisible = true;
//                     answer = num;
//                     break;
//                 }
//             }
//             if(divisible)
//             {
//                 break;
//             }
//         }
//         if(divisible)
//         {
//             break;
//         }
//     }

//     //Outputs
//     if(divisible)
//     {
//         cout << "YES" << endl;
//         cout << answer << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// const int N = 105;
// bool dp[N][8];
// int previous[N][8];

// int32_t main()
// {
//     string s;
//     cin >> s;

//     int n = s.size();

//     //Initialization
//     memset(previous, -1, sizeof(previous));
//     //The remainder obtained by considering only the first digit of s is achievable.
//     dp[0][(s[0] - '0') % 8] = true;

//     //Dynamic programming
//     for(int i=1; i<n; i++)
//     {
//         int digit = s[i]-'0';
//         dp[i][digit%8] = true;

//         for(int j=0; j<8; j++)
//         {
//             if(dp[i-1][j])
//             {
//                 int new_mod = (j * 10 + digit) % 8;
//                 dp[i][new_mod] = true;
//                 previous[i][new_mod] = j;

//                 dp[i][j] = true;
//                 previous[i][j] = j;
//             }
//         }
//     }

//     //Finding the divisible number
//     for (int i = 0; i < n; ++i)
//     {
//         if (dp[i][0])
//         {
//             string ans = "";
//             int curI = i, curJ = 0;

//             while (true)
//             {
//                 if (previous[curI][curJ] == -1 || previous[curI][curJ] != curJ)
//                 {
//                     ans.push_back(s[curI]);
//                 }

//                 if (previous[curI][curJ] == -1) break;

//                 curJ = previous[curI][curJ];
//                 --curI;
//             }

//             //Output
//             cout << "YES" << endl;
//             reverse(ans.begin(), ans.end());
//             cout << ans << endl;

//             return 0;
//         }
//     }

//     //No solution found
//     cout << "NO" << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    //Inputs
    string s;
    cin >> s;

    int n = s.size();

    //For one digit
    for(int i=0; i<n; i++)
    {
        if(s[i]=='0' || s[i]=='8')
        {
            cout << "YES" << endl;
            cout << s[i] << endl;
            return 0;
        }
    }

    //For two digits
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            string s2;
            //s2 += (s[i]-'0') + (s[j]-'0');
            s2 += s[i];
            s2 += s[j];
            int digit2 = stoi(s2);
            if(digit2%8==0)
            {
                cout << "YES" << endl;
                cout << digit2 << endl;
                return 0;
            }
        }
    }

    //For three digits
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                string s3;
                //s3 += (s[i]-'0') + (s[j]-'0') + (s[k]-'0');
                s3 += s[i];
                s3 += s[j];
                s3 += s[k];
                int digit3 = stoi(s3);
                if(digit3%8==0)
                {
                    cout << "YES" << endl;
                    cout << digit3 << endl;
                    return 0;
                }
            }
        }
    }

    //IF none of the conditions turned out to be true
    cout << "NO" << endl;
    return 0;
}
