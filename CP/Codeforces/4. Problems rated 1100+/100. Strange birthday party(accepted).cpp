// A. Strange Birthday Party

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Petya organized a strange birthday party. He invited n friends and assigned an integer ki to the i-th of them. Now Petya would like to give a present to each of them. In the nearby shop there are m unique presents available, the j-th present costs cj dollars (1≤c1≤c2≤…≤cm). It's not allowed to buy a single present more than once. For the i-th friend Petya can either buy them a present j≤ki, which costs cj dollars, or just give them cki dollars directly. Help Petya determine the minimum total cost of hosting his party.

// Input
// The first input line contains a single integer t (1≤t≤103) — the number of test cases. The first line of each test case contains two integers n and m (1≤n,m≤3⋅105) — the number of friends, and the number of unique presents available. The following line contains n integers k1,k2,…,kn (1≤ki≤m), assigned by Petya to his friends. The next line contains m integers c1,c2,…,cm (1≤c1≤c2≤…≤cm≤109) — the prices of the presents. It is guaranteed that sum of values n over all test cases does not exceed 3⋅105, and the sum of values m over all test cases does not exceed 3⋅105.

// Output
// For each test case output a single integer — the minimum cost of the party.

// Examples
// inputCopy
// 2
// 5 4
// 2 3 4 3 2
// 3 5 12 20
// 5 5
// 5 4 3 2 1
// 10 40 90 160 250
// outputCopy
// 30
// 190
// inputCopy
// 1
// 1 1
// 1
// 1
// outputCopy
// 1

// Note

// In the first example, there are two test cases. In the first one, Petya has 5 friends and 4 available presents. Petya can spend only 30 dollars if he gives

// 5 dollars to the first friend.
// A present that costs 12 dollars to the second friend.
// A present that costs 5 dollars to the third friend.
// A present that costs 3 dollars to the fourth friend.
// 5 dollars to the fifth friend.

// In the second one, Petya has 5 and 5 available presents. Petya can spend only 190 dollars if he gives

// A present that costs 10 dollars to the first friend.
// A present that costs 40 dollars to the second friend.
// 90 dollars to the third friend.
// 40 dollars to the fourth friend.
// 10 dollars to the fifth friend.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<long long int> k(n);
//     vector<long long int> c(m);
//     vector<long long int> combined;
//     for(int i=0; i<n; i++)
//     {
//         cin >> k[i];
//         combined.push_back(k[i]);
//     }
//     for(int i=0; i<m; i++)
//     {
//         cin >> c[i];
//         combined.push_back(c[i]);
//     }

//     sort(combined.begin(), combined.end());
//     int totalBudget = 0;
//     for(int i=0; i<n; i++)
//     {
//         totalBudget += combined[i];
//     }

//     cout << totalBudget << endl;
//     return;
// }

// int32_t main()
// {
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

// int32_t main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         int n, m;
//         cin >> n >> m;

//         //Assigned number to ith friend
//         vector<int> assignedNumber(n);
//         for(int i=0; i<n; i++)
//         {
//             assignedNumber[i];
//         }

//         //Price of the jth gift
//         vector<long long int> giftPrices(m);
//         for(int i=0; i<m; i++)
//         {
//             cin >> giftPrices[i];
//         }

//         //Store the total cost for the birthday party
//         long long int totatCost = 0;

//         //Iterate over each assigned number
//         for(int i=0; i<n; i++)
//         {
//             //The minimum price required for ith friend
//             int minPrice = 0;

//             //Iterating from 0 to j where j<=k(ith)
//             //Finding the minimum price
//             for(int j=0; j<assignedNumber[i]; j++)
//             {
//                 if(minPrice<=giftPrices[j])
//                 {
//                     minPrice = giftPrices[j];
//                 }
//             }
//             if(minPrice<=giftPrices[assignedNumber[i]])
//             {
//                 minPrice = giftPrices[assignedNumber[i]];
//             }

//             //Adding up the prices
//             totatCost += minPrice;
//         }

//         //Outputs
//         cout << totatCost << endl;
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int32_t main()
// {
//     //Test cases
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         //Inputs
//         int n, m;
//         cin >> n >> m;

//         //Assigned number to ith friend
//         vector<int> assignedNumber(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> assignedNumber[i];
//         }

//         //Price of the jth gift
//         vector<long long int> giftPrices(m);
//         for(int i=0; i<m; i++)
//         {
//             cin >> giftPrices[i];
//         }

//         //Gifting the cheaper gifts to friends with higher k values
//         sort(assignedNumber.begin(), assignedNumber.end(), greater<int>());
//         sort(giftPrices.begin(), giftPrices.end());

//         //Count main will count the total number of gifts already purchased
//         //Count current will be used to skip the already bought gifts
//         int countMain = 0;
//         int countCurr = 0;
//         long long int totalCost = 0;
//         for(int i=0; i<n; i++)
//         {
//             //Storing the index of the cheapest gift bought(to erase it from the array)
//             int idx = 0;
//             int minimumPrice = 0;
//             for(int j=0; j<assignedNumber[i]; j++)
//             {
//                 //Skipping the gifts already bought
//                 if(countCurr>0)
//                 {
//                     countCurr--;
//                     continue;
//                 }

//                 // int x = giftPrices[j];
//                 // minimumPrice = min(x, minimumPrice);
//                 if(minimumPrice<=giftPrices[j])
//                 {
//                     minimumPrice = giftPrices[j];
//                 }

//                 if(minimumPrice<=giftPrices[assignedNumber[i]])
//                 {
//                     minimumPrice = giftPrices[assignedNumber[i]];
//                     //Since we got our minimum price w/o purchasing any gift
//                     //But directly giving money
//                     //We have to counter the countMAIN counter
//                     //OR basically to nullify the effect of the counter below
//                     countMain--;
//                 }
//             }

//             totalCost += minimumPrice;

//             //Do not erase element from vector while iterating over it
//             //giftPrices.erase(giftPrices.begin() + idx);
//             countMain++;
//             countCurr = countMain;
//         }

//         //Output
//         cout << totalCost << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        //INputs
        int n, m;
        cin >> n >> m;

        vector<int> assignedNumber(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> assignedNumber[i];
            --assignedNumber[i];
        }

        //Reverse sort
        sort(assignedNumber.rbegin(), assignedNumber.rend());

        vector<int> giftPrices(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> giftPrices[i];
        }

        //MAIN logic
        long long totalCost = 0;
        for (int i = 0; i < n; ++i)
        {
            //Adding up the prices of lesser index values
            int idx = (i < assignedNumber[i]) ? i : assignedNumber[i];
            totalCost += giftPrices[idx];
        }

        //OUTputs
        cout << totalCost << endl;
    }

    return 0;
}
