
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

class Solution {
public:
    bool isPalindrome(string s) {
        string all;
    
        for(char c:s)
        {
            if(isalnum(c))
                all+= tolower(c);

        }
        cout<<all;
        int low = 0;
        int high = all.size()-1;

        for(int i = 0 ; i< all.size()/2; i++)
        {
            if(all[low]!=all[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};