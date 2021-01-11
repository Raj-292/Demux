class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size(), i, maxProfit = 0;

		for (i = 1; i < n; i++)
			maxProfit += (prices[i] > prices[i - 1]) ? prices[i] - prices[i - 1] : 0;

		return maxProfit;
	}
};