// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int res = 0, level = 0;
        
        f(level, n, res);
        
        return res;
    }
    
    void f(int &level, int &n, int &res) {
        if(level == n) {
            res++;
            return;
        }
        if(level > n)
            return;
        level++;
        f(level, n, res);
        level++;
        f(level, n, res);
        level -= 2;
    }
};