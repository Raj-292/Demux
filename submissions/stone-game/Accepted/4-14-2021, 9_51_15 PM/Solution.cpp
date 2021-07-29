// https://leetcode.com/problems/stone-game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), i, j;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill the diagonal
        for(i = 0; i < n; i++)
            dp[i][i] = piles[i];
        
        for(i = n-2; i >= 0; i--) {
            for(j = i+1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] > 0;
    }
};