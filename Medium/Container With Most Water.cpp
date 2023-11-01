
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104



class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size() -1;
        while(left<right)
        {
            int width = right - left;
            int hght =min(height[left], height[right]);
            maxarea = max(maxarea, hght*width);
            if(height[left]<=height[right])
            {
                left++;
            }
            else 
                right--;

        }
        return maxarea;


        //Time limit exceeded
        // vector<int> areas;
        // int answer = 0;
        // int prod;

        // for(int i = 0; i<height.size()-1; i++)
        // {
        //    // cout<<"Enter";
        //     for(int j = i+1; j<height.size(); j++)
        //     {
        //         //cout
        //        // cout<<"enter?";
        //         //cout<<min(height[j], height[i]);
        //         prod = (j-i)*(min(height[j], height[i]));
        //         //cout<<prod;
        //         answer = max(prod, answer);
                
        //     }
        // }
        // // auto maxElement = max_element(areas.begin(), areas.end());
        // // int maxNumber = *maxElement;
        // // return maxNumber;
        // return answer;
        
    }
};