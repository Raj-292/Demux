class Solution {
public:
    bool existsInCol(vector<string>& mat, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (mat[i][col] == 'Q')
                return true;
        }

        return false;
    }

    bool existsInDiag(vector<string>& mat, int curr_row, int curr_col, int type, int n) {
        // type = 1 if Principal diagonal (positive slope)
        // type = 2 if Secondary diagonal (negative slope)
        // Go up
        int factor = (type == 1) ? 1 : -1;

        int i = curr_row, j = curr_col;
        while (i >= 0 && j < n && j >= 0) {
            if (mat[i][j] == 'Q')
                return true;
            i--;
            j += factor;
        }

        return false;
    }
    void f(vector<string> &mat, int rem, vector<string>& contri, vector<vector<string>>& res, int n) {
        // Base step
        if (rem == 0) {
            res.push_back(contri);
            return;
        }

        // Recursive step
        // C1 to CN
        // Try n-rem row
        int i;
        for (i = 0; i < n; i++) {
            // Check if this is a valid position
            // Check if possible in the current col
            if (!existsInCol(mat, i, n) &&
                    !existsInDiag(mat, n - rem, i, 1, n) &&
                    !existsInDiag(mat, n - rem, i, 2, n)) {
                mat[n - rem][i] = 'Q';
                contri[n - rem][i] = 'Q';
                f(mat, rem - 1, contri, res, n);
                mat[n - rem][i] = '.';
                contri[n - rem][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> mat(n, string(n, '.'));
        vector<string> contri(n, string(n, '.'));

        f(mat, n, contri, res, n);

        return res;
    }
};

//Most optimal


class Solution {
public:
    void f(vector<bool> &col, vector<bool>& pd, vector<bool>& sd, int rem, vector<string>& contri, vector<vector<string>>& res, int n) {
        // Base step
        if (rem == 0) {
            res.push_back(contri);
            return;
        }

        // Recursive step
        // C1 to CN
        // Try n-rem row
        int i, j = n - rem;
        for (i = 0; i < n; i++) {
            // Check if this is a valid position
            // Check if possible in the current col
            if (!col[i] &&
                    !pd[i + j] &&
                    !sd[j - i + n - 1]) {
                col[i] = pd[i + j] = sd[j - i + n - 1] = true;
                contri[j][i] = 'Q';
                f(col, pd, sd, rem - 1, contri, res, n);
                contri[j][i] = '.';
                col[i] = pd[i + j] = sd[j - i + n - 1] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> contri(n, string(n, '.'));
        vector<bool> col(n, false), pd(2 * n - 1, false), sd(2 * n - 1, false);

        f(col, pd, sd, n, contri, res, n);

        return res;
    }
};