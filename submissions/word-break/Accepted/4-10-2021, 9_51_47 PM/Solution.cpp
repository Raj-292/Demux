// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int i, j, n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        string temp = "";
        
        for(i = n-1; i >= 0; i--) {
            temp = "";
            for(j = i; j < n; j++) {
                temp += s[j];
                
                if (dict.find(temp) == dict.end())
                    continue;
                
                dp[i] = dp[i] || dp[j+1];
                
                if (dp[i])
                    break;
            }
        }
        
        return dp[0];
    }
};