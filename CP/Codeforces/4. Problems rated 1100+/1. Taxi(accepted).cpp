// B. Taxi

// time limit per test3 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

// Input
// The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

// Output
// Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

// Examples
// inputCopy
// 5
// 1 2 4 3 3
// outputCopy
// 4

// inputCopy
// 8
// 2 3 4 4 2 1 3 1
// outputCopy
// 5

// Note

// In the first test we can sort the children into four cars like this:

// the third group (consisting of four children),
// the fourth group (consisting of three children),
// the fifth group (consisting of three children),
// the first and the second group (consisting of one and two children, correspondingly).

// There are other ways to sort the groups into four cars.

// My original soln

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     //Num of groups
//     int n;
//     cin >> n;

//     //Num of children in the ith group
//     vector<int> si(n);

//     int totalChildren = 0;

//     int count1 = 0;
//     int count2 = 0;
//     int count3 = 0;
//     int count4 = 0;

//     for(int i=0; i<n; i++)
//     {
//         cin >> si[i];
//         totalChildren += si[i];

//         if(si[i]==1)
//         {
//             count1++;
//         }
//         if(si[i]==2)
//         {
//             count2++;
//         }
//         if(si[i]==3)
//         {
//             count3++;
//         }
//         // if(si[i]==4)
//         // {
//         //     count4++;
//         // }
//     }

//     if(totalChildren==4)
//     {
//         cout << 1 << endl;
//         return 0;
//     }

//     int minNumOfTaxis = ceil(totalChildren/4);

//     if((float)minNumOfTaxis==totalChildren/4 && ((((count1%4) != (count3%4)) && count1!=0 && count3!=0) || ((count2%2!=0) && count2!=0) || ((2*(count1%4) != (count2%4)) && count1!=0 && count2!=0)))
//     {
//         minNumOfTaxis += 1;
//     }

//     cout << minNumOfTaxis << endl;

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    vector<long long int> groups(n);
    long long int count1=0, count2=0, count3=0, count4=0;
    for(int i=0; i<n; i++)
    {
        cin >> groups[i];

        if(groups[i]==1)
            count1++;
        if(groups[i]==2)
            count2++;
        if(groups[i]==3)
            count3++;
        if(groups[i]==4)
            count4++;
    }

    long long int minTaxis = 0;
    long long int remainder1 = 0, remainder2 = 0;

    //Handling the 1s and 3s
    // if(count1==count3)
    // {
    //     minTaxis += min(count1, count3);
    // }
    // else if(count1<count3)
    // {
    //     minTaxis += min(count1, count3);
    //     minTaxis += abs(count1-count3);
    // }
    // else if(count1>count3)
    // {
    //     minTaxis += min(count1, count3);
    //     minTaxis += count1/4;

    //     remainder += count1-count3;
    // }

    //Handling the 2s
    // if(count2%2==0)
    // {
    //     minTaxis += count2/2;
    // }
    // else if(count2%2!=0)
    // {
    //     minTaxis += count2/2;
    //     remainder += count2%2;
    // }

    //Handling the remainders
    // if(remainder%4==0)
    // {
    //     minTaxis += remainder/4;
    // }
    // else if(remainder%4!=0)
    // {
    //     minTaxis += (remainder/4) + 1;
    // }

    //Handling the 4s
    //minTaxis += count4;

    //Corrected logic

    //Handling the 1s and 3s
    if(count1 <= count3)
    {
        minTaxis += count1;
        minTaxis += abs(count1-count3);
    }
    else
    {
        minTaxis += count3;
        remainder1 += abs(count1-count3);
    }

    //Handling the 2s
    minTaxis += count2/2;
    remainder2 += count2%2;

    //Handling the remainders
    minTaxis += ((remainder1 + 2*remainder2)+3)/4;

    //Handling the 4s
    minTaxis += count4;

    cout << minTaxis << endl;

    return 0;
}
