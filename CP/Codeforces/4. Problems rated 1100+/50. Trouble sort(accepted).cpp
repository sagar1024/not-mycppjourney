// B. Trouble Sort

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Ashish has n elements arranged in a line. These elements are represented by two integers ai — the value of the element and bi — the type of the element (there are only two possible types: 0 and 1). He wants to sort the elements in non-decreasing values of ai. He can perform the following operation any number of times:

// Select any two elements i and j such that bi≠bj and swap them. That is, he can only swap two elements of different types in one move.

// Tell him if he can sort the elements in non-decreasing values of ai after performing any number of operations.

// Input
// The first line contains one integer t (1≤t≤100) — the number of test cases. The description of the test cases follows. The first line of each test case contains one integer n (1≤n≤500) — the size of the arrays. The second line contains n integers ai (1≤ai≤105) — the value of the i-th element. The third line containts n integers bi (bi∈{0,1}) — the type of the i-th element.

// Output
// For each test case, print "Yes" or "No" (without quotes) depending on whether it is possible to sort elements in non-decreasing order of their value. You may print each letter in any case (upper or lower).

// Example
// inputCopy
// 5
// 4
// 10 20 20 30
// 0 1 0 1
// 3
// 3 1 2
// 0 1 1
// 4
// 2 2 4 8
// 1 1 1 1
// 3
// 5 15 4
// 0 0 0
// 4
// 20 10 100 50
// 1 0 0 1
// outputCopy
// Yes
// Yes
// Yes
// No
// Yes

// Note
// For the first case: The elements are already in sorted order.
// For the second case: Ashish may first swap elements at positions 1 and 2, then swap elements at positions 2 and 3.
// For the third case: The elements are already in sorted order.
// For the fourth case: No swap operations may be performed as there is no pair of elements i and j such that bi≠bj. The elements cannot be sorted.
// For the fifth case: Ashish may swap elements at positions 3 and 4, then elements at positions 1 and 2.

// My original soln -

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
//         //Inputs
//         int n;
//         cin >> n;

//         vector<pair<int,int>> a(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i].first;
//         }
//         for(int i=0; i<n; i++)
//         {
//             cin >> a[i].second;
//         }

//         //MAIN logic
//         bool possible1 = true;
//         bool possible2 = true;

//         int x=0, y=0;

//         //Checking if the elements with same type(0 OR 1) are in ascending order or not
//         //If NOT, then the array can never be sorted
//         for(int i=0; i<n; i++)
//         {
//             if(a[i].second==0)
//             {
//                 //The succeeding element should always be greater than the previous element
//                 //Else set false and break away from the loop
//                 if(x<=a[i].first)
//                 {
//                     x = a[i].first;
//                 }
//                 else
//                 {
//                     possible1 = false;
//                     break;
//                 }
//             }
//             else if(a[i].second==1)
//             {
//                 if(y<=a[i].first)
//                 {
//                     y = a[i].first;
//                 }
//                 else
//                 {
//                     possible2 = false;
//                     break;
//                 }
//             }
//         }

//         //Output
//         if(possible1 && possible2)
//         {
//             cout << "Yes" << endl;
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; ++i)
//         {
//             cin >> a[i];
//         }

//         for (int i = 0; i < n; ++i)
//         {
//             cin >> b[i];
//         }

//         bool possible = false;
//         int last_0_index = 0, first_1_index = 0;

//         for (int i = 0; i < n; ++i)
//         {
//             if (b[i] == 0)
//             {
//                 last_0_index = i;
//             }
//             else
//             {
//                 if(!first_1_index)
//                 {
//                     first_1_index = i;
//                 }
//             }
//         }

//         if (last_0_index < first_1_index)
//         {
//             possible = true;
//         }

//         cout << (possible ? "Yes" : "No") << endl;
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Inputs
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        //MAIN logic
        bool element0 = false;
        bool element1 = false;
        for(int i=0; i<n; i++)
        {
            cin >> b[i];
            if(b[i]==0)
            {
                element0 = true;
            }
            if(b[i]==1)
            {
                element1 = true;
            }
        }

        bool possible = true;
        if(element0 && element1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            for(int i=1; i<n; i++)
            {
                if(a[i-1]>a[i])
                {
                    possible = false;
                }
            }
            if(possible) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
