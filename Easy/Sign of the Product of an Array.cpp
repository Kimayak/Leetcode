// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

 

// Example 1:

// Input: nums = [-1,-2,-3,-4,3,2,1]
// Output: 1
// Explanation: The product of all values in the array is 144, and signFunc(144) = 1
// Example 2:

// Input: nums = [1,5,0,2,-3]
// Output: 0
// Explanation: The product of all values in the array is 0, and signFunc(0) = 0
// Example 3:

// Input: nums = [-1,1,-1,1,-1]
// Output: -1
// Explanation: The product of all values in the array is -1, and signFunc(-1) = -1



class Solution {
public:
    int arraySign(vector<int>& nums) {
        //both codes similar in time and memory
        // int countNeg = 0;
        // for(int num:nums)
        // {
        //     if(num == 0)
        //         return 0;
        //     if(num<0)
        //         countNeg++;
        // }
        // return countNeg%2==0 ? 1: -1;

        //memory complexity high
        double product=1;

        for(int i =0; i<size(nums); i++)
        {
            if(nums[i] == 0)
                {
                return 0;
                }
            
            product*=nums[i];
        }
        
        if(product>0)
            return 1;
        else if (product<0)
            return -1;
        else
            return 0;
    }
};