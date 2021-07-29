// https://leetcode.com/problems/subsets

class Solution {
public:
    void f(vector<int>& nums, int i, int end, vector<int> contri, vector<vector<int>> &res) {
        if(i == end) {
            res.push_back(contri);
            
            contri.push_back(nums[end]);
            res.push_back(contri);
        }
        else {
            // Recursive step
            // C2
            f(nums, i+1, end, contri, res);
 
            // C1
            // Contribution at this step is nums[i]
            contri.push_back(nums[i]);
            f(nums, i+1, end, contri, res);
        }  
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        // Implicit return
        f(nums, 0, nums.size()-1, {}, res);
        
        return res;
    }
};