// C. Sofia and the Lost Operations

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Sofia had an array of n integers a1,a2,…,an. One day she got bored with it, so she decided to sequentially apply m modification operations to it. Each modification operation is described by a pair of numbers ⟨cj,dj⟩ and means that the element of the array with index cj should be assigned the value dj, i.e., perform the assignment acj=dj. After applying all modification operations sequentially, Sofia discarded the resulting array. Recently, you found an array of n integers b1,b2,…,bn. You are interested in whether this array is Sofia's array. You know the values of the original array, as well as the values d1,d2,…,dm. The values c1,c2,…,cm turned out to be lost. Is there a sequence c1,c2,…,cm such that the sequential application of modification operations ⟨c1,d1,⟩,⟨c2,d2,⟩,…,⟨cm,dm⟩ to the array a1,a2,…,an transforms it into the array b1,b2,…,bn?

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. Then follow the descriptions of the test cases. The first line of each test case contains an integer n (1≤n≤2⋅105) — the size of the array. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the original array. The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤109) — the elements of the found array. The fourth line contains an integer m (1≤m≤2⋅105) — the number of modification operations. The fifth line contains m integers d1,d2,…,dm (1≤dj≤109) — the preserved value for each modification operation. It is guaranteed that the sum of the values of n for all test cases does not exceed 2⋅105, similarly the sum of the values of m for all test cases does not exceed 2⋅105.

// Output
// Output t lines, each of which is the answer to the corresponding test case. As an answer, output "YES" if there exists a suitable sequence c1,c2,…,cm, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

// Example
// inputCopy
// 7
// 3
// 1 2 1
// 1 3 2
// 4
// 1 3 1 2
// 4
// 1 2 3 5
// 2 1 3 5
// 2
// 2 3
// 5
// 7 6 1 10 10
// 3 6 1 11 11
// 3
// 4 3 11
// 4
// 3 1 7 8
// 2 2 7 10
// 5
// 10 3 2 2 1
// 5
// 5 7 1 7 9
// 4 10 1 2 9
// 8
// 1 1 9 8 7 2 10 4
// 4
// 1000000000 203 203 203
// 203 1000000000 203 1000000000
// 2
// 203 1000000000
// 1
// 1
// 1
// 5
// 1 3 4 5 1
// outputCopy
// YES
// NO
// NO
// NO
// YES
// NO
// YES

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    //Array size
    int n;
    cin >> n;

    //Original array
    //Found array
    vector<long long int> a(n), b(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    //Modifications
    int m;
    cin >> m;

    //Preserved value for each modification
    vector<long long int> d(m);
    for(int i=0; i<m; i++)
    {
        cin >> d[i];
    }

    bool yes = true;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            if(find(b.begin(), b.end(), b[i]) != b.end())
            {
                if(find(d.begin(), d.end(), b[i]) != d.end())
                {
                    yes = true;
                }
                else
                {
                    yes = false;
                }
            }
            else
            {
                yes = false;
            }
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;

    return;
}

int32_t main()
{   
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
