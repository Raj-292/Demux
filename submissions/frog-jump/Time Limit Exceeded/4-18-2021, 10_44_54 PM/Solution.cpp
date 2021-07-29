// https://leetcode.com/problems/frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        
        int n = stones.size(), i, j;
        unordered_map<int, int> m;
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        
        // Populate the map and the base case
        for(i = 0; i < n; i++){
            m[stones[i]] = i;
            dp[n-1][i+1] = true;
        }
            
        // DP table
        for(i = n-2; i >= 1; i--) {
            for(j = 1; j <= n; j++) {
                // 3 cases
                // j-1
                if (j > 1 && m.find(stones[i]+j-1) != m.end())
                    dp[i][j] = dp[i][j] || dp[m[stones[i]+j-1]][j-1];
                
                // j
                if(m.find(stones[i]+j) != m.end())
                    dp[i][j] = dp[i][j] || dp[m[stones[i]+j]][j];
                
                // j+1
                if (m.find(stones[i]+j+1) != m.end())
                    dp[i][j] = dp[i][j] || dp[m[stones[i]+j+1]][j+1];
            }
        }
        
        return dp[1][1];
    }
};