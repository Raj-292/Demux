// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class DisjointSet {
public:
    DisjointSet(int len) {
        parent.resize(len);
        for (int i = 0; i < len; i++)
            parent[i] = i;
        
        num_components = len;
    }
    
    void union_(int x, int y) {
        int r_x = find_(x);
        int r_y = find_(y);
        
        parent[r_x] = r_y;
        num_components--;
    }
    
    int find_(int x) {
        while(x != parent[x])
            x = parent[x];
        
        return x;
    }
    
    int getNumComponents() {
        return num_components;
    }

private:
    vector<int> parent;
    int num_components;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n-1)
            return -1;
        
        DisjointSet ds(n);
        
        // Keep adding edges.
        for (int i = 0; i < connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            
            // Extra edge?
            if (ds.find_(x) != ds.find_(y))
                ds.union_(x, y);
        }
        
        int num_components = ds.getNumComponents();
        
        return num_components-1;
    }
};