// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
        int n = coins.size(), i, j;
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        
        for(i = 1; i <= amount; i++) {
            for(j = 0; j < n; j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};