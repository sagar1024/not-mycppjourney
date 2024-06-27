// A. Calculating Function

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// For a positive integer n let's define a function f:
// f(n) =  - 1 + 2 - 3 + .. + ((-1)^n)*n

// Your task is to calculate f(n) for a given integer n.

// Input
// The single line contains the positive integer n(1≤n≤10^15).

// Output
// Print f(n) in a single line.

// CODE:

// #include <iostream>
// #include <math.h>
// using namespace std;

// int myFunction(long int n)
// {
//     int answer = 0;
//     for(int i=1; i<=n; i++)
//     {
//         answer = answer + i*(pow(-1, i));
//     }
//     return answer;
// }

// int main()
// {
//     long int n;
//     cin >> n;

//     if(1<=n && n<=1e15)
//     {
//         cout << myFunction(n) << endl;
//     }
//     else
//     {
//         return -1;
//     }

//     return 0;
// }

// ChatGPT CODE:

#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << endl;
    } else {
        cout << -(n + 1) / 2 << endl;
    }

    return 0;
}
