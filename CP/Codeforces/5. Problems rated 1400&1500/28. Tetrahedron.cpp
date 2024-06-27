// E. Tetrahedron

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.

// Figure of a tetrahedron

// An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. The ant just can't stand on one place. You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (109 + 7).

// Input
// The first line contains the only integer n (1 ≤ n ≤ 107) — the required length of the cyclic path.

// Output
// Print the only integer — the required number of ways modulo 1000000007 (109 + 7).

// Examples
// inputCopy
// 2
// outputCopy
// 3
// inputCopy
// 4
// outputCopy
// 21

// Note
// The required paths in the first sample are:
// D - A - D
// D - B - D
// D - C - D

// Explanation - The number of ways to return to vertex D after n steps can be calculated based on the number of ways to reach each vertex from vertex D in n steps. The ant can move from D to any other vertex (A, B, or C) in 1 step, and from any other vertex back to D in 1 step as well. The ant can reach each of the other three vertices from D in one step, and from each of those vertices back to D in one step as well, resulting in a total of 3 ways to return to D in 1 step. For each additional step beyond the first, there are 3 possible edges the ant can traverse, leading to a total of 3 * 3 = 9 ways to return to D in 2 steps. Similarly, for each step beyond that, there are again 3 possible edges the ant can traverse, leading to a total of 3 * 3 * 3 = 27 ways to return to D in 3 steps. This pattern continues, resulting in the total number of ways to return to D after n steps being 3^n. However, if n is even, the ant can return to D along the same path, resulting in 3 additional ways. If n is odd, the ant cannot return to D along the same path, resulting in 3 fewer ways. Finally, to find the count modulo 1000000007 (109 + 7), the intermediate result is multiplied by the modular multiplicative inverse of 2 modulo 1000000007, which is 250000002. This ensures that the result remains within the range of representable integers

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    long long int n;
    cin >> n;

    // MAIN logic
    long long int answer = 0;

    //We have 3 choices for initial n-2 steps
    for (int i = 1; i <= n - 2; i++)
    {
        if(!answer)
        {
            answer = 1;
        }
        answer = (answer * 3) % mod;
    }

    //Second last step - we only have 2 choices as we have to avoid vertex D
    answer *= 2;

    //Then we have only one choice from each of the three vertex so we add 3
    answer += 3;

    cout << answer << endl;

    return 0;
}
