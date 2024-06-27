#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Calculate the angle subtended by each side of the 2n-gon
    double angle = (180.0 - (360.0 / (2 * (double)n))) / 2;

    // The radius of the inscribing circle is half the side length of the square we're looking for.
    double radius = 0.5;

    // The diagonal of the square is twice the radius of the inscribing circle.
    double diagonal = 2 * radius;

    // The side length of the square is the square root of the diagonal squared divided by 2,
    // since the diagonal divides the square into two right triangles.
    double side_length = sqrt(diagonal * diagonal / 2);

    // Output the result with fixed precision to match the required output format
    cout << fixed << setprecision(9) << side_length << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
