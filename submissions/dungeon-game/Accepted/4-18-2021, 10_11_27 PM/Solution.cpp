// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size(), i, j;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        dp[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);
        
        for(i = m-1; i >= 0; i--) {
            for(j = n-1; j >= 0; j--) {
                if (i+1 < m)
                    dp[i][j] = min(dp[i][j], dp[i+1][j] - dungeon[i][j]);
                
                if (j+1 < n)
                    dp[i][j] = min(dp[i][j], dp[i][j+1] - dungeon[i][j]);
                
                dp[i][j] = max(1, dp[i][j]);
            }
        }
        
        return dp[0][0];
    }
};