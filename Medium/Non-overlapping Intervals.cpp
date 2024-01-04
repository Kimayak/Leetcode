

// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104

bool Comparesecond(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    // bool isOverlap(vector<int>&a, vector<int>&b){
    //         return min(a[1],b[1]) - max(a[0], b[0])>=0;
    //     }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Comparesecond);
        int ans = 0; 
        int k = INT_MIN;

        for(int i = 0; i<intervals.size(); i++){
            int x = intervals[i][0];
            int y = intervals[i][1];

            if(x>=k){
                k = y;
            }
            else{
                ans++;
            }
            
                    }
        
        return ans; 
        
    }
};