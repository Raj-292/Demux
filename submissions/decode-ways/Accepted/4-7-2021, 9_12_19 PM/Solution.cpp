// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), i;
        vector<int> dp(n);
        
        dp[n-1] = s[n-1] == '0'? 0: 1;
        
        for (int i = n-2; i >= 0; i--) {
            dp[i] = 0;
            // 2 cases
            // Single digit
            if (s[i] != '0')
                dp[i] += dp[i+1];
            
            // Double digit
            if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                if (i == n-2)
                    dp[i] += 1;
                else
                    dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};