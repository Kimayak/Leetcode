
# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

# You must write an algorithm that runs in O(n) time.

 

# Example 1:

# Input: nums = [100,4,200,1,3,2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
# Example 2:

# Input: nums = [0,3,7,2,5,8,4,6,0,1]
# Output: 9
 

# Constraints:

# 0 <= nums.length <= 105
# -109 <= nums[i] <= 109

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if not nums:
            return 0
        num_set = set(nums)

        longest_streak = 0
        for num in num_set:
            current_streak = 1 
            if num-1 not in num_set:
                current_num = num
                #current_streak = 1

                while current_num+1 in num_set:
                    current_num = current_num+1
                    current_streak +=1

            longest_streak = max(longest_streak, current_streak)
        return longest_streak 
        # if len(nums) == 0:
        #     return 0
        # sort_nums = sorted(nums)
        # maxStreak = 1
        # currentStreak = 1

        # for i in range(len(sort_nums)-1):
        #     if(sort_nums[i]!=sort_nums[i+1]):
        #         if(sort_nums[i+1] == sort_nums[i]+1):
        #             currentStreak+=1
        #         else:
        #             maxStreak = max(maxStreak, currentStreak)
        # return max(maxStreak, currentStreak)

        