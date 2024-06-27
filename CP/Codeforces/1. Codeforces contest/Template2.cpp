#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    vector<pair<int,int>> queries(q);
    for(int i=0; i<q; i++)
    {
        cin >> queries[i].first;
        cin >> queries[i].second;
    }

    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
