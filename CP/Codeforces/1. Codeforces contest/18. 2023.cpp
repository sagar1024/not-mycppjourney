// A. 2023

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In a sequence a, whose product was equal to 2023, k numbers were removed, leaving a sequence b of length n. Given the resulting sequence b, find any suitable sequence a and output which k elements were removed from it, or state that such a sequence could not have existed. Notice that you are not guaranteed that such array exists.

// Input
// Each test consists of several test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. This is followed by a description of the test cases. The first line of each test case contains two integers n (1≤n,k≤5) — the size of sequence b and the number of numbers removed from sequence a. The second line contains n integers b1,b2,…,bn (1≤bi≤2023) — the remaining sequence. The values of bi might not be divisors of 2023.

// Output
// For each test case, output "YES" if the sequence a exists, and in the following line output k non-negative integers that were removed from the sequence a. If the sequence a does not exist, output "NO" in a single line. You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

// Example
// inputCopy
// 7
// 2 2
// 5 2
// 3 1
// 7 17 7
// 4 2
// 1 289 1 1
// 3 1
// 7 17 17
// 1 1
// 289
// 1 1
// 2023
// 1 3
// 1
// outputCopy
// NO
// NO
// YES
// 7 1
// YES
// 1
// YES
// 7
// YES
// 1
// YES
// 7 17 17

// Note
// In third test case product is equal to 289⋅7=2023.
// In fourth test case product is already equal to 2023.
// In seventh test case product is equal to 7⋅17⋅17=2023.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Size of the sequence b
        int b;
        cin >> b;

        // Num of elements removed from sequence a
        int k;
        cin >> k;

        // Elements of sequence b
        vector<int> seqB(b);
        int seqProductB = 1;
        for (int i = 0; i < b; i++)
        {
            cin >> seqB[i];
            seqProductB *= seqB[i];
        }

        // Product of all elements of sequence a
        // int product = 2023;

        // Dividing the product by the elements of seqB
        // float remainingProduct = product/seqProductB;

        // If the remaining product has no decimal value
        // Then the sequence a exists
        //  bool sequenceExists = false;
        //  if(floor(remainingProduct)==remainingProduct)
        //  {
        //      sequenceExists = true;
        //  }

        // //If the seq a exists
        // if(sequenceExists)
        // {
        //     cout << "YES" << endl;

        //     //Printing the k elements
        //     for(int i=0; i<k; i++)
        //     {
        //         if(i==0)
        //         {
        //             cout << remainingProduct << " ";
        //         }
        //         cout << 1 << " ";
        //     }
        //     cout << endl;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }

        // Checking if sequence 'a' exists
        if (2023 % seqProductB == 0 && 2023 / seqProductB > 0)
        {
            cout << "YES" << endl;

            // Finding elements removed from sequence 'a'
            int remainingProduct = 2023 / seqProductB;
            for (int i = 0; i < k; i++)
            {
                if(i==0)
                {
                    cout << remainingProduct << " ";
                    continue;
                }
                cout << 1 << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
