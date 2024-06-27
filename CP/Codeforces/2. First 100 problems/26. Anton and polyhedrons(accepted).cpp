// A. Anton and Polyhedrons

// time limit per test: 2 seconds
// memory limit per test: 256 megabytes
// input: standard input
// output: standard output

// Anton's favourite geometric figures are regular polyhedrons. Note that there are five kinds of regular polyhedrons:

// Tetrahedron. Tetrahedron has 4 triangular faces.
// Cube. Cube has 6 square faces.
// Octahedron. Octahedron has 8 triangular faces.
// Dodecahedron. Dodecahedron has 12 pentagonal faces.
// Icosahedron. Icosahedron has 20 triangular faces.

// All five kinds of polyhedrons are shown on the picture below:
// (Unable to copy the figure)

// Anton has a collection of n polyhedrons. One day he decided to know, how many faces his polyhedrons have in total. Help Anton and find this number!

// Input
// The first line of the input contains a single integer n (1 ≤ n ≤ 200 000) — the number of polyhedrons in Anton's collection.

// Each of the following n lines of the input contains a string si — the name of the i-th polyhedron in Anton's collection. The string can look like this:

// "Tetrahedron" (without quotes), if the i-th polyhedron in Anton's collection is a tetrahedron.
// "Cube" (without quotes), if the i-th polyhedron in Anton's collection is a cube.
// "Octahedron" (without quotes), if the i-th polyhedron in Anton's collection is an octahedron.
// "Dodecahedron" (without quotes), if the i-th polyhedron in Anton's collection is a dodecahedron.
// "Icosahedron" (without quotes), if the i-th polyhedron in Anton's collection is an icosahedron.

// Output
// Output one number — the total number of faces in all the polyhedrons in Anton's collection.

// Examples:

// Input 1 -
// 4
// Icosahedron
// Cube
// Tetrahedron
// Dodecahedron

// Output - 
// 42

// Input 2 - 
// 3
// Dodecahedron
// Octahedron
// Octahedron

// Output -
// 28

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Number of polyhedrons
    int n;
    cin >> n;

    //Name of the polyhedron
    string s;

    //Cumulative sum of number of faces of all polyhedrons
    int count = 0;

    //Iterating over each polyhedron 
    for(int i=0; i<n; i++)
    {
        //Taking input after every loop
        cin >> s;

        if(s == "Tetrahedron")
        {
            count += 4;
            continue;
        }
        if(s == "Cube")
        {
            count += 6;
            continue;
        }
        if(s == "Octahedron")
        {
            count += 8;
            continue;
        }
        if(s == "Dodecahedron")
        {
            count += 12;
            continue;
        }
        if(s == "Icosahedron")
        {
            count += 20;
            continue;
        }
    }

    //Printing the cumulative sum
    //Total number of faces in all polyhedrons
    cout << count << endl;

    return 0;
}
