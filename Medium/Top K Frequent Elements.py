# Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

# Example 1:

# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]
# Example 2:

# Input: nums = [1], k = 1
# Output: [1]
 

# Constraints:

# 1 <= nums.length <= 105
# -104 <= nums[i] <= 104
# k is in the range [1, the number of unique elements in the array].
# It is guaranteed that the answer is unique.
 

# Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count the frequency of each number in nums
        count = Counter(nums)

        # Create a heap of tuples with negative frequency and the number
        # Negative frequency is used because Python's heapq is a min-heap,
        # and we want the largest frequencies
        heap = [(-freq, num) for (num, freq) in count.items()]

        # Transform the list into a heap in place
        heapq.heapify(heap)

        # Extract the top k elements from the heap
        # Since the frequencies are negative, heappop returns the largest frequencies
        return [heapq.heappop(heap)[1] for _ in range(k)]
