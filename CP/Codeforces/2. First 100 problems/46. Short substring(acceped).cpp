// A. Short Substrings

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Alice guesses the strings that Bob made for her. At first, Bob came up with the secret string a consisting of lowercase English letters. The string a has a length of 2 or more characters. Then, from string a he builds a new string b and offers Alice the string b so that she can guess the string a.

// Bob builds b from a as follows: he writes all the substrings of length 2 of the string a in the order from left to right, and then joins them in the same order into the string b.

// For example, if Bob came up with the string a="abac", then all the substrings of length 2 of the string a are: "ab", "ba", "ac". Therefore, the string b="abbaac".

// You are given the string b. Help Alice to guess the string a that Bob came up with. It is guaranteed that b was built according to the algorithm given above. It can be proved that the answer to the problem is unique.

// Input
// The first line contains a single positive integer t (1≤t≤1000) — the number of test cases in the test. Then t test cases follow.

// Each test case consists of one line in which the string b is written, consisting of lowercase English letters (2≤|b|≤100) — the string Bob came up with, where |b| is the length of the string b. It is guaranteed that b was built according to the algorithm given above.

// Output
// Output t answers to test cases. Each answer is the secret string a, consisting of lowercase English letters, that Bob came up with.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Secret string
        string a = "";

        //Given string
        string b;
        cin >> b;

        // //Iterating over the given string
        // for(int i=0; i<b.size(); i++)
        // {
        //     //If the two adjacent letters are same
        //     //Skip the letter and move on
        //     if(b[i]==b[i+1])
        //     {
        //         continue;
        //     }
        //     //Storing the cleansed string after removing all the repetition
        //     // a[i] = b[i];

        //     //String a elements needs to be appended one by one
        //     //Instead of accessing each element of a to store the elements of b 
        //     a += b[i];
        // }

        //Incrementing i by 2 to get the required string
        for(int i=0; i<b.size(); i+=2)
        {
            //Appending the elements one by one
            a += b[i];
        }

        //If the string size is odd
        //Adding the last character of b to a
        a += b.back();

        cout << a << endl;
    }
    
    return 0;
}
