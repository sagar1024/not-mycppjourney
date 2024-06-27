// A. Even Odds

// time limit per test: 1 second
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Being a nonconformist, Volodya is displeased with the current state of things, particularly with the order of natural numbers (natural number is positive integer number). He is determined to rearrange them. But there are too many natural numbers, so Volodya decided to start with the first n. He writes down the following sequence of numbers: firstly all odd integers from 1 to n (in ascending order), then all even integers from 1 to n (also in ascending order). Help our hero to find out which number will stand at the position number k.

// Input
// The only line of input contains integers n and k (1 ≤ k ≤ n ≤ 1012).

// Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Output
// Print the number that will stand at the position number k after Volodya's manipulations.

//The code is showing runtime error :/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arranged_num(n);

    for(int i=1; i<=n; i++)
    {
        //Odds ones in the first half
        if(i%2 != 0)
        {
            arranged_num[(i+1)/2] = i;
        }

        //Followed by even ones
        if(i%2 == 0)
        {
            arranged_num[(n/2)+i] = i;
        }
    }

    cout << arranged_num[k] << endl;

    return 0;
}
