// A. Beautiful Year

// time limit per test: 2 seconds
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits. Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.

// Input
// The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

// Output
// Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.

// #include <iostream>
// using namespace std;

// First attempt

// int main()
// {
//     int y;
//     cin >> y;

//     int alt_y = y;

//     if (1000 <= y && y <= 9000)
//     {
//         int a = y % 10;

//         y = y / 10;
//         int b = y % 10;

//         y = y / 10;
//         int c = y % 10;

//         y = y / 10;
//         int d = y % 10;

//         while(a!=b && b!=c && c!=d && d!=a)
//         {
//             alt_y++;
//         }
//     }

//     cout << alt_y << endl;

//     return  0;
// }

// Second attempt

#include <iostream>
using namespace std;

bool isDistinct(int year)
{
    string x = to_string(year);
    int length1 = x.length();

    for(int i=0; i<length1; i++)
    {
        for(int j=i+1; j<length1; j++)
        {
            if(x[i]==x[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int y;
    cin >> y;

    while(true)
    {
        y++;
        if(isDistinct(y))
        {
            cout << y << endl;
            break;
        }
    }

    return 0;
}