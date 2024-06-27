// B. Different Divisors

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Positive integer x is called divisor of positive integer y, if y is divisible by x without remainder. For example, 1 is a divisor of 7 and 3 is not divisor of 8. We gave you an integer d and asked you to find the smallest positive integer a, such that

// a has at least 4 divisors;
// difference between any two divisors of a is at least d.

// Input
// The first line contains a single integer t (1≤t≤3000) — the number of test cases. The first line of each test case contains a single integer d (1≤d≤10000).

// Output
// For each test case print one integer a — the answer for this test case.

// Example
// inputCopy
// 2
// 1
// 2
// outputCopy
// 6
// 15

// Note
// In the first test case, integer 6 have following divisors: [1,2,3,6]. There are 4 of them and the difference between any two of them is at least 1. There is no smaller integer with at least 4 divisors.
// In the second test case, integer 15 have following divisors: [1,3,5,15]. There are 4 of them and the difference between any two of them is at least 2.
// The answer 12 is INVALID because divisors are [1,2,3,4,6,12]. And the difference between, for example, divisors 2 and 3 is less than d=2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// int lcm(int a, int b)
// {
//     return abs(a * b) / gcd(a, b);
// }

// int lmcOf4(int a, int b, int c, int d)
// {
//     return lcm(lcm(lcm(a, b), c), d);
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int d;
//         cin >> d;

//         int first = 1;
//         int second = first + d;
//         int third = second + d;
//         int fourth = third + d;

//         cout << lmcOf4(first, second, third, fourth) << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Function to check if a number is prime
// bool isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }
//     for (int i=2; i<=sqrt(n); i++)
//     {
//         if (n%i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// //Finding the next prime number coming after a given number
// int findNextPrime(int current)
// {
//     while (!isPrime(current))
//     {
//         current++;
//     }
//     return current;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int d;
//         cin >> d;

//         //Main logic
//         //Choosing four consecutive prime numbers
//         int first = 1;
//         int second = findNextPrime(first + d);
//         int third = findNextPrime(second + d);
//         int fourth = findNextPrime(third + d);

//         cout << first*second*third*fourth << endl;
//     }

//     return 0;
// }

//Alternate soln(spent 8+ days) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

//Finding the next prime number coming after a given number
int findNextPrime(int current)
{
    while (!isPrime(current))
    {
        current++;
    }
    return current;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Diff btw two divisors
        int d;
        cin >> d;

        //MAIN LOGIC

        //Theory behind the formula -
        
        //To find the smallest integer
        //We need 4 small numbers, as small as possible
        //The 1st num will be 1
        //Smallest and divisor of all integers
        //The 4th & last num will be the required num itself
        //The second num will be ofcourse 1+d
        //The third num will be 1+2d
        //To calculate 4th num
        //We just have to 2ndx3rd

        //long long int smallestPositiveInteger = (1+d)*(1+2*d);
        //cout << smallestPositiveInteger << endl;

        //Finding the four divisors
        //Form of 1, p, q, pq
        //int firstNum1 = 1;
        int secondNum1 = findNextPrime(1+d);
        long int thirdNum1 = findNextPrime(secondNum1+d);

        //1LL is important here
        long long int fourthNum1 = abs(1LL*secondNum1*thirdNum1);

        //Form of 1, p, p^2, p^3
        //int firstNum2 = 1;
        int secondNum2 = findNextPrime(1+d);
        long int thirdNum2 = pow(secondNum2, 2);

        //1LL is basically long long 1 or literal of long long type
        long long int fourthNum2 = abs(1LL*secondNum2*thirdNum2);

        //Printing the min of the two
        long long int smallestPositiveInteger = min(fourthNum1, fourthNum2);
        cout << smallestPositiveInteger << endl;
    }

    return 0;
}
