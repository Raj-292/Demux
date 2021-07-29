// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool ispalindrome(string& a){
        int i=0;
        int j=a.size()-1;
        while(i<=j){
            if(a[i]!=a[j])
                return false;
            i++; j--;
        }
        return true;
    }
    void f(string& s, int start, vector<string>& contri, vector<vector<string>>& res){
        if(start==s.size())
        {
            res.push_back(contri);
            return;
        }
        string a;
        for(int i=start; i<s.size(); i++){
            a=s.substr(start, i-start+1);
            if(!ispalindrome(a))
                continue;
            contri.push_back(a);
            f(s, i+1,contri, res);
            contri.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> contri;
        f(s, 0,contri, res);
        return res;
    }  
};