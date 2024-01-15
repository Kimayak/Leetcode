
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans; 
        deque<int> dq;

        for(int i = 0; i< nums.size(); i++){
            while(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front(); 
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        // vector<int> ans;
        // //vector<int> temp;
        // //int maxNum = INT_MIN;
        // for(int i =0; i<nums.size()-k+1; i++){
        //     // int maxNum = INT_MIN;
        //     // for(int j = 0; j<k; j++){
        //     //     if(nums[i+j]>maxNum){
        //     //         maxNum = nums[i+j];
        //     //     }
                
        //     // }
        //     vector<int> temp(nums.begin()+i, nums.begin()+i+k);
        //     sort(temp.begin(), temp.end());
        //     ans.push_back(temp.back());

        // }
        // return ans; 
        
    }
};