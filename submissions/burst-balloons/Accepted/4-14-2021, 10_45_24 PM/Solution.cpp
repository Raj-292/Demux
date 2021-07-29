// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(), len, i, k, left = 1, right = 1, left_term, right_term;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(len = 1; len <= n; len++) {
            for(i = 0; i+len-1 < n; i++) {
                // nums[i][i+len-1]
                for(k = i; k <= i+len-1; k++) {
                    left = right = 1;
                    if(i-1 >= 0)
                        left = nums[i-1];
                    
                    if(i+len-1+1 < n)
                        right = nums[i+len-1+1];
                    
                    left_term = right_term = 0;
                    if(k-1 >= 0)
                        left_term = dp[i][k-1];
                    
                    if(k+1 < n)
                        right_term = dp[k+1][i+len-1];
                    
                    dp[i][i+len-1] = max(dp[i][i+len-1], left_term+right_term+left*nums[k]*right);
                }
            }
        }
        
        return dp[0][n-1];
    }
};