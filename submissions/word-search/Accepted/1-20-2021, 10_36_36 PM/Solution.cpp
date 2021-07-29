// https://leetcode.com/problems/word-search

class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // f(int x, int y, int z)
    // x <-- IN (read only)
    // y <-- OUT (return values)
    // z <-- IN/OUT
    bool f(vector<vector<char>>& board, int start_i, int start_j, vector<vector<bool>>& visited, string &word, int pos) {
        
        if(pos == word.size())
            return true;
        
        // 4 possibilities
        int m = board.size(), n = board[0].size();
        bool res = false;
        for(int i = 0; i < dirs.size(); i++) {
            int x = start_i + dirs[i][0];
            int y = start_j + dirs[i][1];
            
            // Check if it is valid
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            
            // Check if it is already visited
            if(visited[x][y] || board[x][y] != word[pos]) continue;
            
            visited[x][y] = true;
            res = res || f(board, x, y, visited, word, pos+1);
            visited[x][y] = false;
        }
        
        return res;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool res = false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    res = res || f(board, i, j, visited, word, 1);
                    visited[i][j] = false;
                }
            }
        }
        
        return res;
    }
};