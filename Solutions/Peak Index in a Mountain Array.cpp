class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1, mid;
        while (lo < hi)
        {
            mid = lo + (hi - lo + 1) / 2;
            if (arr[mid] > arr[mid - 1])
                lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};