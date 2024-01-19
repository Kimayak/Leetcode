
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Initialize the maximum area to 0
        int maxArea = 0;
        // Use a stack to keep track of the indices of the bars
        stack<int> s; 
        // Add a zero height to the end of the heights array to handle any remaining bars in the stack at the end
        heights.push_back(0);

        // Get the number of bars in the histogram
        int n = heights.size();

        // Iterate through each bar
        for(int i = 0; i < n; i++){
            // While the stack is not empty and the current bar's height is less than the height of the bar at the top of the stack
            while(!s.empty() && heights[s.top()] > heights[i]){
                // Get the height of the bar at the top of the stack
                int height = heights[s.top()];
                // Pop the top element from the stack
                s.pop();
                // Calculate the width of the rectangle
                // If the stack is empty, use the current index as the width
                // Otherwise, calculate the width as the difference between the current index and the index of the new top of the stack minus 1
                int width = s.empty() ? i : i - s.top() - 1;
                // Update the maximum area if necessary
                maxArea = max(maxArea, height * width);
            }
            // Push the current index onto the stack
            s.push(i);
        }
        // Return the maximum area found
        return maxArea; 
    }
};
