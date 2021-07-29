// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void f(vector<int>&candidates, int start, int end, vector<int>&contri, vector<vector<int> >&res, int target) {
        //Base Case :
        if(target == 0) {
            res.push_back(contri);
            return;
        }
        if(target < 0 || start > end)
            return;
        
        //Recursive Step:
        //next different number:
        int j = start;
        while(j <= end && candidates[j] == candidates[start])
            j++;
        
        //Where start element is not included at all:
        f(candidates, j, end, contri, res, target);
        
        //if start element is included in contri:
        contri.push_back(candidates[start]);
        
        //changing target to target - element because it is included:
        f(candidates, start+1, end, contri, res, target - candidates[start]);
        contri.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> >res;
        vector<int>contri;
        f(candidates, 0, candidates.size()-1, contri, res, target);
        return res;
    }
};