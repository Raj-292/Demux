// https://leetcode.com/problems/map-of-highest-peak

class Solution {
public:
    vector<vector<int>> offset = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){ 
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for (auto& entry : offset) {
                int x = p.first + entry[0];
                int y = p.second + entry[1];
                
                if (x < 0 || y < 0 || x >= m || y >= n|| res[x][y]!=-1)
                    continue;

                res[x][y] = res[p.first][p.second] + 1;
                q.push({x, y});
            }
        }
        
        return res;
    }
};