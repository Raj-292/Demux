// https://leetcode.com/problems/house-robber

class Solution {
public:
    
    int f(vector<int>& nums,vector<int>& dp,int pos){
        
        if(pos>=nums.size()){
            return 0;
        }
        
        int c1 = 0;
        int c2 = 0;
        
        if(dp[pos+2]==-1){
            c1 = f(nums,dp,pos+2);
            dp[pos+2]=c1;
            c1+=nums[pos];
        } else{
            c1 = dp[pos+2] + nums[pos] ;
        }
        
        if(dp[pos+1]==-1){
            c2 = f(nums,dp,pos+1);
            dp[pos+1] = c2;
        } else{
            c2 = dp[pos+1];
        }
        
        return max(c1,c2);
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(105,-1);
        return f(nums,dp,0);
    }
};