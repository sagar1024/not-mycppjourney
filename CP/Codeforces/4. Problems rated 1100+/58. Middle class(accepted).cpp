// B. Middle Class

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Many years ago Berland was a small country where only n people lived. Each person had some savings: the i-th one had ai burles. The government considered a person as wealthy if he had at least x burles. To increase the number of wealthy people Berland decided to carry out several reforms. Each reform looked like that:

// the government chooses some subset of people (maybe all of them);
// the government takes all savings from the chosen people and redistributes the savings among the chosen people equally.

// For example, consider the savings as list [5,1,2,1]: if the government chose the 1-st and the 3-rd persons then it, at first, will take all 5+2=7 burles and after that will return 3.5 burles to the chosen people. As a result, the savings will become [3.5,1,3.5,1]. A lot of data was lost from that time, so we don't know how many reforms were implemented and to whom. All we can do is ask you to calculate the maximum possible number of wealthy people after several (maybe zero) reforms.

// Input
// The first line contains single integer T (1≤T≤1000) — the number of test cases. Next 2T lines contain the test cases — two lines per test case. The first line contains two integers n and x (1≤n≤105, 1≤x≤109) — the number of people and the minimum amount of money to be considered as wealthy. The second line contains n integers a1,a2,…,an (1≤ai≤109) — the initial savings of each person. It's guaranteed that the total sum of n doesn't exceed 105.

// Output
// Print T integers — one per test case. For each test case print the maximum possible number of wealthy people after several (maybe zero) reforms.

// Example
// inputCopy
// 4
// 4 3
// 5 1 2 1
// 4 10
// 11 9 11 9
// 2 5
// 4 3
// 3 7
// 9 4 9
// outputCopy
// 2
// 4
// 0
// 3

// Note
// The first test case is described in the statement.
// In the second test case, the government, for example, could carry out two reforms: [11–––,9–,11,9]→[10,10,11–––,9–]→[10,10,10,10].
// In the third test case, the government couldn't make even one person wealthy.
// In the fourth test case, the government could choose all people to carry out a reform: [9–,4–,9–]→[713,713,713].

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //Num of people
    int n;
    cin >> n;

    //Minimum amount of money to be considered as wealthy
    long long int x;
    cin >> x;

    vector<long long int> savings(n);
    for(long long int i=0; i<n; i++)
    {
        cin >> savings[i];
    }

    //MAIN logic
    sort(savings.begin(), savings.end(), greater<long long int>());

    long long int counter = 0;
    long long int currAvgSum = 0;
    long long int currCumSum = 0;
    long long int wealthyPeopleCount = 0;

    // for(long long int i=n-1; i>=0; i--)
    // {
    //     //Calc the cumulative sum and store the current avg values simultaneously
    //     currCumSum += savings[i];
    //     counter++;
    //     currAvgSum = currCumSum/counter;

    //     //If the avg sum becomes less than x, we break the loop
    //     if(currAvgSum<x)
    //     {
    //         wealthyPeopleCount = counter-1;
    //         break;
    //     }
    //     else if(currAvgSum==x)
    //     {
    //         wealthyPeopleCount = counter+1;
    //         break;
    //     }
    // }

    long long int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += savings[i];
        if (currSum / (i + 1) < x)
        {
            break;
        }
        counter++;
    }

    //Output
    cout << counter << endl;
    return;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
