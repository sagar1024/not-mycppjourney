// E. Negatives and Positives

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given an array a consisting of n elements, find the maximum possible sum the array can have after performing the following operation any number of times: Choose 2 adjacent elements and flip both of their signs. In other words choose an index i such that 1≤i≤n−1 and assign ai=−ai and ai+1=−ai+1.

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The descriptions of the test cases follow. The first line of each test case contains an integer n (2≤n≤2⋅105) — the length of the array. The following line contains n space-separated integers a1,a2,…,an (−109≤ai≤109). It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the maximum possible sum the array can have after performing the described operation any number of times.

// Example
// inputCopy
// 5
// 3
// -1 -1 -1
// 5
// 1 5 -5 0 2
// 3
// 1 2 3
// 6
// -1 10 9 8 7 6
// 2
// -1 -1
// outputCopy
// 1
// 13
// 6
// 39
// 2

// Note

// For the first test case, by performing the operation on the first two elements, we can change the array from [−1,−1,−1] to [1,1,−1], and it can be proven this array obtains the maximum possible sum which is 1+1+(−1)=1.
// For the second test case, by performing the operation on −5 and 0, we change the array from [1,5,−5,0,2] to [1,5,−(−5),−0,2]=[1,5,5,0,2], which has the maximum sum since all elements are non-negative. So, the answer is 1+5+5+0+2=13.
// For the third test case, the array already contains only positive numbers, so performing operations is unnecessary. The answer is just the sum of the whole array, which is 1+2+3=6.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long int> elements(n);

        vector<long long int> negElements;
        vector<long long int> posElements;

        for(int i=0; i<n; i++)
        {
            cin >> elements[i];

            //Logic starts here
            if(elements[0]<0)
            {
                negElements.push_back(elements[i]);
            }
            else
            {
                posElements.push_back(elements[i]);
            }
        }

        //Size of the pos and neg arrays
        int x = negElements.size();
        int y = posElements.size();

        //Sorting
        sort(negElements.begin(), negElements.end());
        sort(posElements.begin(), posElements.end());

        //Answer variable
        long long int maxSum = 0;

        //Case 1
        //When positives(y) are more than negatives(x)
        if(x<y)
        {
            //Compare the first(common number of) elements
            //Which is already in sorted order
            for(int i=0; i<x; i++)
            {
                if(abs(negElements[i]) > posElements[i])
                {
                    maxSum += abs(negElements[i])-posElements[i];
                }
                else
                {
                    maxSum += posElements[i]-negElements[i];
                }
            }
            //Adding the remaining elements of positive's array(y)
            for(int i=x+1; i<y; i++)
            {
                maxSum += posElements[i];
            }
        }
        //Case 2
        //When both positive and negtive nums are equal
        else if(x==y)
        {
            for(int i=0; i<x; i++)
            {
                if(abs(negElements[i]) > posElements[i])
                {
                    maxSum += abs(negElements[i])-posElements[i];
                }
                else
                {
                    maxSum += posElements[i]-negElements[i];
                }
            }
        }
        //Case 3
        //When negatives(x) are greater than positives(y)
        else
        {
            for(int i=0; i<y; i++)
            {
                if(abs(negElements[i]) > posElements[i])
                {
                    maxSum += abs(negElements[i])-posElements[i];
                }
                else
                {
                    maxSum += posElements[i]-negElements[i];
                }
            }

            //Adding the remaining elements
            for(int i=y+1; i<x; i++)
            {
                maxSum += abs(negElements[i]);
            }
        }

        //Output
        cout << maxSum << endl;
    }

    return 0;
}
