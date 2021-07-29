// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool containsCycle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& curr_path, int i) {
        visited[i] = true;
        curr_path[i] = true;
        bool t = false;
        for (auto& nbrs: graph[i]) {
            if (curr_path[nbrs] == true)
                return true;
            
            if (!visited[nbrs]) 
                t = t || containsCycle(graph, visited, curr_path, nbrs);
        }
        curr_path[i] = false;
        return t;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct the graph.
        // Adjacency list.
        vector<vector<int>> graph(numCourses);
        
        for (auto& pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        
        // Find out if this graph contains a cycle.
        vector<bool> visited(numCourses, false);
        vector<bool> curr_path(numCourses, false);
        bool t = false;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                t = t || containsCycle(graph, visited, curr_path, i);
            }  
        }
        
        return !t;
    }
};