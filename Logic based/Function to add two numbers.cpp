#include <iostream>
#include <cmath>
using namespace std;

int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << add(a,b) << endl;

    return 0;
}