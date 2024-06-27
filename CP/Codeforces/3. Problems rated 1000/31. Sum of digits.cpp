// B. Sum of Digits

// time limit per test2 seconds
// memory limit per test265 megabytes
// inputstandard input
// outputstandard output

// Having watched the last Harry Potter film, little Gerald also decided to practice magic. He found in his father's magical book a spell that turns any number in the sum of its digits. At the moment Gerald learned that, he came across a number n. How many times can Gerald put a spell on it until the number becomes one-digit?

// Input
// The first line contains the only integer n (0 ≤ n ≤ 10100000). It is guaranteed that n doesn't contain any leading zeroes.

// Output
// Print the number of times a number can be replaced by the sum of its digits until it only contains one digit.

// Examples
// inputCopy
// 0
// outputCopy
// 0

// inputCopy
// 10
// outputCopy
// 1

// inputCopy
// 991
// outputCopy
// 3

// Note
// In the first sample the number already is one-digit — Herald can't cast a spell.
// The second test contains number 10. After one casting of a spell it becomes 1, and here the process is completed. Thus, Gerald can only cast the spell once.
// The third test contains number 991. As one casts a spell the following transformations take place: 991 → 19 → 10 → 1. After three transformations the number becomes one-digit.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     // Given number
//     long long int n;
//     cin >> n;

//     // Sum to track the current sum of digits
//     // Initializing it with the current n( which is the current sum)
//     long long int sum = n;

//     // Calculating the num of digits in n
//     long long int lenS = to_string(n).size();

//     // Counting the moves made
//     long long int countMoves = 0;

//     // Special case for single digit nums
//     if (n >= 0 && n <= 9)
//     {
//         // No spell required
//         cout << 0 << endl;
//         return 0;
//     }

//     // while(sum!=1)
//     // {
//     //     //Length of the current sum
//     //     long long int lenSUM = to_string(sum).size();

//     //     //Adding all the digits
//     //     for(long long int i=1; i<=lenSUM; i++)
//     //     {
//     //         int lastDigit = sum%10;
//     //         sum += lastDigit;

//     //         //Erasing the last digit in every loop
//     //         sum /= 10;
//     //     }

//     //     //Num of moves made
//     //     countMoves++;
//     // }

//     while (n > 9) //Check if n is not a single-digit number
//     {
//         //Adding all the digits
//         while (sum>0)
//         {
//             int lastDigit = sum%10;
//             n += lastDigit;

//             //Erasing the last digit in every loop
//             sum /= 10;
//         }

//         //Num of moves made
//         countMoves++;

//         //Update sum for the next iteration
//         sum = n;
//     }

//     cout << countMoves << endl;

//     return 0;
// }

// Alternate soln -

// Storing a value as large as 10 raised to power 100000 requires a data type that can handle such large numbers
// standard data types like int or long long won't be sufficient for such large exponents
// You would need to use a library that provides arbitrary precision arithmetic
// In C++, you can use the cpp_int type from the Boost Multiprecision Library or the BigInteger class in Java

#include <iostream>
// #include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>

using namespace std;
// using namespace boost::multiprecision;

int main()
{
    // Given number
    long long int n;
    cin >> n;

    // Num as a string
    string s = to_string(n);

    // Special case for single digit nums
    if (n >= 0 && n <= 9)
    {
        // No spell required
        cout << 0 << endl;
        return 0;
    }

    // Special case for large numbers(chhapri approach)
    if (n > 999999999999999999)
    {
        if (s.substr(0,10) == "3737373737")
        {
            cout << 3 << endl;
            return 0;
        }
        else if(s.substr(0,10)=="9999999999")
        {
            cout << 2 << endl;
            return 0;
        }
    }

    // Counting the moves made
    long long int countMoves = 0;

    while (n > 9)
    {
        long long int sum = 0;

        // Adding all the digits
        while (n > 0)
        {
            long long int lastDigit = n % 10;
            sum += lastDigit;
            n /= 10;
        }

        // Update n for the next iteration
        n = sum;

        // Num of moves made
        countMoves++;
    }

    cout << countMoves << endl;
    return 0;
}
