// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    void f(int k, int n, vector<int>& contri, vector<vector<int>>& res, int start, int sum){
        if(k==0){
            if(sum==n)
                res.push_back(contri);
            return;
        }
        if(start==10)
            return;
         f(k, n, contri, res, start+1, sum);
        sum+=start;
        contri.push_back(start);
        f(k-1, n, contri, res, start+1, sum);
       // sum-=start;
        contri.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> contri;
        f(k, n, contri, res, 1, 0);
        return res;
    }
};