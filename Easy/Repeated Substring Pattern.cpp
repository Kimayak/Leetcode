
// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

// Example 1:

// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
// Example 2:

// Input: s = "aba"
// Output: false
// Example 3:

// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i =1; i<=n/2; i++){
            if(n%i == 0)
            {
            string pattern="";
            for(int j = 0; j<n/i; j++)
            {
                pattern+=s.substr(0,i);

            }
            if(s == pattern)
                return 1;
            }

        }
        return 0;
        // string temp;
        // temp = s[0];
        // for(int i =0; i<size(s); i++)
        // {
        //     temp.append(s[i]);

        //     if(s.)

        // }
        
    }
};