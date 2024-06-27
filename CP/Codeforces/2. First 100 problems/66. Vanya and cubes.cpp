// A. Vanya and Cubes

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vanya got n cubes. He decided to build a pyramid from them. Vanya wants to build the pyramid as follows: the top level of the pyramid must consist of 1 cube, the second level must consist of 1 + 2 = 3 cubes, the third level must have 1 + 2 + 3 = 6 cubes, and so on. Thus, the i-th level of the pyramid must have 1 + 2 + ... + (i - 1) + i cubes. Vanya wants to know what is the maximum height of the pyramid that he can make using the given cubes.

// Input
// The first line contains integer n (1 ≤ n ≤ 104) — the number of cubes given to Vanya.

// Output
// Print the maximum possible height of the pyramid in the single line.

//My original soln

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    //Number of cubes in ith layer
    int numOfCubes = 0;
    //Total number of cubes used
    int totalNumOfCubes = 0;
    //Number of levels in the pyramid structure
    int maxHeight = 0;

    //Taking care of 1 cube separately
    //To reduce the time complexity
    //Now we can reduce the for loop traversal down to n/2 number of cubes
    if(n==1 || n==2 || n==3)
    {
        return 1;
    }
    for(int i=1; i<=n/2; i++)
    {
        //Once the total number of cubes used exceeds number of cubes, return the height i.e number of layers
        //No subtraction needed
        if(totalNumOfCubes==n)
        {
            return maxHeight;
        }
        //Subtracting by 1 to nullify the effect of extra loop
        if(totalNumOfCubes>n)
        {
            return maxHeight-1;
        }
        //Number of cubes in the next layer increases by i
        numOfCubes += i;
        //Total number of cubes
        totalNumOfCubes +=numOfCubes;
        maxHeight++;
    }
}

int main()
{
    //Number of cubes
    int n;
    cin >> n;

    //Return doesnt print values
    //Hence
    int answer = solve(n);
    cout << answer << endl;

    return 0;
}
