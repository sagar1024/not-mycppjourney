#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int array[n];
    for(int i = 0; i<n; i++)
    {
        cin >> array[i];
    }

    int maxNUM = INT_MIN;
    int minNUM = INT_MAX;

    for(int i = 0; i<n; i++)
    {
        maxNUM = max(maxNUM, array[i]);
        minNUM = min(minNUM, array[i]);
    }

    cout << maxNUM << " " << minNUM << endl;

    return 0;
}