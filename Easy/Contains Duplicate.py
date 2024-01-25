# Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

# Example 1:

# Input: nums = [1,2,3,1]
# Output: true
# Example 2:

# Input: nums = [1,2,3,4]
# Output: false
# Example 3:

# Input: nums = [1,1,1,3,3,4,3,2,4,2]
# Output: true
 

# Constraints:

# 1 <= nums.length <= 105
# -109 <= nums[i] <= 109


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        d = set()
        for i in nums:
            if i in d:
                return True
            d.add(i)
        return False
        # sorted_nums = sorted(nums)

        # for i in range(len(sorted_nums)-1):
        #     if(sorted_nums[i] == sorted_nums[i+1]): 
        #         return True
        # return False

        