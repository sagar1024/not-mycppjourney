// D. Camp Schedule

// time limit per test1 second
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// The new camp by widely-known over the country Spring Programming Camp is going to start soon. Hence, all the team of friendly curators and teachers started composing the camp's schedule. After some continuous discussion, they came up with a schedule s, which can be represented as a binary string, in which the i-th symbol is '1' if students will write the contest in the i-th day and '0' if they will have a day off. At the last moment Gleb said that the camp will be the most productive if it runs with the schedule t (which can be described in the same format as schedule s). Since the number of days in the current may be different from number of days in schedule t, Gleb required that the camp's schedule must be altered so that the number of occurrences of t in it as a substring is maximum possible. At the same time, the number of contest days and days off shouldn't change, only their order may change. Could you rearrange the schedule in the best possible way?

// Input
// The first line contains string s (1⩽|s|⩽500000), denoting the current project of the camp's schedule. The second line contains string t (1⩽|t|⩽500000), denoting the optimal schedule according to Gleb. Strings s and t contain characters '0' and '1' only.

// Output
// In the only line print the schedule having the largest number of substrings equal to t. Printed schedule should consist of characters '0' and '1' only and the number of zeros should be equal to the number of zeros in s and the number of ones should be equal to the number of ones in s. In case there multiple optimal schedules, print any of them.

// Examples
// inputCopy
// 101101
// 110
// outputCopy
// 110110

// inputCopy
// 10010110
// 100011
// outputCopy
// 01100011

// inputCopy
// 10
// 11100
// outputCopy
// 01

// Note
// In the first example there are two occurrences, one starting from first position and one starting from fourth position.
// In the second example there is only one occurrence, which starts from third position. Note, that the answer is not unique. For example, if we move the first day (which is a day off) to the last position, the number of occurrences of t wouldn't change.
// In the third example it's impossible to make even a single occurrence.

// My original soln(runtime on tc4) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     string s, t;
//     cin >> s >> t;

//     int n = s.size();
//     int m = t.size();

//     unordered_map<int,int> mp1(2), mp2(2);
//     for(int i=0; i<n; i++)
//     {
//         mp1[s[i]-'0'] += 1;
//     }
//     for(int i=0; i<m; i++)
//     {
//         mp2[t[i]-'0'] += 1;
//     }

//     int maxOccurence = INT_MAX;
//     for(int i=0; i<2; i++)
//     {
//         maxOccurence = min(mp1[i]/mp2[i], maxOccurence);
//         maxOccurence = max(maxOccurence, 1);
//     }

//     string ans;
//     if(mp1[0]<mp2[0] || mp1[1]<mp2[1])
//     {
//         ans = s;
//     }
//     else
//     {
//         for(int i=0; i<maxOccurence; i++)
//         {
//             ans += t;
//         }

//         int extra0 = mp1[0]%mp2[0];
//         int extra1 = mp1[1]%mp2[1];
//         for(int i=0; i<extra0; i++)
//         {
//             ans += '0';
//         }
//         for(int i=0; i<extra1; i++)
//         {
//             ans += '1';
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// Alternate soln(wrong on tc6) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Function to compute the prefix function for string t
// vector<int> computePrefixFunction(const string &t)
// {
//     int m = t.size();
//     vector<int> pi(m, 0);
//     for (int i = 1; i < m; ++i)
//     {
//         int j = pi[i - 1];
//         while (j > 0 && t[i] != t[j])
//         {
//             j = pi[j - 1];
//         }
//         if (t[i] == t[j])
//         {
//             j++;
//         }
//         pi[i] = j;
//     }

//     return pi;
// }

// void solve()
// {
//     string s, t;
//     cin >> s >> t;

//     int n = s.size();
//     int m = t.size();

//     int count0_s = count(s.begin(), s.end(), '0');
//     int count1_s = count(s.begin(), s.end(), '1');

//     int count0_t = count(t.begin(), t.end(), '0');
//     int count1_t = count(t.begin(), t.end(), '1');

//     if (count0_t == 0 || count1_t == 0)
//     {
//         //Special case: If t contains only '0's or only '1's
//         cout << s << endl;
//         return;
//     }

//     //Calculate the maximum number of full `t` that can fit into `s`
//     int maxFullT = min(count0_s / count0_t, count1_s / count1_t);

//     //Construct the result string by concatenating `t` maxFullT times
//     string result;
//     for (int i = 0; i < maxFullT; ++i)
//     {
//         result += t;
//     }

//     //Update the counts of remaining '0's and '1's in `s`
//     count0_s -= maxFullT * count0_t;
//     count1_s -= maxFullT * count1_t;

//     //Append remaining characters
//     result += string(count0_s, '0') + string(count1_s, '1');

//     cout << result << endl;
// }

// int main()
// {
//     solve();
//     return 0;
// }

//Alternate soln -

