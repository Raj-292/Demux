class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1, mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if ((mid - 1 < 0 || nums[mid] > nums[mid - 1]) && (mid + 1 >= n || nums[mid] > nums[mid + 1]))
                return mid;

            if (mid - 1 >= 0 && nums[mid] <= nums[mid - 1])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return -1;
    }
};