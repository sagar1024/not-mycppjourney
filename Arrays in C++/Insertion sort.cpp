#include <iostream>
using namespace std;

int main()
{
    // For array size
    int n;
    cin >> n;

    // For array elements
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[n];
    }

    // Starting from 1(and not 0) bcs we need n-1 loops
    for(int i = 1; i<n; i++)
    { 
        // This j variable stores the preceding index wrt the current index
        // This variable compares the ith and i+1th terms while traversing the array
        int j = i-1;

        // For comparison
        while(arr[j]>arr[i] && j>=0)
        {
            // Swapping the elements, if theyre in wrong order
            arr[j+1] = arr[j];

            // Keeps the sorted elements in check
            // AND
            // Puts the value in its right place 
            j--;
        }

        // For completing the swap
        arr[i] = arr[j+1];
    }

    // The loop outputs the array
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
