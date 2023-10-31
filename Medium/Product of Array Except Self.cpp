// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


class Solution {
public:
    // bool isAllZeros(vector<int>& vec) {
    //     for (int element : vec) {
    //         if (element != 0) {
    //             return false; // If any element is not zero, return false
    //         }
    //     }
    //     return true; // All elements are zero
    // };
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> left_prod(n);
        vector<int> right_prod(n);
        left_prod[0] =1;
        for(int i = 1; i <nums.size(); i++)
        {
            left_prod[i] = left_prod[i-1]*nums[i-1];
        }
        right_prod[n-1] = 1;
        for(int i =n-2; i>=0; i--)
        {
            right_prod[i] = right_prod[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++)
        {
            answer[i] = left_prod[i]*right_prod[i];
        }
        return answer;
        // int prod=1;
        // int prod1 = 1; 
        // vector<int> answer;
        // if(isAllZeros(nums))
        // {
        //     for(int i = 0; i<nums.size(); i++)
        //         answer.push_back(0);
        //     return answer;
        // }
        // for(int num:nums)
        // {
        //     if (num==0)
        //         {
        //             prod1 = 0;
        //             continue;
        //         }
        //     prod*=num;
        // }
       
        // for(int i =0; i <nums.size(); i++)
        // {
        //     if (prod1 == 0 && nums[i]!=0)
        //         {answer.push_back(prod1);
        //         continue;}
        //     else if (prod1 == 0 && nums[i]==0)
        //         {answer.push_back(prod);
        //         continue;}
        //     answer.push_back(prod/nums[i]);
        // }
        // return answer;
        
    }
};