// B. BerSU Ball

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// The Berland State University is hosting a ballroom dance in celebration of its 100500-th anniversary! n boys and m girls are already busy rehearsing waltz, minuet, polonaise and quadrille moves. We know that several boy&girl pairs are going to be invited to the ball. However, the partners' dancing skill in each pair must differ by at most one. For each boy, we know his dancing skills. Similarly, for each girl we know her dancing skills. Write a code that can determine the largest possible number of pairs that can be formed from n boys and m girls.

// Input
// The first line contains an integer n (1 ≤ n ≤ 100) — the number of boys. The second line contains sequence a1, a2, ..., an (1 ≤ ai ≤ 100), where ai is the i-th boy's dancing skill. Similarly, the third line contains an integer m (1 ≤ m ≤ 100) — the number of girls. The fourth line contains sequence b1, b2, ..., bm (1 ≤ bj ≤ 100), where bj is the j-th girl's dancing skill.

// Output
// Print a single number — the required maximum possible number of pairs.

// Examples

// inputCopy
// 4
// 1 4 6 2
// 5
// 5 1 5 7 9
// outputCopy
// 3

// inputCopy
// 4
// 1 2 3 4
// 4
// 10 11 12 13
// outputCopy
// 0

// inputCopy
// 5
// 1 1 1 1 1
// 3
// 1 2 3
// outputCopy
// 2

//My original soln(using two pointers) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Num of boys
    int n;
    cin >> n;

    vector<int> boys(n);
    for(int i=0; i<n; i++)
    {
        cin >> boys[i];
    }

    //Num of girls
    int m;
    cin >> m;

    vector<int> girls(m);
    for(int i=0; i<m; i++)
    {
        cin >> girls[i];
    }

    //Sorting the boys and girls based on their skills
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    //Initializing the two pointers
    int i = 0;
    int j = 0;

    //Answer variable
    int pairs = 0;

    while(i<n && j<m)
    {
        //If the difference in dancing skills is at most one, then form a pair
        if(abs(boys[i]-girls[j])<=1)
        {
            //New pair found
            pairs++;

            //Shift the two pointers to find another pair
            i++;
            j++;
        }

        //If the difference is more than one
        else
        {
            //If the skill of the boys is less, change the boy
            if(boys[i]<girls[j])
            {
                i++;
            }
            //Else move to the next girl
            else
            {
                j++;
            }
        }
    }

    cout << pairs << endl;

    return 0;
}
