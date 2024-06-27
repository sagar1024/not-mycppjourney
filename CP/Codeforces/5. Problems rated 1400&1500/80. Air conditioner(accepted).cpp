// C. Air Conditioner

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Gildong owns a bulgogi restaurant. The restaurant has a lot of customers, so many of them like to make a reservation before visiting it. Gildong tries so hard to satisfy the customers that he even memorized all customers' preferred temperature ranges! Looking through the reservation list, he wants to satisfy all customers by controlling the temperature of the restaurant. The restaurant has an air conditioner that has 3 states: off, heating, and cooling. When it's off, the restaurant's temperature remains the same. When it's heating, the temperature increases by 1 in one minute. Lastly, when it's cooling, the temperature decreases by 1 in one minute. Gildong can change the state as many times as he wants, at any integer minutes. The air conditioner is off initially. Each customer is characterized by three values: ti — the time (in minutes) when the i-th customer visits the restaurant, li — the lower bound of their preferred temperature range, and hi — the upper bound of their preferred temperature range. A customer is satisfied if the temperature is within the preferred range at the instant they visit the restaurant. Formally, the i-th customer is satisfied if and only if the temperature is between li and hi (inclusive) in the ti-th minute. Given the initial temperature, the list of reserved customers' visit times and their preferred temperature ranges, you're going to help him find if it's possible to satisfy all customers.

// Input
// Each test contains one or more test cases. The first line contains the number of test cases q (1≤q≤500). Description of the test cases follows. The first line of each test case contains two integers n and m (1≤n≤100, −109≤m≤109), where n is the number of reserved customers and m is the initial temperature of the restaurant. Next, n lines follow. The i-th line of them contains three integers ti, li, and hi (1≤ti≤109, −109≤li≤hi≤109), where ti is the time when the i-th customer visits, li is the lower bound of their preferred temperature range, and hi is the upper bound of their preferred temperature range. The preferred temperature ranges are inclusive. The customers are given in non-decreasing order of their visit time, and the current time is 0.

// Output
// For each test case, print "YES" if it is possible to satisfy all customers. Otherwise, print "NO". You can print each letter in any case (upper or lower).

// Example
// inputCopy
// 4
// 3 0
// 5 1 2
// 7 3 5
// 10 -1 0
// 2 12
// 5 7 10
// 10 16 20
// 3 -100
// 100 0 0
// 100 -50 50
// 200 100 100
// 1 100
// 99 -100 0

// outputCopy
// YES
// NO
// YES
// NO

// Note
// In the first case, Gildong can control the air conditioner to satisfy all customers in the following way:

// At 0-th minute, change the state to heating (the temperature is 0).
// At 2-nd minute, change the state to off (the temperature is 2).
// At 5-th minute, change the state to heating (the temperature is 2, the 1-st customer is satisfied).
// At 6-th minute, change the state to off (the temperature is 3).
// At 7-th minute, change the state to cooling (the temperature is 3, the 2-nd customer is satisfied).
// At 10-th minute, the temperature will be 0, which satisfies the last customer.

// In the third case, Gildong can change the state to heating at 0-th minute and leave it be. Then all customers will be satisfied. Note that the 1-st customer's visit time equals the 2-nd customer's visit time.
// In the second and the fourth case, Gildong has to make at least one customer unsatisfied.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// void solve()
// {
//     //Num of reserved seats and initial temp
//     long long int n, m;
//     cin >> n >> m;

//     vector<vector<long long int>> givenArray(n, vector<long long int>(3));
//     for(int i=0; i<n; i++)
//     {
//         long long int x, y, z;
//         cin >> x >> y >> z;
//         givenArray.push_back({x, y, z});
//     }

//     //MAIN logic
//     //Iterate thru each customer's arrival time and temp range
//     //If we are successfully able to reach the desired temp on time for every customer
//     //If the difference between the current temp
//     //AND
//     //The closer temp range(upper or lower bound) is less than the diff in thier arrival time
//     //Then output YES else NO

//     bool possible = true;

//     //For the first customer, we start at time = 0
//     if(givenArray[0][0] < min(abs(givenArray[0][1]-m), abs(givenArray[0][2]-m)))
//     {
//         possible = false;
//     }

//     //For subsequent customers
//     for(int i=1; i<n; i++)
//     {
//         if(abs(givenArray[i-1][0]-givenArray[i][0]) < min(abs(givenArray[0][1]-m), abs(givenArray[0][2]-m)))
//         {
//             possible = false;
//             break;
//         }
//     }

//     if(possible) cout << "YES" << endl;
//     else cout << "NO" << endl;

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

// Alternate soln - Since the range of temperatures can be large, it is impossible to consider all possible cases. However, we only need to find any case that can satisfy all customers, so let's try to maximize the possible range for each customer in the order of their visit time. Let's define two variables mn and mx, each representing the minimum and maximum possible temperature that can be set now. Initially they are both m and the current time is 0. After K minutes, we can see that the possible range is [mn−K,mx+K]. This means if a customer that visits after K minutes has preferred temperature range [L,R] that intersects with this range (inclusive), Gildong can satisfy that customer. In other words, mn−K≤R and L≤mx+K must be satisfied. Then we can reset mn and mx to fit this intersected range: mn=max(mn−K,L) and mx=min(mx+K,R). If this can be continued until the last customer, the answer is "YES". Otherwise, the answer is "NO". Time complexity: O(n) for each test case.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAX_CUSTOMERS = 100;

int arrivalTime[MAX_CUSTOMERS], lowerTemp[MAX_CUSTOMERS], upperTemp[MAX_CUSTOMERS];

int32_t main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int numCustomers, initialTemp, i;
        cin >> numCustomers >> initialTemp;

        for (i = 0; i < numCustomers; i++)
            cin >> arrivalTime[i] >> lowerTemp[i] >> upperTemp[i];

        //Initializing variables for current temperature range
        int previousArrivalTime = 0;
        int minTemp = initialTemp, maxTemp = initialTemp;

        bool isPossible = true;

        //Iterating through each customer's reservation
        for (i = 0; i < numCustomers; i++)
        {
            //Updating temperature range based on time difference since last customer
            maxTemp += arrivalTime[i] - previousArrivalTime;
            minTemp -= arrivalTime[i] - previousArrivalTime;

            //Checking if the temperature range is within customer's preference
            if (maxTemp < lowerTemp[i] || minTemp > upperTemp[i])
            {
                isPossible = false;
                break;
            }

            //Adjusting temperature range based on customer's preferences
            maxTemp = min(maxTemp, upperTemp[i]);
            minTemp = max(minTemp, lowerTemp[i]);

            previousArrivalTime = arrivalTime[i];
        }

        if (isPossible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
