#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll countTriplets(ll n, ll x) {
    ll count = 0;
    for (ll a = 1; a <= x - 2; ++a) {
        ll maxBC = n / a - a;
        ll maxB = min(maxBC, x - a - 1);

        for (ll b = 1; b <= maxB; ++b) {
            ll maxC = min(x - a - b, n / (a + b) - b);
            count += maxC;
        }
    }

    // Correctly adjust the count for the special case where a = 1
    // This part was incorrect in your original code. It needs to account for all valid combinations of b and c given a = 1.
    // For a = 1, the condition simplifies to b + c <= x - 1 and bc <= n - 1.
    // We iterate through all possible values of b and for each b, calculate the maximum value of c that satisfies the conditions.
    if (n > 0 && x > 2) {
        for (ll b = 1; b <= x - 2; ++b) {
            ll maxC = min(x - 1 - b, n / b - 1);
            count += maxC;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        cout << countTriplets(n, x) << endl;
    }

    return 0;
}
