// https://leetcode.com/problems/stone-game-iii

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int>dp(n+3,0);
        
        // dp[0][n-1] = stoneValue[n-1];
        // dp[1][n-1] = stoneValue[n-1];
        dp[n-1] = stoneValue[n-1];
        dp[n-2] = stoneValue[n-2] + stoneValue[n-1];
        
        for(int i = n-3;i>=0;i--){
            int p,q,r;
            // if(i+1 <n){
                // cout<<"here ---- "<<i<<" =i\n";
                p = stoneValue[i] - dp[i+1];
            // }   
            // else
                // p = ;
            // if(i+2<n){
                q = stoneValue[i] + stoneValue[i+1] - dp[i+2];
            // }
            // else
                // q = INT_MAX;
            // if(i+3<n){
                r = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
            // }
            // else
                // r =INT_MAX;
            
            dp[i] = max(q,max(p,r));
        }
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        string ss;
        if(dp[0] > 0){
            ss = "Alice";
        }
        else if(dp[0] == 0)
            ss = "Tie";
        else
            ss = "Bob";
        
        return ss;
    }
};