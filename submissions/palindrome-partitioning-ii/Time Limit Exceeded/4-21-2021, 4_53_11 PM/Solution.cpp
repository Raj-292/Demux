// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool ispalindrome(string ss){
        string temp = ss;
        reverse(temp.begin(),temp.end());
        int n = ss.length();
        
        for(int i=0;i<n;i++){
            if(ss[i] != temp[i])
                return false;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
            
        vector<int>dp(n+1,INT_MAX);
        dp[n] = -1;
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            string temp = "";
            for(int j=i;j<n;j++){
                temp += s[j];
                if(ispalindrome(temp) == true){
                    dp[i] = min(dp[i],1 + dp[j+1]);
                }
                else{
                    continue;
                }
            }
        }
        return dp[0];
        
    }
};