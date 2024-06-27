#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int x = 1; x<n; x++)
    {
        for(int y = 0; y<n-x; y++)
        {
            if(arr[y]>arr[y+1])
            {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}