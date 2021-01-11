class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, j, maxE = INT_MIN, pi, res = 0;

        if (n == 0) return 0;


        // Reverse the order of iteration of i
        maxE = prices[n - 1];
        for (i = n - 2; i >= 0; i--) {
            // Get pi
            pi = maxE - prices[i];


            // Update res
            res = max(res, pi);

            // Update maxE
            maxE = max(maxE, prices[i]);
        }

        return res;
    }
};