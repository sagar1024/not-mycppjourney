// B. Perfect Number

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// We consider a positive integer perfect, if and only if the sum of its digits is exactly 10. Given a positive integer k, your task is to find the k-th smallest perfect positive integer.

// Input
// A single line with a positive integer k (1≤k≤10000).

// Output
// A single number, denoting the k-th smallest perfect integer.

// Examples
// inputCopy
// 1
// outputCopy
// 19
// inputCopy
// 2
// outputCopy
// 28

// Note
// The first perfect integer is 19 and the second one is 28.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int k;
//     cin >> k;

//     string givenNum = to_string(k);
//     int size = givenNum.size();

//     int answer = (k+size)*9+1;
//     cout << answer << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to calculate the sum of digits of a number
int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int k;
    cin >> k;

    //Starting from 19 and find the k-th smallest perfect positive integer
    int count = 0;
    for (int i = 19; ; ++i)
    {
        if (sumOfDigits(i) == 10)
        {
            count++;
            if (count == k)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
