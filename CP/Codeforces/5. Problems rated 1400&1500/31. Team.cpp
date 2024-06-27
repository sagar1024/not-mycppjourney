// C. Team

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Now it's time of Olympiads. Vanya and Egor decided to make his own team to take part in a programming Olympiad. They've been best friends ever since primary school and hopefully, that can somehow help them in teamwork. For each team Olympiad, Vanya takes his play cards with numbers. He takes only the cards containing numbers 1 and 0. The boys are very superstitious. They think that they can do well at the Olympiad if they begin with laying all the cards in a row so that:

// there wouldn't be a pair of any side-adjacent cards with zeroes in a row;
// there wouldn't be a group of three consecutive cards containing numbers one.

// Today Vanya brought n cards with zeroes and m cards with numbers one. The number of cards was so much that the friends do not know how to put all those cards in the described way. Help them find the required arrangement of the cards or else tell the guys that it is impossible to arrange cards in such a way.

// Input
// The first line contains two integers: n (1 ≤ n ≤ 106) — the number of cards containing number 0; m (1 ≤ m ≤ 106) — the number of cards containing number 1.

// Output
// In a single line print the required sequence of zeroes and ones without any spaces. If such sequence is impossible to obtain, print -1.

// Examples
// inputCopy
// 1 2
// outputCopy
// 101

// inputCopy
// 4 8
// outputCopy
// 110110110101

// inputCopy
// 4 10
// outputCopy
// 11011011011011

// inputCopy
// 1 5
// outputCopy
// -1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Num of 0s and 1s
//     long int n, m;
//     cin >> n >> m;

//     //Special cases
//     if(n>m || ceil((float)m/n)>3)
//     {
//         return -1;
//     }

//     string answer;

//     if(m/n==1)
//     {
//         if(m%n==0)
//         {
//             for(int i=0; i<n; i++)
//             {
//                 answer += "10";
//             }
//         }
//         else
//         {
//             for(int i=0; i<n; i++)
//             {
//                 answer += "110";
//             }
//         }
//     }
//     else if(m/n==2)
//     {
//         if(m%n==0)
//         {
//             for(int i=0; i<n; i++)
//             {
//                 answer += "110";
//             }
//         }
//         else
//         {
//             for(int i=0; i<n; i++)
//             {
//                 answer += "110";
//             }
//             for(int i=0; i<m-n; i++)
//             {
//                 answer += "1";
//             }
//         }
//     }
//     else if(m/n==3 && m%n==0)
//     {
//         for(int i=0; i<n; i++)
//         {
//             answer += "110";
//         }
//         for(int i=0; i<m-n; i++)
//         {
//             answer += "1";
//         }
//     }

//     cout << answer << endl;

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     long long n, m;
//     cin >> n >> m;

//     // Checking if the given range of m is valid. The number of cards with 1 should be between n - 1 and 2 * (n + 1) (inclusive).
//     if ((n - 1) <= m && m <= 2 * (n + 1))
//     {
//         // If m is equal to n - 1, there is a special case
//         if (m == n - 1)
//         {
//             cout << "0"; // Start with '0'
//             // Print '110' (n - 1) times
//             for (int i = 0; i < n - 1; ++i)
//             {
//                 cout << "110";
//             }
//         }
//         // If m is equal to n, there is another special case
//         else if (m == n)
//         {
//             // Print '110' n times
//             for (int i = 0; i < n; ++i)
//             {
//                 cout << "110";
//             }
//         }
//         else
//         {
//             // Print '110' n times
//             for (int i = 0; i < n; ++i)
//             {
//                 cout << "110";
//             }
//             // Print '1' (m - n) times
//             for (int i = 0; i < m - n; ++i)
//             {
//                 cout << "1";
//             }
//         }

//         // Print '1' at the end if applicable
//         if (m > n && m <= 2 * (n + 1))
//         {
//             cout << "1";
//         }
//         cout << endl;
//     }
//     else
//     {
//         // If the range of m is not valid, print -1
//         cout << "-1" << endl;
//     }

//     return 0;
// }

// Alternate soln(from tutorial) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n, m, t, a[3000001], k;

int main()

{
    cin >> n >> m;
    if (n - 1 <= m && m <= 2 * (n + 1))
    {
        if (m == n - 1)
        {
            a[0] = -1;
            a[m + 1] = -1;
            t = n - 1;
        }
        else if (m == n)
        {
            a[m + 1] = -1;
            t = n;
        }
        else t = n + 1;

        k = m % t;
        if (k == 0 && m != t) k = n + 1;
        if (a[0] == -1) cout << "0";

        for (int i = 1; i <= n; i++)
        {
            if (a[i] != -1)
            {
                if (k > 0) cout << "110";
                else cout << "10";
                k--;
            }
        }
        if (a[m + 1] != -1)
        {
            if (k > 0) cout << "11" << endl;
            else cout << "1" << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}