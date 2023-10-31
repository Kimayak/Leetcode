
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int longest_streak = 1;
        int current_streak = 1;

        for (int i = 1; i < nums.size(); i++) { // Start from i = 1
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    current_streak++;
                } else {
                    longest_streak = max(longest_streak, current_streak);
                    current_streak = 1;
                }
            }
        }
        return max(longest_streak, current_streak);

        // if(nums.size()==0)
        //     return 0;
        // sort(nums.begin(), nums.end());
        // int longest_streak = 1;
        // int current_streak = 1;

        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]!= nums[i-1])
        //     {
        //         if(nums[i]==nums[i-1]+1)
        //         {
        //             current_streak++;
        //         }
        //         else
        //         {
        //             longest_streak = max(longest_streak, current_streak);
        //             current_streak = 1; 
        //         }
        //     }
        // }
        // return max(longest_streak, current_streak);

        //Time limit exceeded

        // int longest_streak = 0;
        // int current_num;
        // int current_streak;
        // //vector<int>::iterator it;
        // for(int num: nums)
        // {
        //     current_num = num;
        //     current_streak = 1;
        //     //it = find(nums.begin(), nums.end(), num+1)

        //     while (find(nums.begin(), nums.end(), current_num + 1) != nums.end())
        //         {
        //             current_num++;
        //             current_streak++;
        //         }
        //     longest_streak = max(longest_streak, current_streak);

        // }
        // return longest_streak;

    //     cout<< nums[0]<< nums[1];
    //     int count = 0; 
    //     for (int i =0; i <nums.size()-1; i++)
    //     {
    //         if(nums[i+1]- nums[i] == 1)
    //           {  count++;
    //           cout<<nums[i+1]<<nums[i];
    //           }
    //         else 
    //             continue;
    //     }
    //     if (count!= 0)
    //         return (count+1); 
    //     return count;
    }
};