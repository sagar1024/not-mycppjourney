// Max and min out of the 3 numbers using functions
#include <iostream>
using namespace std;

int max1 = 0;
int min1 = 0;
int max(int a, int b, int c)
{
    if(a>b)
    {
        if(a>c)
        {
            cout << a;
        }
        else
        {
            cout << c;
        }
    }
    else
    {
        if(b>c)
        {
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}

int min(int a, int b, int c)
{
    if(a<b)
    {
        if(a<c)
        {
            cout << a;
        }
        else
        {
            cout << c;
        }
    }
    else
    {
        if(b<c)
        {
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}

int main()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    cout << max(x,y,z);
    cout << endl;
    cout << min(x,y,z);

    return 0;
}

