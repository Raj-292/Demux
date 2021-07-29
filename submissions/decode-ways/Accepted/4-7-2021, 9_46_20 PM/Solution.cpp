// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), i;
        int last = s[n-1] == '0'?0:1, last_last = 1;
        
        for(i = n-2; i >= 0; i--) {
            int ans = 0;
            
            if(s[i] != '0')
                ans += last;
            
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                ans += last_last;
            last_last = last;
            last = ans;
        }
        
        return last;
    }
};