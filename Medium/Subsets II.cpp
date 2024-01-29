

// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}};

        int subsetSize = 0; 

        for(int i = 0; i <nums.size(); i++){
            int startingIndex = (i>=1 && nums[i] == nums[i-1])? subsetSize: 0;

            subsetSize = subsets.size();
            for(int j =startingIndex; j < subsetSize; j++){
                vector<int> currentSubset = subsets[j];
                currentSubset.push_back(nums[i]);

                subsets.push_back(currentSubset);
            }
        }
        return subsets;
        
    }
};