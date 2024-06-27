// A. Milica and String

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Milica has a string s of length n, consisting only of characters A and B. She wants to modify s so it contains exactly k instances of B. In one operation, she can do the following:

// 1. Select an integer i (1≤i≤n) and a character c (c is equal to either A or B).

// 2. Then, replace each of the first i characters of string s (that is, characters s1,s2,…,si) with c. Milica does not want to perform too many operations in order not to waste too much time on them.

// She asks you to find the minimum number of operations required to modify s so it contains exactly k instances of B. She also wants you to find these operations (that is, integer i and character c selected in each operation).

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of test cases follows.

// The first line of each test case contains two integers n and k (3≤n≤100, 0≤k≤n) — the length of the string s and the number of characters B Milica wants to appear in s in the end.

// The second line of each test case contains the string s of length n, consisting only of characters A and B.

// Output
// For each test case, in the first line output a single integer m — the minimum number of operations Milica should perform.

// In the j-th of the next m lines output an integer i (1≤i≤n) and a character c (c is 'A' or 'B') — the parameters of the j-th operation as described in the statement.

// If there are multiple solutions with the minimum possible number of operations, output any of them.

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    // Number of test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Length of the string
        int n;
        cin >> n;

        // Number of characters B Milica wants to appear in s in the end
        int k;
        cin >> k;

        // String s of length n
        // Consisting only of characters A and B.
        vector<char> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        // Taking input and counting the number of B in the original string
        int counting_B = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                counting_B++;
            }
        }

        // Number of initial elements
        // The character by which we will replace
        // int i;
        // char c;

        if (counting_B == k)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            cout << 1 << endl;

            if (k == 0)
            {
                cout << n << " " << "A" << endl;
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(s[i]=='B' && i==counting_B)
                    {
                        cout << i + 1 << " " << "B" << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

