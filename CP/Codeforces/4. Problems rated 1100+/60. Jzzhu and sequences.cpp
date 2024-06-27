// B. Jzzhu and Sequences

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Jzzhu has invented a kind of sequences, they meet the following property:

// f1 = x, f2 = y, for all i(i>=2), fi = fi-1 + fi+1

// You are given x and y, please calculate fn modulo 1000000007 (109 + 7).

// Input
// The first line contains two integers x and y (|x|, |y| ≤ 109). The second line contains a single integer n (1 ≤ n ≤ 2·109).

// Output
// Output a single integer representing fn modulo 1000000007 (109 + 7).

// Examples
// inputCopy
// 2 3
// 3
// outputCopy
// 1

// inputCopy
// 0 -1
// 2
// outputCopy
// 1000000006

// Note
// In the first sample, f2 = f1 + f3, 3 = 2 + f3, f3 = 1.
// In the second sample, f2 =  - 1;  - 1 modulo (109 + 7) equals (109 + 6).

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Func to calc f(nth) num
// long long int fnth(long long int f1, long long int f2, long long int n)
// {
//     long long int f3 = f2-f1;

//     if(n<=3)
//     {
//         return f3;
//     }

//     //Recursion
//     fnth(f2, f3, n-1);
// }

// int main()
// {
//     //Inputs
//     long long int x, y, n;
//     cin >> x >> y >> n;

//     //MAIN logic
//     long long int f1 = abs(x), f2 = abs(y);

//     long long int result = fnth(f1,f2,n);
//     cout << result << endl;

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // Function to calculate fn (nth) number
// long long int fnth(long long int f1, long long int f2, long long int n)
// {
//     long long int mod = 1000000007;
//     long long int f3 = f2 - f1;

//     // Handle negative values
//     if (f1 < 0 && n % 3 == 1)
//         f1 += mod;
//     if (f2 < 0 && n % 3 == 2)
//         f2 += mod;
//     if (f3 < 0 && n % 3 == 0)
//         f3 += mod;

//     //Base cases
//     if (n == 1)
//         return f1;
//     if (n == 2)
//         return f2;
//     if (n == 3)
//         return f3;

//     //Recurrence relation
//     long long int fn_minus_2 = f1;
//     long long int fn_minus_1 = f2;
//     long long int fn;

//     for (int i = 3; i <= n; ++i)
//     {
//         fn = (fn_minus_1 + fn_minus_2) % mod;
//         fn_minus_2 = fn_minus_1;
//         fn_minus_1 = fn;
//     }

//     return fn;
// }

// int main()
// {
//     // Inputs
//     long long int x, y, n;
//     cin >> x >> y >> n;

//     //Handling negative values
//     long long int f1 = abs(x), f2 = abs(y);

//     //Calculating nth term of the sequence modulo 1000000007
//     long long int result = fnth(f1, f2, n);
//     cout << result << endl;

//     return 0;
// }

//Alternate soln - We can easily find that every 6 numbers are the same. It's like {x, y, y - x,  - x,  - y, x - y, x, y, y - x, ...}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Inputs
    long long int x, y, n;
    cin >> x >> y >> n;

    //MAIN logic
    long long int f1, f2, f3, f4, f5, f6;
    f1 = x;
    f2 = y;
    f3 = y-x;
    f4 = -x;
    f5 = -y;
    f6 = x-y;

    int remainder = n%6;
    if(remainder==1) cout << f1 << endl;
    else if(remainder==2) cout << f2 << endl;
    else if(remainder==3) cout << f3 << endl;
    else if(remainder==4) cout << f4 << endl;
    else if(remainder==5) cout << f5 << endl;
    else cout << f6 << endl;

    return 0;
}
