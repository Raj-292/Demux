class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), lo, hi, mid;

        if (n == 0) return 0;

        lo = 1, hi = n - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (citations[mid] >= n - mid && citations[mid - 1] <= n - mid) return n - mid;

            if (citations[mid] >= n - mid)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        // Check for 0 as the h-index
        if (citations[n - 1] <= 0) return 0;

        return n;
    }
};

// Another solution

class Solution {
public:
    void f(vector<int>& nums, int i, int end, vector<int> contri, vector<vector<int>> &res) {
        if (i == end) {
            res.push_back(contri);

            contri.push_back(nums[end]);
            res.push_back(contri);
        }
        else {
            // Recursive step
            // C2
            f(nums, i + 1, end, contri, res);

            // C1
            // Contribution at this step is nums[i]
            contri.push_back(nums[i]);
            f(nums, i + 1, end, contri, res);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;

        // Implicit return
        f(nums, 0, nums.size() - 1, {}, res);

        return res;
    }
};