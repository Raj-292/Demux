// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
        visited[start] = true;
        
        for(int i = 0; i < (int)graph.size(); i++) {
            if (graph[start][i] && !visited[i])
                dfs(graph, visited, i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(isConnected, visited, i);
            }
        }
        
        return res;
    }
};