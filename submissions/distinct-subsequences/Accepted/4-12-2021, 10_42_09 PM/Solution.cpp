// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(), i, j, temp;
        vector<unsigned long> dp(n+1, 0);
        
        dp[0] = 1;
        
        for(i = 1; i <= m; i++) {
            for (j = n; j >= 1; j--) {
                if (s[i-1] == t[j-1])
                    dp[j] += dp[j-1];
            }
        }
        
        return dp[n];
    }
};