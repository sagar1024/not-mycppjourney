// D1. Magic Powder - 1

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// This problem is given in two versions that differ only by constraints. If you can solve this problem in large constraints, then you can just write a single solution to the both versions. If you find the problem too difficult in large constraints, you can write solution to the simplified version only. Waking up in the morning, Apollinaria decided to bake cookies. To bake one cookie, she needs n ingredients, and for each ingredient she knows the value ai — how many grams of this ingredient one needs to bake a cookie. To prepare one cookie Apollinaria needs to use all n ingredients. Apollinaria has bi gram of the i-th ingredient. Also she has k grams of a magic powder. Each gram of magic powder can be turned to exactly 1 gram of any of the n ingredients and can be used for baking cookies. Your task is to determine the maximum number of cookies, which Apollinaria is able to bake using the ingredients that she has and the magic powder.

// Input
// The first line of the input contains two positive integers n and k (1 ≤ n, k ≤ 1000) — the number of ingredients and the number of grams of the magic powder. The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, needed to bake one cookie. The third line contains the sequence b1, b2, ..., bn (1 ≤ bi ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, which Apollinaria has.

// Output
// Print the maximum number of cookies, which Apollinaria will be able to bake using the ingredients that she has and the magic powder.

// Examples
// inputCopy
// 3 1
// 2 1 4
// 11 3 16
// outputCopy
// 4
// inputCopy
// 4 3
// 4 3 5 6
// 11 12 14 20
// outputCopy
// 3

// Note
// In the first sample it is profitably for Apollinaria to make the existing 1 gram of her magic powder to ingredient with the index 2, then Apollinaria will be able to bake 4 cookies.
// In the second sample Apollinaria should turn 1 gram of magic powder to ingredient with the index 1 and 1 gram of magic powder to ingredient with the index 3. Then Apollinaria will be able to bake 3 cookies. The remaining 1 gram of the magic powder can be left, because it can't be used to increase the answer.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int,int>> cookies;
    for(int i=0; i<n; i++)
    {
        cookies.push_back({b[i]/a[i], b[i]%a[i]});
    }

    sort(cookies.begin(), cookies.end(), compare);

    // while(k>0)
    // {
    //     for(int i=0; i<n && k>0; i++)
    //     {
    //         if(cookies[i].second<k)
    //         {
    //             k -= cookies[i].second;
    //             cookies[i].first++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }

    bool converted = true;

    while(k && converted)
    {
        converted = false; //Reset the flag at the beginning of each iteration
        for(int i=0; i<n && k>0; i++)
        {
            if(cookies[i].second < a[i] && k >= a[i] - cookies[i].second)
            {
                int diff = a[i] - cookies[i].second;
                k -= diff;
                cookies[i].first += diff / a[i];
                cookies[i].second = 0;
                converted = true; //Set the flag if a conversion is made
            }
        }
    }

    cout << cookies[0].first << endl;

    return 0;
}
