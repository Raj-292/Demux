// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), i, j, res = 1;
        vector<vector<int> > dp(n, vector<int>(1001, 1));
        
        for(i = 1; i < n; i++) {
            for(j = 0; j < i; j++) {
                int cd = A[i]-A[j];
                
                dp[i][cd+500] = max(1+dp[j][cd+500], dp[i][cd+500]);
                
                res = max(res, dp[i][cd+500]);
            }
        }
        return res;
    }
};