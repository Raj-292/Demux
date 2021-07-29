// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        
        vector<int> dp(n+1, INT_MAX);
        
        dp[n-1] = 0;
        
        // Bottom to Top, R to L
        for(i = m-1; i >= 0; i--) {
            dp[n] = INT_MAX;
            for(j = n-1; j >= 0; j--) {
                dp[j] = min(dp[j+1], dp[j]) + grid[i][j];
            }
        }
        
        return dp[0];
    }
};