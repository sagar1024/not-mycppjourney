// Same quesion, different approach
// Chatgpts help

// Importing the header files
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to process the input string
// Return type of the function is string
string process(string input)
{
    // Creating a stack for processing the input string
    stack<char> typedString;

    // Traversing each char in the input string
    for (char c : input)
    {
        // If b
        if (c == 'b')
        {
            if (!typedString.empty() && islower(typedString.top()))
            {
                typedString.pop();
            }
        }

        // If B
        else if (c == 'B')
        {
            string temp;
            while (!typedString.empty())
            {
                if (isupper(typedString.top()))
                {
                    // Remove the rightmost uppercase letter
                    typedString.pop();
                    break;
                }
                // Store lowercase letters to reinsert them later
                temp += typedString.top();
                typedString.pop();
            }
            reverse(temp.begin(), temp.end());
            for (char ch : temp)
            {
                // Reinsert lowercase letters in the correct order
                typedString.push(ch);
            }
        }

        // If neither b nor B
        else
        {
            typedString.push(c);
        }
    }

    // Stores the processed string
    string result = "";

    while (!typedString.empty())
    {
        // Result is written after top element
        // To store the input string in the original order
        result = typedString.top() + result;

        // Keep popping the top element from the stack
        typedString.pop();
    }

    return result;
}

int main()
{
    // Test cases
    int t;
    cin >> t;

    while (t--)
    {
        // Input string
        string s;
        cin >> s;
        // Calling the function
        cout << process(s) << endl;
    }

    return 0;
}
