#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<long long int> &a, int n, long long int &sum)
{
    //Base case
    if(n<0)
    {
        return;
    }

    solve(a,n-1,sum);
    sum += a[n];

    return;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    long long int sum = 0;
    solve(a,n-1,sum);

    cout << sum << endl;

    return 0;
}
