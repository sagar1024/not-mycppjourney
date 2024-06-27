// B. Pipeline

// time limit per test0.4 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vova, the Ultimate Thule new shaman, wants to build a pipeline. As there are exactly n houses in Ultimate Thule, Vova wants the city to have exactly n pipes, each such pipe should be connected to the water supply. A pipe can be connected to the water supply if there's water flowing out of it. Initially Vova has only one pipe with flowing water. Besides, Vova has several splitters. A splitter is a construction that consists of one input (it can be connected to a water pipe) and x output pipes. When a splitter is connected to a water pipe, water flows from each output pipe. You can assume that the output pipes are ordinary pipes. For example, you can connect water supply to such pipe if there's water flowing out from it. At most one splitter can be connected to any water pipe. The figure shows a 4-output splitter. Vova has one splitter of each kind: with 2, 3, 4, ..., k outputs. Help Vova use the minimum number of splitters to build the required pipeline or otherwise state that it's impossible. Vova needs the pipeline to have exactly n pipes with flowing out water. Note that some of those pipes can be the output pipes of the splitters.

// Input
// The first line contains two space-separated integers n and k (1 ≤ n ≤ 1018, 2 ≤ k ≤ 109). Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Output
// Print a single integer — the minimum number of splitters needed to build the pipeline. If it is impossible to build a pipeline with the given splitters, print -1.

// Examples
// inputCopy
// 4 3
// outputCopy
// 2
// inputCopy
// 5 5
// outputCopy
// 1
// inputCopy
// 8 4
// outputCopy
// -1

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// signed main()
// {
//     ll n, k;
//     cin >> n >> k;

//     //Calc total pipes possible, using the formula of sum of first n natural nums
//     ll totalPipesPossible = ((k*(k+1))/2 - 1) - (k-2);
//     ll pipesRequired = 0;
//     if(n>totalPipesPossible)
//     {
//         cout << "-1" << endl;
//     }
//     else
//     {
//         for(int i=k; i>=2 && n>0; i++)
//         {
//             n -= i;
//             pipesRequired++;
//             if(n<=0)
//             {
//                 break;
//             }
//             n += 1;
//         }
//         cout << pipesRequired << endl;
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//Sum of the first n natural numbers
ll sum(ll n)
{
    return (n * (n + 1)) / 2;
}

//Sum of the range [start, end]
ll rangeSum(ll start, ll end)
{
    if (start <= 1)
    {
        return sum(end);
    }
    return sum(end) - sum(start - 1);
}

//Minimum number of splitters needed
ll minSplitters(ll maxSplitter, ll pipesNeeded)
{
    ll low = 1, high = maxSplitter;
    while (low < high)
    {
        ll mid = (low + high) / 2;
        ll currentSum = rangeSum(mid, maxSplitter);

        if (currentSum == pipesNeeded)
        {
            return maxSplitter - mid + 1;
        }
        if (currentSum > pipesNeeded)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return maxSplitter - low + 2;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    if (n == 1)
    {
        //Only one pipe is needed, no splitter required
        cout << 0 << "\n";
    }
    else if (n <= k)
    {
        //A single splitter with n outputs will suffice
        cout << 1 << "\n";
    }
    else
    {
        --k;
        --n;
        if (sum(k) < n)
        {
            //It's impossible to create n pipes with the given splitters
            cout << -1 << "\n";
        }
        else
        {
            //Calculate the minimum number of splitters
            cout << minSplitters(k, n) << "\n";
        }
    }

    return 0;
}
