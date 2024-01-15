
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Get the lengths of the two input strings
        int m = text1.length(); 
        int n = text2.length();

        // Create a 2D DP array to store the lengths of common subsequences
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Iterate through both strings using nested loops
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // If the characters at the current positions match:
                if(text1[i-1] == text2[j-1]) {
                    // Increment the length of the common subsequence by 1
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // If characters don't match, take the maximum length
                    // from either moving one character back in text1 or
                    // moving one character back in text2
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // The length of the longest common subsequence is stored in dp[m][n]
        return dp[m][n];
    }
};
