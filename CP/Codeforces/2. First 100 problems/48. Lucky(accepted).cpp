// A. Lucky?

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A ticket is a string consisting of six digits. A ticket is considered lucky if the sum of the first three digits is equal to the sum of the last three digits. Given a ticket, output if it is lucky or not. Note that a ticket can have leading zeroes.

// Input
// The first line of the input contains an integer t (1≤t≤103) — the number of testcases. The description of each test consists of one line containing one string consisting of six digits.

// Output
// Output t lines, each of which contains the answer to the corresponding test case. Output "YES" if the given ticket is lucky, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Ticket number
        string s;
        cin >> s;

        //Converting the string to integer array to perform mathematical operation
        vector<int> numbers(s.size());
        for(int i=0; i<s.size(); i++)
        {
            numbers[i] = int(s[i]);
        }

        //Main logic
        if(numbers[0]+numbers[1]+numbers[2]==numbers[3]+numbers[4]+numbers[5])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

