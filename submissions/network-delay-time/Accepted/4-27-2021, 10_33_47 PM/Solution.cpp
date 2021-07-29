// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Construct the graph.
        vector<vector<pair<int, int>>> graph(n+1);
        vector<bool> visited(n+1, false);
        int res = 0, count = 0;
        
        for (const auto& edge : times) {
            graph[edge[0]].push_back({edge[2], edge[1]});
        }
        
        // Weighted BFS.
        // Declare a min Priority Queue.
        priority_queue<pair<int, int>, vector<pair<int, int>>, /* Type of priority */ greater<pair<int, int>> > pq;
        
        pq.push({0, k});
        
        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            
            if (visited[t.second])
                continue;
            
            visited[t.second] = true;
            count++;
            // Shortest path from k to t.second.
            
            res = max(res, t.first);
            
            // Push all the nbrs
            for (const auto& nbrs : graph[t.second]) {
                pq.push({t.first+nbrs.first, nbrs.second});
            }
        }
        
        return count == n? res: -1;
    }
};