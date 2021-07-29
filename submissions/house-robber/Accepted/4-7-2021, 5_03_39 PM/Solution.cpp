// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2);
        dp[n%2] = 0;
        dp[(n-1)%2] = nums[n-1];
        
        for(int i = n-2; i >=0; i--) {
            dp[i%2] = max( dp[(i+1)%2], nums[i]+dp[(i+2)%2] );
        }
        return dp[0];
    }
};