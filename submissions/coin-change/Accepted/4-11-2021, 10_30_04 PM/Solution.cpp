// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), i, j;
        vector<vector<int>> dp(2, vector<int>(amount+1, INT_MAX));
        
        dp[n%2][0] = 0;
        for(i = n-1; i >= 0; i--) {
            for(j = 0; j <= amount; j++) {
                dp[i%2][j] = dp[(i+1)%2][j];
                
                if (j-coins[i] >= 0 && dp[i%2][j-coins[i]] != INT_MAX)
                    dp[i%2][j] = min(dp[i%2][j], 1+dp[i%2][j-coins[i]]);
            }
        }
        
        return dp[0][amount] == INT_MAX? -1: dp[0][amount];
    }
};