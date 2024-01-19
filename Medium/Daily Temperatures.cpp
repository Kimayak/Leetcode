
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0; 

        for(int currDay = n-1; currDay >=0; currDay--){
            int currTemp = temperatures[currDay];

            if(currTemp>=hottest){
                hottest = currTemp;
                continue;
            }

            int days = 1;

            while(temperatures[currDay+ days]<= currTemp){
                days+=ans[currDay+days];
            }
            ans[currDay] = days;
        }
        return ans; 





        // for(int i = 0; i<temperatures.size()-1; i++){

        //     for(int j = i+1 ; j<temperatures.size(); j++){
        //         if(temperatures[i]< temperatures[j]){
        //             ans[i] = j - i;
        //             break; 
        //         }
        //     }
        // }



        // return ans;  
        
    }
};