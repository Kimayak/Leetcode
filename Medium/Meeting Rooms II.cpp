

// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

// Example 1:

// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2
// Example 2:

// Input: intervals = [[7,10],[2,4]]
// Output: 1
 

// Constraints:

// 1 <= intervals.length <= 104
// 0 <= starti < endi <= 106



class Solution {
  
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        map<int, int> mp;
        //key: time; val: +1 if start, -1 if end


        for (int i =0; i< intervals.size(); i++){
            mp[intervals[i][0]]+=1;
            mp[intervals[i][1]]-=1;
        }

        int cnt = 0, maxCnt =0; 
        for(auto it = mp.begin(); it!= mp.end(); it++){
            cnt+=it->second; 
            maxCnt = max(cnt, maxCnt); 
        }

        return maxCnt; 
       
    }
};