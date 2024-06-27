// E. Sonya and Matrix Beauty

// time limit per test1.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Sonya had a birthday recently. She was presented with the matrix of size n×m and consist of lowercase Latin letters. We assume that the rows are numbered by integers from 1 to n from bottom to top, and the columns are numbered from 1 to m from left to right. Let's call a submatrix (i1,j1,i2,j2) (1≤i1≤i2≤n;1≤j1≤j2≤m) elements aij of this matrix, such that i1≤i≤i2 and j1≤j≤j2. Sonya states that a submatrix is beautiful if we can independently reorder the characters in each row (not in column) so that all rows and columns of this submatrix form palidroms. Let's recall that a string is called palindrome if it reads the same from left to right and from right to left. For example, strings abacaba,bcaacb,a are palindromes while strings abca,acbba,ab are not. Help Sonya to find the number of beautiful submatrixes. Submatrixes are different if there is an element that belongs to only one submatrix.

// Input
// The first line contains two integers n and m (1≤n,m≤250) — the matrix dimensions. Each of the next n lines contains m lowercase Latin letters.

// Output
// Print one integer — the number of beautiful submatrixes.

// Examples
// inputCopy
// 1 3
// aba
// outputCopy
// 4
// inputCopy
// 2 3
// aca
// aac
// outputCopy
// 11
// inputCopy
// 3 5
// accac
// aaaba
// cccaa
// outputCopy
// 43

// Note
// In the first example, the following submatrixes are beautiful: ((1,1),(1,1));((1,2),(1,2)); ((1,3),(1,3));((1,1),(1,3)).
// In the second example, all submatrixes that consist of one element and the following are beautiful: ((1,1),(2,1)); ((1,1),(1,3));((2,1),(2,3));((1,1),(2,3));((2,1),(2,2)).
// Some of the beautiful submatrixes are: ((1,1),(1,5));((1,2),(3,4)); ((1,1),(3,5)).
// The submatrix ((1,1),(3,5)) is beautiful since it can be reordered as:
// accca
// aabaa
// accca
// In such a matrix every row and every column form palindromes.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<char>> matrix(n, vector<char>(m,0));
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }

//     //Beautiful submatrix count
//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             vector<vector<char>> curr(i, vector<char>(j,0));
//             //Fill in the values from the original matrix
//             //Check if it is palindrome
//             //If row length is odd, then all chars should have even freq, only one char with odd freq
//             //If row length is even, then all chars must have even freq
//             //If palindrome, then count++;
//         }
//     }

//     cout << count << endl;
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const long long KEY = 397;

long long p1[600]; //Array to store powers of KEY
long long b[600];  //Temporary array used in solve function

int n, m; //Matrix dimensions
vector<string> matrix;

long long h[600]; //Array to store hash values for each row
int msk[600];     //Array to store masks for each row
int cnt[610][26]; //Array to count character occurrences

//Initialize powers of the hash base
void init_hash()
{
    p1[0] = 1;
    for (int i = 1; i < 600; i++)
    {
        p1[i] = (p1[i - 1] * KEY) % MOD;
    }
}

//Check if a number is zero or a power of two
inline bool is_power_of_two_or_zero(int x)
{
    return (x == 0 || (x & (x - 1)) == 0);
}

int dp1[1005]; //Array for storing odd length palindrome radii
int dp2[1005]; //Array for storing even length palindrome radii

//Calculate the number of palindromic subarrays in b
long long solve(int i1, int i2)
{
    int sz = 0;
    for (int i = i1; i <= i2; i++)
    {
        b[++sz] = h[i];
    }

    long long res = 0;
    int l = 0, r = 0, x;

    //Odd length palindromes
    for (int i = 1; i <= sz; i++)
    {
        x = (i > r) ? 1 : min(dp1[l + r - i], r - i + 1);
        while (i - x >= 1 && i + x <= sz && b[i - x] == b[i + x])
        {
            x++;
        }

        dp1[i] = x;
        if (i + x - 1 > r)
        {
            l = i - x + 1, r = i + x - 1;
        }

        res += x;
    }

    //Even length palindromes
    l = r = 0;
    for (int i = 1; i <= sz; i++)
    {
        x = (i > r) ? 0 : min(dp2[l + r - i + 1], r - i + 1);
        while (i - x - 1 >= 1 && i + x <= sz && b[i - x - 1] == b[i + x])
        {
            x++;
        }

        dp2[i] = x;
        if (i + x > r)
        {
            l = i - x, r = i + x - 1;
        }
        res += x;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    matrix.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> matrix[i];
        for (char &ch : matrix[i])
        {
            ch -= 'a';
        }
    }

    init_hash();
    long long ans = 0;

    //Iterate over all column pairs
    for (int j1 = 1; j1 <= m; j1++)
    {
        memset(msk, 0, sizeof(msk));
        memset(h, 0, sizeof(h));
        memset(cnt, 0, sizeof(cnt));
        for (int j2 = j1; j2 <= m; j2++)
        {
            //Update hash and mask for each row
            for (int i = 1; i <= n; i++)
            {
                int x = matrix[i][j2 - 1];
                if (cnt[i][x])
                {
                    h[i] = (h[i] - cnt[i][x] * p1[x + 1] % MOD + MOD) % MOD;
                }

                ++cnt[i][x];
                h[i] = (h[i] + cnt[i][x] * p1[x + 1] % MOD) % MOD;
                msk[i] ^= (1 << x);
            }

            //Identify submatrices that can form palindromes
            int i1 = 1;
            while (i1 <= n)
            {
                if (!is_power_of_two_or_zero(msk[i1]))
                {
                    ++i1;
                    continue;
                }

                int i2 = i1;
                while (i2 <= n && is_power_of_two_or_zero(msk[i2]))
                {
                    ++i2;
                }

                --i2;
                ans += solve(i1, i2);
                i1 = i2 + 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
