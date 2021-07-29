// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& query) {
        // Preprocessing step
        int n = arr.size(), run_xor = 0;
        vector<int> prefix(n, 0);
        
        // Compute the prefix sum
        for(int i = 0; i < n; i++) {
            run_xor ^= arr[i];
            prefix[i] = run_xor;
        }
        
        // Actual query
        vector<int> res;
        for(int i = 0; i < query.size(); i++) {
            if(query[i][0] == 0)
                res.push_back(prefix[query[i][1]]);
            else
                res.push_back(prefix[query[i][1]]^prefix[query[i][0]-1]);
        }
        
        return res;
    }
};