// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), i, j, res = 1;
        vector<int> dp(n, 1);
        
        for(i = 1; i < n; i++) {
            // Compute dp[i]
            for(j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1+dp[j]);    
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};