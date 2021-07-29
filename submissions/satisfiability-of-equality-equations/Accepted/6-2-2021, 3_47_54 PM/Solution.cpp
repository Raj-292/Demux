// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    void dfs(unordered_map<char, vector<char>>& graph, char start, unordered_map<char, int>& visited, int label) {
        visited[start] = label;
        
        for (auto& nbr: graph[start]) {
            if (visited.find(nbr) == visited.end())
                dfs(graph, nbr, visited, label);
        }
    }
    bool equationsPossible(vector<string>& equations) {
        // Construct graph
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> visited;
        
        for (auto& eqn: equations) {
            if (eqn[1] == '=' && eqn[2] == '=') {
                graph[eqn[0]].push_back(eqn[3]);
                graph[eqn[3]].push_back(eqn[0]);
            }
        }
        
        int label = 0;
        
        for (auto& node: graph) {
            if (visited.find(node.first) == visited.end()) {
                dfs(graph, node.first, visited, label);
                label++;
            }
        }
        
        // Process inquality
        for (auto& eqn: equations) {
            if (eqn[1] == '!') {
                if (eqn[0]==eqn[3] || (visited.find(eqn[0]) != visited.end() &&
                    visited.find(eqn[3]) != visited.end() && 
                    visited[eqn[0]] == visited[eqn[3]])) {
                        return false;    
                    }
            }
        }
        
        return true;
        
    }
};