// C. Hamburgers

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again. Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese. Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

// Input
// The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C). The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen. The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has. Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Output
// Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

// Examples
// inputCopy
// BBBSSC
// 6 4 1
// 1 2 3
// 4
// outputCopy
// 2
// inputCopy
// BBC
// 1 10 1
// 1 10 1
// 21
// outputCopy
// 7
// inputCopy
// BSC
// 1 1 1
// 1 1 3
// 1000000000000
// outputCopy
// 200000000001

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Global variables
//Available stock
long long int nb, ns, nc;
//Price
long long int pb, ps, pc;
//Money
long long int r;
//Num of BSC req for 1 ham
long long int bread, sausages, cheese;

//Func to calc the price of x hamburgers
long long int price(long long int x)
{
    long long int total = 0;

    //Need these many bread, sausages, and cheese to make x hams
    //Besides available stock
    long long int x1 = max(0LL, bread*x-nb);
    long long int x2 = max(0LL, sausages*x-ns);
    long long int x3 = max(0LL, cheese*x-nc);

    total = x1*pb + x2*ps + x3*pc;
    return total;
}

int32_t main()
{
    //Recipe
    string s;
    cin >> s;

    for(auto c: s)
    {
        if(c=='B') bread++;
        else if(c=='S') sausages++;
        else cheese++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    //MAIN logic
    //Binary search
    long long int left=0, right = r+1000;
    long long int mid = 0, ans = 0;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(price(mid)==r)
        {
            cout << mid << endl;
            return 0;
        }
        if(price(mid)<r)
        {
            left = mid+1;
            ans = mid;
        }
        else
        {
            right = mid-1;
        }
    }

    cout << ans << endl;
    return 0;
}
