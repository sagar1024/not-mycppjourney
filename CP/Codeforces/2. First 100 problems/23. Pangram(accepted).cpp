// A. Pangram

// time limit per test: 2 seconds
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

// You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

// Input
// The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string.

// The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

// Output
// Output "YES", if the string is a pangram and "NO" otherwise.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin.ignore();
    getline(cin, s);

    bool lettersFound[26] = {false};

    for (int i = 0; i < s.length(); i++)
    {
        if (islower(s[i]))
        {
            lettersFound[s[i] - 'a'] = true;
            continue;
        }
        else if (isupper(s[i]))
        {
            lettersFound[s[i] - 'A'] = true;
            continue;
        }
    }

    bool pangram = true;

    for (int i = 0; i < 26; i++)
    {
        if (lettersFound[i] == true)
        {
            continue;
        }
        if (lettersFound[i] == false)
        {
            pangram = false;
            break;
        }
    }

    if (pangram)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

