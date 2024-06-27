//Same problem, different appproach
//Using binary search to reduce time complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function for binary search
//Modified according to the question

int countingAffordableShops(vector<int> arr, int budget)
{
    int left = 0; //First element
    int right = arr.size()-1; //(n-1)th element

    while(left<=right)
    {
        int mid = (left + (right-left)/2);

        // if(arr[mid]<budget)
        // {
        //     left = mid+1;
        // }
        // else if(arr[mid]>budget)
        // {
        //     right = mid-1;
        // }
        // else if(arr[mid]==budget)
        // {
        //     left = mid;
        // }
        if (arr[mid] <= budget)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    //Not adding one because "left" is giving the count not index
    return left;
}

//Using for each loop
//Function to find the number of prices(shops) below my budget(coins)
//No use of it
//Since it also uses for loop
//The time complexity still remains O(q*n)

// int countPricesBelowBudget(vector<int> prices, int budget)
// {
//     int count = 0;
//     for(int price: prices)
//     {
//         if(price<=budget)
//         {
//             count++;
//         }
//     }
//     return count;
// } 

//The main function
//The driver code
int main()
{
    // Number of shops
    int n;
    cin >> n;

    // Prices of the bottles
    vector<int> bottlePrices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bottlePrices[i];
    }

    // Sorting the prices
    sort(bottlePrices.begin(), bottlePrices.end());

    // Number of days Vasiliy plans to drink
    int q;
    cin >> q;

    // Number of coins he plans to spend
    vector<int> numOfCoins(q);
    for (int i = 0; i < q; i++)
    {
        cin >> numOfCoins[i];
    }

    // Iterate for each day
    for (int i = 0; i < q; i++)
    {
        // Use binary search to find the number of affordable shops for the day
        //int numAffordableShops = upper_bound(bottlePrices.begin(), bottlePrices.end(), numOfCoins[i]) - bottlePrices.begin();

        //Calling the binary search function
        int result = countingAffordableShops(bottlePrices, numOfCoins[i]);

        //Calling the function to count the affordable shops using for each loop
        //int result = countPricesBelowBudget(bottlePrices, numOfCoins[i]);

        //Not adding 1 because the function is returning position
        cout << result << endl;
    }

    return 0;
}

//BSA didnt work
//Even after using binary search, still getting time limit exceeded
//Use of upper bound method seems to be necessary
