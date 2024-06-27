// C. Powers Of Two

// time limit per test4 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// A positive integer x is called a power of two if it can be represented as x=2y, where y is a non-negative integer. So, the powers of two are 1,2,4,8,16,…. You are given two positive integers n and k. Your task is to represent n as the sum of exactly k powers of two.

// Input
// The only line of the input contains two integers n and k (1≤n≤109, 1≤k≤2⋅105).

// Output
// If it is impossible to represent n as the sum of k powers of two, print NO. Otherwise, print YES, and then print k positive integers b1,b2,…,bk such that each of bi is a power of two, and ∑i=1kbi=n. If there are multiple answers, you may print any of them.

// Examples

// inputCopy
// 9 4
// outputCopy
// YES
// 1 2 2 4
// inputCopy
// 8 1
// outputCopy
// YES
// 8
// inputCopy
// 5 1
// outputCopy
// NO
// inputCopy
// 3 7
// outputCopy
// NO

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int closestPowerOfTwo(int n)
// {
//     long long int x = 1;
//     int reqNum = 0;
//     while(n>x)
//     {
//         x *= 2;
//         reqNum = x/2; //Dividing by 2 to backtrack from one extra loop
//     }

//     return reqNum;
// }

// int32_t main()
// {
//     long long int n, k;
//     cin >> n >> k;

//     //MAIN logic
//     bool can = true;
//     vector<long long int> powersOfTwo(k);

//     long long int sum = 0;

//     int loopBreaker = 0;
//     while(sum!=n && k>0)
//     {
//         long long int closestPower = closestPowerOfTwo(n);
//         sum += closestPower;
//         n = n - closestPower;

//         powersOfTwo.push_back(closestPower);
//         k--;

//         loopBreaker++;
//         if(loopBreaker>40)
//         {
//             can = false;
//             break;
//         }
//     }

//     if(can)
//     {
//         cout << "YES" << endl;
//         for(int i=0; i<k; i++)
//         {
//             cout << powersOfTwo[i] << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

// Alternate soln -

// First of all, let's analyze how can we calculate the minimum number of powers of two needed to get n as the sum. We can use binary representation of n: each bit in it, which is equal to 1, becomes a summand in the answer. Firstly, if the number of summands is greater than k then the answer is NO. Okay, what if we don't have enough summands? Every summand x>1 can be broken down into two summands equal to x2. Let's maintain all summands greater than 1 somewhere (stack, array, queue, multiset, anything you want), and pick an arbitrary summand and break it into two until we have exactly k summands. If n≥k, then this process will terminate since we will have some summand to pick until all of them are equal to 1.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    long long int n, k;
    cin >> n >> k;

    map<int, int> ans;
    queue<int> q;

    //Calculating the summands based on the binary representation of n
    //In mathematics, a "summand" refers to each individual term that is being added together in a sum
    for(int i = 0; i <= 30; i++)
    {
        //Basically, checking if n has "1" in ith bit
        //If yes, then storing it in a queue
        if(n & (1 << i))
        {
            if(i > 0)
            {
                q.push(1 << i);
            }

            //Updating the frequency of a particular summand in the ans map
            ans[1 << i]++;
        }
    }

    //If the number of summands is greater than k, output "NO"
    if (ans.size() > k)
    {
        cout << "NO" << endl;
        return 0;
    }

    int cnt = ans.size();

    //Breaking down the summands until we have exactly k summands
    while (cnt < k && !q.empty())
    {
        //Popping and using summands from the front of the queue
        int z = q.front();
        q.pop();

        //Reducing the freq of the summand AND increasing its half's freq by 2
        ans[z]--;
        ans[z / 2] += 2;

        //Checking if the split summand z/2 is greater than 1, indicating that it can be further divided
        if(z/2 > 1)
        {
            q.push(z / 2);
            q.push(z / 2);
        }

        //Incrementing the number of summands
        cnt++;
    }

    //If we still don't have enough summands, output "NO"
    if (cnt < k)
    {
        cout << "NO" << endl;
        return 0;
    }

    //Output the result
    cout << "YES" << endl;
    for (auto x : ans)
    {
        for (int i = 0; i < x.second; i++)
        {
            cout << x.first << " ";
        }
    }

    cout << endl;

    return 0;
}
