// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), i, res = INT_MIN;
        vector<int> dp(n+1, 0);
        
        for(i = 1; i <= n; i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};