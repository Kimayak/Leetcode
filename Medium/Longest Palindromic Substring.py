

# Given a string s, return the longest 
# palindromic
 
# substring
#  in s.

 

# Example 1:

# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.
# Example 2:

# Input: s = "cbbd"
# Output: "bb"
 

# Constraints:

# 1 <= s.length <= 1000
# s consist of only digits and English letters.


class Solution:
    def longestPalindrome(self, s: str) -> str:

        if s == s[::-1]:
            return s
        start, size = 0,1

        for i in range(1, len(s)):
            left, right = i-size, i+1
            substring = s[left-1: right]

            if left>=1 and substring == substring[::-1]:
                size+=2
                start = left - 1
            else:
                substring = s[left:right]
                if substring == substring[::-1]:
                    size+=1
                    start = left
        return s[start: start+size]
        # n = len(s)

        # dp = [[0]*n for i in range(n)]

        # ans = [0,0]


        # for i in range(n):
        #     dp[i][i] = 1

        # for i in range(n-1):
        #     if s[i] == s[i+1]:
        #         dp[i][i+1] = 1
        #         ans = [i, i+1]

        # for diff in range(2,n):
        #     for i in range(n - diff):
        #         j = i + diff
        #         if s[i] == s[j] and dp[i+1][j-1]:
        #             dp[i][j] = 1
        #             ans = [i,j]

        # i = ans[0]
        # j = ans[1]

        # return s[i:j+1]
                    
                    
                
                
            
        
                
            


        
            

        

        
        
        