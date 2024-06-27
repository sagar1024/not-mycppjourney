// B. Minimum Product

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given four integers a, b, x and y. Initially, a≥x and b≥y. You can do the following operation no more than n times: Choose either a or b and decrease it by one. However, as a result of this operation, value of a cannot become less than x, and value of b cannot become less than y. Your task is to find the minimum possible product of a and b (a⋅b) you can achieve by applying the given operation no more than n times. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The only line of the test case contains five integers a, b, x, y and n (1≤a,b,x,y,n≤109). Additional constraint on the input: a≥x and b≥y always holds.

// Output
// For each test case, print one integer: the minimum possible product of a and b (a⋅b) you can achieve by applying the given operation no more than n times.

// Example
// inputCopy
// 7
// 10 10 8 5 3
// 12 8 8 7 2
// 12343 43 4543 39 123212
// 1000000000 1000000000 1 1 1
// 1000000000 1000000000 1 1 1000000000
// 10 11 2 1 5
// 10 11 9 1 10

// outputCopy
// 70
// 77
// 177177
// 999999999000000000
// 999999999
// 55
// 10

// Note
// In the first test case of the example, you need to decrease b three times and obtain 10⋅7=70.
// In the second test case of the example, you need to decrease a one time, b one time and obtain 11⋅7=77.
// In the sixth test case of the example, you need to decrease a five times and obtain 5⋅11=55.
// In the seventh test case of the example, you need to decrease b ten times and obtain 10⋅1=10.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         long long int a, b, x, y, n;
//         cin >> a >> b >> x >> y >> n;

//         //MAIN logic
//         //Decrementing the lower num to obtain the min product
//         if(a<=b)
//         {
//             while(a>x && n>0)
//             {
//                 a--;
//                 n--;
//             }
//             while(b>y && n>0)
//             {
//                 b--;
//                 n--;
//             }
//         }
//         else
//         {
//             while(b>y && n>0)
//             {
//                 b--;
//                 n--;
//             }
//             while(a>x && n>0)
//             {
//                 a--;
//                 n--;
//             }
//         }

//         int result = a*b;
//         cout << result << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <algorithm>

using namespace std;

long long minProduct(long long a, long long b, long long x, long long y, long long n)
{
    //Decrement a
    long long int dA = min(n, a - x);
    a -= dA;
    n -= dA;
    //Decrement b
    long long int dB = min(n, b - y);
    b -= dB;

    return a * b;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        //MAIN logic
        //Different order of arguments
        long long int ans1 = minProduct(a, b, x, y, n);
        long long int ans2 = minProduct(b, a, y, x, n);

        cout << min(ans1, ans2) << endl;
    }

    return 0;
}
