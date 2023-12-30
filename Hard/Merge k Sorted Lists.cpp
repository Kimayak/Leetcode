
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        else if(l1->val<l2->val)
        {
            l1->next = merge2Lists(l1->next , l2);
            return l1;
        }
        else
        {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n , interval;
        n = lists.size();
        interval = 1;

        while (interval<n)
        {
            for(int i = 0 ; i<n-interval; i= i +2*interval)
            {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            interval = interval*2; 
        }
        if (n>0)
            return lists[0];
        else 
            return nullptr;


        

        
    }
};