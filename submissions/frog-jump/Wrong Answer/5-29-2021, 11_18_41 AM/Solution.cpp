// https://leetcode.com/problems/frog-jump

class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &dp, unordered_map<int,int>&m, vector<int> &stones){
        if(i == n-1){
            return 1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        else{
            bool temp = false;
            if(j>1 && m.find(stones[i]+j-1)!=m.end()){
                temp = temp||f(m[stones[i]+j-1],j-1,n,dp,m,stones);
            }
            if(m.find(stones[i]+j)!=m.end()){
                temp = temp||f(m[stones[i]+j],j,n,dp,m,stones);
            }
            if(m.find(stones[i]+j+1)!=m.end()){
                temp = temp||f(m[stones[i]+j+1],j+1,n,dp,m,stones);
            }
            dp[i][j] = (int)temp;
        }
        
        return dp[i][j];
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
            dp[n-1][i+1] = 1;
        }
        
        return f(1,1,n,dp,m,stones);
    }
};