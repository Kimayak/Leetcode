
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
    
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0; 

        if(n<=0)
            return 0;

        bool dp[n][n];

        fill_n(*dp, n*n, false);

        //base case: single letter substrings
        for(int i = 0; i<n; i++, ans++)
            dp[i][i] = true;
        
        //base case: double letter strings
        for(int i = 0; i<n-1; i++){
            dp[i][i+1] = (s[i]==s[i+1]);

            ans+=dp[i][i+1];
        }
        //n>3
        for(int len = 3; len<=n; len++){
            for(int i=0, j=i+len-1; j<n; i++,j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                ans+=dp[i][j];
            }


        }
        return ans; 
    }
};