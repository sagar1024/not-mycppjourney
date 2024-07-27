// D. Plus Minus Permutation

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given 3 integers — n, x, y. Let's call the score of a permutation† p1,…,pn the following value: (p1⋅x+p2⋅x+…+p⌊nx⌋⋅x)−(p1⋅y+p2⋅y+…+p⌊ny⌋⋅y). In other words, the score of a permutation is the sum of pi for all indices i divisible by x, minus the sum of pi for all indices i divisible by y. You need to find the maximum possible score among all permutations of length n. For example, if n=7, x=2, y=3, the maximum score is achieved by the permutation [2,6–,1–,7–,5,4––,3] and is equal to (6+7+4)−(1+4)=17−5=12. A permutation of length n is an array consisting of n distinct integers from 1 to n in any order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (the number 2 appears twice in the array) and [1,3,4] is also not a permutation (n=3, but the array contains 4).

// Input
// The first line of input contains an integer t (1≤t≤104) — the number of test cases. Then follows the description of each test case. The only line of each test case description contains 3 integers n, x, y (1≤n≤109, 1≤x,y≤n).

// Output
// For each test case, output a single integer — the maximum score among all permutations of length n.

// Example
// inputCopy
// 8
// 7 2 3
// 12 6 3
// 9 1 9
// 2 2 2
// 100 20 50
// 24 4 6
// 1000000000 5575 25450
// 4 4 1
// outputCopy
// 12
// -3
// 44
// 0
// 393
// 87
// 179179179436104
// -6

// Note

// The first test case is explained in the problem statement above.
// In the second test case, one of the optimal permutations will be [12,11,2–,4,8,9––,10,6,1–,5,3,7––]. The score of this permutation is (9+7)−(2+9+1+7)=−3. It can be shown that a score greater than −3 can not be achieved. Note that the answer to the problem can be negative.
// In the third test case, the score of the permutation will be (p1+p2+…+p9)−p9. One of the optimal permutations for this case is [9,8,7,6,5,4,3,2,1], and its score is 44. It can be shown that a score greater than 44 can not be achieved.
// In the fourth test case, x=y, so the score of any permutation will be 0.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long long n, x, y;
//     cin >> n >> x >> y;

//     vector<long long int> a(n,0);
//     long long n1=n, n2=1;
//     for(int i=0; i<n; i++)
//     {
//         if((i+1)%x==0 && n>0)
//         {
//             a[i] = n1;
//             n1--;
//         }
//         else if((i+1)%y==0 && n2<=n)
//         {
//             a[i] = n2;
//             n2++;
//         }
//     }

//     int sum = 0;
//     for(auto x: a)
//     {
//         sum += x;
//     }

//     cout << sum << endl;
//     return;
// }

// int main()
// {
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
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, x, y;
    cin >> n >> x >> y;

    long long countx = n/x;
    long long county = n/y;

    long long lcmxy = (x*y)/__gcd(x,y);
    long long countxy = n/lcmxy;

    countx -= countxy;
    county -= countxy;

    // long long sumx = 0;
    // long long sumy = 0;
    // for(long long i=countx; i>=0; i--)
    // {
    //     sumx += i;
    // }
    // for(long long i=1; i<=county; i++)
    // {
    //     sumy += i;
    // }

    //Calculate the sum of the largest countx numbers using the formula for the sum of an arithmetic series: sumx=countx(2n−countx+1)/2. This formula computes the sum of the largest countx numbers. Calculate the sum of the smallest county numbers using the formula for the sum of the first county natural numbers: sumy=county×(county+1)/2.

    //Sum of the largest countx numbers
    long long sumx = (countx * (2 * n - countx + 1)) / 2;
    
    //Sum of the smallest county numbers
    long long sumy = (county * (county + 1)) / 2;

    cout << sumx - sumy << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
