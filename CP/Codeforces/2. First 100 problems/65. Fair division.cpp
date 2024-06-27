// B. Fair Division

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Alice and Bob received n candies from their parents. Each candy weighs either 1 gram or 2 grams. Now they want to divide all candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies. Check if they can do that. Note that candies are not allowed to be cut in half.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow. The first line of each test case contains an integer n (1≤n≤100) — the number of candies that Alice and Bob received. The next line contains n integers a1,a2,…,an — the weights of the candies. The weight of each candy is either 1 or 2. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output on a separate line:

// "YES", if all candies can be divided into two sets with the same weight;
// "NO" otherwise.

// You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).

// Example
// Input
// 5
// 2
// 1 1
// 2
// 1 2
// 4
// 1 2 1 2
// 3
// 2 2 2
// 3
// 2 1 2

// Output
// YES
// NO
// YES
// NO
// NO

// Note
// In the first test case, Alice and Bob can each take one candy, then both will have a total weight of 1.
// In the second test case, any division will be unfair.
// In the third test case, both Alice and Bob can take two candies, one of weight 1 and one of weight 2.
// In the fourth test case, it is impossible to divide three identical candies between two people.
// In the fifth test case, any division will also be unfair.

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
        //Number of candies
        int n;
        cin >> n;

        //To count the number of 1g and 2 g candies
        int count1 = 0, count2 = 0;

        //Array to store the weights
        vector<int> weights(n);
        for(int i=0; i<n; i++)
        {
            cin >> weights[i];

            //Counting the number of 1g candies
            if(weights[i]==1)
            {
                count1++;
            }
            //Counting the number of 2g candies
            if(weights[i]==2)
            {
                count2++;
            }
        }

        //Checking whether it is fairly divisible or not
        bool divisible = false;

        //Main logic
        //If both type of candies are in even numbers
        if(count1%2==0)
        {
            if(count2%2==0)
            {
                //Then it is divisible
                divisible = true;
            }
        }

        if(divisible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
