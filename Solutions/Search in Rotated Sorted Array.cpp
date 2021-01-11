class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1, mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[0]) {
                if (nums[mid] < target || nums[0] > target) lo = mid + 1;
                else hi = mid - 1;
            }
            else {
                if (nums[mid] > target || target >= nums[0]) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return -1;
    }
};