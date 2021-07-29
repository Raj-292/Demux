// https://leetcode.com/problems/permutations

class Solution {
public:
    void f(vector<int>& nums, vector<bool> visited, vector<int> contri, vector<vector<int>>& res) {
        // Base step
        // When everything is visited
        int i;
        for(i = 0; i < nums.size(); i++) {
            if(!visited[i])
                break;
        }
        
        if(i == nums.size()) {
            res.push_back(contri);
            return;
        }
        
        // Recursive step
        // Iterate over all possibilities for the current position
        for(i = 0; i < nums.size(); i++) {
            // Consider the ones that aren't visited
            if(!visited[i]) {
                // Pass down this contribution
                // Try for this elt at the current position
                contri.push_back(nums[i]);
                visited[i] = true;
                f(nums, visited, contri, res);
                // Undo
                contri.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        vector<int> contri;
        
        f(nums, visited, contri, res);
        
        return res;
        
    }
};