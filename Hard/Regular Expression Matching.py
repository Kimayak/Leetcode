
# 10. Regular Expression Matching
# Hard
# 11.7K
# 2K
# company
# Amazon
# company
# Facebook
# company
# Microsoft
# Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

# '.' Matches any single character.​​​​
# '*' Matches zero or more of the preceding element.
# The matching should cover the entire input string (not partial).

 

# Example 1:

# Input: s = "aa", p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
# Example 2:

# Input: s = "aa", p = "a*"
# Output: true
# Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
# Example 3:

# Input: s = "ab", p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
 

# Constraints:

# 1 <= s.length <= 20
# 1 <= p.length <= 20
# s contains only lowercase English letters.
# p contains only lowercase English letters, '.', and '*'.
# It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

class Solution:
#     def isMatch(self, s: str, p: str) -> bool:
#         # initialize 2D table
#         #+1 is used to include empty string or pattern as one of the possibilities

#         dp =[[False]*(len(p)+1) for _ in range(len(s)+1)]

#         dp[0][0] = True # both string and pattern empty

#         #* denotes matching zero or more of the preceding elements 
#         #Let us not handle inputs that include *, so for each * there will be zero or more previous elements
#         # starts from one as we need to consider preceding elements
#         # only check 0th row as we are checking if the character can match an empty string
#         for j in range(1, len(p)+1):
#             if p[j - 1] == '*':
#                 dp[0][j] = dp[0][j-2]

#         #fill in the dp table
#         for i in range(1, len(s)+1):
#             for j in range(1,len(p)+1):
#                 if p[j-1] == s[i-1] or p[j-1] == '.':
#                     dp[i][j] = dp[i - 1][j - 1]
#                 elif dp[j-1] == '*':
#                     dp[i][j] = dp[i][j-2] or (dp[i - 1][j] if s[i - 1] == p[j - 2] or p[j - 2] == '.' else False)
#         return dp[len(s)][len(p)]



    def isMatch(self, s: str, p: str) -> bool:
        # Initialize a 2D DP table
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        
        # Empty pattern matches empty string
        dp[0][0] = True
        
        # Handle patterns with '*'
        for j in range(1, len(p) + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]
        
        # Fill in the DP table
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (dp[i - 1][j] if s[i - 1] == p[j - 2] or p[j - 2] == '.' else False)
        
        return dp[len(s)][len(p)]

# # Test case
# s = "aab"
# p = "c*a*b"
# print(isMatch(s, p))  # Output: True
