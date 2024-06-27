// B. Plus and Multiply

// time limit per test3 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output

// There is an infinite set generated as follows:

// 1 is in this set.
// If x is in this set, x⋅a and x+b both are in this set.

// For example, when a=3 and b=6, the five smallest elements of the set are:

// 1,
// 3 (1 is in this set, so 1⋅a=3 is in this set),
// 7 (1 is in this set, so 1+b=7 is in this set),
// 9 (3 is in this set, so 3⋅a=9 is in this set),
// 13 (7 is in this set, so 7+b=13 is in this set).

// Given positive integers a, b, n, determine if n is in this set.

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤105) — the number of test cases. The description of the test cases follows. The only line describing each test case contains three integers n, a, b (1≤n,a,b≤109) separated by a single space.

// Output
// For each test case, print "Yes" if n is in this set, and "No" otherwise. You can print each letter in any case.

// Example
// inputCopy
// 5
// 24 3 5
// 10 3 6
// 2345 1 4
// 19260817 394 485
// 19260817 233 264
// outputCopy
// Yes
// No
// Yes
// No
// Yes

// Note
// In the first test case, 24 is generated as follows:
// 1 is in this set, so 3 and 6 are in this set;
// 3 is in this set, so 9 and 8are in this set;
// 8 is in this set, so 24 and 13 are in this set.
// Thus we can see 24 is in this set.
// The five smallest elements of the set in the second test case is described in statements. We can see that 10 isn't among them.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// bool found(long long int n, long long int a, long long int b, int x)
// {
//     if(x==n)
//     {
//         return true;
//     }

//     return found(n,a,b,x*a) || found(n,a,b,x+b);
// }

// void solve()
// {
//     long long int n, a, b;
//     cin >> n >> a >> b;

//     if(found(n,a,b,1)) cout << "Yes" << endl;
//     else cout << "No" << endl;

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

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long long int n, a, b;
//     cin >> n >> a >> b;

//     //Creating a queue to keep storing the newly formed nums from behind
//     //Using the elements at the front one by one to generate the new nums
//     queue<long long int> q;

//     //Creating a set to keep a track of the visited elements
//     unordered_set<long long int> visited;

//     //Given
//     q.push(1);

//     while(!q.empty())
//     {
//         long long int x = q.front();
//         q.pop();

//         //Found the number n
//         if(x==n)
//         {
//             cout << "Yes" << endl;
//             return;
//         }

//         //Over to the next loop if the current num x is greater than req num n
//         //OR if the element has been visited before
//         if(x>n || visited.count(x))
//         {
//             continue;
//         }

//         //Inserting x into the set of visited elements
//         visited.insert(x);

//         //Keep pushing the two newly generated nums in the queue
//         q.push(x*a);
//         q.push(x+b);
//     }

//     //If the num n is not found
//     cout << "No" << endl;
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     long long int n, a, b;
//     cin >> n >> a >> b;

//     //Finding all powers of a that are smaller than n
//     long long int power_of_a = 1;
//     while (power_of_a < n)
//     {
//         if (power_of_a % b == n % b)
//         {
//             cout << "Yes" << endl;
//             return;
//         }
//         power_of_a *= a;
//     }

//     cout << "No" << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    long long int n, a, b;
    cin >> n >> a >> b;

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
