// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), len, i;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Length wise
        for (len = 1; len <= n; len++) {
            for(i = 0; i+len-1 < n; i++) {
                if (len == 1)
                    dp[i][i] = 1;
                else {
                    // s[i][i+len-1]
                    if (s[i] == s[i+len-1])
                        dp[i][i+len-1] = 2 + (i+1 > i+len-2? 0: dp[i+1][i+len-2]);
                    else
                        dp[i][i+len-1] = max(dp[i+1][i+len-1], dp[i][i+len-2]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};