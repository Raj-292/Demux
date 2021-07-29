// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), i;
        vector<int> dp(2, 0);
        
        dp[n%2] = 1;
        dp[(n-1)%2] = s[n-1] == '0'? 0: 1;
        
        for (int i = n-2; i >= 0; i--) {
            int t = 0;
            // 2 cases
            // Single digit
            if (s[i] != '0')
                t += dp[(i+1)%2];
            
            // Double digit
            if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                t += dp[(i+2)%2];
            }
            
            dp[i%2] = t;
        }
        
        return dp[0%2];
    }
};