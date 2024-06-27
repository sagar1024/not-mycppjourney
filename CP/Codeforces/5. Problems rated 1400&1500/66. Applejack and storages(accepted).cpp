// B. Applejack and Storages

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// This year in Equestria was a year of plenty, so Applejack has decided to build some new apple storages. According to the advice of the farm designers, she chose to build two storages with non-zero area: one in the shape of a square and another one in the shape of a rectangle (which possibly can be a square as well). Applejack will build the storages using planks, she is going to spend exactly one plank on each side of the storage. She can get planks from her friend's company. Initially, the company storehouse has n planks, Applejack knows their lengths. The company keeps working so it receives orders and orders the planks itself. Applejack's friend can provide her with information about each operation. For convenience, he will give her information according to the following format: + x: the storehouse received a plank with length x− x: one plank with length x was removed from the storehouse (it is guaranteed that the storehouse had some planks with length x). Applejack is still unsure about when she is going to order the planks so she wants to know if she can order the planks to build rectangular and square storages out of them after every event at the storehouse. Applejack is busy collecting apples and she has completely no time to do the calculations so she asked you for help! We remind you that all four sides of a square are equal, and a rectangle has two pairs of equal sides.

// Input
// The first line contains a single integer n (1≤n≤105): the initial amount of planks at the company's storehouse, the second line contains n integers a1,a2,…,an (1≤ai≤105): the lengths of the planks. The third line contains a single integer q (1≤q≤105): the number of events in the company. Each of the next q lines contains a description of the events in a given format: the type of the event (a symbol + or −) is given first, then goes the integer x (1≤x≤105).

// Output
// After every event in the company, print "YES" if two storages of the required shape can be built from the planks of that company's set, and print "NO" otherwise. You can print each letter in any case (upper or lower).

// Example
// inputCopy
// 6
// 1 1 1 2 1 1
// 6
// + 2
// + 1
// - 1
// + 2
// - 1
// + 2
// outputCopy
// NO
// YES
// NO
// NO
// NO
// YES

// Note

// After the second event Applejack can build a rectangular storage using planks with lengths 1, 2, 1, 2 and a square storage using planks with lengths 1, 1, 1, 1.
// After the sixth event Applejack can build a rectangular storage using planks with lengths 2, 2, 2, 2 and a square storage using planks with lengths 1, 1, 1, 1.

// My original soln(wa on tc3) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> planks(n);
//     vector<int> freq(100005,0);
//     for(int i=0; i<n; i++)
//     {
//         cin >> planks[i];
//         freq[planks[i]]++;
//     }

//     int q;
//     cin >> q;

//     for(int i=0; i<q; i++)
//     {
//         char type;
//         int x;
//         cin >> type >> x;

//         if(type=='+')
//         {
//             freq[x]++;
//         }
//         else if(type=='-')
//         {
//             freq[x]--;
//         }

//         int count2 = 0, count4 = 0;

//         for(int i=0; i<100005; i++)
//         {
//             if(freq[i]>=4)
//             {
//                 count4 += freq[i]/4;
//                 if(freq[i]%4==2)
//                 {
//                     count2++;
//                 }
//             }
//             else if(freq[i]>=2 && freq[i]<4)
//             {
//                 count2++;
//             }
//         }

//         if((count4 >=2) || (count4>=1 && count2>=2))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     //Freq array
//     vector<int> cnt(100005, 0);

//     for (int i = 0; i < n; ++i)
//     {
//         int len;
//         cin >> len;
//         cnt[len]++;
//     }

//     //Here sum2 stores the sum of ⌊cnt[i]/2⌋, sum4 stores the sum of ⌊cnt[i]/4⌋
//     int sum2 = 0, sum4 = 0;

//     //Calculating sum2 and sum4
//     for (int i = 1; i <= 100000; ++i)
//     {
//         sum2 += cnt[i] / 2;
//         sum4 += cnt[i] / 4;
//     }

//     //Events in the company
//     int q;
//     cin >> q;

//     while (q--)
//     {
//         char type;
//         cin >> type;

//         int len;
//         cin >> len;

//         if (type == '+')
//         {
//             cnt[len]++;
//             if (cnt[len] % 4 == 0)
//             {
//                 sum4++;
//                 sum2--;
//             }
//             else if (cnt[len] % 2 == 0)
//             {
//                 sum2++;
//             }
//         }
//         else
//         {
//             if (cnt[len] % 4 == 0)
//             {
//                 sum4--;
//                 sum2++;
//             }
//             else if (cnt[len] % 2 == 0)
//             {
//                 sum2--;
//             }
//             cnt[len]--;
//         }

//         if (sum4 >= 1 && sum2 >= 4)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int const MAXN = 1e5 + 5;

//Freq array
int plankCount[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //Here n - num of planks && q - num of events in the company
    //Here length is the length of the current plank
    int n, q, length, count2 = 0, count4 = 0;

    char type;

    //Initial num of planks
    cin >> n;

    //Input the initial plank lengths and update count2 and count4 accordingly
    for (int i = 1; i <= n; ++i)
    {
        cin >> length;

        count2 -= plankCount[length] / 2;
        count4 -= plankCount[length] / 4;
        
        plankCount[length]++;

        count2 += plankCount[length] / 2;
        count4 += plankCount[length] / 4;
    }

    //Num of events in the company
    cin >> q;

    //Processing each event and update count2 and count4 accordingly
    for (int i = 1; i <= q; ++i)
    {
        cin >> type >> length;
        count2 -= plankCount[length] / 2;
        count4 -= plankCount[length] / 4;

        if (type == '+') plankCount[length]++;
        else plankCount[length]--;

        count2 += plankCount[length] / 2;
        count4 += plankCount[length] / 4;

        //Checking if it's possible to build both a square and a rectangle
        if (count4 >= 1 && count2 >= 4) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
