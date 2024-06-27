// C. Number Game

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ashishgup and FastestFinger play a game. They start with a number n and play in turns. In each turn, a player can make any one of the following moves:

// Divide n by any of its odd divisors greater than 1.
// Subtract 1 from n if n is greater than 1.
// Divisors of a number include the number itself.

// The player who is unable to make a move loses the game. Ashishgup moves first. Determine the winner of the game if both of them play optimally.

// Input
// The first line contains a single integer t (1≤t≤100)  — the number of test cases. The description of the test cases follows. The only line of each test case contains a single integer  — n (1≤n≤109).

// Output
// For each test case, print "Ashishgup" if he wins, and "FastestFinger" otherwise (without quotes).

// Example
// inputCopy
// 7
// 1
// 2
// 3
// 4
// 5
// 6
// 12
// outputCopy
// FastestFinger
// Ashishgup
// Ashishgup
// FastestFinger
// Ashishgup
// FastestFinger
// Ashishgup

// Note
// In the first test case, n=1, Ashishgup cannot make a move. He loses.
// In the second test case, n=2, Ashishgup subtracts 1 on the first move. Now n=1, FastestFinger cannot make a move, so he loses.
// In the third test case, n=3, Ashishgup divides by 3 on the first move. Now n=1, FastestFinger cannot make a move, so he loses.
// In the last test case, n=12, Ashishgup divides it by 3. Now n=4, FastestFinger is forced to subtract 1, and Ashishgup gets 3, so he wins by dividing it by 3.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     long long int n;
//     cin >> n;

//     if(n==1)
//     {
//         cout << "FastestFinger" << endl;
//     }

//     bool flag = false;
//     while(n>1)
//     {
//         if(n%2==0)
//         {
//             n -= 1;
//             flag = !flag;
//         }
//         else
//         {
//             n /= n;
//             flag = !flag;
//         }
//     }

//     if(flag) cout << "Ashishgup" << endl;
//     else cout << "FastestFinger" << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;

//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    if (n==1)
    {
        cout << "FastestFinger" << endl;
        return;
    }

    if (n==2 || n%2==1)
    {
        cout << "Ashishgup" << endl;
        return;
    }

    // If n is even and not a power of 2
    //To count the num of "2" multiples
    int count = 0;
    while(n>1 && n%2==0)
    {
        n = n/2;
        count++;
    }

    //If n==1, means n is the power of 2
    if(n==1)
    {
        //If number of "2" multiple is even then Ashish will win
        //Else Fastestfinger
        if(count%2!=0)
        {
            cout << "Ashishgup" << endl;
            return;
        }
        else
        {
            cout << "FastestFinger" << endl;
            return;
        }
    }

    //If number of "2" multiple is odd then Ashish will  win
    //ELSE Fastestfinger
    if(count%2==0)
    {
        cout << "Ashishgup" << endl;
    }
    else
    {
        cout << "FastestFinger" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
