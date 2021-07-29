// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base cases
        // 0 -> sell
        // 1 -> buy
        dp[n-1][0] = prices[n-1] - fee;
        dp[n-1][1] = max(0, -prices[n-1]);
        
        for (int i = n-2; i >= 0; i--) {
            dp[i][0] = max(prices[i] - fee + dp[i+1][1], dp[i+1][0]);
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
        }
        
        return dp[0][1];
    }
};