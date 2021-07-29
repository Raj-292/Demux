// https://leetcode.com/problems/house-robber

class Solution {
public:
   int robHelper(vector<int>& nums, int start, vector<int>& dp) {
        int n = nums.size();
        // Base cases
        if (start == n-1)
            return nums[n-1];
        
        if (start == n)
            return 0;
        
        // Checking if already computed
        if (dp[start] != -1)
            return dp[start];
        
        // Recursive calls
        dp[start] = max(nums[start] + robHelper(nums, start+2, dp), robHelper(nums, start+1, dp));
        
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return robHelper(nums, 0, dp);
    }
};