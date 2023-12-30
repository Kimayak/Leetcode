
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

class Solution {
public:
    int characterReplacement(string s, int k) {
        int m = 0;
        int lo = 0, hi =s.size()+1, mid;
        
        while(lo+1<hi)
        {
            mid = (lo + hi)/2;
            if (can_make_valid_string(s,mid, k))
            {
                lo = mid;
            }
            else
                hi = mid; 


        }
        return lo;

        // for(int i = 0; i<k; i++)
        // {

        // }
        
    }

    bool can_make_valid_string(string s, int mid, int k)
    {
        unordered_map<int, int> freq_map;
        int max_frequency = 0;
        int start = 0;
        for(int end = 0; end<s.size(); end++)
        {
            freq_map[s[end]] = freq_map.find(s[end]) != freq_map.end() ? freq_map[s[end]] + 1 : 1;

            if (end+1-start> mid)
            {
                freq_map[s[start]]-=1;
                start+=1;

            }
            max_frequency = max(max_frequency, freq_map[s[end]]);
            if (mid-max_frequency <= k)
            {
                return 1;
            }

        }
        return 0; 
    }
};