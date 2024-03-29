// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int i, j, k, count, res = INT_MAX, res_vertex;
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
            // Base case.
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
        
        // Base case.
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
                        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        
        for (i = 0; i < n; i++) {
            count = 0;
            for (j = 0; j < n; j++) {
                if (dp[i][j] <= distanceThreshold)
                    count++;
            }
            
            if (res >= count) {
                res = count;
                res_vertex = i;
            }
        }
        
        return res_vertex;
        
    }
};