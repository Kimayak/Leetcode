# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

# You must write an algorithm that runs in O(n) time and without using the division operation.

 

# Example 1:

# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]
# Example 2:

# Input: nums = [-1,1,0,-3,3]
# Output: [0,0,9,0,0]
 

# Constraints:

# 2 <= nums.length <= 105
# -30 <= nums[i] <= 30
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

# Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n= len(nums)
        prefix = [1]*n
        postfix = [1]*n
        answer = [1]*n

        for i in range(1,n ):
            prefix[i] = prefix[i-1]*nums[i-1]

        for j in range(n-2, -1, -1):
            postfix[j] = postfix[j+1]*nums[j+1]

        for k in range(n):
            answer[k] = prefix[k]*postfix[k]
        
        return answer

        



        # answer =[0]*length

        # answer[0] = 1

        # for i in range(1, length):
        #     answer[i] = nums[i-1]*answer[i-1]

        # r = 1
        # for i in reversed(range(length)):
        #     answer[i] = answer[i]*r
        #     r*=nums[i]

        # return answer
        