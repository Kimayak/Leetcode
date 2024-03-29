

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0
 

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n<=1) return 0;

        vector<int> hold(n,0), sell(n,0), cooldown(n,0);

        hold[0] = -prices[0];

        for(int i =1; i<n; i++){
            hold[i] = max(hold[i-1], cooldown[i-1]- prices[i]);
            sell[i] = hold[i-1]+prices[i];
            cooldown[i] = max(cooldown[i-1], sell[i-1]);


        }
        return max(sell[n-1], cooldown[n-1]);
        
    }
};