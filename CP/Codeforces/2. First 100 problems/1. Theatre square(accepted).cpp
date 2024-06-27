// A. Theatre Square

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

// What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

// Input
// The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 10^9).
// Output
// Write the needed number of flagstones.

//My original soln - Sept 2023

// #include <iostream>
// #include <cmath>

// using namespace std;

// int main()
// {
//     long int n, m, a;
//     cin >> n >> m >> a;

//     long long count = 0;

//     if(1<=n && n<=1000000000 && 1<=m && m<=1000000000 && 1<=a && a<=1000000000 && a<=n && a<=m)
//     {
//         long int length = ceil((double)n/a);
//         long int width = ceil((double)m/a);
        
//         count = length*width;
//     }
//     else
//     {
//         return -1;
//     }

//     cout << count << endl;

//     return 0;
// }

//My alternate soln - Dec 2023

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, m, a;
    cin >> n >> m >> a;

    //In this code, n/a performs integer division (resulting in 1), and ceil() is then applied to 1, which results in 1. However, the expected result might be 2, as when n = 6 and a = 4, the calculation should yield n/a = 1.5, which should be rounded up to 2. But due to integer division, the result of n/a is 1, leading ceil() to return 1 as well. This happens because ceil() operates on floating-point types. When you perform integer division and pass that result to ceil(), it doesn't consider the fractional part and operates directly on the integer division result, resulting in the loss of precision.

    // long long int length = ceil(n/a);
    // long long int breadth = ceil(m/a);

    long long length = (n+a-1)/a; // Rounds up n/a
    long long breadth = (m+a-1)/a; // Rounds up m/a


    long long int flagstones = length*breadth;

    cout << flagstones << endl;

    return 0;
}
