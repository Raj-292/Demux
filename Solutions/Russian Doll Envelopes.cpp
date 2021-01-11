class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int i, n = envelopes.size(), maxNum = 0, j;
        vector<int> dp(n, 0);
        for (i = 0; i < n; i++) {
            dp[i] = 1;
            maxNum = max(maxNum, dp[i]);
            for (j = i - 1; j >= 0; j--) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxNum = max(maxNum, dp[i]);
                }
            }
        }

        return maxNum;
    }
};