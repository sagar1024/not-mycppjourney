// B. Count the Number of Pairs

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kristina has a string s of length n, consisting only of lowercase and uppercase Latin letters. For each pair of lowercase letter and its matching uppercase letter, Kristina can get 1 burl. However, pairs of characters cannot overlap, so each character can only be in one pair. For example, if she has the string s = "aAaaBACacbE", she can get a burl for the following character pairs:

// s1 = "a" and s2 = "A"
// s4 = "a" and s6 = "A"
// s5 = "B" and s10 = "b"
// s7= "C" and s9 = "c"

// Kristina wants to get more burles for her string, so she is going to perform no more than k operations on it. In one operation, she can:

// either select the lowercase character si (1≤i≤n) and make it uppercase.
// or select uppercase character si (1≤i≤n) and make it lowercase.

// For example, when k = 2 and s = "aAaaBACacbE" it can perform one operation: choose s3 = "a" and make it uppercase. Then she will get another pair of s3 = "A" and s8 = "a". Find maximum number of burles Kristina can get for her string.

// Input
// The first line of input data contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n (1≤n≤2⋅105) and k (0≤k≤n) — the number of characters in the string and the maximum number of operations that can be performed on it. The second line of each test case contains a string s of length n, consisting only of lowercase and uppercase Latin letters. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print exactly one integer on a separate line: the maximum number of burles that Kristina can get for her string s.

// Example
// inputCopy
// 5
// 11 2
// aAaaBACacbE
// 2 2
// ab
// 4 1
// aaBB
// 6 0
// abBAcC
// 5 3
// cbccb
// outputCopy
// 5
// 0
// 1
// 3
// 2

// Note
// The first test case is explained in the problem statement.
// In the second test case, it is not possible to get any pair by performing any number of operations.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to check if the string only has unique chars
bool hasUniqueLetters(const string& str)
{
    unordered_set<char> charSet;
    for(char c: str)
    {
        //It searches the charSetfor the presence of the character c
        //It returns an iterator pointing to the element if found
        //OR charSet.end() if not found
        //If the character is already in the set
        //The string does not have unique letters
        if(charSet.find(c) != charSet.end())
        {
            return false;
        }
        //Add the character to the set
        charSet.insert(c);
    }

    // All characters are unique
    return true;
}

//Function to solve the problem
void solve()
{
    //String length
    int n;
    cin >> n;

    //Max num of operations
    int k;
    cin >> k;

    //Given string
    string s;
    cin >> s;

    if(hasUniqueLetters(s))
    {
        cout << 0 << endl;
        return;
    }

    //MAIN LOGIC
    //Storing the letters frequency
    int lowerFreq[26] = {0};
    int upperFreq[26] = {0};

    for(int i=0; i<n; i++)
    {
        if(islower(s[i]))
        {
            lowerFreq[s[i]-'a']++;
        }
        else if(isupper(s[i]))
        {
            upperFreq[s[i]-'A']++;
        } 
    }

    //Calculating the num of BURLES

    //Num of burles
    //int burles = 0;
    //Total num of burles
    //int totalBurles = 0;

    //Num of letters convertable by k
    //Current difference btw the frequencies
    //Minus the number of pairs already made
    // int diff = 0;
    // int totalDiffs = 0;
    // for(int i=0; i<26; i++)
    // {
    //     //Current num of burles is the min of the two frequencies
    //     burles = min(lowerFreq[i], upperFreq[i]);
    //     //Keep adding the burles
    //     totalBurles += min(lowerFreq[i], upperFreq[i]);

    //     //Finding the num of letters that can be converted by k
    //     diff = max(abs(lowerFreq[i]-upperFreq[i]), diff)-burles;
    //     totalDiffs += diff;
    // }

    // totalBurles += min(k, totalDiffs);
    // cout << totalBurles << endl;

    //Alternate logic -

    int burles = 0;
    int count1 = 0;
    int count2 = 0;

    int identicalPairs = 0;
    int unidenticalPairs = 0;

    //CRUX of the problem
    for(int i=0; i<26; i++)
    {
        identicalPairs = min(lowerFreq[i], upperFreq[i]);
        burles += identicalPairs;
        unidenticalPairs += (lowerFreq[i]+upperFreq[i]) - 2*identicalPairs;
    }

    burles += min(k, unidenticalPairs/2);
    cout << burles << endl;

    return;
}

//MAIN function
int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Calling the function
        solve();
    }

    return 0;
}
