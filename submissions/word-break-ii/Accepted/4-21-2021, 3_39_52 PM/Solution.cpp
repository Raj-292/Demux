// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    void func(string& s,int index,string& contri,vector<string>& res,vector<bool>& dp,vector<string>& wordDict){
        int n = s.size();
        if(index == n){
            contri = contri.substr(0,contri.length()-1);
            res.push_back(contri);
            return ;
        }
        
        if(dp[index] == false)
            return ;
        
        string temp ="";
        string prev_contri = "";
        
        for(int i=index;i<n;i++){
            temp+=s[i];
            if(find(wordDict.begin(),wordDict.end(),temp) == wordDict.end()){
                continue;
            }
            prev_contri = contri;
            contri += temp + " ";
            func(s,i+1,contri,res,dp,wordDict);
            contri = prev_contri;            
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool>dp(n+1,false);
        
        dp[n] = true;
        
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<=n;j++){
                
                string ss = s.substr(i,j-i);
                if(find(wordDict.begin(),wordDict.end(),ss) != wordDict.end()){
                    dp[i] = (dp[i]) || (dp[j]);
                }
            }
        }
        
        vector<string>res;
        if(dp[0] == false){
            return res;
        }
        string contri = "";
        
        func(s,0,contri,res,dp,wordDict);
        return res;
    }
};