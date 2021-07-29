// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    // Returns the number of ways you can climb to top
    int climbStairsHelper(int n, vector<int>& dp) {
        // Base cases
        if (n == 1)
            return 1;
        
        if (n == 2)
            return 2;
        
        // Recursive step
        // Have I solved the subproblem?
        if (dp[n] != -1)
            return dp[n];
        
        // If I haven't solved it.
        // Solve it now and store it
        dp[n] = climbStairsHelper(n-1, dp) + climbStairsHelper(n-2, dp);
        
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        return climbStairsHelper(n, dp);
        
    }
};