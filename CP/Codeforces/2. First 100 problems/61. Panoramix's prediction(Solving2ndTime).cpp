// Same question, different approach
// Chatgpts help

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    bool foundNextPrime = false;

    for (int i = n+1; i <= m-1; i++)
    {
        if (isPrime(i))
        {
            foundNextPrime = true;
            break;
        }
    }

    if(!isPrime(n) || !isPrime(m))
    {
        foundNextPrime = false;
    }
    
    string result = "";
    if(foundNextPrime)
    {
        result = "YES";
    }
    else
    {
        result = "NO";
    }

    cout << result << endl;
    
    return 0;
}
