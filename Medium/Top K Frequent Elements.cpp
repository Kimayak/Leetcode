
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#include<vector>
#include<iostream> 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size())
            return nums;
        map<int,int> count_map;
        for(int n:nums){
            count_map[n]+=1;
        }
        vector<pair<int,int>> val(count_map.begin(), count_map.end());
        vector<int> top_nums;
        sort(val.begin(), val.end(),[](auto &x, auto &y){return x.second > y.second;});
        //auto it = val;
        for (int i=0; i<k; i++)
        {
            top_nums.push_back(val[i].first);
        }
        return top_nums;
        
        
        
        // unordered_map<int, int> frequency_map;
        // for(int num: nums)
        //     frequency_map[num]++;
        
        // vector<int> ans,temp;
        // temp = nums;
        // temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
        // vector<int> nums1;
        // int k1;
        
        // for(int num: temp)
        // {
        //     k1 =0;
        //     for(int i=0; i<nums.size(); i++)
        //     {
        //         if(num == nums[i])
        //         {
        //             k1++;
        //             if(k1 == k)
        //             {
        //                 ans.push_back(num);
        //                 continue;
        //             }
        //         }

        //     }
        //     // if(k1==k)
        //     //     ans.push_back(num);
        // }
        // return ans;
        
    }
};