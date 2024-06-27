// F. Eating Candies

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// There are n candies put from left to right on a table. The candies are numbered from left to right. The i-th candy has weight wi. Alice and Bob eat candies. Alice can eat any number of candies from the left (she can't skip candies, she eats them in a row). Bob can eat any number of candies from the right (he can't skip candies, he eats them in a row). Of course, if Alice ate a candy, Bob can't eat it (and vice versa). They want to be fair. Their goal is to eat the same total weight of candies. What is the most number of candies they can eat in total?

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains an integer n (1≤n≤2⋅105) — the number of candies on the table. The second line of each test case contains n integers w1,w2,…,wn (1≤wi≤104) — the weights of candies from left to right. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print a single integer — the maximum number of candies Alice and Bob can eat in total while satisfying the condition.

// Example
// inputCopy
// 4
// 3
// 10 20 10
// 6
// 2 1 4 2 4 1
// 5
// 1 2 4 8 16
// 9
// 7 3 20 5 15 1 11 8 10

// outputCopy
// 2
// 6
// 0
// 7

// Note
// For the first test case, Alice will eat one candy from the left and Bob will eat one candy from the right. There is no better way for them to eat the same total amount of weight. The answer is 2 because they eat two candies in total.
// For the second test case, Alice will eat the first three candies from the left (with total weight 7) and Bob will eat the first three candies from the right (with total weight 7). They cannot eat more candies since all the candies have been eaten, so the answer is 6 (because they eat six candies in total).
// For the third test case, there is no way Alice and Bob will eat the same non-zero weight so the answer is 0.
// For the fourth test case, Alice will eat candies with weights [7,3,20] and Bob will eat candies with weights [10,8,11,1], they each eat 30 weight. There is no better partition so the answer is 7.

// My original soln(time limit exceeded) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n;
//         cin >> n;

//         vector<int> candies(n);
//         for(int i=0; i<n; i++)
//         {
//             cin >> candies[i];
//         }

//         if(n==1)
//         {
//             cout << "0" << endl;
//             continue;
//         }
//         if(n==2 && candies[0]==candies[1])
//         {
//             cout << "2" << endl;
//             continue;
//         }
//         else
//         {
//             cout << "0" << endl;
//             continue;
//         }

//         //Alice
//         int a = candies[0];
//         //Bob
//         int b = candies[n-1];

//         int aliceCount = 0;
//         int bobCount = 0;

//         int aliceWt = 0;
//         int bobWt = 0;

//         int count = 0;
//         for(int i=0; i<n; i++)
//         {
//             int j = n-i+1;
//             if(candies[i]==candies[j])
//             {
//                 count += 2;
//                 j--;
//             }
//             else if(candies[i]<candies[j])
//             {
//                 aliceCount++;
//                 bobCount++;

//                 aliceWt += candies[i];
//                 bobWt += candies[j];

//                 if(aliceCount == bobCount)
//                 {
//                     count += 2;
//                 }
//                 continue;
//             }
//             else
//             {
//                 aliceCount++;
//                 bobCount++;

//                 aliceWt += candies[i--]; //Countering the loop's "i++"
//                 bobWt += candies[j--]; //Decreasing the j index, Bob is eating from the right

//                 if(aliceCount == bobCount)
//                 {
//                     count += 2;
//                 }
//                 continue;
//             }
//         }

//         cout << count << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> candies(n);
        for (int i = 0; i < n; i++)
        {
            cin >> candies[i];
        }

        int aliceSum = candies[0];
        int bobSum = candies[n-1];
        int aliceCount = 1;
        int bobCount = 1;

        int left = 1, right = n-2;
        int count = 0;

        while (left <= right)
        {
            if(aliceSum==bobSum)
            {
                count += 2;
                if (left == right) break;
                aliceSum += candies[left++];
                bobSum += candies[right--];

                aliceCount++;
                bobCount++;
            }
            else if(aliceSum<bobSum)
            {
                aliceSum += candies[left++];
                aliceCount++;
            }
            else
            {
                bobSum += candies[right--];
                bobCount++;
            }
        }

        cout << aliceCount+bobCount << endl;
    }

    return 0;
}
