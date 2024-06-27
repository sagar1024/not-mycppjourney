// A. Division?

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Codeforces separates its users into 4 divisions by their rating:

// For Division 1: 1900≤rating
// For Division 2: 1600≤rating≤1899
// For Division 3: 1400≤rating≤1599
// For Division 4: rating≤1399
// Given a rating, print in which division the rating belongs.

// Input
// The first line of the input contains an integer t (1≤t≤104) — the number of testcases.

// The description of each test consists of one line containing one integer rating (−5000≤rating≤5000).

// Output
// For each test case, output a single line containing the correct division in the format "Division X", where X is an integer between 1 and 4 representing the division for the corresponding rating.

// My Original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int rating;
//         cin >> rating;

//         //To convert the -ve numbers to +ve
//         int x = abs(rating);

//         //Using simple if statements
//         if(x>=1900)
//         {
//             cout << "Division 1" << endl;
//         }
//         else if(x<=1899 && x>=1600)
//         {
//             cout << "Division 2" << endl;
//         }
//         else if(x<=1599 && x>=1400)
//         {
//             cout << "Division 3" << endl;
//         }
//         else if(x<=1399)
//         {
//             cout << "Division 4" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        long long int rating;
        cin >> rating;

        //Converting the negative numbers to positive
        //int x = abs(rating);
        long long int x = rating;

        if (x >= 1900)
        {
            cout << "Division 1" << endl;
        }
        else if (x >= 1600)
        {
            cout << "Division 2" << endl;
        }
        else if (x >= 1400)
        {
            cout << "Division 3" << endl;
        }
        else
        {
            cout << "Division 4" << endl;
        }
    }

    return 0;
}
