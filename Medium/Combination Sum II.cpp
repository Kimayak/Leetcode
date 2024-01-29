

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combinations;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, combinations, result, target, 0);
        return result;
    }

    private:
    void backtrack(const vector<int>& candidates, vector<int>& combination, vector<vector<int>>& result, int target, int start){
        if(target == 0){
            result.push_back(combination);
            return;
        }

        for(int i = start; i<candidates.size() && target>=candidates[i]; i++ ){
            if(i>start && candidates[i]==candidates[i-1]) continue;

            combination.push_back(candidates[i]);
            backtrack(candidates, combination, result, target-candidates[i], i+1);
            combination.pop_back();
        }
    }
};