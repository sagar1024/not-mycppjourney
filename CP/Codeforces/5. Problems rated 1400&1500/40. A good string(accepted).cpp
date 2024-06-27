// D. a-Good String

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s[1…n] consisting of lowercase Latin letters. It is guaranteed that n=2k for some integer k≥0. The string s[1…n] is called c-good if at least one of the following three conditions is satisfied:

// The length of s is 1, and it consists of the character c (i.e. s1=c);
// The length of s is greater than 1, the first half of the string consists of only the character c (i.e. s1=s2=⋯=sn2=c) and the second half of the string (i.e. the string sn2+1sn2+2…sn) is a (c+1)-good string;
// The length of s is greater than 1, the second half of the string consists of only the character c (i.e. sn2+1=sn2+2=⋯=sn=c) and the first half of the string (i.e. the string s1s2…sn2) is a (c+1)-good string.

// For example: "aabc" is 'a'-good, "ffgheeee" is 'e'-good. In one move, you can choose one index i from 1 to n and replace si with any lowercase Latin letter (any character from 'a' to 'z'). Your task is to find the minimum number of moves required to obtain an 'a'-good string from s (i.e. c-good string for c= 'a'). It is guaranteed that the answer always exists. You have to answer t independent test cases. Another example of an 'a'-good string is as follows. Consider the string s="cdbbaaaa". It is an 'a'-good string, because:

// the second half of the string ("aaaa") consists of only the character 'a';
// the first half of the string ("cdbb") is 'b'-good string, because:
// the second half of the string ("bb") consists of only the character 'b';
// the first half of the string ("cd") is 'c'-good string, because:
// the first half of the string ("c") consists of only the character 'c';
// the second half of the string ("d") is 'd'-good string.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The first line of the test case contains one integer n (1≤n≤131 072) — the length of s. It is guaranteed that n=2k for some integer k≥0. The second line of the test case contains the string s consisting of n lowercase Latin letters. It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer — the minimum number of moves required to obtain an 'a'-good string from s (i.e. c-good string with c= 'a'). It is guaranteed that the answer exists.

// Example
// inputCopy
// 6
// 8
// bbdcaaaa
// 8
// asdfghjk
// 8
// ceaaaabb
// 8
// bbaaddcc
// 1
// z
// 2
// ac
// outputCopy
// 0
// 7
// 4
// 5
// 1
// 1

//My original soln(with tutorial help) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

int minMoves(const string &s, char c)
{
    //Base case
    if(s.size()==1)
    {
        //If that one char is equal to c, then 0 moves req else 1 move
        return s[0]!=c;
    }

    int mid = s.size()/2;
    int countL = minMoves(string(s.begin(), s.begin()+mid), c+1);
    countL += s.size()/2 - count(s.begin()+mid, s.end(), c);

    int countR = minMoves(string(s.begin()+mid, s.end()), c+1);
    countR += s.size()/2 - count(s.begin(), s.begin()+mid, c);

    return min(countL, countR);
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    //Min moves req to make the string good
    cout << minMoves(s, 'a') << endl;

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
