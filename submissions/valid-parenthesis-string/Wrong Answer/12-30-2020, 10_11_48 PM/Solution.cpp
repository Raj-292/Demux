// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int c = 0,i,d = 0;
        for(i = 0; i < s.size() ; i++)
        {
            if(s[i] == '(')
                c++;
            else if(s[i] == ')')
                c--;
            else
                d++;
        }
        if(c == 0||abs(c)-d==0)
            return true;
        else return false;
        
    }
};