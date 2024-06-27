// B. K-th Beautiful String

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// For the given integer n (n>2) let's write down all the strings of length n which contain n−2 letters 'a' and two letters 'b' in lexicographical (alphabetical) order. Recall that the string s of length n is lexicographically less than string t of length n, if there exists such i (1≤i≤n), that si<ti, and for any j (1≤j<i) sj=tj. The lexicographic comparison of strings is implemented by the operator < in modern programming languages. For example, if n=5 the strings are (the order does matter):

// aaabb
// aabab
// aabba
// abaab
// ababa
// abbaa
// baaab
// baaba
// babaa
// bbaaa

// It is easy to show that such a list of strings will contain exactly n⋅(n−1)2 strings. You are given n (n>2) and k (1≤k≤n⋅(n−1)2). Print the k-th string from the list.

// Input
// The input contains one or more test cases. The first line contains one integer t (1≤t≤104) — the number of test cases in the test. Then t test cases follow. Each test case is written on the the separate line containing two integers n and k (3≤n≤105,1≤k≤min(2⋅109,n⋅(n−1)2). The sum of values n over all test cases in the test doesn't exceed 105.

// Output
// For each test case print the k-th string from the list of all described above strings of length n. Strings in the list are sorted lexicographically (alphabetically).

// Example
// inputCopy
// 7
// 5 1
// 5 2
// 5 8
// 5 10
// 3 1
// 3 2
// 20 100
// outputCopy
// aaabb
// aabab
// baaba
// bbaaa
// abb
// bab
// aaaaabaaaaabaaaaaaaa

//My original soln -

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

        // vector<char> firstString(n, 'a');
        // firstString[n-2] = 'b';
        // firstString[n-1] = 'b';

        //string firstString = (n-1)*"a" + 2*"b"; 
        // string firstString;
        // for(int i=0; i<n-2; i++)
        // {
        //     firstString += 'a';
        // }
        // firstString += "bb";

        // vector<string> lexicographicStrings;
        // for(int i=0; i<n*(n-1)/2; i++)
        // {
        //     if(i==0)
        //     {
        //         lexicographicStrings.push_back(firstString);
        //     }
        // }

        //Initializing string with aaaaa...(n times)
        string s(n, 'a');
        //Iterating backwards
        for(int i=n-2; i>=0; i--)
        {
            //If k(req position) is less than (n-1)-i i.e ith position from the back
            //We put the "b"s to their respective positions
            //AND
            //Print them
            if(k<=(n-1)-i)
            {
                s[i] = 'b';
                s[n-k] = 'b';

                cout << s << endl;
                break;
            }
            else //we update the "k"
            {
                k -= (n-1)-i;
            }
        }
    }

    return 0;
}
