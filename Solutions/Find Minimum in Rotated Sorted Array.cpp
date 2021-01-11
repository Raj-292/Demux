class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), lo, hi, mid;

        lo = 0, hi = n - 1;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] < nums[0])
                hi = mid;
            else
                lo = mid + 1;
        }

        if (nums[lo] < nums[0])
            return nums[lo];
        return nums[0];
    }
};