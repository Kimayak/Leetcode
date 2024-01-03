

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

// Constraints:

// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 105
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 105


class Solution {
public:
    bool doesIntervaloverlap(vector<int>& a, vector<int>& b){
        return min(a[1], b[1]) - max(a[0], b[0])>=0;
    }

    vector<int> mergeIntervals(vector<int>& a, vector<int>& b){
        return{min(a[0], b[0]), max(a[1], b[1])};

    }

    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        int index = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();

        if(index!= intervals.size()){
            intervals.insert(intervals.begin()+index, newInterval);
        } else{
            intervals.push_back(newInterval); 
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        insertInterval(intervals, newInterval);

        vector<vector<int>> ans;

        for(int i =0 ;i<intervals.size(); i++){
            vector<int> currentInterval = {intervals[i][0], intervals[i][1]};
            while(i<intervals.size() && doesIntervaloverlap(currentInterval, intervals[i]))
            {
                currentInterval = mergeIntervals(currentInterval, intervals[i]);
                i++;
            }
            i--;
            ans.push_back(currentInterval);
        }   
        return ans;     
    }
};


