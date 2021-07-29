// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    vector<vector<int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j,0});
            }
        }
        vector<vector<int>> shortestPath(n,vector<int>(n,-1));
        int res = -1;
        int x,y;
        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            if(shortestPath[curr[0]][curr[1]]==-1)
            {
                shortestPath[curr[0]][curr[1]] = curr[2];
                if(grid[curr[0]][curr[1]]!=1)
                    res = max(res,curr[2]);
            }
            for(auto &element : directions)
            {
                x = curr[0] + element[0];
                y = curr[1] + element[1];
                if(x>=0 && x<n && y>=0 && y<n && shortestPath[x][y]==-1)
                    q.push({x,y,1+curr[2]});
            }
        }
        return res;
    }
};