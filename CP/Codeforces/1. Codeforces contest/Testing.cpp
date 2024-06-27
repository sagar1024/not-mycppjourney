#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Checking if the teams never had a tie
        if (((x1 - y1) * (x2 - y2) > 0 || x1 == x2 || y1 == y2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
