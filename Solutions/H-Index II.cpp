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