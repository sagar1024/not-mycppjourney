#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
#define ll long long

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int currentSum = 0, minOps = INT_MAX;
    int left = 0;

    // Sliding window to find the maximum length subarray with sum s
    for (int right = 0; right < n; right++) {
        currentSum += a[right];

        while (currentSum > s && left <= right) {
            currentSum -= a[left];
            left++;
        }

        if (currentSum == s) {
            minOps = min(minOps, n - (right - left + 1));
        }
    }

    cout << (minOps == INT_MAX ? -1 : minOps) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
