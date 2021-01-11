class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // Straightforward binary search
        int n = arr.size(), lo = 0, hi = n - 1, mid;

        // FFF*TTT*
        // p(i): abs(x-arr[i]) <= abs(x-arr[i+k])
        // First T
        while (lo < hi) {

            mid = lo + (hi - lo) / 2;

            if (mid + k >= n || abs(x - arr[mid]) <= abs(x - arr[mid + k]))
                hi = mid;
            else
                lo = mid + 1;
        }

        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);

    }
};