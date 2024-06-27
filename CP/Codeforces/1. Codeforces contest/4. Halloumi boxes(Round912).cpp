// A. Halloumi Boxes

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Theofanis is busy after his last contest, as now, he has to deliver many halloumis all over the world. He stored them inside n boxes and each of which has some number ai written on it. He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. It can only reverse any subarray of boxes with length at most k. Find if it's possible to sort the boxes using any number of reverses. Reversing a subarray means choosing two indices i and j (where 1≤i≤j≤n) and changing the array a1,a2,…,an to a1,a2,…,ai−1,aj,aj−1,…,ai,aj+1,…,an−1,an. The length of the subarray is then j−i+1.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of test cases.

// Each test case consists of two lines.

// The first line of each test case contains two integers n and k (1≤k≤n≤100) — the number of boxes and the length of the maximum reverse that Theofanis can make.

// The second line contains n integers a1,a2,…,an (1≤ai≤109) — the number written on each box.

// Output
// For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise.

// Example

// Input
// 5
// 3 2
// 1 2 3
// 3 1
// 9 9 9
// 4 4
// 6 4 2 1
// 4 3
// 10 3 830 14
// 2 1
// 3 

// Output
// YES
// YES
// YES
// YES
// NO

// Note
// In the first two test cases, the boxes are already sorted in non-decreasing order. In the third test case, we can reverse the whole array. In the fourth test case, we can reverse the first two boxes and the last two boxes. In the fifth test case, it can be shown that it's impossible to sort the boxes.

//Solution -

//My original code + chatgpt's help
//Importing the libraries
#include <bits/stdc++.h>
using namespace std;

//Function to check if the box numbers are sortable
//If we can only sort x of them at a time
bool sortable(vector<int> & boxNums, int & x)
{
    int n = boxNums.size();

    //To check if it is already sorted
    vector<int> sortedBoxNum(n);
    sortedBoxNum = boxNums;

    //Sorting the box nums
    sort(sortedBoxNum.begin(), sortedBoxNum.end());

    //If already sorted
    if(sortedBoxNum == boxNums)
    {
        return true;
    }

    //Special cases
    if(x == n-1 && x != 1)
    {
        return true;
    }

    //Iterating through the whole box num array
    for(int i=0; i<n; i++)
    {
        //Storing the last index of the subarray to be reversed
        int lastIndex = min(i+x-1, n-1);

        //Using the built in reverse function
        //Reversing the subarray from the original array, starting from index "i" till index "lastIndex+1"
        //In reverse function, the starting point is inclusive
        //But the ending point is exclusive, so we add 1 to make it inclusive
        reverse(boxNums.begin()+i, boxNums.begin()+lastIndex+1);

        //Checking if the array is sorted after n number of reversals
        if(boxNums == sortedBoxNum)
        {
            //The array is sorted
            return true;
        }

        //Resetting the subarray to its previous form
        //So that the next loop doesnt get flawed input
        //reverse(boxNums.begin()+i, boxNums.begin()+lastIndex+1);
    }

    //After n iterations, if the array isnt sorted, we return false
    return false;
}

int main()
{
    //Test cases
    int t;
    cin >> t;

    while(t--)
    {
        //Number of boxes
        int n;
        cin >> n;

        //Max number of reverses at a time
        int k;
        cin >> k;

        //Storing numbers written on each box
        vector<int> numbers(n);
        for(int i=0; i<n; i++)
        {
            cin >> numbers[i];
        }

        //Calling the function and letting it do the work
        if(sortable(numbers, k))
        {
            //If true
            cout << "YES" << endl;
        }
        else
        {
            //If false
            cout << "NO" << endl;
        }
    }

    return 0;
}
