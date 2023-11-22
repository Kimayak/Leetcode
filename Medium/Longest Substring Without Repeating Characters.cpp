
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m =0;
        int l = s.length();
        

        for(int i = 0; i<l;i++)
        {
            for(int j =i;j<l;j++)
            {
                if(checkrep(s,i,j))
                {
                    cout<<s.substr(i,j)<<"\n";
                    m = max(m,j-i+1);
                    cout<<"i"<<i<<"\n";
                    cout<<"j"<<j<<"\n";
                    cout<<"m"<<m<<"\n";

                }
                    

            }
        }
        return m;
    }

    bool checkrep(string &s, int start, int end)
    {
        unordered_set<char> chars;

        for(int i = start; i<=end;i++)
        {
            char c = s[i];
            if(chars.count(c))
            {
                cout<<"Entered multiple char loop\n";
                return false;
                
            }
            chars.insert(c);
        }
        return true;

    }

};
