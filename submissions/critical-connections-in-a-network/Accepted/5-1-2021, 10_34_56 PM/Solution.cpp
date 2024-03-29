// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    int dfs (vector<vector<int>>& graph, int i, vector<int>& rank, vector<vector<int>>& res, int prev_rank, int n) {
        rank[i] = prev_rank + 1;
        int t = INT_MAX;
        
        for (const auto& nbr : graph[i]) {
            if (rank[nbr] == -1) {
                int k = dfs(graph, nbr, rank, res, prev_rank+1, n);
                if (k > rank[i])
                    res.push_back({i, nbr});
                t = min(t, k);
            }
            else if (rank[nbr] == n+1)
                continue;
            else if (rank[nbr] != prev_rank)
                t = min(t, rank[nbr]);
        }
        
        rank[i] = n + 1;
        return t;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Construct the graph.
        vector<vector<int>> graph(n);
        
        for (const auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Tarzan's Algorithm.
        vector<vector<int>> res;
        vector<int> rank(n, -1);
        
        int k = dfs(graph, 0, rank, res, 0, n);
        
        return res;
    }
};