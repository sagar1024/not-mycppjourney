// B. Two Buttons

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display can show arbitrarily large numbers. Initially, the display shows number n. Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?

// Input
// The first and the only line of the input contains two distinct integers n and m (1 ≤ n, m ≤ 104), separated by a space .

// Output
// Print a single number — the minimum number of times one needs to push the button required to get the number m out of number n.

// Examples
// inputCopy
// 4 6
// outputCopy
// 2

// inputCopy
// 10 1
// outputCopy
// 9

// Note
// In the first example you need to push the blue button once, and then push the red button once.
// In the second example, doubling the number is unnecessary, so we need to push the blue button nine times.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Inputs
//     int n, m;
//     cin >> n >> m;

//     //Counter variable
//     int count = 0;

//     //Answer
//     //Min num of clicks req
//     int minClicks = INT_MAX;

//     //MAIN logic
//     if(n>m)
//     {
//         cout << n-m << endl;
//     }
//     else if(n==m)
//     {
//         cout << 0 << endl;
//     }
//     else
//     {
//         //CRUX of the problem
//         while(n<m)
//         {
//             //Shortest path
//             //Red button
//             //If m is even, half it
//             if(m%2==0)
//             {
//                 m = m/2;
//             }
//             //Blue button
//             //Else increase it by 1
//             else
//             {
//                 m++;
//             }
//             count++;
//         }

//         //Calc the min clicks req
//         minClicks = min(count + abs(n-m), minClicks);
//         cout << minClicks << endl;
//     }

//     return 0;
// }

//Alternate soln(using bfs) -

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

//Function to find min num of clicks
int minButtonClicks(int& n, int& m)
{
    queue<pair<int, int>> q; // Queue to perform bfs
    unordered_set<int> visited; //To keep track of visited nums

    //Starting with the initial number and the number of button clicks
    q.push({n,0});

    //This loop continues until the queue q becomes empty
    //In each iteration, it dequeues a pair (currentNum, clicks)
    //Representing the current number on the display
    //And the number of button clicks needed to reach that number
    while (!q.empty())
    {
        //Storing the details of the front node
        //The front() returns a reference to the first element(the one at the front) in the queue
        //The front element is the element that has been in the queue the longest
        int currentNum = q.front().first;
        int clicks = q.front().second;

        //In each iteration, it dequeues a pair (currentNum, clicks)
        //Representing the current number on the display and the number of clicks
        q.pop();

        //Target number reached, return the number of clicks
        if (currentNum == m)
        {
            return clicks;
        }

        //Performing the red button operation(subtracting 1)
        //It checks if subtracting 1 from the current number(currentNum-1) is a valid operation
        //That is if the result is greater than 0
        //AND If the result has not been visited before
        //If both conditions are met
        //It enqueues the new pair (currentNum - 1, clicks + 1) and marks the result as visited
        if (currentNum>1 && visited.find(currentNum-1) == visited.end())
        {
            q.push({currentNum-1, clicks+1});
            visited.insert(currentNum-1);
        }

        //Performing the blue button operation(multiplying by 2)
        //It checks if doubling the current number(2*currentNum) is a valid operation
        //That is if the result is less than the target m
        //AND if the result has not been visited before
        //If both conditions are met
        //It enqueues the new pair(2*currentNum, clicks+1) and marks the result as visited.
        if (currentNum<m && visited.find(2*currentNum) == visited.end())
        {
            q.push({2*currentNum, clicks+1});
            visited.insert(2*currentNum);
        }
    }
}

int main()
{
    //Inputs
    int n, m;
    cin >> n >> m;

    //MAIN logic
    int result = minButtonClicks(n,m);
    cout << result << endl;

    return 0;
}

