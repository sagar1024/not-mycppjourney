// D. Unnatural Language Processing

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Lura was bored and decided to make a simple language using the five letters a, b, c, d, e. There are two types of letters:

// vowels — the letters a and e. They are represented by V.
// consonants — the letters b, c, and d. They are represented by C.

// There are two types of syllables in the language: CV (consonant followed by vowel) or CVC (vowel with consonant before and after). For example, ba, ced, bab are syllables, but aa, eda, baba are not. A word in the language is a sequence of syllables. Lura has written a word in the language, but she doesn't know how to split it into syllables. Help her break the word into syllables. For example, given the word bacedbab, it would be split into syllables as ba.ced.bab (the dot . represents a syllable boundary).

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows. The first line of each test case contains an integer n (1≤n≤2⋅105) — the length of the word. The second line of each test case contains a string consisting of n lowercase Latin characters  — the word. All words given are valid words in the language; that is, they only use the letters a, b, c, d, e, and each word is made up of several syllables. The sum of n over all test cases does not exceed 2⋅105.

// Output
// For test case, output a string denoting the word split into syllables by inserting a dot . between every pair of adjacent syllables. If there are multiple possible splittings, output any of them. The input is given in such a way that at least one possible splitting exists.

// My original soln

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Length of the word
//         int n;
//         cin >> n;

//         //The word
//         string word;
//         cin >> word;

//         word.append("xx");

//         //Main logic
//         string answer = "";
//         for(int i=0; i<n; i++)
//         {
//             if((word[i]=='b' || word[i]=='c' || word[i]=='d') && (word[i+1]=='a' || word[i+1]=='e'))
//             {
//                 answer.append(word[i] + word[i+1] + ".");
//             }
//             else if((word[i]=='b' || word[i]=='c' || word[i]=='d') && (word[i+1]=='a' || word[i+1]=='e') && (word[i+2]=='b' || word[i+2]=='c' || word[i+2]=='d'))
//             {
//                 answer.append(word[i] + word[i+1] + word[i+2] + ".");
//             }
//         }

//         cout << answer << endl;
//     }

//     return 0;
// }

// Alternate soln

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         string word;
//         cin >> word;

//         string answer = "";
//         for (int i = 0; i < n;)
//         {
//             if (i < n - 1 && ((word[i] == 'b' || word[i] == 'c' || word[i] == 'd') && (word[i + 1] == 'a' || word[i + 1] == 'e')))
//             {
//                 answer += word[i];
//                 answer += word[i + 1];
//                 i += 2;
//             }
//             else if (i < n - 2 && (word[i] == 'b' || word[i] == 'c' || word[i] == 'd') && (word[i + 1] == 'a' || word[i + 1] == 'e') && (word[i + 2] == 'b' || word[i + 2] == 'c' || word[i + 2] == 'd'))
//             {
//                 answer += word[i];
//                 answer += word[i + 1];
//                 answer += word[i + 2];
//                 i += 3;
//             }
//             else
//             {
//                 answer += word[i];
//                 i++;
//             }

//             if (i < n) answer += '.';
//         }

//         cout << answer << endl;
//     }

//     return 0;
// }

// Alternate soln

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e';
}

string splitIntoSyllables(string word)
{
    string syllables = "";
    int i = 0;
    while (i < word.size())
    {
        if (isVowel(word[i]))
        {
            syllables += word[i++];
            if (i < word.size() && !isVowel(word[i]))
            {
                syllables += word[i++];
            }
        }
        else
        {
            syllables += word[i++];
        }
        if (i < word.size() && isVowel(word[i]))
        {
            syllables += '.';
        }
    }
    return syllables;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string word;
        cin >> word;

        string answer = splitIntoSyllables(word);
        cout << answer << endl;
    }

    return 0;
}
