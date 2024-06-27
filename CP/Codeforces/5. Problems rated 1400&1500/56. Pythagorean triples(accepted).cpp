// D. Pythagorean Triples

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A Pythagorean triple is a triple of integer numbers (a,b,c) such that it is possible to form a right triangle with the lengths of the first cathetus, the second cathetus and the hypotenuse equal to a, b and c, respectively. An example of the Pythagorean triple is (3,4,5). Vasya studies the properties of right triangles, and he uses a formula that determines if some triple of integers is Pythagorean. Unfortunately, he has forgotten the exact formula; he remembers only that the formula was some equation with squares. So, he came up with the following formula: c=a2−b. Obviously, this is not the right formula to check if a triple of numbers is Pythagorean. But, to Vasya's surprise, it actually worked on the triple (3,4,5): 5=32−4, so, according to Vasya's formula, it is a Pythagorean triple. When Vasya found the right formula (and understood that his formula is wrong), he wondered: how many are there triples of integers (a,b,c) with 1≤a≤b≤c≤n such that they are Pythagorean both according to his formula and the real definition? He asked you to count these triples.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Each test case consists of one line containing one integer n (1≤n≤109).

// Output
// For each test case, print one integer — the number of triples of integers (a,b,c) with 1≤a≤b≤c≤n such that they are Pythagorean according both to the real definition and to the formula Vasya came up with.

// Example
// inputCopy
// 3
// 3
// 6
// 9
// outputCopy
// 0
// 1
// 1

// Note
// The only Pythagorean triple satisfying c=a2−b with 1≤a≤b≤c≤9 is (3,4,5); that's why the answer for n=3 is 0, and the answer for n=6 (and for n=9) is 1.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// bool binary_search(vector<long long int> arr, long long int x)
// {
//     int left = 0;
//     int right = arr.size() - 1; //Adjusted the right boundary

//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2; //Updated mid calculation
//         if (arr[mid] < x) {
//             left = mid + 1;
//         }
//         else if (arr[mid] > x) {
//             right = mid - 1;
//         }
//         else if (arr[mid] == x) {
//             return true;
//         }
//     }

//     return false; //Return false if element is not found
// }


// void solve()
// {
//     long long int n;
//     cin >> n;

//     vector<long long int> givenArray(n+1);
//     for(int i=0; i<n; i++)
//     {
//         givenArray[i] = i+1;
//     }

//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             bool found1 = binary_search(givenArray, (pow(i,2)-j));
//             bool found2 = binary_search(givenArray, sqrt(pow(i,2)+pow(j,2)));

//             if(found1 && found2)
//             {
//                 count++;
//             }
//         }
//     }

//     cout << count << endl;
    
//     return;
// }

// int32_t main()
// {
//     fastio;
    
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln(tutorial help) -

//We have to find the number of triples (a,b,c) such that equations a2+b2=c2 and a2−b=c are satisfied. Let's subtract one equation from another and get that b2+b=c2−c⟹b(b+1)=c(c−1). So we know that c=b+1 and after substituting, we get that a2=2b+1. We can see that there is only one correct value of b (and c) for every odd value of a (greater than 1). So we can iterate over the value of a and check that the corresponding value of doesn't exceed n. This solution works in O(n−−√) because a≈c√≤n−−√, but you can also solve it in O(1)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    long long int n;
    cin >> n;

    //Initialization: The loop starts with a = 3, which is the smallest odd integer greater than 1
    //Condition: The loop continues as long as the square of a (a * a) is less than or equal to 2 * n. This condition ensures that a^2 doesn't exceed 2 * n, as we're only interested in values of a where a^2 could potentially be equal to 2 * b + 1
    //Increment: After each iteration, a is incremented by 2. This ensures that a remains an odd number, as only odd values of a can result in valid Pythagorean triples (since a^2 will be odd).
    int count = 0;
    for(int a=3; a*a<=2*n; a+=2)
    {
        count++;
    }

    cout << count << endl;
    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
