// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    vector<vector<int>> nbrs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        
        // Perform dfs on the neighbors.
        for (auto& nbr: nbrs) {
            int x = i + nbr[0];
            int y = j + nbr[1];
            
            // (x, y) is adjacent to (i, j)
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() 
                || visited[x][y] || grid[x][y] == '0')
                continue;
            
            dfs(grid, x, y, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    res++;
                }
            }
        }
        
        return res;
    }
};