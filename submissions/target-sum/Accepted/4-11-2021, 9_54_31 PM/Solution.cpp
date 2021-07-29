// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), i, j;
        vector<vector<int>> dp(2, vector<int>(2001, 0));
        
        // sum = 0
        // -1000 to 1000 to [0, 2000]
        // 0 to 1000
        dp[n%2][1000] = 1;
        
        for(i = n-1; i >= 0; i--) {
            for(j = -1000; j <= 1000; j++) {
                dp[i%2][j+1000] = 0;
                
                // two cases
                // +ve sign
                if (j+1000-nums[i] >= 0)
                    dp[i%2][j+1000] += dp[(i+1)%2][j+1000-nums[i]];
                
                // -ve sign
                if (j+1000+nums[i] <= 2000)
                    dp[i%2][j+1000] += dp[(i+1)%2][j+1000+nums[i]];
            }
        }
        
        return dp[0%2][target+1000];
    }
};