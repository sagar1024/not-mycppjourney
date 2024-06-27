// A. Game 23

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp plays "Game 23". Initially he has a number n and his goal is to transform it to m. In one move, he can multiply n by 2 or multiply n by 3. He can perform any number of moves. Print the number of moves needed to transform n to m. Print -1 if it is impossible to do so. It is easy to prove that any way to transform n to m contains the same number of moves (i.e. number of moves doesn't depend on the way of transformation).

// Input
// The only line of the input contains two integers n and m (1≤n≤m≤5⋅108).

// Output
// Print the number of moves to transform n to m, or -1 if there is no solution.

// Examples
// inputCopy
// 120 51840
// outputCopy
// 7

// inputCopy
// 42 42
// outputCopy
// 0

// inputCopy
// 48 72
// outputCopy
// -1

// Note
// In the first example, the possible sequence of moves is: 120→240→720→1440→4320→12960→25920→51840. The are 7 steps in total.
// In the second example, no moves are needed. Thus, the answer is 0.
// In the third example, it is impossible to transform 48 to 72.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if(n==m)
    {
        cout << 0 << endl;
        return 0;
    }
    if((m%2!=0 && m%3!=0) || (m%n!=0))
    {
        cout << -1 << endl;
        return 0;
    }

    //Number of transformations required
    int x = m/n;

    int count = 0;

    while(x>1)
    {
        if(x%2==0)
        {
            x = x/2;
            count++;
        }
        else if(x%3==0)
        {
            x = x/3;
            count++;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count << endl;

    return 0;
}
