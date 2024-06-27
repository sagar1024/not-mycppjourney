#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cin >> a;
    cin >> b;

    for(int i = a; i<b; i++)
    {
        int n;
        for(n=2; n<i; n++)
        {
            if(i%n==0)
            break;
        }
        if(n==i)
        {
            cout<<i<<"\n";
        }
    }
    return 0;
}