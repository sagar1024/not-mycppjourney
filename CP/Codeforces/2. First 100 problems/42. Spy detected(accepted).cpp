// A. Spy Detected!

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given an array a consisting of n (n≥3) positive integers. It is known that in this array, all the numbers except one are the same (for example, in the array [4,11,4,4] all numbers except one are equal to 4).

// Print the index of the element that does not equal others. The numbers in the array are numbered from one.

// Input
// The first line contains a single integer t (1≤t≤100). Then t test cases follow.

// The first line of each test case contains a single integer n (3≤n≤100) — the length of the array a.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100).

// It is guaranteed that all the numbers except one in the a array are the same.

// Output
// For each test case, output a single integer — the index of the element that is not equal to others.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Number of test cases
    int t;
    cin >> t;

    // Runnig the loop until t reaches 0
    while (t--)
    {
        int n;
        cin >> n;

        if (n < 3 || n > 100)
        {
            continue;
        }

        // Storing the numbers in an array
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        for (int i = 0; i < n; i++)
        {
            // Speacial case for the first two elements
            if (numbers[0] != numbers[1])
            {
                // Using the third element to know which one is the spy
                if (numbers[1] == numbers[2])
                {
                    // If the second and third element are same
                    // First element in the array is the spy
                    cout << 1 << endl;
                    break;
                }
                else
                {
                    // If the second and third element are not same
                    // Second element in the array is the spy
                    cout << 2 << endl;
                    break;
                }
            }

            // Keep iterating the array elements until it reaches the spy i.e unequal number
            else if (numbers[i] == numbers[i + 1])
            {
                continue;
            }

            // When the above condition fails
            // Output the Index of the spy + 1
            else
            {
                cout << i + 2 << endl;
                break;
            }
        }
    }

    return 0;
}

