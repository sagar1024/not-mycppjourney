// C. Given Length and Sum of Digits

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You have a positive integer m and a non-negative integer s. Your task is to find the smallest and the largest of the numbers that have length m and sum of digits s. The required numbers should be non-negative integers written in the decimal base without leading zeroes.

// Input
// The single line of the input contains a pair of integers m, s (1 ≤ m ≤ 100, 0 ≤ s ≤ 900) — the length and the sum of the digits of the required numbers.

// Output
// In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1" (without the quotes).

// Examples
// inputCopy
// 2 15
// outputCopy
// 69 96

// inputCopy
// 3 0
// outputCopy
// -1 -1

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Length of the digit
//     //AND
//     //Req sum
//     int m, s;
//     cin >> m >> s;

//     if(s==0)
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }
//     if(m==1 && (s<1 || s>10))
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }

//     //NOTE
//     //Now "s" and "m" are >= 2

//     //MAIN logic
//     //Finding the smallest num with the req sum
//     int reqNum = 0;
//     int digitSum = 0;

//     // for(int i=pow(10,m); i<pow(10,m+1); i++)
//     // {
//     //     int lastDigit = i%10;
//     //     digitSum += lastDigit

//     //     if(digitSum==s)
//     //     {
//     //         break;
//     //     }
//     // }

//     while(s>0)
//     {
//         for(int i=9; i>=1; i--)
//         {
//             if(s>i)
//             {
//                 s = s-i;
//                 if(reqNum==0)
//                 {
//                     reqNum = i;
//                 }
//                 else
//                 {
//                     reqNum = reqNum + i*10;
//                 }
//             }
//         }
//     }

//     //Reversing the smallest num to get the largest num
//     string reverseNum = reqNum + "";
//     reverse(reverseNum.begin(), reverseNum.end());

//     cout << reqNum << " " << reverseNum << endl;

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Length of the digit
//     //AND
//     //Req sum
//     int m, s;
//     cin >> m >> s;

//     //MAIN logic
//     if(s==0)
//     {
//         //Special case: Smallest and largest numbers are both 0
//         if(m==1)
//         {
//             cout << "0 0" << endl;
//             return 0;
//         }
//         else
//         {
//             cout << "-1 -1" << endl;
//             return 0;
//         }
//     }

//     //For the smallest number
//     string largestNum;
//     for(int i=0; i<m; ++i)
//     {
//         int digit = min(s, 9); //Take the minimum of s and 9
//         largestNum += (char)(digit+'0');
//         s -= digit;
//     }

//     //If s is not 0 after constructing the smallest number, then not possible
//     if(s!=0)
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }

//     //Reverse the smallest number to get the largest number
//     string reverseNum = largestNum;
//     reverse(reverseNum.begin(), reverseNum.end());

//     cout << reverseNum << " " << largestNum<< endl;

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <string>

// using namespace std;

// bool can(int m, int s)
// {
//     return s >= 0 && s <= 9 * m;
// }

// int main()
// {
//     int m, s;
//     cin >> m >> s;

//     // For the smallest number
//     string minn;
//     int sum = s;
//     for (int i = 0; i < m; i++)
//     {
//         for (int d = 0; d < 10; d++)
//         {
//             if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
//             {
//                 minn += char('0' + d);
//                 sum -= d;

//                 break;
//             }
//         }
//     }

//     // If sum is not 0 after constructing the smallest number, then not possible
//     if (sum != 0)
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }

//     // For the largest number
//     string maxx;

//     sum = s;
//     for (int i = 0; i < m; i++)
//     {
//         for (int d = 9; d >= 0; d--)
//         {
//             if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
//             {
//                 maxx += char('0' + d);
//                 sum -= d;
//                 break;
//             }
//         }
//     }

//     cout << minn << " " << maxx << endl;

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <string>

// using namespace std;

// bool can(int m, int s)
// {
//     return s >= 0 && s <= 9 * m;
// }

// int main() {
//     int m, s;
//     cin >> m >> s;

//     // For the smallest number
//     string minn;
//     int sum = s;

//     // Handle the case where the first digit is 0
//     if (m == 1 && s == 0)
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }

//     for (int i = 0; i < m; i++)
//     {
//         for (int d = (i == 0) ? 1 : 0; d < 10; d++)
//         {
//             if (can(m - i - 1, sum - d))
//             {
//                 minn += char('0' + d);
//                 sum -= d;
//                 break;
//             }
//         }
//     }

//     // If sum is not 0 after constructing the smallest number, then not possible
//     if (sum != 0)
//     {
//         cout << "-1 -1" << endl;
//         return 0;
//     }

//     // For the largest number
//     string maxx;
//     sum = s;
//     for (int i = 0; i < m; i++)
//     {
//         for (int d = 9; d >= 0; d--)
//         {
//             if (can(m - i - 1, sum - d))
//             {
//                 maxx += char('0' + d);
//                 sum -= d;
//                 break;
//             }
//         }
//     }

//     cout << minn << " " << maxx << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool can(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}

int main()
{
    int m, s;
    cin >> m >> s;

    if(s==0)
    {
        cout << "-1 -1" << endl;
        return 0;
    }

    string minn;
    int sum = s;

    for (int i = 0; i < m; i++)
    {
        for (int d = 0; d < 10; d++)
        {
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
            {
                minn += char('0' + d);
                sum -= d;

                break;
            }
        }
    }

    //Min num
    string a = minn;

    //Max num
    reverse(minn.begin(), minn.end());
    string b = minn;

    //It the number has trailing 0s
    if(a[m-1]=='0')
    {
        cout << max(a,b) << " " << max(a,b) << endl;
    }
    //Normal output
    else
    {
        cout << a << " " << b << endl;
    }

    return 0;
}
