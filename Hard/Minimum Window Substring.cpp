
// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size()==0)
        {
            return "";
        }

        unordered_map<char, int> letter_map, window_map;
        char character;
        for(int i = 0; i<t.size(); i++)
        {
            letter_map[t[i]] +=1;
        }
        int l, r;
        l = 0;
        r = 0;
        int required = letter_map.size();


        int formed = 0;
        tuple<int, int, int> ans = make_tuple(numeric_limits<int>::max(), -1, -1);

        while(r<s.size())
        {
            character = s[r];
            window_map[s[r]] = window_map.find(s[r]) != window_map.end() ? window_map[s[r]] + 1 : 1;

            if(letter_map.find(character) != letter_map.end() && window_map[character]== letter_map[character])
            {formed+=1;}
            while((l<=r) && formed == required)
            {
                character = s[l];
                if(r-l+1 < get<0>(ans))
                {
                    get<0>(ans) = r-l+1;
                    get<1>(ans) = l;
                    get<2>(ans) = r;
                
                }
                window_map[character]-=1;

                if(letter_map.find(character) != letter_map.end() && window_map[character]<letter_map[character])
                {
                    formed-=1;
                }
                l+=1;
            }
            r+=1;
            
        }
        // cout<< get<0>(ans);
        // cout<< get<1>(ans);
        // cout<< get<2>(ans);
        if(get<0>(ans) == numeric_limits<int>::max())
            return "";
        else
            return s.substr(get<1>(ans),get<0>(ans));

        
    }
};