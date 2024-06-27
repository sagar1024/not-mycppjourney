// A. Holiday Of Equality

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In Berland it is the holiday of equality. In honor of the holiday the king decided to equalize the welfare of all citizens in Berland by the expense of the state treasury.

// Totally in Berland there are n citizens, the welfare of each of them is estimated as the integer in ai burles (burle is the currency in Berland).

// You are the royal treasurer, which needs to count the minimum charges of the kingdom on the king's present. The king can only give money, he hasn't a power to take away them.

// Input
// The first line contains the integer n (1 ≤ n ≤ 100) — the number of citizens in the kingdom.

// The second line contains n integers a1, a2, ..., an, where ai (0 ≤ ai ≤ 106) — the welfare of the i-th citizen.

// Output
// In the only line print the integer S — the minimum number of burles which are had to spend.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    //Num of citizens
    int n;
    cin >> n;

    //Storing the welfare in an array
    vector<long int> welfare(n);
    for(int i=0; i<n; i++)
    {
        cin >> welfare[i];
    }

    //Sorting the welfare array
    sort(welfare.begin(), welfare.end());

    //Storing the max value in the array
    int z = welfare[n-1];

    //Total welfare needed
    int sum = 0;

    //Iterating over each citizen
    for(int i=0; i<n; i++)
    {
        //If the welfare of the current citizen is less than the highest welfare
        if(welfare[i]<z)
        {
            //Then keep adding the difference between them in a sum variable
            sum += z-welfare[i];
        }
    }

    cout << sum << endl;

    return 0;
}

