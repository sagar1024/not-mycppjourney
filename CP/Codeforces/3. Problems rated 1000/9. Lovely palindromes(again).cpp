#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin >> n;

    string s1 = n;

    reverse(n.begin(), n.end());
    string s2 = n;

    cout << s1+s2 << endl;

    return 0;
}
