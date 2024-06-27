// B. Anton and currency you all know

// time limit per test0.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Berland, 2016. The exchange rate of currency you all know against the burle has increased so much that to simplify the calculations, its fractional part was neglected and the exchange rate is now assumed to be an integer. Reliable sources have informed the financier Anton of some information about the exchange rate of currency you all know against the burle for tomorrow. Now Anton knows that tomorrow the exchange rate will be an even number, which can be obtained from the present rate by swapping exactly two distinct digits in it. Of all the possible values that meet these conditions, the exchange rate for tomorrow will be the maximum possible. It is guaranteed that today the exchange rate is an odd positive integer n. Help Anton to determine the exchange rate of currency you all know for tomorrow!

// Input
// The first line contains an odd positive integer n — the exchange rate of currency you all know for today. The length of number n's representation is within range from 2 to 105, inclusive. The representation of n doesn't contain any leading zeroes.

// Output
// If the information about tomorrow's exchange rate is inconsistent, that is, there is no integer that meets the condition, print  - 1. Otherwise, print the exchange rate of currency you all know against the burle for tomorrow. This should be the maximum possible number of those that are even and that are obtained from today's exchange rate by swapping exactly two digits. Exchange rate representation should not contain leading zeroes.

// Examples
// inputCopy
// 527
// outputCopy
// 572
// inputCopy
// 4573
// outputCopy
// 3574
// inputCopy
// 1357997531
// outputCopy
// -1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     //Inputs
//     int n;
//     cin >> n;

//     string s = to_string(n);
//     int len = s.size();
//     // char lastChar = s.back();
//     bool flag = false;
//     int lastEvenNum = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if ((s[i] - '0') % 2 == 0)
//         {
//             // First even num will be swapped with the last odd digit
//             // Without any conditions
//             if (!flag)
//             {
//                 char temp = s[i];
//                 s[i] = s.back();
//                 s.back() = temp;
//                 flag = true;
//             }
//             else
//             {
//                 // Subsequent even nums will be swapped if the first even num is greater than the last num and if the subsequent even nums are greater than first even num
//                 if ((s[i] - '0') > s.back() - '0')
//                 {
//                     lastEvenNum = s[i] - '0';
//                     continue;
//                 }
//                 if ((s[i] - '0') > lastEvenNum)
//                 {
//                     if ((s[i] - '0') < s.back())
//                     {
//                         char temp = s[i];
//                         s[i] = s.back();
//                         s.back() = temp;
//                     }
//                     else
//                     {
//                         lastEvenNum = s[i] - '0';
//                         continue;
//                     }
//                 }
//             }
//         }
//     }

//     //Outputs
//     if (flag)
//     {
//         cout << s << endl;
//     }
//     else
//     {
//         cout << "-1" << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;

//     //MAIN logic
//     string s1 = to_string(n);
//     string s2 = to_string(n);

//     int sLength = s1.size();
//     bool swapped = false;

//     for (int i = 0; i < sLength; i++)
//     {
//         if ((s1[i] - '0') % 2 == 0)
//         {
//             if (!swapped)
//             {
//                 swap(s1[i], s1.back());
//                 swapped = true;
//             }
//         }
//     }

//     for (int i = 0; i < sLength; i++)
//     {
//         if ((s2[i] - '0') % 2 == 0)
//         {
//             if ((s2[i] - '0') < s2.back())
//             {
//                 swap(s2[i], s2.back());
//                 swapped = true;
//             }
//         }
//     }

//     //Outputs
//     int a = stoi(s1);
//     int b = stoi(s2);
//     if (swapped)
//     {
//         cout << max(a, b) << endl;
//     }
//     else
//     {
//         cout << "-1" << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;

//     //MAIN logic
//     string s1 = to_string(n);
//     string s2 = to_string(n);

//     int len = s1.size();
//     bool swapped = false;

//     vector<pair<int,int>> evenNums;
//     int lastDigit = s1[len-1]-'0';
//     for(int i=0; i<len; i++)
//     {
//         if((s1[i]-'0')%2==0)
//         {
//             evenNums.push_back({i, s1[i]-'0'});
//         }
//     }

//     if(evenNums.size()>0)
//     {
//         for(int i=0; i<len; i++)
//         {
//             if(evenNums[i].second < lastDigit)
//             {
//                 //How to replace this particular num by the last digit?
//                 //Replaced the first num(front)
//                 s2[evenNums[i].first] = lastDigit + '0';
//                 //Replaced the second num(back)
//                 char temp = evenNums[i].second;
//                 s2.pop_back();
//                 s2.push_back(temp);
//             }
//         }
//         cout << s2 << endl;
//     }
//     else
//     {
//         cout << "-1" << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     //INputs
//     string s;
//     cin >> s;

//     //MAIN logic
//     int len = s.size();
//     int lastDigit = s[len - 1] - '0';

//     vector<int> evenNums;
//     for (int i = 0; i < len - 1; i++)
//     {
//         if ((s[i] - '0') % 2 == 0)
//         {
//             evenNums.push_back(s[i] - '0');
//         }
//     }

//     if (evenNums.empty())
//     {
//         cout << "-1" << endl;
//     }
//     else
//     {
//         int maxIndex = -1;
//         for (int i = 0; i < evenNums.size(); i++)
//         {
//             if (evenNums[i] < lastDigit)
//             {
//                 maxIndex = i;
//             }
//         }

//         if (maxIndex == -1)
//         {
//             swap(s[len - 1], s[evenNums[0]]);
//             cout << s << endl;
//         }
//         else
//         {
//             swap(s[len - 1], s[evenNums[maxIndex]]);
//             cout << s << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     string s;
//     cin >> s;

//     //MAIN logic
//     int len = s.size();
//     int lastDigit = s[len - 1] - '0';

//     //Checking if the number consists only of odd digits
//     bool allOdd = true;
//     for (char c : s)
//     {
//         int digit = c - '0';
//         if (digit % 2 == 0)
//         {
//             allOdd = false;
//             break;
//         }
//     }

//     if (allOdd)
//     {
//         cout << "-1" << endl;
//     }
//     else
//     {
//         int firstEvenLess = -1;
//         int firstEvenMore = -1;

//         //Finding the first even digit less than the last digit
//         for (int i = 0; i < len - 1; i++)
//         {
//             int digit = s[i] - '0';
//             if (digit % 2 == 0 && digit < lastDigit)
//             {
//                 firstEvenLess = i;
//                 break;
//             }
//         }

//         //Finding the first even digit more than the last digit
//         for (int i = 0; i < len - 1; i++)
//         {
//             int digit = s[i] - '0';
//             if (digit % 2 == 0 && digit > lastDigit)
//             {
//                 firstEvenMore = i;
//                 break;
//             }
//         }

//         if (firstEvenLess != -1)
//         {
//             swap(s[len - 1], s[firstEvenLess]);
//             cout << s << endl;
//         }
//         else if (firstEvenMore != -1)
//         {
//             swap(s[len - 1], s[firstEvenMore]);
//             cout << s << endl;
//         }
//         else
//         {
//             cout << "-1" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    //MAIN logic
    int n = s.length() - 1;
    int index = n;

    for (int i = 0; i < n; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            index = i;
            if(s[n] > s[i]) break;
        }
    }

    //Outputs
    if (n == index)
    {
        cout << -1 << endl;
    }
    else
    {
        swap(s[index], s[n]);
        cout << s << endl;
    }

    return 0;
}
