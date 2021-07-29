// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool ispalindrome(string a){
        int i=0, j=a.size()-1;
        while(i<=j && a[i]==a[j]){
            i++;
            j--;
        }
        if(i>j) return true;
        return false;
    }
    
    void f(string& s, vector<string>& contri, vector<vector<string>>& ans, int start){
        //Base
        if(start == s.size()){
            ans.push_back(contri);
            return;
        }
        
        //Recursion
        for(int i=start; i<s.size();i++){
            string a = s.substr(start, i-start+1);
            if( ispalindrome(a)){
                contri.push_back(a);
                f(s, contri, ans, i+1);
                contri.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> contri;
        f(s,contri, ans, 0);
        return ans;
    }
};