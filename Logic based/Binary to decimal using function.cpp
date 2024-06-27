#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int answer = 0;
    int x = 1;

    // The logic used down here needs some good attention

    while(n>0)
    {
        int y = n%10;
        answer = answer + x*y;
        x = x*2;
        n = n/10;
    }
    return answer;
}

int main()
{
    int a;
    cin >> a;

    cout << binaryToDecimal(a);
    cout << endl;
    
    return 0;
}