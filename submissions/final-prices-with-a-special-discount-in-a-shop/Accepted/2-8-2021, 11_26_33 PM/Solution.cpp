// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>res(prices.size(),0);
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i])
                st.pop();
            
            if(st.empty())
                res[i]=prices[i];
            else
                res[i]=prices[i]-st.top();
            
          st.push(prices[i]);
        }
        return res;
    }
};