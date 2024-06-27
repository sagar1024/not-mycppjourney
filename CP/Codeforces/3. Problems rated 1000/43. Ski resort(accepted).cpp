// C. Ski Resort

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Dima Vatrushin is a math teacher at school. He was sent on vacation for n days for his good work. Dima has long dreamed of going to a ski resort, so he wants to allocate several consecutive days and go skiing. Since the vacation requires careful preparation, he will only go for at least k days. You are given an array a containing the weather forecast at the resort. That is, on the i-th day, the temperature will be ai degrees. Dima was born in Siberia, so he can go on vacation only if the temperature does not rise above q degrees throughout the vacation. Unfortunately, Dima was so absorbed in abstract algebra that he forgot how to count. He asks you to help him and count the number of ways to choose vacation dates at the resort.

// Input
// The first line of the input contains an integer t (1≤t≤104) — the number of test cases. Then follow the descriptions of the test cases. The first line of each test case contains three integers n, k, q (1≤n≤2⋅105, 1≤k≤n, −109≤q≤109) — the length of the array a, the minimum number of days at the resort, and the maximum comfortable temperature for Dima. The second line of each test case contains n integers a1,a2,a3,…,an (−109≤ai≤109) — the temperature at the ski resort. The sum of all n values over all test cases does not exceed 2⋅105.

// Output
// Output t integers, each of which is the answer to the corresponding test case — the number of ways for Dima to choose vacation dates at the resort.

// Example
// inputCopy
// 7
// 3 1 15
// -5 0 -10
// 5 3 -33
// 8 12 9 0 5
// 4 3 12
// 12 12 10 15
// 4 1 -5
// 0 -1 2 5
// 5 5 0
// 3 -1 4 -5 -3
// 1 1 5
// 5
// 6 1 3
// 0 3 -2 5 -4 -4
// outputCopy
// 6
// 0
// 1
// 0
// 0
// 1
// 9

// Note
// In the first test case of the example, Dima can go on any day, so the suitable dates for him are [1], [2], [3], [1, 2], [2, 3], [1, 2, 3].
// In the second and fourth test cases of the example, Dima cannot go on any day due to the high temperature, so there are no suitable dates.
// In the third test case of the example, Dima can only go on the dates [1, 2, 3].

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Function to calculate factorial
// int factorial(int n)
// {
//     if (n==0 || n==1)
//     {
//         return 1;
//     }
//     return n*factorial(n-1);
// }

// //Function to calculate combinations
// int combinations(int n, int m)
// {
//     return factorial(n)/(factorial(m)*factorial(n-m));
// }

// int main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Length of the array of weather forecast
//         //Min num of days at the resort(atleast k)
//         //Max comfortable temp for Dima
//         int n, k, q;
//         cin >> n >> k >> q;

//         //Weather forecast details
//         vector<int> weather(n);

//         //Num of days suitable for the vacation
//         int suitableDates = 0;

//         for(int i=0; i<n; i++)
//         {
//             cin >> weather[i];

//             //MAIN logic
//             if(weather[i]<=q)
//             {
//                 suitableDates++;
//             }
//         }

//         //Number of ways to choose vacation dates
//         if(suitableDates<k)
//         {
//             cout << 0 << endl;
//         }
//         else if(suitableDates==k)
//         {
//             cout << 1 << endl;
//         }
//         else
//         {
//             int x = combinations(suitableDates, k);
//             cout << x << endl;
//         }
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
        //Array length, min num of vacation days, max bearable temp
        long long int n, k, q;
        cin >> n >> k >> q;

        vector<long long int> weatherDetails(n);
        for(int i=0; i<n; i++)
        {
            cin >> weatherDetails[i];
        }

        //MAIN logic
        //Length of each segment
        long long int length = 0;
        //Storing the total num of ways to choose vacation
        long long int answer = 0;

        for(int i=0; i<n; i++)
        {
            //Counting the suitable dates(consecutive)
            if(weatherDetails[i]<=q)
            {
                length += 1;
            }
            else
            {
                //The point where the suitable dates streak ends
                //We will calculate the total "num of ways" to choose vacation
                //If the length < k, then we will ignore it
                if(length>=k)
                {
                    answer += (length-k+1)*(length-k+2)/2;
                }

                //Resetting length to 0
                //Once we are done with the current segment
                length = 0;
            }
        }

        //Writing the else part again because the loop might end without ever entering the else part
        if(length >= k)
        {
            answer += (length-k+1)*(length-k+2)/2;
        }

        cout << answer << endl;
    }

    return 0;
}
