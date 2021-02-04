class Solution {
public:
    void f(vector<int>& nums, int j, vector<int>& contri, vector<vector<int>>& res) {
        // Base step
        // When everything is visited
        if (j == nums.size()) {
            res.push_back(contri);
            return;
        }

        // Recursive step
        // Iterate over all possibilities for the current position
        int i;
        for (i = j; i < nums.size(); i++) {
            // Consider the ones that aren't visited
            // Pass down this contribution
            // Try for this elt at the current position
            contri.push_back(nums[i]);
            swap(nums[j], nums[i]);
            f(nums, j + 1, contri, res);
            // Undo
            contri.pop_back();
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> contri;

        f(nums, 0, contri, res);

        return res;

    }
};