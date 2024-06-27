// C. Spy Syndrome 2

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// After observing the results of Spy Syndrome, Yash realised the errors of his ways. He now believes that a super spy such as Siddhant can't use a cipher as basic and ancient as Caesar cipher. After many weeks of observation of Siddhant’s sentences, Yash determined a new cipher technique. For a given sentence, the cipher is processed as: Convert all letters of the sentence to lowercase. Reverse each of the words of the sentence individually. Remove all the spaces in the sentence. For example, when this cipher is applied to the sentence Kira is childish and he hates losing. The resulting string is: ariksihsidlihcdnaehsetahgnisol. Now Yash is given some ciphered string and a list of words. Help him to find out any original sentence composed using only words from the list. Note, that any of the given words could be used in the sentence multiple times.

// Input
// The first line of the input contains a single integer n (1 ≤ n ≤ 10 000) — the length of the ciphered text. The second line consists of n lowercase English letters — the ciphered text t. The third line contains a single integer m (1 ≤ m ≤ 100 000) — the number of words which will be considered while deciphering the text. Each of the next m lines contains a non-empty word wi (|wi| ≤ 1 000) consisting of uppercase and lowercase English letters only. It's guaranteed that the total length of all words doesn't exceed 1 000 000.

// Output
// Print one line — the original sentence. It is guaranteed that at least one solution exists. If there are multiple solutions, you may output any of those.

// Examples
// inputCopy
// 30
// ariksihsidlihcdnaehsetahgnisol
// 10
// Kira
// hates
// is
// he
// losing
// death
// childish
// L
// and
// Note
// outputCopy
// Kira is childish and he hates losing
// inputCopy
// 12
// iherehtolleh
// 5
// HI
// Ho
// there
// HeLLo
// hello
// outputCopy
// HI there HeLLo
// Note
// In sample case 2 there may be multiple accepted outputs, "HI there HeLLo" and "HI there hello" you may output any of them.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int m;
//     cin >> m;

//     vector<string> words(m);
//     for(int i=0; i<m; i++)
//     {
//         cin >> words[i];
//     }

//     string curr;
//     vector<string> ans;
//     for(int i=0; i<n; i++)
//     {
//         curr += s[i];
//         reverse(curr.begin(), curr.end());
//         if(find(words.begin(), words.end(), curr) != words.end())
//         {
//             int idx = 0;
//             for(int j=0; j<m; j++)
//             {
//                 //string x = tolower(curr);
//                 //string y = tolower(words[j]);
//                 string x;
//                 string y;
//                 transform(x.begin(), x.end(), x.begin(), ::tolower);
//                 transform(y.begin(), y.end(), y.begin(), ::tolower);
//                 if(x==y)
//                 {
//                     idx = j;
//                     break;
//                 }
//             }
//             ans.push_back(words[idx]);
//             curr = "";
//         }
//         else
//         {
//             reverse(curr.begin(), curr.end());
//         }
//     }

//     //Output
//     for(auto a: ans) cout << a << " " << endl;
//     return 0;
// }

// Alternate soln(wrong ans on tc28) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int m;
//     cin >> m;

//     vector<string> words(m);
//     for (int i = 0; i < m; i++)
//     {
//         cin >> words[i];
//     }

//     string curr;
//     vector<string> ans;

//     unordered_set<string> wordSet;
//     for (const auto &word : words)
//     {
//         string lowerWord = word;
//         transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
//         wordSet.insert(lowerWord);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         curr += s[i];
//         string revCurr = curr;
//         reverse(revCurr.begin(), revCurr.end());
//         if (wordSet.find(revCurr) != wordSet.end())
//         {
//             for (const auto &word : words)
//             {
//                 string lowerWord = word;
//                 transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
//                 if (lowerWord == revCurr)
//                 {
//                     ans.push_back(word);
//                     break;
//                 }
//             }

//             curr.clear();
//         }
//     }

//     for (size_t i = 0; i < ans.size(); i++)
//     {
//         if (i > 0) cout << " ";
//         cout << ans[i];
//     }

//     cout << endl;

//     return 0;
// }

// Alternate soln(tle on tc67) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int m;
//     cin >> m;

//     vector<string> words(m);
//     unordered_set<string> reversedWords;
//     unordered_map<string, string> originalWordMap;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> words[i];
//         string lowerWord = words[i];
//         transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
//         reverse(lowerWord.begin(), lowerWord.end());
//         reversedWords.insert(lowerWord);
//         originalWordMap[lowerWord] = words[i];
//     }

//     vector<bool> dp(n + 1, false);
//     dp[0] = true;
//     vector<string> result(n + 1, "");
//     for (int i = 0; i < n; i++)
//     {
//         if (dp[i])
//         {
//             string curr = "";
//             for (int j = i; j < n; j++)
//             {
//                 curr += s[j];
//                 if (reversedWords.find(curr) != reversedWords.end())
//                 {
//                     dp[j + 1] = true;
//                     result[j + 1] = originalWordMap[curr];
//                 }
//             }
//         }
//     }

//     string originalSentence = "";
//     for (int i = n; i > 0;)
//     {
//         originalSentence = result[i] + " " + originalSentence;
//         i -= result[i].length();
//     }

//     cout << originalSentence << endl;

//     return 0;
// }

// Alternate soln -
