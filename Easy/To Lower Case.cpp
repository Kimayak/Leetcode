
// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

// Example 1:

// Input: s = "Hello"
// Output: "hello"
// Example 2:

// Input: s = "here"
// Output: "here"
// Example 3:

// Input: s = "LOVELY"
// Output: "lovely"


#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    string toLowerCase(string s) {

    string result;
    for (char c : s) {
        result += std::tolower(c);
    }
    return result;

        
    }
};