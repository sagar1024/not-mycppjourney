// A. Divisibility Problem

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// You are given two positive integers a and b. In one move you can increase a by 1(replace a with a+1). Your task is to find the minimum number of moves you need to do in order to make a divisible by b. It is possible, that you have to make 0 moves, as a is already divisible by b. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t(1≤t≤10^4) — the number of test cases. Then t test cases follow. The only line of the test case contains two integers a and b(1≤a&b≤10^9)

// Output
// For each test case print the answer — the minimum number of moves you need to do in order to make a divisible by b

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    //Here a is the dividend, b is the divisor
    int a, b;

    int moves = 0;

    //For each test case
    for(int i=1; i<=t; i++)
    {
        //Taking input for each test case
        cin >> a >> b;

        if(a%b==0)
        {
            moves = 0;
            cout << moves << endl;
        }

        else if(a>b)
        {
            //Subtracting the divisor by the remainder
            //Gives us the required number of moves(a=a+1) to make 
            moves = b - (a%b);
            cout << moves << endl;
        }

        else if(a<b)
        {
            //If a is smaller than b, then their difference is the number of moves required to be made
            moves = b - a;
            cout << moves << endl;
        }
    }

    return 0;
}
