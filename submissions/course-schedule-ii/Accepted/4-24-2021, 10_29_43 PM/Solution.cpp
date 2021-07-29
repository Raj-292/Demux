// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Populate the graph and the indegree vector.
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses, 0);
        vector<int> curr_set;
        int idx = 0;
        vector<int> res;
        
        
        for(auto& pre: prerequisites) {
            // Edge from 1 to 0.
            graph[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }
        
        // Initialize the initial list to traverse.
        for(int i = 0; i < numCourses; i++) {
            if (in[i] == 0)
                curr_set.push_back(i);
        }
        
        // Traverse this list;
        while(idx < curr_set.size()) {
            int curr_node = curr_set[idx];
            res.push_back(curr_node);
            // Decrease the indegree by 1 for all the nbrs of idx
            for (auto& nbr: graph[curr_node]) {
                in[nbr]--;
                if (in[nbr] == 0)
                    curr_set.push_back(nbr);
            }
            idx++;
        }
        
        return (int)res.size() == numCourses? res: vector<int>();
    }
};