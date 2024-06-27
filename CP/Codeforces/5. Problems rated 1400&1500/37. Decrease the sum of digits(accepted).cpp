// D. Decrease the Sum of Digits

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a positive integer n. In one move, you can increase n by one (i.e. make n:=n+1). Your task is to find the minimum number of moves you need to perform in order to make the sum of digits of n be less than or equal to s. You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow. The only line of the test case contains two integers n and s (1≤n≤1018; 1≤s≤162).

// Output
// For each test case, print the answer: the minimum number of moves you need to perform in order to make the sum of digits of n be less than or equal to s.

// Example
// inputCopy
// 5
// 2 1
// 1 1
// 500 4
// 217871987498122 10
// 100000000000000001 1

// outputCopy
// 8
// 0
// 500
// 2128012501878
// 899999999999999999

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     string n;
//     cin >> n;

//     long long int s;
//     cin >> s;

//     //Base/different case
//     if(n.size()<=3)
//     {
//         if(stoll(n)==s)
//         {
//             cout << "0" << endl;
//             return;
//         }
//     }

//     //Iterating the given num
//     //Calculating the sum of digits from L to R
//     //If the sum becomes greater or equal to s, save the index and break the loop
//     //The digits from that index till last need to be converted to 0
//     //Subtract those digits(only those digits) by 10^(those digits' size)
//     long long int currSum = 0;
//     long long int index = 0;
//     for(int i=0; i<n.size(); i++)
//     {
//         currSum += n[i]-'0';
//         if(currSum>=s)
//         {
//             index = i;
//             break;
//         }
//     }

//     long long int x = pow(10, n.size()-index);

//     //string y1 = n.substr(index);
//     //long long int y2 = stoll(y1);
//     long long int y = stoll(n.substr(index));

//     cout << x-y << endl;
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Function to calculate the sum of digits of a number
int digitSum(long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        int s;

        cin >> n >> s;

        //Count of moves made to decrease the sum of digits
        long long moves = 0;

        if (digitSum(n) <= s)
        {
            //Checking if the sum of digits of n is already less than or equal to s
            cout << "0" << endl;
            continue;
        }

        long long powTen = 1; //Power of 10, used to extract digits
        
        //Iterating through each digit of the number
        for (int i = 0; i < 18; ++i)
        {
            int digit = (n / powTen) % 10; //Extracting the current digit
            long long add = powTen * ((10 - digit) % 10); //Calculating the value to add to decrease the sum of digits
            n += add; //Updating the number
            moves += add; //Updating the count of moves

            if (digitSum(n) <= s)
            {
                //Checking if the sum of digits of the updated number is less than or equal to s
                break; //If so, stop iterating
            }

            powTen *= 10; //Moving to the next digit
        }

        cout << moves << endl;
    }

    return 0;
}
