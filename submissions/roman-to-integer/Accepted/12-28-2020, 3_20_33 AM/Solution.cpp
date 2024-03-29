// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int getValue(char c) {
        if(c == 'I')
            return 1;
        
        if(c == 'V')
            return 5;
        
        if(c == 'X')
            return 10;
        
        if(c == 'L')
            return 50;
        
        if(c == 'C')
            return 100;
        
        if(c == 'D')
            return 500;
        
        return 1000;
    }
    int romanToInt(string s) {
        int i, res = 0;
        
        for(i = 0; i < s.size()-1; i++) {
            // Get the corresponding value of the symbol
            if(getValue(s[i]) >= getValue(s[i+1]))
                res += getValue(s[i]);
            else
                res -= getValue(s[i]);
        }
        
        // Last character
        res += getValue(s[i]);
        
        return res;
    }
};