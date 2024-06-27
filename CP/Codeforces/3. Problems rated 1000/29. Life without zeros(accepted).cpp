// A. Life Without Zeros

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Can you imagine our life if we removed all zeros from it? For sure we will have many problems. In this problem we will have a simple example if we removed all zeros from our life, it's the addition operation. Let's assume you are given this equation a + b = c, where a and b are positive integers, and c is the sum of a and b. Now let's remove all zeros from this equation. Will the equation remain correct after removing all zeros? For example if the equation is 101 + 102 = 203, if we removed all zeros it will be 11 + 12 = 23 which is still a correct equation. But if the equation is 105 + 106 = 211, if we removed all zeros it will be 15 + 16 = 211 which is not a correct equation.

// Input
// The input will consist of two lines, the first line will contain the integer a, and the second line will contain the integer b which are in the equation as described above (1 ≤ a, b ≤ 109). There won't be any leading zeros in both. The value of c should be calculated as c = a + b.

// Output
// The output will be just one line, you should print "YES" if the equation will remain correct after removing all zeros, and print "NO" otherwise.

// Examples
// inputCopy
// 101
// 102
// outputCopy
// YES
// inputCopy
// 105
// 106
// outputCopy
// NO

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to remove zeros
// int removeZeros(int x)
// {
//     string s = to_string(x);

//     //Erasing the zeros
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]=='0')
//         {
//             s.erase(i,1);
            
//             //Updating i after erasing an element
//             i--;
//         }
//     }

//     //String to integer
//     int a = stoi(s);
//     return a;
// }

//Function to remove zeros - simplified and correct
int removeZeros(int x)
{
    int result = 0;
    int power = 1;

    while (x > 0)
    {
        int digit = x % 10;
        if (digit != 0)
        {
            result += digit * power;
            power *= 10;
        }
        x /= 10;
    }

    return result;
}

int main()
{
    long long int a, b;
    cin >> a >> b;

    //Original equation
    long long sum = a + b;

    int A_Without0 = removeZeros(a);
    int B_Without0 = removeZeros(b);
    int SUM_Without0 = removeZeros(sum);

    //Checking the equality of newly made equation
    if(A_Without0 + B_Without0 == SUM_Without0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
