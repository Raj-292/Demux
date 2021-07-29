// https://leetcode.com/problems/n-queens

class Solution {
public:
    void f(vector<bool> &col, vector<bool>& pd, vector<bool>& sd, int rem, vector<string>& contri, vector<vector<string>>& res, int n) {
        // Base step
        if(rem == 0) {
            res.push_back(contri);
            return;
        }
        
        // Recursive step
        // C1 to CN
        // Try n-rem row
        int i, j = n-rem;
        for(i = 0; i < n; i++) {
            // Check if this is a valid position
            // Check if possible in the current col
            if(!col[i] &&
              !pd[i+j] &&
              !sd[j-i+n-1]) {
                col[i] = pd[i+j] = sd[j-i+n-1] = true;
                contri[j][i] = 'Q';
                f(col, pd, sd, rem-1, contri, res, n);
                contri[j][i] = '.';
                col[i] = pd[i+j] = sd[j-i+n-1] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> contri(n, string(n, '.'));
        vector<bool> col(n, false), pd(2*n-1, false), sd(2*n-1, false);
        
        f(col, pd, sd, n, contri, res, n);
        
        return res;
    }
};