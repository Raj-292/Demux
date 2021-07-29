// https://leetcode.com/problems/frog-jump

class Solution {
public:
    int canCrossHelper(unordered_map<int, int>& m, vector<vector<int>>& dp, int i, int j, vector<int>& stones) {
        // Base case.
        int n = stones.size();
        if (i == n-1)
            return 1;
        
        // DP step.
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursive step
        int t1 = 0, t2 = 0, t3 = 0;
        if (j > 1 && m.find(stones[i]+j-1) != m.end())
            t1 = canCrossHelper(m, dp, m[stones[i]+j-1], j-1, stones);
                
        // j
        if(m.find(stones[i]+j) != m.end())
            t2 = canCrossHelper(m, dp, m[stones[i]+j], j, stones);

        // j+1
        if (m.find(stones[i]+j+1) != m.end())
            t3 = canCrossHelper(m, dp, m[stones[i]+j+1], j+1, stones);
        
        dp[i][j] = t1 || t2 || t3;
        
        return dp[i][j];
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        
        int n = stones.size();
        unordered_map<int, int> m;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        // Populate the map and the base case
        for(int i = 0; i < n; i++){
            m[stones[i]] = i;
        }
            
        // DP table
        return (bool)canCrossHelper(m, dp, 1, 1, stones);
    }
};