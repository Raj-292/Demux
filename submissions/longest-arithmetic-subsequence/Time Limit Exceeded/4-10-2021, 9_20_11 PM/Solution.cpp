// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), i, j, cd, res = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for(i = 0; i < n; i++) {
            // Compute dp[i]
            for(j = 0; j < i; j++) {
                cd = A[i] - A[j];
                dp[i][cd] = max(2, 1+dp[j][cd]);
                res = max(res, dp[i][cd]);
            }
        }
        
        return res;
    }
};