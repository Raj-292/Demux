// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    void wordBreakHelper(string& s, unordered_set<string>& dict, int start, string& contri, vector<string>& res/*, vector<bool>& dp */) {
        int n = s.size();
        // Positive base case.
        if(start == n) {
            contri = contri.substr(0, contri.size()-1);
            res.push_back(contri);
            return;
        }
        
        // Pruning
        // if (!dp[start])
        //     return;
        
        string temp = "";
        string prev_contri;
        for(int i = start; i < n; i++) {
            temp += s[i];
            
            if (dict.find(temp) == dict.end())
                continue;
            
            prev_contri = contri;
            contri = contri + temp + " ";
            wordBreakHelper(s, dict, i+1, contri, res/*, dp*/);
            // Undo
            contri = prev_contri;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int i, j, n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        string temp = "";
        
//         for(i = n-1; i >= 0; i--) {
//             temp = "";
//             for(j = i; j < n; j++) {
//                 temp += s[j];
                
//                 if (dict.find(temp) == dict.end())
//                     continue;
                
//                 dp[i] = dp[i] || dp[j+1];
                
//                 if (dp[i])
//                     break;
//             }
//         }
        
        vector<string> res;
        string contri = "";
        wordBreakHelper(s, dict, 0, contri, res/*, dp*/);
        
        return res;
    }
};