// https://leetcode.com/problems/combinations

class Solution {
public:
    void comb(int start, int end, int k, vector<int>&contri, vector<vector<int> >&res) {
        //Base Case:
        if(k == 0) {
            res.push_back(contri);
            return;
        }
        if(start > end)
            return;
        
        //Pruning:
        if(end-start+1 < k)
            return;
        
        //Recursive Case:
        //containing 1st element:
        contri.push_back({start});
        comb(start+1, end, k-1, contri, res);
        contri.pop_back();
        
        //Not containing !st Element:
        comb(start+1, end, k, contri, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >res;
        vector<int>contri;
        comb(1, n, k, contri, res);
        return res;
    }
};