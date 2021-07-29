// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        
        int m = matrix.size(), n = matrix[0].size(), lo, hi, mid, i, j;
        
        if(n == 0) return false;
        
        lo = 0, hi = m*n-1;
        
        // FFFTTTT
        // p(x): x > target
        // last F
        // [F, T]
        
        // m = 1, n = 2
        // lo = 0, hi = 1, mid = 1
        // i = 1, j = 0;
        
        // Next iteration
        // lo = 0, hi = 0;
        
        // i = 1, j = 0;
        // lo = 0, hi = 0, mid = 1, i = 1, j = 0;
        while(lo < hi) {
            mid = lo + (hi-lo+1)/2;
            
            i = mid/n;
            j = mid%n;
            
            if(matrix[i][j] > target)
                hi = mid-1;
            else
                lo = mid;
  
        }
        
        // Sanity check
        i = lo/n;
        j = lo%n;
        
        if(matrix[i][j] == target)
            return true;
        
        return false;
        
    }
};