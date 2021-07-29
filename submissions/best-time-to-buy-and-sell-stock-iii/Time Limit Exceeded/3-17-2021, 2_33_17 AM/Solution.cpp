// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    void f(vector<int>& prices, int i, int maxsofar, int profit, int count, int& ans){
        //Base
        if(i<0 || count ==2){
            ans = max(ans,profit);
            return;
        }
        
        //Recursion
        if(prices[i]>maxsofar){
            maxsofar = prices[i];
            f(prices, i-1, maxsofar, profit, count, ans);
        }
        else{
            f(prices,i-1,maxsofar,profit,count,ans);
            f(prices,i-1,0,profit+maxsofar-prices[i],count+1, ans);
        }
        return;
    }
    
    int maxProfit(vector<int>& prices) {
        int profit = 0, count =0, ans=0, i = prices.size()-1, maxsofar = prices[i];
        f(prices, i-1, maxsofar, profit, count, ans);
        return ans;
    }
};