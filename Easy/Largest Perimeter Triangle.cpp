// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

// Example 1:

// Input: nums = [2,1,2]
// Output: 5
// Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
// Example 2:

// Input: nums = [1,2,1,10]
// Output: 0
// Explanation: 
// You cannot use the side lengths 1, 1, and 2 to form a triangle.
// You cannot use the side lengths 1, 1, and 10 to form a triangle.
// You cannot use the side lengths 1, 2, and 10 to form a triangle.
// As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
 

// Constraints:

// 3 <= nums.length <= 104
// 1 <= nums[i] <= 106


class Solution {
public:
    // bool isTriangle(int side1, int side2, int side3) {
    //     // Check the triangle inequality theorem
    //     if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
    //         return true; // The sides can form a triangle
    //     } else {
    //         return false; // The sides cannot form a triangle
    //     }
    // }
    int largestPerimeter(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    for(int i = nums.size()-3; i>=0; --i)
    {
        if(nums[i]+nums[i+1]>nums[i+2])
            return nums[i]+nums[i+1]+nums[i+2];
        
    }
    return 0; 
    // if(nums.size()<3)
    //     return 0;
    // else if(nums.size() == 3)
    //     if isTriangle(nums[0], nums[1],nums[2])
    //         return nums[0]+nums[1]+nums[2];
    //     else
    //         return 0;
    // else
    // {







    // }
        
        
    }
};