// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int res = 0;
        
        f(0, n, res);
        
        return res;
    }
    
    void f(int level, int &n, int &res) {
        if(level == n) {
            res++;
            return;
        }
        if(level > n)
            return;
        
        f(level+1, n, res);
        f(level+2, n, res);
    }
};