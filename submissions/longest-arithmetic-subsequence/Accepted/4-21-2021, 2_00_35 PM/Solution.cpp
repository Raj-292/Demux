// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        
        vector<vector<int>>dp(n,vector<int>(2001,1));
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                dp[i][A[i]-A[j] + 1000] = 1 + dp[j][A[i]-A[j] + 1000];
                ans = max(ans,dp[i][A[i]-A[j] + 1000]);
            }
        }
        return ans;
    }
};