// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    vector<vector<int> > offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<char> > &graph, vector<vector<bool> > &visited) {
        visited[i][j] = true;
        
        for(int k = 0; k < 4; k++) {
            int x = i + offset[k][0];
            int y = j + offset[k][1];
            
            if(x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size() || visited[x][y] || graph[x][y] == '0')
                continue;
            dfs(x, y, graph, visited);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int i, j, n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return res;
    }
};