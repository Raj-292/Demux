class Solution {
public:
    vector<vector<int>> f(vector<int>& nums, int i, int end) {
        // Base step
        if (i == end) {
            return {{}, {nums[end]}};
        }

        // Recursive step
        // Get C2 & C1
        // Get C2
        vector<vector<int>> c2 = f(nums, i + 1, end);

        // Get C1
        // c2 = {{2}, {3}, {}, {2,3}}
        // c1 = {{2, 1}, {3, 1}, {1}, {2,3,1}}
        vector<vector<int>> c1 = c2;

        for (int j = 0; j < c1.size(); j++)
            c1[j].push_back(nums[i]);

        // Combine them
        vector<vector<int>> res = c2;

        for (int j = 0; j < c1.size(); j++)
            res.push_back(c1[j]);

        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);
    }
};