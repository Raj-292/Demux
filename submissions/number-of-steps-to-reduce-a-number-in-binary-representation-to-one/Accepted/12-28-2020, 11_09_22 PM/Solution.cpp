// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), i, res = 0, first_one_idx = -1;
        bool one_seen = false;
        
        for(i = n-1; i >= 0; i--) {
            // If I haven't seen a 1
            if(!one_seen) {
                if(s[i] == '0')
                    res++;
                else {
                    res += 2;
                    one_seen = true;
                    first_one_idx = i;
                }
            }
            else {
                if(s[i] == '1')
                    res++;
                else
                    res += 2;
            }
        }
        
        return first_one_idx == 0? res-2: res;
    }
};