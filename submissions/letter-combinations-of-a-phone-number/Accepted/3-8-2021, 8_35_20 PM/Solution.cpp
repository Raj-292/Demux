// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    
    void f(string& digits, unordered_map<int,string>& m, int i, int n, string& run, vector<string>& ans){
        //Base
        if(run.size()==n){
            ans.push_back(run);
            return;
        }
        //Recursion
        for(int j=0; j< m[digits[i]-'0'].size(); j++){
            run.push_back(m[digits[i]-'0'][j]);
            f(digits, m, i+1, n, run, ans);
            run.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int i, n = digits.size();
        if(n==0) return vector<string>();
        
        unordered_map<int,string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        string run = "";
        vector<string> ans;
        f(digits, m, 0, n, run, ans);
        return ans;
    }
};