// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Key is position
        // value is the count
        // Declared an empty hash map
        unordered_map<int, int> m;
        
        int i, j, pos, max_count = 0;
        
        for(i = 0; i < wall.size(); i++) {
            pos = 0;
            for(j = 0; j < wall[i].size()-1; j++) {
                // Calculate the position
                pos += wall[i][j];
                
                m[pos]++;
                
                max_count = max(max_count, m[pos]);
            }
        }
        
        return wall.size()-max_count;
    }
};