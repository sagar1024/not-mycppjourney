// A. Dislike of Threes

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarp doesn't like integers that are divisible by 3 or end with the digit 3 in their decimal representation. Integers that meet both conditions are disliked by Polycarp, too. Polycarp starts to write out the positive (greater than 0) integers which he likes: 1,2,4,5,7,8,10,11,14,16,... Output the k-th element of this sequence (the elements are numbered from 1).

// Input
// The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow. Each test case consists of one line containing one integer k (1≤k≤1000).

// Output
// For each test case, output in a separate line one integer x — the k-th element of the sequence that was written out by Polycarp.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        //To find the kth position
        int k;
        cin >> k;

        //Creating an uninitialized array to store the polycarp sequence
        vector<int> polycarpSequence;

        //ATQ, the max value of k could be as high as 1000
        //Hence, calculating the sequence till some random number like 3000(i.e triple of 1000)
        int maxNaturalNum = 3000;

        //Calculating and storing the polycarp sequence
        for(int i=1; i<maxNaturalNum; i++)
        {
            if(i%3==0 || i%10==3)
            {
                continue;
            }
            else
            {
                //We use pushback method to append the elements in an uninitialized vector
                polycarpSequence.push_back(i);
            }
        }
        //Printing the kth element of the sequence
        cout << polycarpSequence[k-1] << endl;
    }

    return 0;
}

