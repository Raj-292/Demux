// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(), i, j;
        vector<vector<unsigned long>> dp(m+1, vector<unsigned long>(n+1, 0));
        
        // Fill the first column with 1s
        for(i = 0; i <= m; i++)
            dp[i][0] = 1;
        
        for(i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                
                if (s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[m][n];
    }
};