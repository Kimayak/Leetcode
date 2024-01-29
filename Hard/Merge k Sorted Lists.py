
# ou are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

# Merge all the linked-lists into one sorted linked-list and return it.

 

# Example 1:

# Input: lists = [[1,4,5],[1,3,4],[2,6]]
# Output: [1,1,2,3,4,4,5,6]
# Explanation: The linked-lists are:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# merging them into one sorted list:
# 1->1->2->3->4->4->5->6
# Example 2:

# Input: lists = []
# Output: []
# Example 3:

# Input: lists = [[]]
# Output: []
 

# Constraints:

# k == lists.length
# 0 <= k <= 104
# 0 <= lists[i].length <= 500
# -104 <= lists[i][j] <= 104
# lists[i] is sorted in ascending order.
# The sum of lists[i].length will not exceed 104.


# Definition for singly-linked list.
# 

class Solution:
    def merge2Lists(self, list1: List[Optional[ListNode]], list2: List[Optional[ListNode]]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        elif list2 is None:
            return list1
        elif list1.val<list2.val:
            list1.next = self.merge2Lists(list1.next, list2)
            return list1
        else:
            list2.next = self.merge2Lists(list1, list2.next)
            return list2
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists is None: 
            return None
        interval = 1
        n = len(lists)

        while interval<n:
            for i in range(0,n-interval, 2*interval):
                lists[i] = self.merge2Lists(lists[i], lists[i+interval])
            interval = interval*2
        if n>0:
            return lists[0]
        else:
            return None
            