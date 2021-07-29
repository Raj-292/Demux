// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        
        string tprime = t.substr(1, t.size()-2);
        
        int idx = tprime.find(s);
        
        if(idx == string::npos)
            return false;
        
        
        return true;
        
    }
};