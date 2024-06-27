// Chatgpt solution

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        //Counting 0s and 1s
        int zeros = 0, ones = 0;
        for (char c : s)
        {
            if (c == '0')
                zeros++;
            else
                ones++;
        }

        // Check if the number of zeros is strictly greater than the number of ones
        if (zeros > ones)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
