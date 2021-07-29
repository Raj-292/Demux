// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), i, j, res = 0;
        vector<int> dp(n, 0);
        
        for(i = 1; i < n; i++) {
            if (s[i] == '(')
                dp[i] = 0;
            else {
                j = i - dp[i-1] - 1;
                
                if (j >= 0 && s[j] == '(') {
                    dp[i] = 2 + dp[i-1];
                    
                    if (j-1 >= 0)
                        dp[i] += dp[j-1];
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};