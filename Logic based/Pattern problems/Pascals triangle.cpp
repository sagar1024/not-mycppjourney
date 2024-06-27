#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Pascals triangle
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    int coef = 1;

    for(int i = 1; i<=n; i++)
    {
        // For spaces
        for(int x = 1; x<=n-i; x++)
        {
            cout << " ";
        }

        // For numbers
        for(int y = 1; y<=2*i-1; y++)
        {
            if(y==1 || y==2*i-1)
            {
                cout << 1;
            }
            else
            {
                // For Binomial coefficients
                coef *= (i-y)/(y+1);
                cout << coef;
            }          
        }
        cout << endl;
    }
    return 0;
}