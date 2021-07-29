// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, maxOneTxn = INT_MIN, minSoFar = INT_MAX, res = 0, currProfit = 0, currMax;
        
        if(n < 2) return 0;
        
        vector<int> maxSoFar(n, INT_MIN);
        
        maxSoFar[n-1] = prices[n-1];
        
        for(i = n-2; i >= 0; i--)
            maxSoFar[i] = max(maxSoFar[i+1], prices[i]);
        
        minSoFar = min(prices[1], prices[0]);
        maxOneTxn = prices[1]-prices[0];
        res = max(res, maxOneTxn);
        
        for(i = 2; i < n; i++){
            if(i < n-1)
                currProfit = maxSoFar[i+1]-prices[i];
            else
                currProfit = 0;
            
            currMax = max(currProfit, currProfit+maxOneTxn);
            res = max(res, currMax);
            
            maxOneTxn = max(maxOneTxn, prices[i]-minSoFar);
            minSoFar = min(minSoFar, prices[i]);
            
        }
        
        res = max(res, maxOneTxn);
        
        return res;
    }
};