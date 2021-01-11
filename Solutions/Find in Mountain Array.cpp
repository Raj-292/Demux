/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int binarySearch2(MountainArray &mountainArr, int target, int lo, int hi) {

        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (mountainArr.get(mid) <= target)
                hi = mid;
            else
                lo = mid + 1;
        }

        if (mountainArr.get(lo) == target) return lo;
        return -1;


    }
    int binarySearch(MountainArray &mountainArr, int target, int lo, int hi) {

        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (mountainArr.get(mid) >= target)
                hi = mid;
            else
                lo = mid + 1;
        }

        if (mountainArr.get(lo) == target) return lo;
        return -1;


    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // First get the peak element
        int n = mountainArr.length(), lo, hi, mid, minIdx;

        if (mountainArr.get(0) == target) return 0;

        lo = 0, hi = n - 1;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                hi = mid;
            else
                lo = mid + 1;
        }

        minIdx = lo;

        // cout << minIdx << endl;

        // Now search for the target
        if (mountainArr.get(minIdx) < target) return -1;

        if (mountainArr.get(minIdx) == target) return minIdx;

        int idx = binarySearch(mountainArr, target, 0, minIdx);

        // cout << idx << endl;

        if (idx != -1) return idx;

        return binarySearch2(mountainArr, target, minIdx + 1, n - 1);
    }
};