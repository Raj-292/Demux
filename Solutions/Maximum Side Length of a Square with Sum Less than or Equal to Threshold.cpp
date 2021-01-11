class Solution {
public:
    int getSubmatrixSum(vector<vector<int>> &prefixSum, int botI, int botJ, int length) {
        int topI = botI - length;
        int topJ = botJ - length;

        int sum = prefixSum[botI][botJ];

        if (topJ >= 0)
            sum -= prefixSum[botI][topJ];

        if (topI >= 0)
            sum -= prefixSum[topI][botJ];

        if (topJ >= 0 && topI >= 0)
            sum += prefixSum[topI][topJ];

        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // First compute the prefix sums
        int m = mat.size(), n = mat[0].size(), i, j, rowSum = 0, temp, lo, hi, mid, res = 0;
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));

        for (i = 0; i < m; i++) {
            rowSum = 0;
            for (j = 0; j < n; j++) {

                rowSum += mat[i][j];

                temp = 0;
                if (i - 1 >= 0)
                    temp = prefixSum[i - 1][j];

                prefixSum[i][j] = temp + rowSum;

            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                // Binary search on length
                lo = 1, hi = min(i, j) + 1;

                while (lo < hi) {
                    mid = lo + (hi - lo + 1) / 2;

                    if (getSubmatrixSum(prefixSum, i, j, mid) > threshold)
                        hi = mid - 1;
                    else
                        lo = mid;
                }

                if (getSubmatrixSum(prefixSum, i, j, lo) <= threshold)
                    res = max(res, lo);
            }
        }

        return res;


    }
};