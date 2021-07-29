// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), temp;
        
        vector<int> dp(2);
        
        // Base cases
        // 0 -> sell
        // 1 -> buy
        dp[0] = prices[n-1] - fee;
        dp[1] = max(0, -prices[n-1]);
        
        for (int i = n-2; i >= 0; i--) {
            temp = max(prices[i] - fee + dp[1], dp[0]);
            dp[1] = max(dp[1], -prices[i] + dp[0]);
            dp[0] = temp;
        }
        
        return dp[1];
    }
};