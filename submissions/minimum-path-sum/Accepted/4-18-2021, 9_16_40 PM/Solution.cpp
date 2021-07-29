// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        
        dp[m][n-1] = dp[m-1][n] = 0;
        
        // Bottom to Top, R to L
        for(i = m-1; i >= 0; i--) {
            for(j = n-1; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};