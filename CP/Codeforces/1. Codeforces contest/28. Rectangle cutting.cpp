// A. Rectangle Cutting

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Bob has a rectangle of size a×b. He tries to cut this rectangle into two rectangles with integer sides by making a cut parallel to one of the sides of the original rectangle. Then Bob tries to form some other rectangle from the two resulting rectangles, and he can rotate and move these two rectangles as he wishes. Note that if two rectangles differ only by a 90∘ rotation, they are considered the same. For example, the rectangles 6×4 and 4×6 are considered the same. Thus, from the 2×6 rectangle, another rectangle can be formed, because it can be cut into two 2×3 rectangles, and then these two rectangles can be used to form the 4×3 rectangle, which is different from the 2×6 rectangle. However, from the 2×1 rectangle, another rectangle cannot be formed, because it can only be cut into two rectangles of 1×1, and from these, only the 1×2 and 2×1 rectangles can be formed, which are considered the same. Help Bob determine if he can obtain some other rectangle, or if he is just wasting his time.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. This is followed by the description of the test cases. The single line of each test case contains two integers a and b (1≤a,b≤109) — the size of Bob's rectangle.

// Output
// For each test case, output "Yes" if Bob can obtain another rectangle from the a×b rectangle. Otherwise, output "No". You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

// Example
// inputCopy
// 7
// 1 1
// 2 1
// 2 6
// 3 2
// 2 2
// 2 4
// 6 3
// outputCopy
// No
// No
// Yes
// Yes
// Yes
// Yes
// No

// Note
// In the first test case, the 1×1 rectangle cannot be cut into two rectangles, so another rectangle cannot be obtained from it.
// In the fourth test case, the 3×2 rectangle can be cut into two 3×1 rectangles, and from these, the 1×6 rectangle can be formed.
// In the fifth test case, the 2×2 rectangle can be cut into two 1×2 rectangles, and from these, the 1×4 rectangle can be formed.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Sides of rect
//         long long int a, b;
//         cin >> a >> b;

//         //MAIN logic
//         //long long int longerSide = max(a,b);
//         //long long int shorterSide = min(a,b);

//         if((a%2==0 && a>=2) || (b%2==0 && b>=2))
//         {
//             if(a/b==2 && b%2!=0)
//             {
//                 cout << "No" << endl;
//             }
//             else
//             {
//                 cout << "Yes" << endl;
//             }
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
using namespace std;

int main()
{
    //Number of test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Inputting sides of the rectangle
        long long int a, b;
        cin >> a >> b;

        //Checking if both sides are even
        if (a%2==0 && b%2==0 && a>=2 && b>=2)
        {
            cout << "Yes" << endl;
        }
        //Checking if both sides are odd
        else if (a%2!=0 && b%2!=0)
        {
            cout << "No" << endl;
        }

        //CRUX
        //When one is even and the other is odd
        //The rect should not be in 2:1 ratio
        // else if((a==2 && b==1) || (a==1 && b==2))
        // {
        //     cout << "No" << endl;
        // }
        else if((max(a,b)/min(a,b)==2) && (min(a,b)%2!=0))
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
