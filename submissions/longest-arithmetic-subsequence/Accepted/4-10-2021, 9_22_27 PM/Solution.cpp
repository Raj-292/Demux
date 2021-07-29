// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), i, j, cd, res = 0;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        
        for(i = 0; i < n; i++) {
            // Compute dp[i]
            for(j = 0; j < i; j++) {
                cd = A[i] - A[j];
                dp[i][cd+500] = max(2, 1+dp[j][cd+500]);
                res = max(res, dp[i][cd+500]);
            }
        }
        
        return res;
    }
};