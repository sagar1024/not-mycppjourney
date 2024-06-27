#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> hashMap;
    hashMap["apple"] = 1;
    hashMap["banana"] = 2;

    if (hashMap.find("apple") != hashMap.end())
    {
        cout << "Apple is in the map with value " << hashMap["apple"] << endl;
    }

    return 0;
}
