class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i, j;

        i = 0, j = n - 1;

        while (i < m && j >= 0) {
            // Compare the top right corner
            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }
};