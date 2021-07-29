// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        vector<int> dp(2);
        
        dp[1%2] = 1;
        dp[2%2] = 2;
        
        for(int i = 3; i <= n; i++) {
            dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
        }
        
        return dp[n%2];
        
    }
};