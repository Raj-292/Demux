// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // History.
        unordered_map<int, int> history;
        int pos, max_val = 0;
        
        // Level by level
        for(int i = 0; i < (int)wall.size(); i++) {
            pos = 0;
            for(int j = 0; j < (int)wall[i].size()-1; j++) {
                pos += wall[i][j];
                
                history[pos]++;
                max_val = max(max_val, history[pos]);
            }
        }
        
        return (int)wall.size()-max_val;
    }
};